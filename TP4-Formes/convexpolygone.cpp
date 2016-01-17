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

bool ConvexPolygone::IsConstructionPossible(const Point *pointList, int pointNumber, string &errorMessage)
// Un polygone est convexe ssi pour tout triplet de sommets consecutif B, A, C,
// sin(AB, AC) est de signe constant
{
    if (pointNumber < 3)
    {
        errorMessage = "Nombre de point insuffisant";
        return false;
    }


    bool sinusThetaIsPositif;
    double currentSinusTheta = getSinusThetaABAC(pointList[0], pointList[pointNumber - 1], pointList[1]);
    if (currentSinusTheta < 0)
    {
        sinusThetaIsPositif = false;
    }
    else if(currentSinusTheta > 0)
    {
        sinusThetaIsPositif = true;
    }
    else
    {
        errorMessage = "Point alignes";
        return false;
    }


    for (int i = 1; i < pointNumber; i++)
    {
        currentSinusTheta = getSinusThetaABAC(pointList[i], pointList[i - 1], pointList[(i + 1) % pointNumber]);
        if (currentSinusTheta == 0)
        {
            errorMessage = "Point alignes";
            return false;
        }
        else if (currentSinusTheta < 0 && !sinusThetaIsPositif || currentSinusTheta > 0 && sinusThetaIsPositif)
        {
            errorMessage = "Polygone non convexe";
            return false;
        }
    }

    return true;

}


//------------------------------------------------------- Surcharge d'operateurs

//-------------------------------------------------- Constructeurs - destructeur

ConvexPolygone::ConvexPolygone(const string &name, const Point *, int pointNumber) : Form(name)
{

}

ConvexPolygone::~ConvexPolygone()
{

}

//------------------------------------------------------------------------ PRIVE

//----------------------------------------------------------- Methodes protegees

//------------------------------------------------------------- Methodes privees

double ConvexPolygone::getSinusThetaABAC(const Point &a, const Point &b, const Point &c)
{
    if (!a.IsDifferent(b)) // division par 0 dans la suite
    {
        return 0;
    }

    double xA = a.GetX();
    double yA = a.GetY();
    double xB = b.GetX();
    double yB = b.GetY();
    double xC = c.GetX();
    double yC = c.GetY();

    double denominateur = (xB - xA)*(xB - xA) + (yB - yA)*(yB - yA);
    double partieImaginaire = ((yC - yA)*(xB - xA) + (yA - yB)*(xC - xA)) / denominateur;
    double partieReel = ((xC - xA)*(xB - xA) + (yC - yA)*(yB - yA)) / denominateur;

    return partieImaginaire / (sqrt(partieReel * partieReel + partieImaginaire * partieImaginaire));
}







