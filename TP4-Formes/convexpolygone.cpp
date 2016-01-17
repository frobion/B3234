/*******************************************************************************
 ConvexPolygone.cpp  -  description
 -------------------
 début                : 08/12
 copyright            : (C) 2015 par frobion
 ******************************************************************************/

//------------------ Réalisation de la classe ConvexPolygone (fichier ConvexPolygone.cpp) --
//---------------------------------------------------------------------- INCLUDE
//-------------------------------------------------------------- Include système
using namespace std;

#include <math.h>

//------------------------------------------------------------ Include personnel
#include "ConvexPolygone.h"

//------------------------------------------------------------------- Constantes

//---------------------------------------------------------- Variables de classe

//----------------------------------------------------------------- Types prives

//----------------------------------------------------------------------- PUBLIC
//-------------------------------------------------------------- Fonctions amies

//----------------------------------------------------------- Methodes publiques

bool ConvexPolygone::Hit(Point p)
{
    return false;
}

string ConvexPolygone::GetInformation()
{
    return "";
}

bool ConvexPolygone::IsConstructionPossible(const string &name, const Point *pointList,
                                            int pointNumber, string &errorMessage)
// Un polygone est convexe ssi pour tout triplet de sommets consecutif B, A, C, le sinus
// sin(AB, AC) est de signe constant
{
    if (pointNumber < 3)
    {
        errorMessage = "Nombre de point insuffisant";
        return false;
    }


    if(pointList[0].IsDifferent(pointList[pointNumber - 1]))
    {

    }


    for (int i = 1; i < pointNumber - 1; i++)
    {
        if(pointList[i - 1].IsDifferent(pointList[i]))
        {
            if(getSinusThetaABAC(pointList[i], pointList[i - 1], pointList[i + 1]) < 0)
            {

            }
        }
    }

}


//------------------------------------------------------- Surcharge d'operateurs

//-------------------------------------------------- Constructeurs - destructeur

ConvexPolygone(const string &name, const Point *, int pointNumber)
{

}

ConvexPolygone::~ConvexPolygone()
{

}

//------------------------------------------------------------------------ PRIVE

//----------------------------------------------------------- Methodes protegees

//------------------------------------------------------------- Methodes privees

double ConvexPolygone::getSinusThetaABAC(const Point *a, const Point *b, const Point *c)
{
    double xA = a->GetX();
    double yA = a->GetY();
    double xB = b->GetX();
    double yB = b->GetY();
    double xC = c->GetX();
    double yC = c->GetY();

    double denominateur = (xB - xA)(xB - xA) + (yB - yA)(yB - yA);
    double partieImaginaire = ((yC - yA)(xB - xA) + (yA - yB)(xC - xA)) / denominateur;
    double partieReel = ((xC - xA)(xB - xA) + (yC - yA)(yB - yA)) / denominateur;

    return partieImaginaire / (sqrt(partieReel * partieReel + partieImaginaire * partieImaginaire));
}







