//File Name: Blea_HW38.cpp
//Description: Towers of Hanoi
//Author: Marcus Blea
//Date: 11/29/2022

#include <iostream>
#include <cstring>
using namespace std;

int moveDiscs(int n, char *sourcePeg, char *toPeg, char *tempPeg);

int main()
{
    int numDiscs;
    char *pegNames[3] = {"Peg A", "Peg B", "Peg C"};
    int count;


    cout << "Towers of Hanoi" << endl;
    cout << endl;

    cout << "How many discs on the peg?" << endl;
    cin >> numDiscs;

    count = moveDiscs(numDiscs, pegNames[0], pegNames[2], pegNames[1]);
    cout << endl;
    cout << "Discs are now in order." << endl;
    cout << "It took " << count << " moves" << endl;
    cout << "Thank you!" << endl;
    return 0;
}

int moveDiscs(int n, char *sourcePeg, char *toPeg, char *tempPeg)
{
    static int count = 0;
    if (n > 0)
    {
        moveDiscs(n-1, sourcePeg, tempPeg, toPeg);
        count++;
        cout << "Move " << count << ". ";

        cout << "Moving Disc " << n << " from " << sourcePeg << " to " << toPeg << endl;
        moveDiscs(n-1, tempPeg, toPeg, sourcePeg);
    }
    return count;
}