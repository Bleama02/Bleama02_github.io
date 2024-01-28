//Filename: CShape.h
//Description: An abstract class to encapsulate the shape properties
//Author: Marcus Blea
//September 9th 2022

#include "CColor.h"

#pragma once
#if !defined(_CELECTRONIC_H_)
#define _CELECTRONIC_H_

class CElectronic
{
    protected:
        CElectronic(void);
        ~CElectronic(void);
    
    protected:
        virtual real size();
        virtual real price();
    
    private:
        CColor m_color;
    
};

#endif