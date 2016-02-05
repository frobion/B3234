/*******************************************************************************
 ConvexPolygone.h  -  description
 -------------------
 début                : 08/12
 copyright            : (C) 2015 par frobion
 ******************************************************************************/

//------------------ Interface de la classe ConvexPolygone (fichier ConvexPolygone.h) ------
#if !defined ( CONVEX_POLYGONE_H )
#define CONVEX_POLYGONE_H

//--------------------------------------------------------- Interfaces utilisées
using namespace std;

#include <vector>

#include "Form.h"
#include "point.h"

//------------------------------------------------------------------- Constantes

//------------------------------------------------------------------------ Types

//------------------------------------------------------------------------------
// Rôle de la classe ConvexPolygone
// La classe ConvexPolygone represente un polygone convexe. Il est possible
// d'effectuer un test d'appartenance, un deplacement, un export vers une
// chaine de caracteres, ou une copie qui modifie legerement le nom.
//------------------------------------------------------------------------------

class ConvexPolygone : public Form
{
//----------------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------------- Méthodes publiques
    virtual bool Hit(Point p);
    // Voir Form::Hit

    virtual string GetInformation();
    // Renvoie les information de la forme sous la forme d'une chaine de caracteres
    // Renvoie "PC <name> <x1> <y1> ... <xn> <yn>\r\n".

    virtual ConvexPolygone* Clone() const;
    // Renvoie un pointeur sur un polygone convexe. La nouvelle forme est identique
    // a la forme de base, sauf son nom qui est : "_<name>", avec <name> le nom
    // de la forme de base.

    static ConvexPolygone* GetConvexPolygone(const string &name, const vector<Point> &pointList,
                                             string &errorMessage);
    // Si le vector de point pointList represente un polygone convexe, cree un polygone
    // convexe de sommets les points representes par pointList. Sinon, renvoie un pointeur
    // nul. Un polygone ayant des points alignes est consideres non convexe

//------------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------------- Constructeurs - destructeur
  // Constructeur par defaut et par copie declares mais non definis
  ConvexPolygone(const ConvexPolygone &ConvexPolygone);
  ConvexPolygone();

  virtual ~ConvexPolygone();

//------------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------------- Methodes protégées


private:
//------------------------------------------------------------- Methodes privées
  static double getSigneSinusABAC(const Point &a, const Point &b, const Point &c);
  // Renvoie un nombre du meme signe que le sinus(AB, AC), avec AB le vecteur
  // des points de a vers b, et AC le vecteur des points de a vers c.

//------------------------------------------------------------------Constructeur
  ConvexPolygone(const string &name, const vector<Point> &pointList);

protected:
//----------------------------------------------------------- Attributs protégés

private:
//------------------------------------------------------------- Attributs privés
  vector<Point> pointList; // La liste des sommets du polygone

//---------------------------------------------------------------- Classes amies

//-------------------------------------------------------------- Classes privées

//----------------------------------------------------------------- Types privés

};

//----------------------------------------------- Types dépendants de <ConvexPolygone>

#endif // CONVEX_POLYGONE_H
