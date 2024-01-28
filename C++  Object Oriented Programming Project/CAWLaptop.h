//Filename: CRectangle.h
//Description: An abstract class to encapsulate the Rectangle properties
//Author: Marcus Blea
//September 9th 2022

#include "CAlienware.h"

#pragma once
#if !defined(_CAWLAPTOP_H_)
#define _CAWLAPTOP_H_

class CAWLaptop : public CAlienware
{
public:
    CAWLaptop(void);
    ~CAWLaptop(void);
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