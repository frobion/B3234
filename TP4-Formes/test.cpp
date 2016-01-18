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
#include "rectangle.h"
#include "segment.h"
#include "union.h"
#include "intersection.h"
#include "point.h"


//------------------------------------------------------------------- Constantes

//---------------------------------------------------------- Variables de classe

//----------------------------------------------------------------- Types prives

//----------------------------------------------------------------------- PUBLIC
//-------------------------------------------------------------- Fonctions amies

//----------------------------------------------------------- Methodes publiques

void Test::TestConvexPolygoneIsConstructionPossible()
{
    //Polygone avec trop peu de point
    Point * tabPoint = new Point[2];
    string messageErreur = "";
    bool constructionPossible = ConvexPolygone::IsConstructionPossible(tabPoint, 2, messageErreur);

    responseToUser(constructionPossible, messageErreur);
}

void Test::TestConstructeurUnion()
{
    const int TAILLE = 3;
    Form ** formList = new Form* [TAILLE];

    Point p1 (0, 1);
    Point p2 (1, 0);
    Point p3 (0, 0);
    Point p4 (2, 2);

    formList[0] = new Rectangle("r", p1, p2);
    formList[1] = new Segment("s1", p3, p4);
    formList[2] = new Segment("s2", p1, p3);

    Union u ("u", formList, TAILLE);
    for (int i = 0; i < TAILLE; i++)
    {
        cout << formList[i]->GetInformation() << endl;
    }
    cout << endl << u.GetInformation() << endl;

    cout << endl << "Deplacement de s1 de (1, 1)" << endl;
    formList[1]->Move(1, 1);


    for (int i = 0; i < TAILLE; i++)
    {
        cout << formList[i]->GetInformation() << endl;
    }
    cout << endl << u.GetInformation() << endl;
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
