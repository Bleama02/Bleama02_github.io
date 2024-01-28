//Filename: CRectangle.h
//Description: See header file for structural information
//Author: Marcus Blea
//September 9th 2022

#include <iostream>
using namespace std;

#include "CLegion.h"


CLegion::CLegion(void)
{
    numVersion = 1;
    #ifdef _DEBUG
    cout << "Number of different Versions of Legions in stock: " << numVersion << endl;
    #endif
}

CLegion::~CLegion(void)
{
    #ifdef _DEBUG
    cout << "Accepting a Payment..."<< endl;
    #endif
}

real CLegion::size()
{
    m_height = 10.33;
    m_width = 14.13;
    #ifdef _DEBUG
    cout << "Screen size Options: " << "(" << m_width << "\", " << m_height << "\")" << endl;
    #endif
    return 0.0;
}
    
real CLegion::price()
{
    basePrice = 1749.99;
    return basePrice;
}