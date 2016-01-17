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


//------------------------------------------------------------------- Constantes

//------------------------------------------------------------------------ Types

//------------------------------------------------------------------------------
// Rôle de la classe Rectangle
//
//------------------------------------------------------------------------------

class Rectangle {
//----------------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------------- Méthodes publiques

//------------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------------- Constructeurs - destructeur
  Rectangle(const Rectangle &Rectangle);

  Rectangle();

  virtual ~Rectangle();

//------------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------------- Methodes protégées

private:
//------------------------------------------------------------- Methodes privées

protected:
//----------------------------------------------------------- Attributs protégés

private:
//------------------------------------------------------------- Attributs privés

//---------------------------------------------------------------- Classes amies

//-------------------------------------------------------------- Classes privées

//----------------------------------------------------------------- Types privés

};

//----------------------------------------------- Types dépendants de <Rectangle>

#endif // RECTANGLE_H
