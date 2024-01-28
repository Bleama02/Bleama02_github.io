//Filename: CColor.h
//Description: See header file for structural information
//Author: Marcus Bleant
//September 9th 2022

#include <iostream>
using namespace std;

#include "CColor.h"


CColor::CColor(void)
{
    m_red = 22;
    m_green = 0;
    m_blue = 42;
    #ifdef _DEBUG
    cout << "Color of Computer (" << m_red << ", " << m_green << ", " << m_blue << ")"<<  endl;
    #endif
}

CColor::~CColor(void)
{
    #ifdef _DEBUG
    cout << "Color of Computer sold" << endl;
    #endif
}