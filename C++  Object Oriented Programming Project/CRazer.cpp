//Filename: CRazer.cpp
//Description: An abstract class to show Razer Brand
//Author: Marcus Blea
//September 9th 2022

#include <iostream>
using namespace std;

#include "CRazer.h"


CRazer::CRazer(void)
{
    numOfComp = 2;
    #ifdef _DEBUG
    cout << "Number of Types Razer Computers: "<< numOfComp << endl;
    #endif
}

CRazer::~CRazer(void)
{
    #ifdef _DEBUG
    cout << "Processing Payment..."<< endl;
    #endif
}

real CRazer::size()
{
    return 0.0;
}
    
real CRazer::price()
{
    #ifdef _DEBUG
    cout << "Verifying Brand" << endl;
    #endif
    return true;
}