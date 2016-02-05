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
// La classe Rectangle represente un rectangle. Il est possible d'effectuer un
// test d'appartenance, un deplacement, un export vers une chaine de caracteres,
// ou une copie qui modifie legerement le nom.
//------------------------------------------------------------------------------

class Rectangle : public Form
{
//----------------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------------- Méthodes publiques
    virtual bool Hit(Point p);
    // voir Form::Hit

    virtual string GetInformation();
    // Renvoie les information du rectangle sous la forme d'une chaine de
    // caracteres de la forme : "R <name> <x1> <y1> <x2> <y2>", avec name
    // le nom du rectangle, (x1, y1) les coordonnees de son point en haut
    // a gauche, et (x2, y2) les coordonnees de son point en bas a droite.

    virtual Rectangle* Clone() const;
    // Renvoie un pointeur sur un rectangle. Le nouveau rectangle est identique
    // au rectangle de base, sauf son nom qui est : "_<name>", avec <name> le nom
    // du rectangle de base.

    static Rectangle* GetRectangle(const string &name, const Point &topLeft,
                                   const Point &bottomRight, string &errorMessage);
    // Verifie si les parametres sont valides pour construire un rectangle. Un
    // rectangle peut etre construit ssi le point topLeft est strictement situe
    // dans le cadran en haut a gauche du point bottomRight. Si le rectangle est
    // constuctible, renvoie un pointeur vers un nouveau rectangle. Sinon, renvoie
    // le pointeur null, et errorMessge prend la valeur "Mauvais cadran".

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
Point topLeft; // Le point en haut a gauche du rectangle.
Point bottomRight; // Le point en bas a droite du rectangle.
//---------------------------------------------------------------- Classes amies

//-------------------------------------------------------------- Classes privées

//----------------------------------------------------------------- Types privés

};

//----------------------------------------------- Types dépendants de <Rectangle>

#endif // RECTANGLE_H
