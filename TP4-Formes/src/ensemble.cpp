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
#include "config.h"

//------------------------------------------------------------------- Constantes

//---------------------------------------------------------- Variables de classe

//----------------------------------------------------------------- Types prives

//----------------------------------------------------------------------- PUBLIC
//-------------------------------------------------------------- Fonctions amies

//----------------------------------------------------------- Methodes publiques

bool Ensemble::Hit(Point p)
{
    p -= offset;
    for (uint i = 0; i < formList.size(); i++)
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
    string rtn = "";
    string nameList = "";

    for (uint i = 0; i < formList.size(); i++)
    {
        formList[i]->Move(offset);
        rtn += formList[i]->GetInformation() + "\r\n";
        nameList += " " + formList[i]->GetName();
    }
    offset.Reset();

    rtn += ((type == Type::UNION) ? "OR " : "OI ") + name + nameList + "\r\n";
    rtn += "DELETE" + nameList;

    return rtn;
}

Ensemble* Ensemble::Clone() const
{
    return new Ensemble("_" + name, formList, type);
}

Ensemble* Ensemble::GetEnsemble(const string &name, vector<Form*> formList, Type type, string &errorMessage)
{
    if (formList.size() == 0)
    {
        errorMessage = "Pas de forme pour faire un ensemble";
        return nullptr;
    }
    return new Ensemble(name, formList, type);
}

//------------------------------------------------------- Surcharge d'operateurs

//-------------------------------------------------- Constructeurs - destructeur

Ensemble::~Ensemble()
{
    for (uint i = 0; i < formList.size(); i++)
    {
        delete formList[i];
    }
}

//------------------------------------------------------------------------ PRIVE

//----------------------------------------------------------- Methodes protegees

//------------------------------------------------------------- Methodes privees

//------------------------------------------------------------------Constructeur

Ensemble::Ensemble(const string &name, vector<Form*> formList, Type type) :
    Form(name), type(type)
{
    for (uint i = 0; i < formList.size(); i++)
    {
        this->formList.push_back(formList[i]->Clone());
    }
}
