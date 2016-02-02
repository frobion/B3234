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

#include <vector>

#include "Form.h"


//------------------------------------------------------------------- Constantes


//------------------------------------------------------------------------ Types

//------------------------------------------------------------------------------
// Rôle de la classe Ensemble
//
//------------------------------------------------------------------------------

class Ensemble : public Form
{
//----------------------------------------------------------------------- PUBLIC
public:

    enum Type {UNION, INTERSECTION};
//----------------------------------------------------------- Méthodes publiques
    virtual bool Hit(Point p);
    virtual string GetInformation();
    virtual Ensemble* Clone() const;

    static Ensemble* GetEnsemble(const string &name, vector<Form*> formList,
                                 Type type, string &errorMessage);

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
  Ensemble(const string &name, vector<Form*> formList, Type type);

protected:
//----------------------------------------------------------- Attributs protégés

private:
//------------------------------------------------------------- Attributs privés

  vector<Form*> formList;
  Type type;

//---------------------------------------------------------------- Classes amies

//-------------------------------------------------------------- Classes privées

//----------------------------------------------------------------- Types privés

};

//----------------------------------------------- Types dépendants de <Intersection>

#endif // ENSEMBLE_H
