/*******************************************************************************
 Intersection.h  -  description
 -------------------
 début                : 08/12
 copyright            : (C) 2015 par frobion
 ******************************************************************************/

//------------------ Interface de la classe Intersection (fichier Intersection.h) ------
#if !defined ( INTERSECTION_H )
#define INTERSECTION_H

//--------------------------------------------------------- Interfaces utilisée
using namespace std;

#include "Form.h"

//------------------------------------------------------------------- Constantes

//------------------------------------------------------------------------ Types

//------------------------------------------------------------------------------
// Rôle de la classe Intersection
//
//------------------------------------------------------------------------------

class Intersection : public Form
{
//----------------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------------- Méthodes publiques
    virtual bool Hit(Point p);
    virtual string GetInformation();
    virtual Intersection* Clone();

    static Intersection* GetIntersection(const string &name, const Form** formList,
                                         int formNumber, string &errorMessage);

//------------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------------- Constructeurs - destructeur
  // Constructeur par defaut et par copie declares mais non definis
  Intersection(const Intersection &Intersection);
  Intersection();

  virtual ~Intersection();

//------------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------------- Methodes protégées

private:
//------------------------------------------------------------- Methodes privées

//------------------------------------------------------------------Constructeur
  Intersection(const string &name, const Form** formList, int formNumber);

protected:
//----------------------------------------------------------- Attributs protégés

private:
//------------------------------------------------------------- Attributs privés

  int formListLength;
  Form** formList;

//---------------------------------------------------------------- Classes amies

//-------------------------------------------------------------- Classes privées

//----------------------------------------------------------------- Types privés

};

//----------------------------------------------- Types dépendants de <Intersection>

#endif // INTERSECTION_H
