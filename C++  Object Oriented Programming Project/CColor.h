//Filename: CColor.h
//Description: An abstract class to encapsulate the Color properties
//Author: Marcus Blea
//September 9th 2022

#include "electronicsGlobal.h"
#pragma once
#if !defined(_CCOLOR_H_)
#define _CCOLOR_H_

class CColor
{
public:

    CColor(void);
    ~CColor(void);

    inline void set(int red = 0, int green = 0, int blue = 0){r(red); g(green); b(blue);}
    inline void setR(int val) { r(val);}
    inline void setG(int val) { g(val);}
    inline void setB(int val) { b(val);}
    inline void r(int val) {if (val >= MIN_COLOR_VALUE && val <= MAX_COLOR_VALUE ) m_red  = val;}
    inline void g(int val) {if (val >= MIN_COLOR_VALUE && val <= MAX_COLOR_VALUE ) m_green = val;}
    inline void b(int val) {if (val >= MIN_COLOR_VALUE && val <= MAX_COLOR_VALUE ) m_blue = val;}



protected:

protected:
    int m_red;
    int m_green;
    int m_blue;
    

};

#endif