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

#include "draw.h"
#include "ensemble.h"
#include <string>

using namespace std;

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
  // Constructeur de copie declare mais non defini
  CommandLineInterface(const CommandLineInterface &CommandLineInterface);

  CommandLineInterface();

  virtual ~CommandLineInterface();

//------------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------------- Methodes protégées

private:
//------------------------------------------------------------- Methodes privées
void createSegment(bool display, istream &in);
void createRectangle(bool display, istream &in);
void createConvexPolygone(bool display, istream &in);
void createEnsemble(Ensemble::Type type, bool display, istream &in);
void hit();
void deleteForm(bool display, istream &in);
void move();
void listForm();
void undo();
void redo();
void load();
void save();
void clear();

void responseToUser(bool response, string errorMessage = "");

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
