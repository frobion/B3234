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
//
//------------------------------------------------------------------------------

class Form
{
//----------------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------------- Méthodes publiques
    virtual bool Hit(Point p) = 0;
    void Move(int dX, int dY);
    void Move(const Point &p);
    virtual string GetInformation() = 0;
    virtual Form* Clone() const = 0;
    string GetName();

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
  Point offset;
  string name;

private:
//------------------------------------------------------------- Attributs privés

//---------------------------------------------------------------- Classes amies

//-------------------------------------------------------------- Classes privées

//----------------------------------------------------------------- Types privés

};

//----------------------------------------------- Types dépendants de <Form>

#endif // FORM_H
