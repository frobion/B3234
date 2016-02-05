/*******************************************************************************
 Form.h  -  description
 -------------------
 début                : 08/12
 copyright            : (C) 2015 par frobion
 ******************************************************************************/

//------------------ Interface de la classe Form (fichier Form.h) ------
#if !defined ( FORM_H )
#define FORM_H

//--------------------------------------------------------- Interfaces utilisées
using namespace std;

#include <string>
#include "point.h"

//------------------------------------------------------------------- Constantes

//------------------------------------------------------------------------ Types

//------------------------------------------------------------------------------
// Rôle de la classe Form
// La classe Form est une classe abstraite, de laquelle herite les autres types
// de formes. Elle sert a definir les operations effectuables sur une forme,
// c'est a dire un deplacement, une operation d'appartenance, un clonage, ou
// une serialisation de la forme.
//------------------------------------------------------------------------------

class Form
{
//----------------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------------- Méthodes publiques
    virtual bool Hit(Point p) = 0;
    // Test si le point represente par p est dans la forme. Renvoie true si oui,
    // et false sinon. Un point situé sur le bord d'une forme est considere hors
    // de la forme. Un point sur  l'extremite d'un segment et considere hors du
    // segment. Un point est dans une union ssi il est dans au moins une forme de
    // l'union, et il est dans une intersection ssi il est dans toutes les formes
    // de l'intersection.

    void Move(int dX, int dY);
    // Deplace la forme de (dX, dY) sur l'axe des x, respectivement des y.

    void Move(const Point &p);
    // Deplace la forme de (dX, dY) sur l'axe des x, respectivement des y,
    // avec dX la coordonnees des x de p, et dY la coordonnees de y de p.

    virtual string GetInformation() = 0;
    // Renvoie une chaine de caracteres representant la forme.

    virtual Form* Clone() const = 0;
    // Renvoie un pointeur sur une forme, ayant les memes caracteristiques que
    // la forme de base, sauf le nom qui devient "_<nom>", avec <nom> le nom
    // de la forme de base.

    string GetName();
    // Renvoie le nom de la forme.

//------------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------------- Constructeurs - destructeur
  Form(const Form &Form); // Constructeur de copie

  Form(const string &name); // Constructeur

  virtual ~Form();

//------------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------------- Methodes protégées

private:
//------------------------------------------------------------- Methodes privées

protected:
//----------------------------------------------------------- Attributs protégés
  Point offset; // Un point permettant de savoir de combien la forme a bouge
                // depuis sa creation. Tous les points de la forme sont donnes
                // en relatif par rapport a celui-ci.
  string name;  // Le nom de la forme.

private:
//------------------------------------------------------------- Attributs privés

//---------------------------------------------------------------- Classes amies

//-------------------------------------------------------------- Classes privées

//----------------------------------------------------------------- Types privés

};

//----------------------------------------------- Types dépendants de <Form>

#endif // FORM_H
