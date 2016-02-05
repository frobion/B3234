/*******************************************************************************
 Draw.cpp  -  description
 -------------------
 début                : 08/12
 copyright            : (C) 2015 par frobion
 ******************************************************************************/

//------------------ Réalisation de la classe Draw (fichier Draw.cpp) --
//---------------------------------------------------------------------- INCLUDE
//-------------------------------------------------------------- Include système
using namespace std;

//------------------------------------------------------------ Include personnel
#include "Draw.h"

//------------------------------------------------------------------- Constantes

//---------------------------------------------------------- Variables de classe

//----------------------------------------------------------------- Types prives

//----------------------------------------------------------------------- PUBLIC
//-------------------------------------------------------------- Fonctions amies

//----------------------------------------------------------- Methodes publiques

bool Draw::AddForm(const string &name, Form* form, string &errorMessage)
{
    if(formMap.find(name) == formMap.end())
    {
        formMap[name] = form;
        return true;
    }
    errorMessage = "Nom deja existant";
    return false;
}

bool Draw::Delete(const vector<string> &nameList, string &errorMessage,
                  string &deletedFormInformation)
{
    // Verification que tous les noms existent bien dans la map
    for (uint i = 0; i < nameList.size(); i++)
    {
        if (formMap.find(nameList[i]) == formMap.end())
        {
            errorMessage = "Le nom " + nameList[i] + " n'existe pas";
            return false;
        }
    }
    for (uint i = 0; i < nameList.size(); i++)
    {
        map<string, Form*>::iterator itFormMap = formMap.find(nameList[i]);
        if (itFormMap != formMap.end()) // Il est possible que le nom ne soit pas trouve si il
                                        // apparaissait deux fois dans la liste de noms a supprimer
        {
            deletedFormInformation += itFormMap->second->GetInformation() + "\r\n";
            delete itFormMap->second;
            formMap.erase(itFormMap);
        }

    }
    return true;
}

void Draw::Enumerate(ostream &out)
{
    map<string, Form*>::iterator itFormMap;
    for (itFormMap = formMap.begin(); itFormMap != formMap.end(); itFormMap++)
    {
        out << (itFormMap->second)->GetInformation() << endl;
    }
}

void Draw::Clear()
{
    map<string, Form*>::iterator itFormMap;
    for (itFormMap = formMap.begin(); itFormMap != formMap.end(); itFormMap++)
    {
        delete itFormMap->second;
    }
    formMap.clear();
}

bool Draw::Hit(const string &name, int x, int y, string &errorMessage)
{
    Point hitPoint(x, y);
    map<string, Form*>::iterator itFormMap = formMap.find(name);
    if (itFormMap != formMap.end())
    {
        return (itFormMap->second)->Hit(hitPoint);
    }
    errorMessage = "Nom inexistant";
    return false;
}

bool Draw::Move(const string &name, int dX, int dY, string &errorMessage)
{
    map<string, Form*>::iterator itFormMap = formMap.find(name);
    if (itFormMap != formMap.end())
    {
        (itFormMap->second)->Move(dX, dY);
        return true;
    }
    errorMessage = "Nom inexistant";
    return false;
}

Form* Draw::GetForm(const string &name)
{
    map<string, Form*>::iterator itFormMap = formMap.find(name);
    if (itFormMap != formMap.end())
    {
        return itFormMap->second;
    }
    return nullptr;
}

//------------------------------------------------------- Surcharge d'operateurs

//-------------------------------------------------- Constructeurs - destructeur

Draw::Draw()
{

}

Draw::~Draw()
{

}

//------------------------------------------------------------------------ PRIVE

//----------------------------------------------------------- Methodes protegees

//------------------------------------------------------------- Methodes privees
