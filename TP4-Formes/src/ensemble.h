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
// La classe Ensemble represente un ensemble, qui peut etre une union ou une
// intersection. Il est possible d'effectuer un test d'appartenance, un
// deplacement, un export vers une chaine de caracteres, ou une copie qui
// modifie legerement le nom.
//------------------------------------------------------------------------------

class Ensemble : public Form
{
//----------------------------------------------------------------------- PUBLIC
public:

    enum Type {UNION, INTERSECTION};
//----------------------------------------------------------- Méthodes publiques
    virtual bool Hit(Point p);
    // Voir Form::Hit

    virtual string GetInformation();
    // Renvoie les information de la forme sous la forme d'une chaine de caracteres
    // La chaine est compose de trois parties:
    // La premiere partie est constitue des instructions permettant de construire
    // les formes constituant l'ensemble.
    // La deuxieme partie est la construction de l'ensemble en utilisant les formes
    // construites precedemment.
    // Finalement, la derniere partie est la destruction des formes intermediaires
    // utilisees.

    virtual Ensemble* Clone() const;
    // Renvoie un pointeur sur un ensemble. Le nouvel ensemble est identique
    // a l'ensemble de base, sauf son nom qui est : "_<name>", avec <name> le nom
    // de l'ensemble de base.

    static Ensemble* GetEnsemble(const string &name, vector<Form*> formList,
                                 Type type, string &errorMessage);
    // Permet de verifier si un ensemble est constructible. L'ensemble est
    // constructible si il y a au moins une forme dans formList. Si
    // l'ensemble peut etre construit, renvoie un pointeur vers l'ensemble
    // construit, et renvoie un pointeur null sinon.

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

  vector<Form*> formList; // La liste des formes constituant l'ensemble
  Type type; // Le type de l'ensemble (Union ou Intersection).

//---------------------------------------------------------------- Classes amies

//-------------------------------------------------------------- Classes privées

//----------------------------------------------------------------- Types privés

};

//----------------------------------------------- Types dépendants de <Intersection>

#endif // ENSEMBLE_H
