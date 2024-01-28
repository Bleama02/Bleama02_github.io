//Filename: CRectangle.h
//Description: An abstract class to encapsulate the Rectangle properties
//Author: Marcus Blea
//September 9th 2022

#include "CRazer.h"

#pragma once
#if !defined(_CRAZERBOOK_H_)
#define _CRAZERBOOK_H_

class CRazerBook : public CRazer
{
public:
    CRazerBook(void);
    ~CRazerBook(void);
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