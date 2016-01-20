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
    p -= offset;

    for (int i = 0; i < formListLength; i++)
    {
        if (formList[i]->Hit(p))
        {
            return true;
        }
    }
    return false;
}

string Union::GetInformation()
{
    string rtn = "U\r\n";
    for (int i = 0; i < formListLength; i++)
    {
        rtn += "  " + formList[i]->GetInformation() + "\r\n";
    }
    return rtn;
}

Union* Union::Clone()
{
    return new Union("_" + name, formList, formListLength);
}

Union* Union::GetUnion(const string &name, Form **formList, int formNumber, string &errorMessage)
{
    if (formNumber == 0)
    {
        errorMessage = "Pas de forme a unir";
        return nullptr;
    }
    return new Union(name, formList, formNumber);
}

//------------------------------------------------------- Surcharge d'operateurs

//-------------------------------------------------- Constructeurs - destructeur

Union::~Union()
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
Union::Union(const string &name, Form ** formList, int formNumber) : Form(name), formListLength(formNumber)
{
    this->formList = new Form* [formListLength];
    for (int i = 0; i < formListLength; i++)
    {
        this->formList[i] = formList[i]->Clone();
    }
}
