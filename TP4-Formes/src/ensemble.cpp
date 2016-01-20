/*******************************************************************************
 Ensemble.cpp  -  description
 -------------------
 début                : 08/12
 copyright            : (C) 2015 par frobion
 ******************************************************************************/

//------------------ Réalisation de la classe Intersection (fichier Intersection.cpp) --
//---------------------------------------------------------------------- INCLUDE
//-------------------------------------------------------------- Include système
using namespace std;

//------------------------------------------------------------ Include personnel
#include "Ensemble.h"

//------------------------------------------------------------------- Constantes

//---------------------------------------------------------- Variables de classe

//----------------------------------------------------------------- Types prives

//----------------------------------------------------------------------- PUBLIC
//-------------------------------------------------------------- Fonctions amies

//----------------------------------------------------------- Methodes publiques

bool Ensemble::Hit(Point p)
{
    p -= offset;
    for (int i = 0; i < formListLength; i++)
    {
        if ((type == Type::UNION && formList[i]->Hit(p)) || (type == Type::INTERSECTION && !formList[i]->Hit(p)))
        {
            return type == Type::UNION;
        }
    }
    return type == Type::INTERSECTION;
}

string Ensemble::GetInformation()
{
    string rtn = (type == Type::UNION) ? "U\r\n" : "I\r\n";
    for (int i = 0; i < formListLength; i++)
    {
        rtn += "  " + formList[i]->GetInformation() + "\r\n";
    }
    return rtn;
}

Ensemble* Ensemble::Clone() const
{
    return new Ensemble(name, formList, formListLength, type);
}

Ensemble* Ensemble::GetEnsemble(const string &name, Form **formList, int formNumber, Type type, string &errorMessage)
{
    if (formNumber == 0)
    {
        errorMessage = "Pas de forme pour faire un ensemble";
        return nullptr;
    }
    return new Ensemble(name, formList, formNumber, type);
}

//------------------------------------------------------- Surcharge d'operateurs

//-------------------------------------------------- Constructeurs - destructeur

Ensemble::~Ensemble()
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

Ensemble::Ensemble(const string &name, Form **formList, const int &formNumber, const Type &type) :
    Form(name), formListLength(formNumber), type(type)
{
    this->formList = new Form* [formListLength];
    for (int i = 0; i < formListLength; i++)
    {
        this->formList[i] = formList[i]->Clone();
    }
}
