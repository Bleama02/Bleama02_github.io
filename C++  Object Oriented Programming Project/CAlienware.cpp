//Filename: CRazer.cpp
//Description: An abstract class to show Razer Brand
//Author: Marcus Blea
//September 9th 2022

#include <iostream>
using namespace std;

#include "CAlienware.h"


CAlienware::CAlienware(void)
{
    numOfComp = 2;
    #ifdef _DEBUG
    cout << "Number Of Alienware Computers: "<< numOfComp << endl;
    #endif
}

CAlienware::~CAlienware(void)
{
    #ifdef _DEBUG
    cout << "Processing Payment"<< endl;
    #endif
}

real CAlienware::size()
{
    return 0.0;
}
    
real CAlienware::price()
{
    #ifdef _DEBUG
    cout << "Verifying Brand" << endl;
    #endif
    return true;
}