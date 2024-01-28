//Filename: CRazer.cpp
//Description: An abstract class to show Razer Brand
//Author: Marcus Blea
//September 9th 2022

#include <iostream>
using namespace std;

#include "CLenovo.h"


CLenovo::CLenovo(void)
{
    numOfComp = 1;
    #ifdef _DEBUG
    cout << "Number Of Types Lenovo Computers: "<< numOfComp << endl;
    #endif
}

CLenovo::~CLenovo(void)
{
    #ifdef _DEBUG
    cout << "Processing Payment"<< endl;
    #endif
}

real CLenovo::size()
{
    return 0.0;
}
    
real CLenovo::price()
{
    #ifdef _DEBUG
    cout << "Verifying Brand" << endl;
    #endif
    return true;
}