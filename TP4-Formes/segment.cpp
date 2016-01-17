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
    double gradient;
    int extremity1X = extremity1.GetX();
    int extremity1Y = extremity1.GetY();
    int extremity2X = extremity2.GetX();
    int extremity2Y = extremity2.GetY();
    double dX;
    double dY;

    if(extremity1X != extremity2X)
    {
       gradient = (extremity2Y - extremity1Y) / (extremity2X - extremity1X);
       dX = p.GetX() - extremity1X;
       dY = p.GetY() - extremity1Y;

       return (dY == dX * gradient);
    }
    else  // Cas où le segment est vertical, et donc coefficient directeur infini
    {
        return (p.GetX() == extremity1X);
    }
}

string Segment::GetInformation()
{
    string information = "S " + name + " " + extremity1.GetX() + " " + extremity1.GetY() + " " + extremity2.GetX() + " " + extremity2.GetY() ;
    return information;
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
