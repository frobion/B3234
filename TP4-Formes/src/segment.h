/*******************************************************************************
 Segment.h  -  description
 -------------------
 début                : 08/12
 copyright            : (C) 2015 par frobion
 ******************************************************************************/

//------------------ Interface de la classe Segment (fichier Segment.h) ------
#if !defined ( SEGMENT_H )
#define SEGMENT_H

//--------------------------------------------------------- Interfaces utilisées
using namespace std;

#include "Form.h"

//------------------------------------------------------------------- Constantes

//------------------------------------------------------------------------ Types

//------------------------------------------------------------------------------
// Rôle de la classe Segment
// La classe Segment represente un segment. Il est possible d'effectuer un test
// d'appartenance, un deplacement, un export vers une chaine de caracteres, ou
// une copie qui modifie legerement le nom.
//------------------------------------------------------------------------------

class Segment : public Form
{
//----------------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------------- Méthodes publiques
    virtual bool Hit(Point p);
    // Voir Form::Hit

    virtual string GetInformation();
    // Renvoie les information du segment sous la forme d'une chaine de
    // caracteres de la forme : "S <name> <x1> <y1> <x2> <y2>", avec name
    // le nom du segment, (x1, y1) les coordonnees d'une extremite du segment,
    // et (x2, y2) les coordonnees de l'autre extremite.

    virtual Segment* Clone() const;
    // Renvoie un pointeur sur un segment. Le nouveau segment est identique
    // au segment de base, sauf son nom qui est : "_<name>", avec <name> le nom
    // du segment de base.

    static Segment* GetSegment(const string &name, const Point &extremity1,
                               const Point &extremity2, string &errorMessage);
    // Verifie si les parametres sont valides pour construire un segment. Un
    // segment peut etre construit ssi les deux points passes en parametres sont
    // different. Si le segment est constuctible, renvoie un pointeur vers un
    // nouveau segment. Sinon, renvoie le pointeur null, et errorMessge prend
    // la valeur "Points identiques".

//------------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------------- Constructeurs - destructeur
  // Constructeur par defaut et par copie declares mais non definis
  Segment(const Segment &Segment);
  Segment();

  virtual ~Segment();

//------------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------------- Methodes protégées


private:
//------------------------------------------------------------- Methodes privées

// Constructeur

  Segment(const string &name,const Point &extremity1, const Point &extremity2);

protected:
//----------------------------------------------------------- Attributs protégés

private:
//------------------------------------------------------------- Attributs privés
Point extremity1; // Une des deux extremite du segment.
Point extremity2; // L'autre extremite du segment.
//---------------------------------------------------------------- Classes amies

//-------------------------------------------------------------- Classes privées

//----------------------------------------------------------------- Types privés

};

//----------------------------------------------- Types dépendants de <Segment>

#endif // SEGMENT_H
