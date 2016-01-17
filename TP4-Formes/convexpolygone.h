/*******************************************************************************
 ConvexPolygone.h  -  description
 -------------------
 début                : 08/12
 copyright            : (C) 2015 par frobion
 ******************************************************************************/

//------------------ Interface de la classe ConvexPolygone (fichier ConvexPolygone.h) ------
#if !defined ( CONVEX_POLYGONE_H )
#define CONVEX_POLYGONE_H

//--------------------------------------------------------- Interfaces utilisées
using namespace std;

#include "Form.h"

//------------------------------------------------------------------- Constantes

//------------------------------------------------------------------------ Types

//------------------------------------------------------------------------------
// Rôle de la classe ConvexPolygone
//
//------------------------------------------------------------------------------

class ConvexPolygone : public Form
{
//----------------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------------- Méthodes publiques
    virtual bool Hit(Point p);
    virtual string GetInformation();

    static bool IsConstructionPossible(const string &name, const Point * pointList,
                                       int pointNumber, string &errorMessage);

//------------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------------- Constructeurs - destructeur
  ConvexPolygone(const ConvexPolygone &ConvexPolygone);

  ConvexPolygone(const string &name, const Point *, int pointNumber);

  virtual ~ConvexPolygone();

//------------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------------- Methodes protégées

private:
//------------------------------------------------------------- Methodes privées

  static double getSinusThetaABAC(const Point &a, const Point &b, const Point &c);

protected:
//----------------------------------------------------------- Attributs protégés

private:
//------------------------------------------------------------- Attributs privés

//---------------------------------------------------------------- Classes amies

//-------------------------------------------------------------- Classes privées

//----------------------------------------------------------------- Types privés

};

//----------------------------------------------- Types dépendants de <ConvexPolygone>

#endif // CONVEX_POLYGONE_H
