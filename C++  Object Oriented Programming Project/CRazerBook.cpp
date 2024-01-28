//Filename: CRectangle.h
//Description: See header file for structural information
//Author: Marcus Blea
//September 9th 2022

#include <iostream>
#include <cstdlib>
#include<time.h>
using namespace std;

#include "CRazerBook.h"


CRazerBook::CRazerBook(void)
{
    numInStock = rand() % 50 + 1;
    #ifdef _DEBUG
    cout << "Razer Books in stock: " << numInStock << endl;
    #endif
}

CRazerBook::~CRazerBook(void)
{
    #ifdef _DEBUG
    cout << "Razer Book Chosen" << endl;
    cout << "Accepting a payment..."<< endl;
    #endif
}

real CRazerBook::size()
{
    m_height = 6.570;
    m_width = 11.679;
    #ifdef _DEBUG
    cout << "Screen size is: " << "(" << m_width << "\", " << m_height << "\")" << endl;
    #endif
    return 0.0;
}
    
real CRazerBook::price()
{
    basePrice = 999.99;
    return basePrice + (basePrice * tax);
}