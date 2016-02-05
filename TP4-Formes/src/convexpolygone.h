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

#include <vector>

#include "Form.h"
#include "point.h"

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
    virtual ConvexPolygone* Clone() const;

    static ConvexPolygone* GetConvexPolygone(const string &name, const vector<Point> &pointList,
                                             string &errorMessage);

//------------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------------- Constructeurs - destructeur
  // Constructeur par defaut et par copie declares mais non definis
  ConvexPolygone(const ConvexPolygone &ConvexPolygone);
  ConvexPolygone();

  virtual ~ConvexPolygone();

//------------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------------- Methodes protégées


private:
//------------------------------------------------------------- Methodes privées
  static void affichePoint(const vector<Point> &pointList);

  static double getSigneSinusABAC(const Point &a, const Point &b, const Point &c);

//------------------------------------------------------------------Constructeur
  ConvexPolygone(const string &name, const vector<Point> &pointList);

protected:
//----------------------------------------------------------- Attributs protégés

private:
//------------------------------------------------------------- Attributs privés
  vector<Point> pointList;

//---------------------------------------------------------------- Classes amies

//-------------------------------------------------------------- Classes privées

//----------------------------------------------------------------- Types privés

};

//----------------------------------------------- Types dépendants de <ConvexPolygone>

#endif // CONVEX_POLYGONE_H
