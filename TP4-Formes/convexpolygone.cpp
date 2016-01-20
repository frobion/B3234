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
#include "config.h"

//------------------------------------------------------------------- Constantes

//---------------------------------------------------------- Variables de classe

//----------------------------------------------------------------- Types prives

//----------------------------------------------------------------------- PUBLIC
//-------------------------------------------------------------- Fonctions amies

//----------------------------------------------------------- Methodes publiques

bool ConvexPolygone::Hit(Point p)
// Un point est dans un polygone convexe ssi il est toujours a gauche
// (respectivement a droite) des segments orientes du polygone
// Le point considere est toujours le point C, le premier point du
// segment le point A, et le deuxieme point du segment le point B
// dans le calcul sin(AB, AC)
{
    p -= offset;

    double currentSinusABAC = getSinusABAC(pointList[pointList.size() - 1], pointList[0], p);
    bool isSinusABACPositif = currentSinusABAC > 0;

    for (uint i = 0; i < pointList.size() - 1; i++)
    {
        currentSinusABAC = getSinusABAC(pointList[i], pointList[i + 1], p);
        if((currentSinusABAC > 0 && !isSinusABACPositif) || (currentSinusABAC < 0 && isSinusABACPositif) || currentSinusABAC == 0)
        {
            return false;
        }
    }
    return true;
}

string ConvexPolygone::GetInformation()
{
    string rtn = "PC " + name;

    for (uint i = 0; i < pointList.size(); i++)
    {
        pointList[i] += offset;
        rtn += " " + to_string(pointList[i].GetX()) + " " + to_string(pointList[i].GetY());
    }
    offset.Reset();

    return rtn;
}

ConvexPolygone* ConvexPolygone::Clone()
{
    return new ConvexPolygone("-" + name, pointList);
}

ConvexPolygone* ConvexPolygone::GetConvexPolygone(const string &name, const vector<Point> &pointList, string &errorMessage)
// Un polygone est convexe ssi pour tout triplet de sommets consecutif B, A, C,
// sin(AB, AC) est de signe constant
{
    if (pointList.size() < 3)
    {
        errorMessage = "Nombre de points insuffisants";
        return nullptr;
    }


    bool sinusThetaIsPositif;
    double currentSinusABAC= getSinusABAC(pointList[0], pointList[pointList.size() - 1], pointList[1]);
    if (currentSinusABAC == 0)
    {
        errorMessage = "Points alignes";
        return nullptr;
    }
    sinusThetaIsPositif = (currentSinusABAC > 0);


    for (uint i = 1; i < pointList.size(); i++)
    {
        currentSinusABAC = getSinusABAC(pointList[i], pointList[i - 1], pointList[(i + 1) % pointList.size()]);
        if (currentSinusABAC == 0)
        {
            errorMessage = "Points alignes";
            return nullptr;
        }
        else if ((currentSinusABAC < 0 && !sinusThetaIsPositif) || (currentSinusABAC > 0 && sinusThetaIsPositif))
        {
            errorMessage = "Polygone non convexe";
            return nullptr;
        }
    }

    return new ConvexPolygone(name, pointList);

}


//------------------------------------------------------- Surcharge d'operateurs

//-------------------------------------------------- Constructeurs - destructeur

ConvexPolygone::~ConvexPolygone()
{

}

//------------------------------------------------------------------------ PRIVE

//----------------------------------------------------------- Methodes protegees

//------------------------------------------------------------- Methodes privees

double ConvexPolygone::getSinusABAC(const Point &a, const Point &b, const Point &c)
{
    if (!a.IsDifferent(b))
    {
        return 0; // Deux point identiques et un troisieme point sont considérées alignés
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

//------------------------------------------------------------------Constructeur
ConvexPolygone::ConvexPolygone(const string &name, const vector<Point> &pointList) : Form(name)
{
    for (uint i = 0; i < pointList.size(); i++)
    {
        this->pointList[i] = pointList[i];
    }
}






