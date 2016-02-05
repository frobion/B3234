/*******************************************************************************
 Point.h  -  description
 -------------------
 début                : 08/12
 copyright            : (C) 2015 par frobion
 ******************************************************************************/

//------------------ Interface de la classe Point (fichier Point.h) ------
#if !defined ( POINT_H )
#define POINT_H

//--------------------------------------------------------- Interfaces utilisées

using namespace std;


//------------------------------------------------------------------- Constantes

//------------------------------------------------------------------------ Types

//------------------------------------------------------------------------------
// Rôle de la classe Point
// La classe Point represente un point. Il est possible de faire bouger un point,
// ainsi que de le reinitialiser.
//------------------------------------------------------------------------------

class Point
{
//----------------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------------- Méthodes publiques
    int GetX() const ;
    // Renvoie la coordonnee x du point.

    int GetY() const ;
    // Renvoie la coordonnee y du point.

    void Move(int dx, int dy);
    // Deplace le point de (dX, dY).

    void Reset();
    // Reinitialise les coordonnees du point a (0, 0).

    bool IsDifferent(const Point & p) const;
    // Renvoie true si l'une des coordonnee du point est differente de celle
    // de p, false sinon.

//------------------------------------------------------- Surcharge d'opérateurs

    Point& operator= (const Point &p);
    Point& operator+= (const Point &p);
    Point& operator-= (const Point &p);

//-------------------------------------------------- Constructeurs - destructeur
  Point(const Point &Point);

  Point(int x = 0, int y = 0);

  virtual ~Point();

//------------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------------- Methodes protégées

private:
//------------------------------------------------------------- Methodes privées

protected:
//----------------------------------------------------------- Attributs protégés

private:
//------------------------------------------------------------- Attributs privés
  int x; // La coordonnee sur x du point
  int y; // La coordonnee sur y du point.

//---------------------------------------------------------------- Classes amies

//-------------------------------------------------------------- Classes privées

//----------------------------------------------------------------- Types privés

};

//----------------------------------------------- Types dépendants de <Point>

#endif // POINT_H
