//Filename: Blea_TermProject1.cpp
//Description: Computer Store
//Author: Marcus Blea
//October 30th 2022

#include <iostream>
#include <cstdlib>
#include<time.h>
using namespace std;

#include "CRazerBook.h"
#include "CBlade17.h"
#include "CAWAurora.h"
#include "CAWLaptop.h"
#include "CLegion5Gen7.h"

int main()
{
    srand(time(NULL));
    cout << "Welcome to the Computer Store!" << endl;
    
    CElectronic *electronics[12];

    electronics[0] = new CRazerBook();
    ((CRazerBook*)electronics[0])->size();
    cout << "Total cost, including tax, is: $" << ((CRazerBook*)electronics[0])->price() << endl;

    electronics[1] = new CRazerBlade();
    ((CRazerBlade*)electronics[1])->size();
    cout << "Cost of Computer Without Tax: $" << ((CRazerBlade*)electronics[1])->price() << endl;
    
    electronics[2] = new CBlade17();
    ((CBlade17*)electronics[2])->size();
    cout << "Total cost, including tax, is: $" << ((CBlade17*)electronics[2])->price() << endl;
    
    electronics[3] = new CAWAurora();
    ((CAWAurora*)electronics[3])->size();
    cout << "Total cost, including tax, is: $" << ((CAWAurora*)electronics[3])->price() << endl;

    electronics[4] = new CAWLaptop();
    ((CAWLaptop*)electronics[4])->size();
    cout << "Total cost, including tax, is: $" << ((CAWLaptop*)electronics[4])->price() << endl;

    electronics[5] = new CLegion();
    ((CLegion*)electronics[5])->size();
    cout << "Cost of Computer Without Tax: $" << ((CLegion*)electronics[5])->price() << endl;

    electronics[6] = new CLegion5Gen7();
    ((CLegion5Gen7*)electronics[6])->size();
    cout << "Total cost, including tax, is: $" << ((CLegion5Gen7*)electronics[6])->price() << endl;

    cout << "Continuing to Checkout..." << endl;

    delete ((CRazerBook*)electronics[0]);
    delete ((CRazerBlade*)electronics[1]);
    delete ((CBlade17*)electronics[2]);
    delete ((CAWAurora*)electronics[3]);
    delete ((CAWLaptop*)electronics[4]);
    delete ((CLegion*)electronics[5]);
    delete ((CLegion5Gen7*)electronics[6]);

    return 0;
}
