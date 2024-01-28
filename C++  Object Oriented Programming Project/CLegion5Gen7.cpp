//Filename: CRectangle.h
//Description: See header file for structural information
//Author: Marcus Blea
//September 9th 2022

#include <iostream>
#include <cstdlib>
#include<time.h>
using namespace std;

#include "CLegion5Gen7.h"


CLegion5Gen7::CLegion5Gen7(void)
{
    numInStock = rand() % 50 + 1;
    #ifdef _DEBUG
    cout << "Legion 5 Gen 7 computers in stock: " << numInStock << endl;
    #endif
}

CLegion5Gen7::~CLegion5Gen7(void)
{
    #ifdef _DEBUG
    cout << "Legion 5 Gen 7 Laptop Chosen!"<< endl;
    #endif
}

real CLegion5Gen7::size()
{
    m_height = 10.33;
    m_width = 14.13;
    #ifdef _DEBUG
    cout << "Screen size is: " << "(" << m_width << "\", " << m_height << "\")" << endl;
    #endif
    return 0.0;
}
    
real CLegion5Gen7::price()
{
    basePrice = 1749.99;
    return basePrice + (basePrice * tax);
}