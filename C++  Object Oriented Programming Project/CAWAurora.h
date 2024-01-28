//Filename: CRectangle.h
//Description: An abstract class to encapsulate the Rectangle properties
//Author: Marcus Blea
//September 9th 2022

#include "CAlienware.h"

#pragma once
#if !defined(_CAWAURORA_H_)
#define _CAWAURORA_H_

class CAWAurora : public CAlienware
{
public:
    CAWAurora(void);
    ~CAWAurora(void);
public:

    real size();
    
    real price();

protected:
    int numInStock;
    real m_width;
    real m_height;
    real m_length;
    real basePrice;

};

#endif