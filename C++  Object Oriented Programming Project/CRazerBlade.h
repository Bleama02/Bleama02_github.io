//Filename: CRectangle.h
//Description: An abstract class to encapsulate the Rectangle properties
//Author: Marcus Blea
//September 9th 2022

#include "CRazer.h"

#pragma once
#if !defined(_CRAZERBLADE_H_)
#define _CRAZERBLADE_H_

class CRazerBlade : public CRazer
{
public:
    CRazerBlade(void);
    ~CRazerBlade(void);
public:

    real size();
    
    real price();

private:
    int numVersion;
    real m_width;
    real m_height;
    real basePrice;

};

#endif