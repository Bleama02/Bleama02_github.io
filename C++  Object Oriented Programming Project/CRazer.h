//Filename: CRazer.h
//Description: An abstract class to show razer brand 
//Author: Marcus Blea
//September 9th 2022

#include "CElectronic.h"

#pragma once
#if !defined(_CRAZER_H_)
#define _CRAZER_H_

class CRazer : public CElectronic
{
    protected:
    CRazer(void);
    ~CRazer(void);

    protected:

    real size();
    real price();

    private:
    int numOfComp;


};


#endif