//Filename: CRectangle.h
//Description: See header file for structural information
//Author: Marcus Blea
//September 9th 2022

#include <iostream>
using namespace std;

#include "CRazerBlade.h"


CRazerBlade::CRazerBlade(void)
{
    numVersion = 1;
    #ifdef _DEBUG
    cout << "Number of different Versions of Razer Blades in stock: " << numVersion << endl;
    #endif
}

CRazerBlade::~CRazerBlade(void)
{
    #ifdef _DEBUG
    cout << "Accepting a payment..."<< endl;
    #endif
}

real CRazerBlade::size()
{
    m_height = 10.33;
    m_width = 14.13;
    #ifdef _DEBUG
    cout << "Screen size Options: " << "(" << m_width << "\", " << m_height << "\")" << endl;
    #endif
    return 0.0;
}
    
real CRazerBlade::price()
{
    basePrice = 3199.99;
    return basePrice;
}