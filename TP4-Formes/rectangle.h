/*******************************************************************************
 Rectangle.h  -  description
 -------------------
 début                : 08/12
 copyright            : (C) 2015 par frobion
 ******************************************************************************/

//------------------ Interface de la classe Rectangle (fichier Rectangle.h) ------
#if !defined ( RECTANGLE_H )
#define RECTANGLE_H

//--------------------------------------------------------- Interfaces utilisées
using namespace std;

#include "Form.h"

//------------------------------------------------------------------- Constantes

//------------------------------------------------------------------------ Types

//------------------------------------------------------------------------------
// Rôle de la classe Rectangle
//
//------------------------------------------------------------------------------

class Rectangle : public Form
{
//----------------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------------- Méthodes publiques
    virtual bool Hit(Point p);
    virtual string GetInformation();
    virtual Rectangle* Clone() const;

    static Rectangle* GetRectangle(const string &name, const Point &topLeft,
                                   const Point &bottomRight, string &errorMessage);

//------------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------------- Constructeurs - destructeur
  // Constructeur par defaut et par copie declares mais non definis
  Rectangle(const Rectangle &Rectangle);
  Rectangle();

  virtual ~Rectangle();

//------------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------------- Methodes protégées


private:
//------------------------------------------------------------- Methodes privées

//------------------------------------------------------------------Constructeur
  Rectangle(const string &name, const Point &topLeft, const Point &bottomRight);

protected:
//----------------------------------------------------------- Attributs protégés

private:
//------------------------------------------------------------- Attributs privés
Point topLeft;
Point bottomRight;
//---------------------------------------------------------------- Classes amies

//-------------------------------------------------------------- Classes privées

//----------------------------------------------------------------- Types privés

};

//----------------------------------------------- Types dépendants de <Rectangle>

#endif // RECTANGLE_H
