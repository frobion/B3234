/*******************************************************************************
 Test.cpp  -  description
 -------------------
 début                : 08/12
 copyright            : (C) 2015 par frobion
 ******************************************************************************/

//------------------ Réalisation de la classe Test (fichier Test.cpp) --
//---------------------------------------------------------------------- INCLUDE
//-------------------------------------------------------------- Include système
using namespace std;

#include <iostream>

//------------------------------------------------------------ Include personnel
#include "Test.h"
#include "convexpolygone.h"

//------------------------------------------------------------------- Constantes

//---------------------------------------------------------- Variables de classe

//----------------------------------------------------------------- Types prives

//----------------------------------------------------------------------- PUBLIC
//-------------------------------------------------------------- Fonctions amies

//----------------------------------------------------------- Methodes publiques

bool Test::TestConvexPolygoneIsConstructionPossible()
{
    //Polygone avec trop peu de point
    Point * tabPoint = new Point[2];
    string messageErreur = "";
    bool constructionPossible = ConvexPolygone::IsConstructionPossible(tabPoint, 2, messageErreur);

    responseToUser(constructionPossible, messageErreur);
}

//------------------------------------------------------- Surcharge d'operateurs

//-------------------------------------------------- Constructeurs - destructeur

//------------------------------------------------------------------------ PRIVE

//----------------------------------------------------------- Methodes protegees

//------------------------------------------------------------- Methodes privees
void Test::responseToUser(bool response, const string &message)
{
    cout << (response ? "OK" : "ERR") << endl;

    if(message!="")
    {
        cout << "# " << message << endl;
    }
}
