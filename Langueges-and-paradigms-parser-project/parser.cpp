#include <iostream>
#include <fstream>
using namespace std;

ifstream infp;
// Tokens names
enum Tokens { LETTER, DIGIT, INT_LIT=10, FLOAT_LIT, IDENT, ASSIGN_OP=20, ADD_OP, SUB_OP,
				MULT_OP, DIV_OP, LEFT_PAREN, RIGHT_PAREN, PERIOD, INT_KEYWORD=40, COMMA, DECL, 
				ENDFILE=80, UNKNOWN=99, FLOAT_KEYWORD};
				
const int SIZE = 100;
Tokens nextToken, charClass;
string lexeme;
char nextChar;

void addChar();
void getChar();
void getNonBlank();
int lex();
void expr();
void term();
void factor();

// Symbol table structure:
struct item
{
    string name;
    int intValue;
    float floatValue;
    string type;
} symbolTable[100];
int tableIndex = 0; // symbol table index

int errors = 0; // counter for error messages
int line = 0;   // variable to keep track of the line number from the source code

/******************************************************/
/*   Helping function to display the token as a string */
void prt (Tokens nt) {
	switch (nt) {
		case LETTER: cout << "<Letter>"; break;
		case DIGIT: cout << "<DIGIT>"; break;
		case INT_LIT: cout << "<INT_LIT>"; break;
		case FLOAT_LIT: cout << "<FLOAT_LIT>"; break;
		case IDENT: cout << "<IDENT>"; break;
		case ASSIGN_OP: cout << "<ASSIGN>"; break;
		case ADD_OP: cout << "<ADD_OP>"; break;
		case SUB_OP: cout << "<SUB_OP>"; break;
		case MULT_OP: cout << "<MULT_OP>"; break;
		case DIV_OP: cout << "<DIV_OP>"; break;
		case LEFT_PAREN: cout << "<LEFT_PAREN>"; break;
		case RIGHT_PAREN: cout << "<RIGHT_PAREN>"; break;
		case COMMA: cout << "<COMMA>"; break;
		case PERIOD: cout << "<PERIOD>"; break;
		case INT_KEYWORD: cout << "<INT_KEYWORD>"; break;
		case ENDFILE: cout << "<ENDOFFILE>"; break;
		case UNKNOWN: cout << "Unknow "; break;
		case FLOAT_KEYWORD: cout << "<FLOAT_KEYWORD>"; break;
	}
}

/********************************************/
/* errMsg - function to display the error message with the line number of the error detected. */
void errMsg (string msg) {
	cout << "Error at line: " << line << ": " << msg << endl;
	errors++;
	lex();
}

/*****************************************************/
/* lookup - a function to lookup operators and parentheses
 and return the token */
int lookup(char ch) {
	switch (ch) {
		case '(':
			addChar();
			nextToken = LEFT_PAREN;
			break;
		case ')':
			addChar();
			nextToken = RIGHT_PAREN;
			break;
		case '+':
			addChar();
			nextToken = ADD_OP;
			break;
		case '-':
			addChar();
			nextToken = SUB_OP;
			break; 
		case '*':
			addChar();
			nextToken = MULT_OP;
			break;
		case '/':
			addChar();
			nextToken = DIV_OP;
			break;
		case '=':
			addChar();
			nextToken = ASSIGN_OP;
			break;
		case ',':
			addChar ();
			nextToken = COMMA;
			break;
		default:
			addChar();
			nextToken = ENDFILE;
			break;
	}
	return nextToken;
}

/*****************************************************/
/* addChar - a function to add nextChar to lexeme */
void addChar() {
	lexeme += nextChar;
	if (lexeme.size() > 99) {
		errMsg ("Lexeme size exceeds 100 characters");
		exit(0);
	}
}

/*****************************************************/
/* getChar - a function to get the next character of 
 input and determine its character class */
void getChar() {
	if ((nextChar = infp.get()) != EOF) {
		if (isalpha(nextChar)) charClass = LETTER;
		else if (isdigit(nextChar)) charClass = DIGIT;
		else if (nextChar == '.') charClass = PERIOD;
		else charClass = UNKNOWN;
	}
	else charClass = ENDFILE;
}

/*****************************************************/
/* getNonBlank - a function to call getChar until it
 returns a non-whitespace character */
void getNonBlank() {
	while (isspace(nextChar)) {
		if (nextChar == '\n') line++; // when end of line is found, increment line
		getChar();
	}
}

/*******************************************************************
LookupKeyword - a simple lookup code for keywords in the language: */
void lookupKeywords (string lexeme) {
	// Insert your code here to check for reserved words (keywords) and set the nextToken variable
	if (lexeme == "int") nextToken = INT_KEYWORD;
	else nextToken = IDENT;

	if (lexeme == "float") nextToken = FLOAT_KEYWORD;

}

/*****************************************************/
/* lex - a simple lexical analyzer for arithmetic 
 expressions */
int lex() {
	lexeme="";
	if (isspace(nextChar)) getNonBlank();
	switch (charClass) {
		case LETTER: 		/* Parse identifiers */
			addChar();
			getChar();
			while (charClass == LETTER || charClass == DIGIT) {
				addChar();
				getChar();
			}
			nextToken = IDENT;
			lookupKeywords (lexeme);
			break;
		case DIGIT: {		/* Parse integer literals */
			addChar();
			getChar();
			bool float_number = false;
			while (charClass == DIGIT || charClass == PERIOD) {
				if (charClass == PERIOD) float_number = true;
				addChar();
				getChar();
			}
			if (float_number) nextToken = FLOAT_LIT;
			else nextToken = INT_LIT;
			break;
		}
		case UNKNOWN: 		/* Parentheses and operators */
			lookup(nextChar);
			getChar();
			break;
		case ENDFILE:	/* EOF */
			nextToken = ENDFILE;
			lexeme = "EOF";
			break;
	} /* End of switch */
	//cout << "Next token is: "; prt (nextToken); cout << " Next lexeme is " << lexeme << endl;
	return nextToken;
} /* End of function lex */

/******************************************* End of Lexical Analyzer (tokenizer) **************************************************************************/

/******************************************* Start of Syntax Analyzer (parser) **************************************************************************/

/*********************************************************************************************/
/*     Symbol table                                                                          */
/* addSymbolTable - add a lexeme name, its type, value (int or float) to the symbol table    */
void addSymbolTable (string lexeme, string type, int intV, float floatV) {
	symbolTable [tableIndex].name = lexeme;
	symbolTable [tableIndex].type = type;
	symbolTable [tableIndex].intValue = intV;
	symbolTable [tableIndex++].floatValue = floatV;
}

/********************************************************************************/
/* searchSymbolTable: search the symbol table for a lexeme and return its index */
bool searchSymbolTable (string lexeme) {
	for (int i=0; i<tableIndex; i++) 
		if (symbolTable[i].name == lexeme) return true;
	return false;
}

void printSymbolTable () {
	cout << "******************** Symbol Table *******************************\n";
	for (int i=0; i<tableIndex; i++) {
		if (symbolTable[i].type == "int")
			cout << symbolTable[i].name << "  " << symbolTable[i].intValue << "  " << symbolTable[i].type << endl;
		else
			cout << symbolTable[i].name << "  " << symbolTable[i].floatValue << "  " << symbolTable[i].type << endl;
	}
	cout << "***************************************************\n";
}

/**************************************************/
/* expr
 Parses strings in the language generated by the rule:
 <expr> -> <term> {(+ | -) <term>}
 */
void expr() {
	/* Parse the first term */
	term();
	/* As long as the next token is + or -, get
 	   the next token and parse the next term */
	while (nextToken == ADD_OP || nextToken == SUB_OP) {
		lex();
		term();
	}
} /* End of function expr */

/*************************************************************/
/* term
 Parses strings in the language generated by the rule:
 <term> -> <factor> {(* | /) <factor>) 
 */
void term() {
	/* Parse the first factor */
	factor();
	/* As long as the next token is * or /, get the
	   next token and parse the next factor */
	while (nextToken == MULT_OP || nextToken == DIV_OP) {
		lex();
		factor();
	}
} /* End of function term */

/***************************************************************/
/* factor
 Parses strings in the language generated by the rule:
 <factor> -> <ident> | <int_literal> | <float_literal> | ( <expr> )
 */
void factor() {
	/* Determine which RHS */
	if (nextToken == IDENT || nextToken == INT_LIT || nextToken == FLOAT_LIT)
 		lex(); 		/* Get the next token */
 	else { // token is not identifier, integer literal or float literal
 		if (nextToken == LEFT_PAREN) { // left paraenthsis founf
 			lex(); // get next token
 			expr(); // parse expression
 			if (nextToken == RIGHT_PAREN) lex();  // right paraenthsis found, get next token
 			else errMsg("Right parenthesis expected, found " + lexeme);
 		} /* End-if (nextToken == LEFT_PAREN */
 		else errMsg("expected identifier, integer literal, float literal or left paranthesis expected, found " + lexeme);
 	} /* End else */
} /* End function factor */


/************************************************/
/* assign - parse assignment statement by the rule:
   <assign> -> <identifier> = <expr>
*/
void assign() {	
	if (nextToken == IDENT) { // identifier found
		if (searchSymbolTable (lexeme)) lex(); // check symbol table, if found get next token
		else errMsg ("Undefined identifier " + lexeme);
		if (nextToken == ASSIGN_OP) { // equal sign found
			lex ();	// get next token
			expr(); // parse expression
		}
		else errMsg ("equal sign expected, found " + lexeme);
	}
	else errMsg("Identifier expected, found " + lexeme);
}

/**************************************************/
/* <floatVar> - parse integer variable by the rule:
   <floatVar> -> <ident> | <ident><floatLit>
*/
void floatVar () {
	string varName = lexeme;
	lex ();
	if (nextToken == ASSIGN_OP) {
		lex (); // get next token
		if (nextToken == FLOAT_LIT) {
	   		float value = atof (lexeme.c_str()); // convert string to integer
	   		addSymbolTable (varName, "float", 0, value); // add identifier to the symbol table
	   		lex(); // get next token
		}
		else errMsg ("Float expected, found " + lexeme);
	}
	else {
		addSymbolTable (varName, "float", 0, 0);
	}
}


/**************************************************/
/* <intVar> - parse integer variable by the rule:
   <intVar> -> <ident> | <ident><intLit>
*/
void intVar () {
	string varName = lexeme;
	lex ();
	if (nextToken == ASSIGN_OP) {
		lex (); // get next token
		if (nextToken == INT_LIT) {
	   		int value = atoi (lexeme.c_str()); // convert string to integer
	   		addSymbolTable (varName, "int", value, 0); // add identifier to the symbol table
	   		lex(); // get next token
		}
		else errMsg ("Integer expected, found " + lexeme);
	}
	else {
		addSymbolTable (varName, "int", 0, 0);
	}
}

/*************************************************/
/* int_ident - integer identifier (variable) parser by the rule:
   <floatIdent> -> <floatVar> <floatVar>*
*/
void floatIdent () {
	if (nextToken == IDENT) {
		while (nextToken == IDENT) {
			floatVar ();
			if (nextToken == COMMA) lex ();
			else break;
		}	
	}
	else errMsg ("Identifier expected, fount " + lexeme);	
}

/*************************************************/
/* int_ident - integer identifier (variable) parser by the rule:
   <intIdent> -> <intVar> <intVar>*
*/
void intIdent () {
	if (nextToken == IDENT) {
		while (nextToken == IDENT) {
			intVar ();
			if (nextToken == COMMA) lex ();
			else break;
		}	
	}
	else errMsg ("Identifier expected, fount " + lexeme);	
}

/***************************************************/
/* decl - parse declaration statement by the rule
   <ident> -> int <intIdent> | float <floatIdent>
*/
void declaration () {
	string typeName = lexeme, name;
	lex ();
	if (typeName == "int") intIdent ();
	else if (typeName == "float") floatIdent ();
}

/********************************************/
/* stmt - statement parser by the rule:
   <stmt> -> <decl> | <assign>
*/
void stmt () {
	if (nextToken == INT_KEYWORD) 
	{
		nextToken == FLOAT_KEYWORD;
		declaration (); // parse declaration
	}
	else assign (); // parse assignment statement
}

/******************************************* End of Syntax Analyzer (parser) **************************************************************************/

/******************************************************/
/* main driver */
int main() {
	/* Open the input data file and process its contents */
	string filename;
	//cout << "Enter file name: ";
	//cin >> filename;
	filename = "prg.in";
	infp.open(filename);
	if (!infp) {
		cout << "ERROR - cannot open "  << filename <<  "\n";
		errors++;
	}
	else {
		nextChar = ' ';
		lex();
		do
		{
			stmt ();
			if (errors > 10) break;
		} while (nextToken != ENDFILE);
		
	}
	cout << "Total number of errors: " << errors << endl;
		
	return 0;
}