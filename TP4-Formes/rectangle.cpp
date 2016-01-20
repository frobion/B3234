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
    p -= offset;
    return (p.GetX()> topLeft.GetX() && p.GetY() < topLeft.GetY() && p.GetX() < bottomRight.GetX() && p.GetY() > bottomRight.GetY());
}

string Rectangle::GetInformation()
{
//    topLeft.Move(offset);
//    bottomRight.Move(offset);
    topLeft += offset;
    bottomRight += offset;
    offset.Reset();

    return ("R " + name + " " + to_string(topLeft.GetX()) + " " + to_string(topLeft.GetY()) +
            " " + to_string(bottomRight.GetX()) + " " + to_string(bottomRight.GetY()));
}

Rectangle* Rectangle::Clone()
{
    return new Rectangle("_" + name, topLeft, bottomRight);
}

Rectangle* Rectangle::GetRectangle(const string &name, const Point &topLeft,
                                   const Point &bottomRight, string &errorMessage)
{
    if (topLeft.GetX() <= bottomRight.GetX() || topLeft.GetY() <= bottomRight.GetY())
    {
        errorMessage = "Mauvais cadran";
        return nullptr;
    }
    return new Rectangle(name, topLeft, bottomRight);
}

//------------------------------------------------------- Surcharge d'operateurs

//-------------------------------------------------- Constructeurs - destructeur

Rectangle::~Rectangle()
{

}

//------------------------------------------------------------------------ PRIVE

//----------------------------------------------------------- Methodes protegees

//------------------------------------------------------------- Methodes privees

//------------------------------------------------------------------Constructeur
Rectangle::Rectangle(const string &name,const Point &topLeft, const Point &bottomRight ) :
    Form(name), topLeft(topLeft), bottomRight(bottomRight)
{

}
