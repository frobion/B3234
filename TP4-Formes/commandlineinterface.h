/*******************************************************************************
 CommandLineInterface.h  -  description
 -------------------
 début                : 08/12
 copyright            : (C) 2015 par frobion
 ******************************************************************************/

//------------------ Interface de la classe CommandLineInterface (fichier CommandLineInterface.h) ------
#if !defined ( COMMAND_LINE_INTERFACE_H )
#define COMMAND_LINE_INTERFACE_H

//--------------------------------------------------------- Interfaces utilisées

using namespace std;

#include "draw.h"

//------------------------------------------------------------------- Constantes

//------------------------------------------------------------------------ Types

//------------------------------------------------------------------------------
// Rôle de la classe CommandLineInterface
//
//------------------------------------------------------------------------------

class CommandLineInterface
{
//----------------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------------- Méthodes publiques

int waitForCommand();

//------------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------------- Constructeurs - destructeur
  CommandLineInterface(const CommandLineInterface &CommandLineInterface);

  CommandLineInterface();

  virtual ~CommandLineInterface();

//------------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------------- Methodes protégées

private:
//------------------------------------------------------------- Methodes privées
bool createSegment();
bool createRectangle();
bool createConvexPolygone();
bool createReunion();
bool createIntersection();
bool hit();
bool deleteForm();
bool move();
bool listForm();
bool undo();
bool redo();
bool load();
bool save();
bool clear();

void responseToUser(bool, string="");

protected:
//----------------------------------------------------------- Attributs protégés

private:
//------------------------------------------------------------- Attributs privés

Draw draw;
//---------------------------------------------------------------- Classes amies

//-------------------------------------------------------------- Classes privées

//----------------------------------------------------------------- Types privés

};

//----------------------------------------------- Types dépendants de <CommandLineInterface>

#endif // COMMAND_LINE_INTERFACE_H
