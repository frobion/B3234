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
// Deux vecteur AB(a, b) et AC(c, d) sont colineaires ssi a*d - b*c == 0
// Ici, A sera le premier point du segment, B le deuxième, et C le ponit p
{
    p -= offset;

    int xAB = extremity2.GetX() - extremity1.GetX();
    int yAB = extremity2.GetY() - extremity1.GetY();
    int xAC = p.GetX() - extremity1.GetX();
    int yAC = p.GetY() - extremity1.GetY();

    if (xAB * yAC - yAB * xAC != 0) // Point non alignes
    {
        return false;
    }
    if (extremity1.GetX() != extremity2.GetX())
    {
        if (p.GetX() >= max(extremity1.GetX(), extremity2.GetX()) || p.GetX() <= min(extremity1.GetX(), extremity2.GetX()))
        {
            return false;
        }
    }
    else if(p.GetY() >= max(extremity1.GetY(), extremity2.GetY()) || p.GetY() <= min(extremity1.GetY(), extremity2.GetY()))
    {
        return false;
    }
    return true;
}

string Segment::GetInformation()
{
    extremity1 += offset;
    extremity2 += offset;
    offset.Reset();

    return ("S " + name + " " + to_string(extremity1.GetX()) + " " + to_string(extremity1.GetY()) + " "
            + to_string(extremity2.GetX()) + " " + to_string(extremity2.GetY()));
}

Segment* Segment::Clone()
{
    return new Segment("_" + name, extremity1, extremity2);
}

Segment* Segment::GetSegment(const string &name, const Point &extremity1,
                                         const Point &extremity2, string &errorMessage)
{
    if(!extremity1.IsDifferent(extremity2))
    {
        errorMessage = "Points identiques";
        return nullptr;
    }
    return new Segment(name, extremity1, extremity2);
}

//------------------------------------------------------- Surcharge d'operateurs

//-------------------------------------------------- Constructeurs - destructeur

Segment::~Segment()
{

}

//------------------------------------------------------------------------ PRIVE

//----------------------------------------------------------- Methodes protegees

//------------------------------------------------------------- Methodes privees

//------------------------------------------------------------------Constructeur
Segment::Segment(const string &name,const Point &extremity1, const Point &extremity2) :
    Form(name), extremity1(extremity1), extremity2(extremity2)
{

}
