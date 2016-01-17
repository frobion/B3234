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


//------------------------------------------------------------------- Constantes

//------------------------------------------------------------------------ Types

//------------------------------------------------------------------------------
// Rôle de la classe CommandLineInterface
//
//------------------------------------------------------------------------------

class CommandLineInterface {
//----------------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------------- Méthodes publiques

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

protected:
//----------------------------------------------------------- Attributs protégés

private:
//------------------------------------------------------------- Attributs privés

//---------------------------------------------------------------- Classes amies

//-------------------------------------------------------------- Classes privées

//----------------------------------------------------------------- Types privés

};

//----------------------------------------------- Types dépendants de <CommandLineInterface>

#endif // COMMAND_LINE_INTERFACE_H
