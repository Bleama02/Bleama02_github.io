//Filename: CRectangle.h
//Description: An abstract class to encapsulate the Rectangle properties
//Author: Marcus Blea
//September 9th 2022

#include "CLegion.h"

#pragma once
#if !defined(_CLEGION5Gen7_H_)
#define _CLEGION5Gen7_H_

class CLegion5Gen7 : public CLegion
{
public:
    CLegion5Gen7(void);
    ~CLegion5Gen7(void);
public:

    real size();
    
    real price();

private:
    int numInStock;
    real m_width;
    real m_height;
    real basePrice;

};

#endif