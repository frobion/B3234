/*******************************************************************************
 Union.h  -  description
 -------------------
 début                : 08/12
 copyright            : (C) 2015 par frobion
 ******************************************************************************/

//------------------ Interface de la classe Union (fichier Union.h) ------
#if !defined ( UNION_H )
#define UNION_H

//--------------------------------------------------------- Interfaces utilisées
using namespace std;

#include <vector>

#include "Form.h"
#include "Point.h"
#include "intersection.h"

//------------------------------------------------------------------- Constantes

//------------------------------------------------------------------------ Types

//------------------------------------------------------------------------------
// Rôle de la classe Union
//
//------------------------------------------------------------------------------

class Union : public Form
{
//----------------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------------- Méthodes publiques
    virtual bool Hit(Point p);
    virtual string GetInformation();

//------------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------------- Constructeurs - destructeur
  Union(const Union &Union);

  Union(const string &name, Form** formList, int formNumber);

  virtual ~Union();

//------------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------------- Methodes protégées

private:
//------------------------------------------------------------- Methodes privées

protected:
//----------------------------------------------------------- Attributs protégés

private:
//------------------------------------------------------------- Attributs privés
  Form** formList;
  int formListLength;

//---------------------------------------------------------------- Classes amies

//-------------------------------------------------------------- Classes privées

//----------------------------------------------------------------- Types privés

};

//----------------------------------------------- Types dépendants de <Union>

#endif // UNION_H
