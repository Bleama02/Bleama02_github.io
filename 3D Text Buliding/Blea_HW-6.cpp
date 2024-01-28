//Filename: Blea_HW05.cpp
//Description: Draw Some Text!
//Author: Marcus Blea
//October 18th 2022
#include <iostream>
using namespace std;

#if defined __APPLE__ 
    #include <GLUT/glut.h>
#elif defined _WIN32 || defined _WIN64
    #include <GL/glut.h>
#elif __linux__
    #include <GL/freeglut.h>
#endif

//Function prototypes..
void display(void);
void enableLights();
void resetScene();
void reshape(GLsizei width, GLsizei height);
void keyboardClick(unsigned char key, GLsizei x, GLsizei y);
void mouseClick(int button, int state, GLsizei x, GLsizei y);
void mouseMotion(GLsizei x, GLsizei y);
void timer(int millisec);
void drawStrokeText(char *text, void *font, GLfloat x, GLfloat y, GLfloat z);
GLfloat getStrokeTextWidth(char *text, void *font);
GLfloat getBitMapTextWidth(char *text, void *font);

void drawBitMapText(char *text, void *font, GLfloat x, GLfloat y);
void drawCube();
void drawPyramid();

//global variables

bool blLightsAreOn;
GLfloat rotationX, rotationY;  // Current rotation of the center object
GLfloat locationX, locationY;  // Current location of the center object
int orbitRotation;             //Rotation in degrees
GLsizei prevMouseX, prevMouseY; //current mouse location in the window
GLsizei windowWidth = 640;      
GLsizei windowHeight = 480;     
bool blMouseMiddleDown;     // current state of the button
bool blMouseRightDown;      // current state of the button
bool blMouseLeftDown;


int main(int argc, char** argv)
{
    //Initialization functions 
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE);    //Use double buffer mode
    glutInitWindowSize(windowWidth, windowHeight);       //Set the window's initial width and height
    glutInitWindowPosition(50,50); // Where the position of the window is

    glutCreateWindow("Draw Lots of GLUT Shapes");

    //callback functions...
    glutDisplayFunc(&display);          //callback to display
    glutReshapeFunc(&reshape);          //callback to catch of the window
    glutKeyboardFunc(&keyboardClick);   // callback to handle normal keyboard clicks
    glutMouseFunc(&mouseClick);         //callback to handle mouse buttons
    glutMotionFunc(&mouseMotion);       //callback to handle mouse movement
    glutTimerFunc(20, &timer, 20);      //Redraw every 20ms (50 times per seconds)

    resetScene();
    glutMainLoop();
    return EXIT_SUCCESS;
}

void display(void)
{
    reshape(windowWidth, windowHeight);
    char text[80];
    GLfloat textWidth = 0.0f;
    //static int i = 0 ;
    //cout << "Drawing" << endl;
    enableLights();

    #if defined __APPLE__ 
        glClear(GL_COLOR_BUFFER_BIT);
    #else
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    #endif

        glEnable(GL_CULL_FACE);
        glMatrixMode(GL_MODELVIEW); //switch to model view mode
        glLoadIdentity();

        glTranslatef(0.0f, 0.0f, -10.0f);

        //Draw my name
        glPushMatrix();
        strcpy(text, "Marcus Blea");
        textWidth = getStrokeTextWidth(text, GLUT_STROKE_ROMAN);
        glRotatef(-orbitRotation, 0.0f, 1.0f, 0.0f);
        glScalef(0.005f, 0.005f, 0.005f);
        glTranslatef(-0.5 * textWidth, 0.0f, 0.0f);
        glLineWidth(5.0f);
        drawStrokeText(text, GLUT_STROKE_ROMAN, 0.0f, 0.0f, 0.0f);
        glPopMatrix();

        //draw text in corner 
        glPushMatrix();
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluOrtho2D(0.0f, (GLdouble)windowWidth, 0.0f, (GLdouble)windowHeight);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glColor3f(1.0f, 1.0f, 1.0f);

        glDisable(GL_LIGHTING);

        glPushMatrix();
        strcpy(text, "Top Left");
        drawBitMapText(text, GLUT_BITMAP_TIMES_ROMAN_10, 0.0f, windowHeight - 15);
        glPopMatrix();

        glPushMatrix();
        strcpy(text, "Top Right");
        textWidth = getBitMapTextWidth(text, GLUT_BITMAP_TIMES_ROMAN_10);
        drawBitMapText(text, GLUT_BITMAP_TIMES_ROMAN_10, windowWidth - textWidth, windowHeight - 15);
        glPopMatrix();

        glPushMatrix();
        strcpy(text, "Bottom Left");
        drawBitMapText(text, GLUT_BITMAP_TIMES_ROMAN_10, 5.0f, 5.0f);
        glPopMatrix();

        
        glPushMatrix();
        strcpy(text, "Bottom Right");
        textWidth = getBitMapTextWidth(text, GLUT_BITMAP_TIMES_ROMAN_10);
        drawBitMapText(text, GLUT_BITMAP_TIMES_ROMAN_10, windowWidth - textWidth, 6.0f);

        glPopMatrix();

        glPopMatrix();

       glutSwapBuffers();
}

void enableLights()
{
    if (blLightsAreOn)
    {
        glEnable(GL_LIGHTING);
        glEnable(GL_COLOR_MATERIAL);

        GLfloat lightsKa[] = {0.3f, 0.3f, 0.3f, 1.0f};    //Ambient light
        GLfloat lightsKd[] = {0.7f, 0.7f, 0.7f, 1.0f};    //diffuse light
        GLfloat lightsKs[] = {1.0f, 1.0f, 1.0f, 1.0f};    //Specular light

        glLightfv(GL_LIGHT0, GL_AMBIENT, lightsKa);
        glLightfv(GL_LIGHT0, GL_DIFFUSE, lightsKd);
        glLightfv(GL_LIGHT0, GL_SPECULAR, lightsKs);

        GLfloat lightPos[] = {0.0f, 0.0f, -15.0f, 1.0f};
        glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
        glEnable(GL_LIGHT0);
    }
    else
    {
        glDisable(GL_LIGHTING);
    }
}

void resetScene()
{
    rotationX = 0.0f;
    rotationY = 0.0f;
    locationX = 0.0f;
    locationY = 0.0f;
    orbitRotation = 0;
    prevMouseX = 0;
    prevMouseY = 0;

    blLightsAreOn = true;
    blMouseLeftDown = false;
    blMouseMiddleDown = false;
    blMouseRightDown = false;


    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); 
    glClearDepth(1.0f);                    // Set background to furthest away
    glEnable(GL_DEPTH_TEST);               // Enable the depth test for z
    glDepthFunc(GL_LEQUAL);                // Set depth to be in front of the background 
    glShadeModel(GL_SMOOTH);               // Set to smooth shading 
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);  // Used best perspective correction
    glFrontFace(GL_CCW);
    enableLights();
}

void reshape(GLsizei width, GLsizei height)
{
    blLightsAreOn = !blLightsAreOn;
    

    //cout << "Reshape" << endl;
    if (height <= 0) height = 1;
    if (width <= 0) width = 1;

    GLfloat aspectRatio = (GLfloat)width/(GLfloat)height;

    windowWidth = width;
    windowHeight = height;

    //Ste the viewport to cover the entire window
    glViewport(0, 0, width, height);

    

    //set the aspect ratio for rendering to math th viewport
    glMatrixMode(GL_PROJECTION);   //Switch to projection mode 
    glLoadIdentity();              //Reset stuff in the currant mode

    //Enable perspective projection mode with (fov, aspect, zNearClip, zfarClip)
    if (height <= 0) height = 1;
    gluPerspective(45.0f, aspectRatio, 0.1f, 100.0f);

}

void keyboardClick(unsigned char key, GLsizei x, GLsizei y)
{
    switch (key)
    {
        case 'q': case 'Q': case 26:
            exit(EXIT_SUCCESS);
            break;
        case 'l': case 'L':
            blLightsAreOn = !blLightsAreOn;
            glutPostRedisplay();
            break;
        case 'r': case 'R':
            resetScene();
            glutPostRedisplay();
            break;
        
    }
}

void mouseClick(int button, int state, GLsizei x, GLsizei y)
{
    if (button == GLUT_LEFT_BUTTON)
    {
        if (state == GLUT_DOWN) blMouseLeftDown = true;
        else blMouseLeftDown = false;
    }

    if (button == GLUT_MIDDLE_BUTTON)
    {
        if (state == GLUT_DOWN) blMouseMiddleDown = true;
        else blMouseMiddleDown = false;
    }

    if (button == GLUT_RIGHT_BUTTON)
    {
        if (state == GLUT_DOWN) blMouseRightDown = true;
        else blMouseRightDown = false;
    }
    prevMouseX = x;
    prevMouseY = y;
    

}

void mouseMotion(GLsizei x, GLsizei y)
{
    if(blMouseLeftDown)
    {
        rotationX += x - prevMouseX;
        rotationY += y - prevMouseY;

    }
    if (blMouseRightDown)
    {
        locationX += 10.0f * (x - prevMouseX) / windowWidth;
        locationY -= 10.0f * (y - prevMouseY) / windowHeight;
    }
    prevMouseX = x;
    prevMouseY = y;
    glutPostRedisplay();
}

void timer(int millisec)
{
    orbitRotation++;
    if (orbitRotation <= 360) orbitRotation -= 360;
    glutTimerFunc(millisec, &timer, millisec);
    glutPostRedisplay();
}

void drawStrokeText(char *text, void *font, GLfloat x, GLfloat y, GLfloat z)
{
    //GLUT_STROKE_ROMAN
    //GLUT_STROKE_MONO_ROMAN
    glPushMatrix();
    glTranslatef(x, y, z);
    char *c;
    for (c = text; *c; c++)
    {
        //glColor3f(*c/255.0f, *c/255.0f, *c/255.0f);
        //glColor3f(*c/127.0f, *c/127.0f, *c/127.0f);
        glColor3f(rand()/(GLfloat)RAND_MAX , rand()/(GLfloat)RAND_MAX, rand()/(GLfloat)RAND_MAX);

        glutStrokeCharacter(font, *c); 
    }
    glPopMatrix();
    
}

GLfloat getStrokeTextWidth(char *text, void *font)
{
    GLfloat w = 0.0f;
    char *c;
    for (c = text; *c; c++)
    {
        w += (GLfloat)glutStrokeWidth(font, *c); 
    }
    return w;
}

void drawBitMapText(char *text, void *font, GLfloat x, GLfloat y)
{
    //GLUT_BITMAP_9_BY_15
    //GLUT_BITMAP_TIMES_ROMAN_10
    //GLUT_BITMAP_HELVETICA_12
    glPushMatrix();
    glRasterPos2f(x, y);
    char *c;
    for (c = text; *c; c++)
    {
        glutBitmapCharacter(font, *c); 
    }
    glPopMatrix();
}

GLfloat getBitMapTextWidth(char *text, void *font)
{
    GLfloat w = 0.0f;
    char *c;
    for (c = text; *c; c++)
    {
        w += (GLfloat)glutBitmapWidth(font, *c); 
    }
    return w;
}


void drawCube()
{

    glBegin(GL_QUADS);

            // Front Face (z = 1.0f)
        glColor3f(1.0f, 1.0f, 0.0f);  //
        glVertex3f( 1.0f,  1.0f,  1.0f); //A
        glVertex3f(-1.0f,  1.0f,  1.0f); //B
        glVertex3f(-1.0f, -1.0f,  1.0f); //C
        glVertex3f( 1.0f, -1.0f,  1.0f); //D

    glEnd();

    glBegin(GL_QUADS);

            // Right Face (z = 1.0f)
        glColor3f(1.0f, 1.0f, 1.0f);  //
        glVertex3f( 1.0f,  1.0f,  1.0f); //A
        glVertex3f( 1.0f, -1.0f,  1.0f); //D
        glVertex3f( 1.0f, -1.0f, -1.0f); //H
        glVertex3f(1.0f,  1.0f, -1.0f); //E

    glEnd();
    

    glBegin(GL_QUADS);

            // Back Face (z = 1.0f)
        glColor3f(1.0f, 0.5f, 0.50f);  //
        glVertex3f(1.0f,  1.0f, -1.0f); //E
        glVertex3f( 1.0f, -1.0f, -1.0f); //H
        glVertex3f(-1.0f, -1.0f, -1.0f); //G
        glVertex3f(-1.0f,  1.0f, -1.0f); //F

    glEnd();

    glBegin(GL_QUADS);

            // Left Face (z = 1.0f)
        glColor3f(0.34f, .65f, 1.0f);  //
        glVertex3f(-1.0f,  1.0f, -1.0f); //F
        glVertex3f(-1.0f, -1.0f, -1.0f); //G
        glVertex3f(-1.0f, -1.0f, 1.0f); //C
        glVertex3f(-1.0f,  1.0f,  1.0f); //B

    glEnd();

    glBegin(GL_QUADS);

            // Bottom Face (z = 1.0f)
        glColor3f(1.0f, 0.0f, 0.0f);  //
        glVertex3f(-1.0f, -1.0f, 1.0f); //C
        glVertex3f(-1.0f, -1.0f, -1.0f); //G
        glVertex3f( 1.0f, -1.0f, -1.0f); //H
        glVertex3f( 1.0f, -1.0f,  1.0f); //D
        

    glEnd();

    glBegin(GL_QUADS);

            // top Face (z = 1.0f)
        glColor3f(1.0f, 0.89f, 0.67f);  //
        glVertex3f(-1.0f,  1.0f, -1.0f); //F
        glVertex3f(-1.0f,  1.0f,  1.0f); //B
        glVertex3f( 1.0f,  1.0f,  1.0f); //A
        glVertex3f(1.0f,  1.0f, -1.0f); //E

    glEnd();

}

void drawPyramid()
{
    glBegin(GL_QUADS);

        glColor3f(1.0f, 0.0f, 0.0f);  //
        glVertex3f(-1.0f, -1.0f, 1.0f); //A
        glColor3f(0.75f, 0.5f, 1.0f);  //
        glVertex3f(-1.0f, -1.0f, -1.0f); //B
        glColor3f(0.95f, 0.0f, 1.0f);  //
        glVertex3f( 1.0f, -1.0f, -1.0f); //C
        glColor3f(0.24f, 1.0f, 1.0f);  //
        glVertex3f( 1.0f, -1.0f,  1.0f); //D

    glEnd();


    glBegin(GL_TRIANGLES);

        glColor3f(1.0f, 1.0f, 0.5f);  //
        glVertex3f(-1.0f, -1.0f, 1.0f); //A
        glColor3f(0.0f, 1.0f, 1.0f);
        glVertex3f(0.0f, 1.0f, 0.0f); //E
        glColor3f(0.2f, 1.0f, 0.5f);
        glVertex3f(-1.0f, -1.0f, -1.0f); //B
        
    glEnd();

    glBegin(GL_TRIANGLES);

        glColor3f(0.2f, 1.0f, 0.5f); 
        glVertex3f(-1.0f, -1.0f, -1.0f); //B
        glColor3f(0.0f, 1.0f, 1.0f);  //
        glVertex3f(0.0f, 1.0f, 0.0f); //E
        glColor3f(0.55f, 0.5f, 0.25f);  //
        glVertex3f( 1.0f, -1.0f, -1.0f); //C
        
    glEnd();

    glBegin(GL_TRIANGLES);

        glColor3f(0.55f, 0.5f, 0.25f); //
        glVertex3f(1.0f, -1.0f, -1.0f); //C
        glColor3f(0.0f, 1.0f, 1.0f);  //
        glVertex3f(0.0f, 1.0f, 0.0f); //E
        glColor3f(0.43f, 0.5f, 0.3f);  //
        glVertex3f( 1.0f, -1.0f,  1.0f); //D
        
        
    glEnd();

    glBegin(GL_TRIANGLES);

          
        glColor3f(0.43f, 0.5f, 0.3f);  //
        glVertex3f( 1.0f, -1.0f, 1.0f); //D
        glColor3f(0.0f, 1.0f, 1.0f); //
        glVertex3f(0.3f, 1.0f,  0.56f); //E
        glColor3f(1.0f, 1.0f, 0.5f);  
        glVertex3f(-1.0f, -1.0f, 1.0f); //A
        
        
    glEnd();

}
