//Filename: CRectangle.h
//Description: An abstract class to encapsulate the Rectangle properties
//Author: Marcus Blea
//September 9th 2022

#include "CRazerBlade.h"

#pragma once
#if !defined(_CBLADE17_H_)
#define _CBLADE17_H_

class CBlade17 : public CRazerBlade
{
public:
    CBlade17();
    ~CBlade17(void);



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