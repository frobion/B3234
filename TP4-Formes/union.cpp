/*******************************************************************************
 Union.cpp  -  description
 -------------------
 début                : 08/12
 copyright            : (C) 2015 par frobion
 ******************************************************************************/

//------------------ Réalisation de la classe Union (fichier Union.cpp) --
//---------------------------------------------------------------------- INCLUDE
//-------------------------------------------------------------- Include système
using namespace std;

//------------------------------------------------------------ Include personnel
#include "Union.h"
#include "intersection.h"

//------------------------------------------------------------------- Constantes

//---------------------------------------------------------- Variables de classe

//----------------------------------------------------------------- Types prives

//----------------------------------------------------------------------- PUBLIC
//-------------------------------------------------------------- Fonctions amies

//----------------------------------------------------------- Methodes publiques

bool Union::Hit(Point p)
{
    return false;
}

string Union::GetInformation()
{
    string rtn = "";
    for (int i = 0; i < formListLength; i++)
    {
        rtn += formList[i]->GetInformation() + "\r\n";
    }
    return rtn;
}

//------------------------------------------------------- Surcharge d'operateurs

//-------------------------------------------------- Constructeurs - destructeur


Union::Union(const string &name, Form * * formList, int formListLength) : Form(name), formListLength(formListLength)
{

    this->formList [formListLength];
    for (int i = 0; i < formListLength; i++)
    {
        this->formList[i] = formList[i]; // Appel au constructeur de copie de
                                         // chacune des formes
    }

}


Union::~Union()
{
    delete [] formList;
}

//------------------------------------------------------------------------ PRIVE

//----------------------------------------------------------- Methodes protegees

//------------------------------------------------------------- Methodes privees
