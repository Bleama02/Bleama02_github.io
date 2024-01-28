//Filename: CShape.h
//Description: See header file for structural information
//Author: Marcus Blea
//September 9th 2022

#include <iostream>
using namespace std;

#include "CElectronic.h"

CElectronic::CElectronic(void)
{
    #ifdef _DEBUG
    cout << "Gaming PC's Found" << endl;
    #endif
}

CElectronic::~CElectronic(void)
{
    #ifdef _DEBUG
    cout << "Computer Sold!" << endl;
    #endif
}

real CElectronic::size()
{
    return 0.0;
}
    
real CElectronic::price()
{
    #ifdef _DEBUG
    cout << "Choosing Brand" << endl;
    #endif
    return true;
}

