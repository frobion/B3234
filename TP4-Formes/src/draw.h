/*******************************************************************************
 Draw.h  -  description
 -------------------
 début                : 08/12
 copyright            : (C) 2015 par frobion
 ******************************************************************************/

//------------------ Interface de la classe Draw (fichier Draw.h) ------
#if !defined ( DRAW_H )
#define DRAW_H

//--------------------------------------------------------- Interfaces utilisées

using namespace std;

#include <string>
#include <vector>
#include <iostream>
#include <map>

#include "form.h"
#include "config.h"


//------------------------------------------------------------------- Constantes

//------------------------------------------------------------------------ Types

//------------------------------------------------------------------------------
// Rôle de la classe Draw
//
//------------------------------------------------------------------------------

class Draw
{
//----------------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------------- Méthodes publiques
    bool AddForm(const string &name, Form * form, string &errorMessage);
    bool Delete(const vector<string> &nameList, string &errorMessage);
    void Enumerate(ostream &out);
    void Clear();
    bool Hit(const string &name, int x, int y, string &errorMessage);
    bool Move(const string &name, int dX, int dY, string &errorMessage);

//------------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------------- Constructeurs - destructeur
  Draw(const Draw &Draw);

  Draw();

  virtual ~Draw();

//------------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------------- Methodes protégées

private:
//------------------------------------------------------------- Methodes privées

protected:
//----------------------------------------------------------- Attributs protégés

private:
//------------------------------------------------------------- Attributs privés
  map<string, Form*> formMap;

//---------------------------------------------------------------- Classes amies

//-------------------------------------------------------------- Classes privées

//----------------------------------------------------------------- Types privés

};

//----------------------------------------------- Types dépendants de <Draw>

#endif // DRAW_H
