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
//
//------------------------------------------------------------------------------

class Segment : public Form
{
//----------------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------------- Méthodes publiques
    virtual bool Hit(Point p);
    virtual string GetInformation();
    virtual Segment* Clone();

    static Segment* GetSegment(const string &name, const Point &extremity1,
                               const Point &extremity2, string &errorMessage);

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
Point extremity1;
Point extremity2;
//---------------------------------------------------------------- Classes amies

//-------------------------------------------------------------- Classes privées

//----------------------------------------------------------------- Types privés

};

//----------------------------------------------- Types dépendants de <Segment>

#endif // SEGMENT_H
