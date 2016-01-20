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

void Point::Reset()
{
    x = 0;
    y = 0;
}

bool Point::IsDifferent(const Point &p) const
{
    return (p.x != x || p.y != y);
}

//------------------------------------------------------- Surcharge d'operateurs

Point& Point::operator = (const Point &p)
{
    x = p.x;
    y = p.y;
    return *this;
}

Point& Point::operator += (const Point &p)
{
    x += p.x;
    y += p.y;
    return *this;
}

Point& Point::operator -= (const Point &p)
{
    x -= p.x;
    y -= p.y;
    return *this;
}

//-------------------------------------------------- Constructeurs - destructeur


Point::Point(int x, int y): x(x), y(y)
{

}

Point::Point(const Point &point)
{
    this->x = point.x;
    this->y = point.y;
}

Point::~Point()
{

}

//------------------------------------------------------------------------ PRIVE

//----------------------------------------------------------- Methodes protegees

//------------------------------------------------------------- Methodes privees
