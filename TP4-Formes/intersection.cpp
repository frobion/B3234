/*******************************************************************************
 Intersection.cpp  -  description
 -------------------
 début                : 08/12
 copyright            : (C) 2015 par frobion
 ******************************************************************************/

//------------------ Réalisation de la classe Intersection (fichier Intersection.cpp) --
//---------------------------------------------------------------------- INCLUDE
//-------------------------------------------------------------- Include système
using namespace std;

//------------------------------------------------------------ Include personnel
#include "Intersection.h"

//------------------------------------------------------------------- Constantes

//---------------------------------------------------------- Variables de classe

//----------------------------------------------------------------- Types prives

//----------------------------------------------------------------------- PUBLIC
//-------------------------------------------------------------- Fonctions amies

//----------------------------------------------------------- Methodes publiques

bool Intersection::Hit(Point p)
{
    p -= offset;
    return false;
}

string Intersection::GetInformation()
{
    return "";
}

//------------------------------------------------------- Surcharge d'operateurs

//-------------------------------------------------- Constructeurs - destructeur

Intersection::~Intersection()
{
    for (int i = 0; i < formListLength; i++)
    {
        delete formList[i];
    }
    delete [] formList;
}

//------------------------------------------------------------------------ PRIVE

//----------------------------------------------------------- Methodes protegees

//------------------------------------------------------------- Methodes privees

//------------------------------------------------------------------Constructeur

Intersection::Intersection(const string &name, const Form **formList, int formNumber) :
    Form(name), formListLength(formNumber)
{
    this->formList = new Form* [formListLength];
    for (int i = 0; i < formListLength; i++)
    {
        this->formList[i] = formList[i]->Clone();
    }
}
