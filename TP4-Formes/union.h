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
    virtual Union* Clone();

    static Union* GetUnion(const string &name, Form** formList,
                           int formNumber, string &errorMessage);

//------------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------------- Constructeurs - destructeur
  // Constructeur par defaut et par copie declares mais non definis
  Union(const Union &Union);
  Union();

  virtual ~Union();

//------------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------------- Methodes protégées

private:
//------------------------------------------------------------- Methodes privées

//------------------------------------------------------------------Constructeur
  Union(const string &name, Form** formList, int formNumber);

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
