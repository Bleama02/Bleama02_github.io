//Filename: CLenovo.h
//Description: An abstract class to show razer brand 
//Author: Marcus Blea
//September 9th 2022

#include "CElectronic.h"

#pragma once
#if !defined(_CLENOVO_H_)
#define _CLENOVO_H_

class CLenovo : public CElectronic
{
    protected:
    CLenovo();
    ~CLenovo();

    protected:

    real size();
    real price();

    private:
    int numOfComp;


};


#endif