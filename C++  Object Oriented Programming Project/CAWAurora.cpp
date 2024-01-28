//Filename: CRectangle.h
//Description: See header file for structural information
//Author: Marcus Blea
//September 9th 2022

#include <iostream>
#include <cstdlib>
#include<time.h>
using namespace std;

#include "CAWAurora.h"


CAWAurora::CAWAurora(void)
{
    
    numInStock = rand() % 50 + 1;
    cout << "Alienware Aurora computers in stock: " << numInStock << endl;
}

CAWAurora::~CAWAurora(void)
{
    #ifdef _DEBUG
    cout << "Alienware Aurora Chosen!" << endl;
    cout << "Accepting a Payment"<< endl;
    #endif
}

real CAWAurora::size()
{
    m_height = 8.86;
    m_width = 20.08;
    m_length = 20.8;
    #ifdef _DEBUG
    cout << "Tower Size: " << "(" << m_width << "\", " << m_height << "\", " << m_length <<"\")" << endl;
    #endif
    return 0.0;
}
    
real CAWAurora::price()
{
    basePrice = 1249.99;
    return basePrice + (basePrice * tax);
}