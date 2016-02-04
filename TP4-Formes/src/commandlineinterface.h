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
#include <list>
#include <sstream>

using namespace std;

//------------------------------------------------------------------- Constantes

//------------------------------------------------------------------------ Types
struct CommandUndoRedo
{
    stringstream *undo;
    stringstream *redo;
    stringstream *load;
    CommandUndoRedo(stringstream *undo, stringstream *redo, stringstream *load = nullptr)
    {
        this->undo = undo;
        this->redo = redo;
        this->load = load;
    }

    ~CommandUndoRedo()
    {
        delete undo;
        delete redo;
        delete load;
    }
};

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
void createSegment(bool display, istream &in, bool doReturnCommand);
void createRectangle(bool display, istream &in, bool doReturnCommand);
void createConvexPolygone(bool display, istream &in, bool doReturnCommand);
void createEnsemble(Ensemble::Type type, bool display, istream &in, bool doReturnCommand);
void hit();
void deleteForm(bool display, istream &in, bool doReturnCommand);
void move(bool display, istream &in, bool doReturnCommand);
void listForm();
void undo();
void redo();
void load(bool display, istream &in);
void load(istream &in, bool undo);
void save();
void clear(bool display, bool doReturnCommand);

void responseToUser(bool response, string errorMessage = "");
void addCommandInUndoList(CommandUndoRedo *command);
void clearRedoList();
void afficherStringstream(const stringstream &in);

protected:
//----------------------------------------------------------- Attributs protégés

private:
//------------------------------------------------------------- Attributs privés

Draw draw;
list<CommandUndoRedo*> undoList;
list<CommandUndoRedo*> redoList;
//---------------------------------------------------------------- Classes amies

//-------------------------------------------------------------- Classes privées

//----------------------------------------------------------------- Types privés


};
//----------------------------------------------- Types dépendants de <CommandLineInterface>

#endif // COMMAND_LINE_INTERFACE_H
