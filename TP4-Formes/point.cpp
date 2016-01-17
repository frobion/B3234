/*******************************************************************************
 Point.cpp  -  description
 -------------------
 début                : 08/12
 copyright            : (C) 2015 par frobion
 ******************************************************************************/

//------------------ Réalisation de la classe Point (fichier Point.cpp) --
//---------------------------------------------------------------------- INCLUDE
//-------------------------------------------------------------- Include système
using namespace std;

//------------------------------------------------------------ Include personnel
#include "Point.h"

//------------------------------------------------------------------- Constantes

//---------------------------------------------------------- Variables de classe

//----------------------------------------------------------------- Types prives

//----------------------------------------------------------------------- PUBLIC
//-------------------------------------------------------------- Fonctions amies

//----------------------------------------------------------- Methodes publiques

int Point::GetX() const
{
    return x;
}

int Point::GetY() const
{
    return y;
}

void Point::Move(int dx, int dy)
{
    x += dx;
    y += dy;
}

//------------------------------------------------------- Surcharge d'operateurs

//-------------------------------------------------- Constructeurs - destructeur

Point::Point(int x, int y): x(x), y(y)
{

}

Point::Point(const Point &point)
{
    this->x = point.GetX();
    this->y = point.GetY();
}

Point::~Point()
{

}

//------------------------------------------------------------------------ PRIVE

//----------------------------------------------------------- Methodes protegees

//------------------------------------------------------------- Methodes privees
