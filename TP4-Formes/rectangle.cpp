/*******************************************************************************
 Rectangle.cpp  -  description
 -------------------
 début                : 08/12
 copyright            : (C) 2015 par frobion
 ******************************************************************************/

//------------------ Réalisation de la classe Rectangle (fichier Rectangle.cpp) --
//---------------------------------------------------------------------- INCLUDE
//-------------------------------------------------------------- Include système
using namespace std;

//------------------------------------------------------------ Include personnel
#include "Rectangle.h"

//------------------------------------------------------------------- Constantes

//---------------------------------------------------------- Variables de classe

//----------------------------------------------------------------- Types prives

//----------------------------------------------------------------------- PUBLIC
//-------------------------------------------------------------- Fonctions amies

//----------------------------------------------------------- Methodes publiques

bool Rectangle::Hit(Point p)
{
    return (p.GetX()>= topLeft.GetX() && p.GetY() <= topLeft.GetY() && p.GetX() <= bottomRight.GetX() && p.GetY() >= bottomRight.GetY());
}

string Rectangle::GetInformation()
{
    return ("R " + name + " " + to_string(topLeft.GetX()) + " " + to_string(topLeft.GetY()) +
            " " + to_string(bottomRight.GetX()) + " " + to_string(bottomRight.GetY()));
}

bool Rectangle::IsConstructionPossible(const Point &topLeft, const Point &bottomRight, string &errorMessage)
{
    if (topLeft.GetX() <= bottomRight.GetX() || topLeft.GetY() <= bottomRight.GetY())
    {
        errorMessage = "Mauvais cadran";
        return false;
    }
    return true;
}

//------------------------------------------------------- Surcharge d'operateurs

//-------------------------------------------------- Constructeurs - destructeur

Rectangle::Rectangle(const string &name,const Point &topLeft, const Point &bottomRight ): Form(name), topLeft(topLeft), bottomRight(bottomRight)
{

}

Rectangle::~Rectangle()
{

}

//------------------------------------------------------------------------ PRIVE

//----------------------------------------------------------- Methodes protegees

//------------------------------------------------------------- Methodes privees
