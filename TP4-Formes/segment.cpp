/*******************************************************************************
 Segment.cpp  -  description
 -------------------
 début                : 08/12
 copyright            : (C) 2015 par frobion
 ******************************************************************************/

//------------------ Réalisation de la classe Segment (fichier Segment.cpp) --
//---------------------------------------------------------------------- INCLUDE
//-------------------------------------------------------------- Include système
using namespace std;

//------------------------------------------------------------ Include personnel
#include "Segment.h"

//------------------------------------------------------------------- Constantes

//---------------------------------------------------------- Variables de classe

//----------------------------------------------------------------- Types prives

//----------------------------------------------------------------------- PUBLIC
//-------------------------------------------------------------- Fonctions amies

//----------------------------------------------------------- Methodes publiques

bool Segment::Hit(Point p)
{
    double coefficientDirecteur;
    int extremity1X = extremity1.GetX();
    int extremity1Y = extremity1.GetY();
    int extremity2X = extremity2.GetX();
    int extremity2Y = extremity2.GetY();
    int DX;
    int DY;

    if(extremity1X != extremity2X)
    {
       coefficientDirecteur = (extremity2Y-extremity1Y)/(extremity2X-extremity1X);
       DX = p.GetX() - extremity1X;
       DY = p.GetY() - extremity1Y;

       if(DY==DX*coefficientDirecteur)
       {
           return true;
       }
       else
       {
           return false;
       }

    }
    else  // Cas où le segment est vertical, et donc coefficient directeur nul
    {
        if (p.GetX() == extremity1X)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    return false;
}

string Segment::GetInformation()
{
    return "";
}

//------------------------------------------------------- Surcharge d'operateurs

//-------------------------------------------------- Constructeurs - destructeur

Segment::Segment(const string &name,const Point &extremity1, const Point &extremity2):Form(name), extremity1(extremity1), extremity2(extremity2)
{

}

Segment::~Segment()
{

}

//------------------------------------------------------------------------ PRIVE

//----------------------------------------------------------- Methodes protegees

//------------------------------------------------------------- Methodes privees
