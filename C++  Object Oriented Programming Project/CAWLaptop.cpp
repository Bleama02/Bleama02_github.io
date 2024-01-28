//Filename: CRectangle.h
//Description: See header file for structural information
//Author: Marcus Blea
//September 9th 2022

#include <iostream>
#include <cstdlib>
#include<time.h>
using namespace std;

#include "CAWLaptop.h"


CAWLaptop::CAWLaptop(void)
{
    
    numInStock = rand() % 50 + 1;
    #ifdef _DEBUG
    cout << "Alienware Laptop computers in stock: " << numInStock << endl;
    #endif
}

CAWLaptop::~CAWLaptop(void)
{
    #ifdef _DEBUG
    cout << "Alienware Laptop Chosen!" << endl;
    cout << "Accepting a Payment"<< endl;
    #endif
}

real CAWLaptop::size()
{
    m_height = 7;
    m_width = 8;
    #ifdef _DEBUG
    cout << "Screen size is: " << "(" << m_width << "\", " << m_height << "\")" << endl;
    #endif
    return 0.0;
}
    
real CAWLaptop::price()
{
    basePrice = 1499.99;
    return basePrice + (basePrice * tax);
}