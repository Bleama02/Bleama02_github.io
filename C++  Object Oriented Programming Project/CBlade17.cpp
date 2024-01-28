//Filename: CRectangle.h
//Description: See header file for structural information
//Author: Marcus Blea
//September 9th 2022

#include <iostream>
#include <cstdlib>
#include<time.h>
using namespace std;

#include "CBlade17.h"


int rand(void);

CBlade17::CBlade17()
{
    numInStock = rand() % 50 + 1;
    #ifdef _DEBUG
    cout << "We have " << numInStock << " Razer Blade 17's in stock" << endl;
    #endif
}

CBlade17::~CBlade17(void)
{
    #ifdef _DEBUG
    cout << "Razer Blade 17 Chosen!"<< endl;
    #endif
}

real CBlade17::size()
{
    m_height = 8.46;
    m_width = 15.08;
    #ifdef _DEBUG
    cout << "Screen size is: " << "(" << m_width << "\", " << m_height << "\")" << endl;
    #endif
    return 0;
}
    
real CBlade17::price()
{
    basePrice = 3199.99;
    #ifdef _DEBUG
    cout << "Calculating Price..." << endl;
    #endif
    return basePrice + (basePrice * tax);
}