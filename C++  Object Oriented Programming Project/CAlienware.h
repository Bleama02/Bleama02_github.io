//Filename: CAlienware.h
//Description: An abstract class to show razer brand 
//Author: Marcus Blea
//September 9th 2022

#include "CElectronic.h"

#pragma once
#if !defined(_CALIENWARE_H_)
#define _CALIENWARE_H_

class CAlienware : public CElectronic
{
    protected:
    CAlienware();
    ~CAlienware();

public:

    real size();
    real price();

private:
    int numOfComp;


};


#endif