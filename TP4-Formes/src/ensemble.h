/*******************************************************************************
 Ensemble.h  -  description
 -------------------
 début                : 08/12
 copyright            : (C) 2015 par frobion
 ******************************************************************************/

//------------------ Interface de la classe Intersection (fichier Ensemble.h) ------
#if !defined ( ENSEMBLE_H )
#define ENSEMBLE_H

//--------------------------------------------------------- Interfaces utilisée
using namespace std;

#include "Form.h"

//------------------------------------------------------------------- Constantes


//------------------------------------------------------------------------ Types

enum Type {UNION, INTERSECTION};

//------------------------------------------------------------------------------
// Rôle de la classe Ensemble
//
//------------------------------------------------------------------------------

class Ensemble : public Form
{
//----------------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------------- Méthodes publiques
    virtual bool Hit(Point p);
    virtual string GetInformation();
    virtual Ensemble* Clone() const;

    static Ensemble* GetEnsemble(const string &name, Form** formList,
                                 int formNumber, Type type, string &errorMessage);

//------------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------------- Constructeurs - destructeur
  // Constructeur par defaut et par copie declares mais non definis
  Ensemble(const Ensemble &Ensemble);
  Ensemble();

  virtual ~Ensemble();

//------------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------------- Methodes protégées


private:
//------------------------------------------------------------- Methodes privées

//------------------------------------------------------------------Constructeur
  Ensemble(const string &name, Form** formList, const int &formNumber, const Type &type);

protected:
//----------------------------------------------------------- Attributs protégés

private:
//------------------------------------------------------------- Attributs privés

  int formListLength;
  Form** formList;
  Type type;

//---------------------------------------------------------------- Classes amies

//-------------------------------------------------------------- Classes privées

//----------------------------------------------------------------- Types privés

};

//----------------------------------------------- Types dépendants de <Intersection>

#endif // ENSEMBLE_H
