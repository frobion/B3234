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
// La classe CommandLineInterface récupère les commandes utilisateurs et les
// analyse.
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
// Recupere les parametres de construction du segment sur le flux d'entrees in
// (le nom du segment, et 4 entiers, representant les coordonnees des points du segment),
// et le construit si possible. Si display est a true, affiche "OK" en cas de succès,
// et "ERR" sinon. Si doReturnCommand est a true, genere la commande inverse et
// l'ajoute a la liste des commandes a annule.

void createRectangle(bool display, istream &in, bool doReturnCommand);
// Recupere les parametres de construction du rectangle sur le flux d'entrees in
// (un nom et 4 entiers), et le construit si possible. Si display est a true,
// affiche "OK" en cas de succès, et "ERR" sinon.
// Si doReturnCommand est a true, genere la commande oppose, et l'ajoute a la
// liste des commandes a annulees.

void createConvexPolygone(bool display, istream &in, bool doReturnCommand);
// Recupere les parametres de construction du polygone convexe sur le flux d'entrees
// in(le nom du polygone, suivi d'une liste paire d'entier, chacun representant
// un des points du polygones dans l'ordre dans lequel ils sont donnes), et le
// construit si possible.
// Si display et est a true, affiche "OK" en cas de succès, et "ERR" sinon.
// Si doReturnCommand est a true, genere la commande oppose, et l'ajoute a la
// liste des commandes a annulees.

void createEnsemble(Ensemble::Type type, bool display, istream &in, bool doReturnCommand);
// Recupere les parametres de construction d'un ensemble sur le flux d'entrees in (le nom
// de l'ensemble, suivi d'une liste de nom representant les differentes formes de l'ensemble),
// et le construit si possible.
// Si display est a true, affiche "OK" en cas de succès, et "ERR" sinon.
// Si doReturnCommand est a true, genere la commande oppose et l'ajoute a la
// liste des commandes a annulees.

void hit();
// Recupere les parametres d'un test d'appartenantce (le nom de la forme sur laquelle l'appartenance
// est teste, suivi de deux entiers qui sont les coordonnees du point dont on test l'appartenance).
// Test l'appartenance du point à la forme, et affiche "YES" en cas de succès, et "NO" sinon.
// Un point situé sur le bord d'une forme est considere hors de la forme. Un point sur  l'extremite
// d'un segment et considere hors du segment. Un point est dans une union ssi il est dans au moins
// une forme de l'union, et il est dans une intersection ssi il est dans toutes les formes de
// l'intersection.

void deleteForm(bool display, istream &in, bool doReturnCommand);
// Recupere les parametres de suppression sur le flux d'entrees in(la liste des noms
// des formes a supprimer). Si tous les noms represente une forme presente dans le
// modele, les detruit. Si un meme nom apparait plusieurs fois, cela ne change pas
// le comportement. Si au moins un des noms de la liste n'est pas present dans le
// modele, la commande ne detruit aucune forme
// Si display est a true, affiche "OK" en cas de succes, et "ERR" sinon.
// Si doReturnCommand est a true, genere la commande oppose et l'ajoute a la
// liste des commandes a annulees.

void move(bool display, istream &in, bool doReturnCommand);
// Recupere les parametres pour effectuer le deplacement d'une forme sur le
// flux d'entrees in (le nom de la forme a deplace, et les deplacements a
// effectuer sur x et sur y), et deplace la forme si elle existe dans le
// modele
// Si display est a true, affiche "OK", et "ERR" sinon.
// Si doReturnCommand est a true, genere la commande oppose et l'ajoute a la
// liste des commandes a annulees.

void listForm();
// Pour chaque forme pris par ordre alphabetique de leur nom, affiche le descripteur
// de la forme en console.

void undo();
// Annule la derniere commande ayant modifie le modele (S, R, PC, OR, OI, MOVE, CLEAR,
// DELETE, LOAD), pour restituer l'etat precedant l'exeecution de cette commande.
// Ne peut pas annuler plus de 20 commandes consecutives. Affiche "OK" si une commande
// a ete annule, et "ERR" sinon.

void redo();
// Refait la derniere commande qui a ete annule. Si la derniere commande ayant
// modifie le modele n'est pas un UNDO, affiche "ERR" et ne fait rien, et annule
// la commande et affiche "OK" sinon.

void load(bool display, istream &in);
// Lis le chemin vers le fichier de sauvegarde sur le flux d'entrees in, et
// rajoute les formes decrites dans ce fichier dans le modele actuelle. Si
// le nom d'une forme decrites dans le fichier est le meme que le nom d'une
// des formes du modele, ignore cette forme et continue le chargement du fichier.
// Si display est a true, affiche "OK" en cas de succes, et "ERR" si le fichier
// n'a pas pu etre ouvert.

void load(istream &in, bool undo);
// Charge les formes depuis le flux d'entrees in, en executant les commandes
// presentent dans ce flux. undo est true lorsque cette methode est appelle
// pour annuler une commande.

void save();
// Lis le nom du fichier dans lequel il faut sauver le modele actuel sur
// l'entree standard. Si le fichier existe deja, son contenu est ecrase.
// Si le fichier n'existe pas encore, il est cree.

void clear(bool display, bool doReturnCommand);
// Efface toutes les formes du modele actuel.
// Si display est a true, affiche "OK"
// Si doReturnCommand est a true, genere la commande oppose et l'ajoute
// a la file des commandes a annulees.

void responseToUser(bool response, string errorMessage = "");
// Si response est a true, affiche "OK", et affiche "ERR" sinon.
// Si errorMessage est different de la chaine vide, affiche a la
// ligne d'en dessous "# <errorMessage>".

void addCommandInUndoList(CommandUndoRedo *command);
// Ajoute la commande represente par command dans la liste des commande
// a la liste des commandes a annules.

void clearRedoList();
// Efface la liste des commandes a refaires, en supprimant proprement
// tous les pointeurs de cette liste.

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
