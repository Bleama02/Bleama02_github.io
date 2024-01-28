//Filename: CRectangle.h
//Description: An abstract class to encapsulate the Rectangle properties
//Author: Marcus Blea
//September 9th 2022

#include "CLenovo.h"

#pragma once
#if !defined(_CLEGION_H_)
#define _CLEGION_H_

class CLegion : public CLenovo
{
public:
    CLegion(void);
    ~CLegion(void);
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