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
// La classe Draw regroupe toutes les formes d'un modeles, et permet d'acceder
// a chacune d'entre elle. De plus, il est possible de supprimer ou d'ajouter
// des formes. Finalement, cette classe sait aussi donner toutes les informations
// necessaires sous formes de chaine de caracteres pour etre reconstruite.
//------------------------------------------------------------------------------

class Draw
{
//----------------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------------- Méthodes publiques
    bool AddForm(const string &name, Form * form, string &errorMessage);
    // Si le nom de la forme passe en parametre n'existe pas encore, ajoute la
    // forme a la map de forme et renvoie true. Sinon, met "Nom deja existant"
    // dans errorMessage, et renvoie faux.

    bool Delete(const vector<string> &nameList, string &errorMessage,
                string & deletedFormInformation);
    // Teste si tous les noms de nameList existe. Si oui, supprime les formes
    // correspondantes et renvoie true. Si le nom d'une forme apparait deux fois,
    // elle est ignores la deuxieme fois.  De plus, les informations des formes
    // supprimes sont stockes dans deletedFormInformation.
    // Si le nom d'au moins une forme n'est pas dans le modele, aucune forme n'est
    // supprime, erroMessage prend la valeur de "<formName> inexistant", et la
    // methode renvoie false.

    void Enumerate(ostream &out);
    // Pour chaque forme pris par ordre alphabetique de leur nom, affiche le descripteur
    // de la forme sur le flux out.

    void Clear();
    // Vide le modele courant en supprimant toutes les formes.

    bool Hit(const string &name, int x, int y, string &errorMessage);
    // Teste si le point de coordonnees (x, y) est dans la forme correspondante a
    // name, et renvoie true si oui, false sinon.
    // Si name ne represente aucune forme, renvoie false, et errorMessage prend la
    // valeur de "Nom inexistant".

    bool Move(const string &name, int dX, int dY, string &errorMessage);
    // Bouge la forme represente par nom de (dX, dY) et renvoie true.
    // Si la forme n'existe pas, renvoie false, et errorMessage prend la valeur
    // de "Nom inexistant".

    Form* GetForm(const string &name);
    // retourne un pointeur sur la forme represente par name. Si la forme n'existe
    // pas, retourne le pointeur null.

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
  map<string, Form*> formMap; // La liste des formes du modeles.

//---------------------------------------------------------------- Classes amies

//-------------------------------------------------------------- Classes privées

//----------------------------------------------------------------- Types privés

};

//----------------------------------------------- Types dépendants de <Draw>

#endif // DRAW_H
