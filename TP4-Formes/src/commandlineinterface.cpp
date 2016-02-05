/*******************************************************************************
 CommandLineInterface.cpp  -  description
 -------------------
 début                : 08/12
 copyright            : (C) 2015 par frobion
 ******************************************************************************/

//- Réalisation de la classe CommandLineInterface (fichier CommandLineInterface.cpp) --
//---------------------------------------------------------------------- INCLUDE
//-------------------------------------------------------------- Include système
using namespace std;

#include <iostream>
#include <fstream>
#include <vector>

//------------------------------------------------------------ Include personnel
#include "CommandLineInterface.h"
#include "point.h"
#include "segment.h"
#include "rectangle.h"
#include "convexpolygone.h"


//------------------------------------------------------------------- Constantes

//---------------------------------------------------------- Variables de classe

//----------------------------------------------------------------- Types prives

//----------------------------------------------------------------------- PUBLIC
//-------------------------------------------------------------- Fonctions amies

//----------------------------------------------------------- Methodes publiques

int CommandLineInterface::waitForCommand()
{
    string nextAction;
    while (cin >> nextAction)
    {
        if(nextAction == "S" )
        {
            clearRedoList();
            createSegment(true, cin, true);
        }
        else if( nextAction == "R" )
        {
            clearRedoList();
            createRectangle(true, cin, true);
        }
        else if( nextAction == "PC" )
        {
            clearRedoList();
            createConvexPolygone(true, cin, true);
        }
        else if( nextAction == "OR" )
        {
            clearRedoList();
            createEnsemble(Ensemble::UNION, true, cin, true);
        }
        else if( nextAction == "OI" )
        {
            clearRedoList();
            createEnsemble(Ensemble::INTERSECTION, true, cin, true);
        }
        else if( nextAction == "HIT" )
        {
            hit();
        }
        else if( nextAction == "DELETE" )
        {
            clearRedoList();
            deleteForm(true, cin, true);
        }
        else if( nextAction == "MOVE" )
        {
            clearRedoList();
            move(true, cin, true);
        }
        else if( nextAction == "LIST" )
        {
            listForm();
        }
        else if( nextAction == "UNDO" )
        {
            undo();
        }
        else if( nextAction == "REDO" )
        {
            redo();
        }
        else if( nextAction == "LOAD" )
        {
            clearRedoList();
            load(true, cin);
        }
        else if( nextAction == "SAVE" )
        {
            save();
        }
        else if( nextAction == "CLEAR" )
        {
            clearRedoList();
            clear(true, true);
        }
        else if( nextAction == "EXIT" )
        {
            clear(false, false);
            return 0;
        }
    }
    return 1;  // Si on sort pas normalement, erreur.
}


//------------------------------------------------------- Surcharge d'operateurs

//-------------------------------------------------- Constructeurs - destructeur

CommandLineInterface::CommandLineInterface()
{

}

CommandLineInterface::~CommandLineInterface()
{
    clearRedoList();
    list<CommandUndoRedo*>::iterator itUndoList;
    for (itUndoList = undoList.begin(); itUndoList != undoList.end(); itUndoList++)
    {
        delete *itUndoList;
    }
    undoList.clear();
}

//------------------------------------------------------------------------ PRIVE

//----------------------------------------------------------- Methodes protegees

//------------------------------------------------------------- Methodes privees

void CommandLineInterface::createSegment(bool display, istream &in, bool doReturnCommand)
{

    string name;
    int x1;
    int y1;
    int x2;
    int y2;

    in >> name >> x1 >> y1 >> x2 >> y2;

    Point p1(x1,y1);
    Point p2(x2,y2);
    string errorMessage = "";
    bool isConstructionPossible = false;
    Segment* s = Segment::GetSegment(name, p1, p2, errorMessage);

    if(s != nullptr)
    {
        isConstructionPossible = draw.AddForm(name, s, errorMessage);
        if (isConstructionPossible && doReturnCommand) // On ne cree la commande oppose que si la construction a bien eu lieu
        {
            stringstream* oppositeCommand = new stringstream("DELETE " + name + "\r\n");
            stringstream* command = new stringstream();
            *command << "S " << name << " " << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
            CommandUndoRedo* commandUndoRedo = new CommandUndoRedo{oppositeCommand, command};
            addCommandInUndoList(commandUndoRedo);
        }
    }

    if (display)
    {
        responseToUser(isConstructionPossible, errorMessage);
    }
}

void CommandLineInterface::createRectangle(bool display, istream &in, bool doReturnCommand)
{
    string name;
    int x1;
    int y1;
    int x2;
    int y2;

    in >> name >> x1 >> y1 >> x2 >> y2;

    Point p1(x1,y1);
    Point p2(x2,y2);
    string errorMessage = "";
    bool isConstructionPossible = false;
    Rectangle* r = Rectangle::GetRectangle(name, p1, p2, errorMessage);

    if(r != nullptr)
    {
        isConstructionPossible = draw.AddForm(name, r, errorMessage);
        if (isConstructionPossible && doReturnCommand) // On ne cree la commande oppose que si la construction a bien eu lieu
        {
            stringstream* oppositeCommand = new stringstream("DELETE " + name + "\r\n");
            stringstream* command = new stringstream();
            *command << "R " << name << " " << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
            CommandUndoRedo* commandUndoRedo = new CommandUndoRedo{oppositeCommand, command};
            addCommandInUndoList(commandUndoRedo);
        }
    }

    if (display)
    {
        responseToUser(isConstructionPossible, errorMessage);
    }
}

void CommandLineInterface::createConvexPolygone(bool display, istream &in, bool doReturnCommand)
{
    string name;
    int x;
    int y;
    vector<Point> parametersArray;

    in >> name;
    while(in.peek() != '\n' && in.peek() != '\r')
    {
        in >> x >> y;
        parametersArray.push_back(Point(x, y));
    }

    string errorMessage = "";
    bool isConstructionPossible = false;
    ConvexPolygone* cP = ConvexPolygone::GetConvexPolygone(name, parametersArray, errorMessage);

    if(cP != nullptr)
    {
        isConstructionPossible = draw.AddForm(name, cP, errorMessage);
        if (isConstructionPossible && doReturnCommand) // On ne cree la commande oppose que si la construction a bien eu lieu
        {
            stringstream* oppositeCommand = new stringstream("DELETE " + name + "\r\n");
            stringstream* command = new stringstream();
            *command << "PC " << name;
            for (uint i = 0; i < parametersArray.size(); i++)
            {
                *command << " " << parametersArray[i].GetX() << " " << parametersArray[i].GetY();
            }
            *command << endl;
            CommandUndoRedo* commandUndoRedo = new CommandUndoRedo{oppositeCommand, command};
            addCommandInUndoList(commandUndoRedo);
        }
    }

    if (display)
    {
        responseToUser(isConstructionPossible, errorMessage);
    }
}

void CommandLineInterface::createEnsemble(Ensemble::Type type, bool display, istream &in, bool doReturnCommand)
{
    vector<Form*> formList;
    string currentName;
    string nameList = "";
    Form* currentForm;

    string ensembleName;
    in >> ensembleName;

    while (in.peek() != '\n' && in.peek() != '\r')
    {
        in >> currentName;
        nameList += " " + currentName;
        currentForm = draw.GetForm(currentName);
        if (currentForm == nullptr)
        {
            responseToUser(false, currentName + " inexistant");
            return;
        }
        formList.push_back(currentForm);
    }

    string errorMessage = "";
    bool isConstructionPossible = false;
    Ensemble * e = Ensemble::GetEnsemble(ensembleName, formList, type, errorMessage);
    if (e != nullptr)
    {
        isConstructionPossible = draw.AddForm(ensembleName, e, errorMessage);
        if (isConstructionPossible && doReturnCommand) // On ne cree la commande oppose que si la construction a bien eu lieu
        {
            stringstream* oppositeCommand = new stringstream("DELETE " + ensembleName + "\r\n");
            stringstream* command = new stringstream();
            *command << (type == Ensemble::UNION ? "OR " : "OI ") << ensembleName << nameList << endl;
            CommandUndoRedo* commandUndoRedo = new CommandUndoRedo{oppositeCommand, command};
            addCommandInUndoList(commandUndoRedo);
        }
    }

    if (display)
    {
        responseToUser(isConstructionPossible, errorMessage);
    }
}

void CommandLineInterface::hit()
{
    string name;
    string errorMessage = "";
    int x;
    int y;

    cin >> name >> x >> y;

    string response = (draw.Hit(name, x, y, errorMessage)) ? "YES" : "NO";
    if (errorMessage != "")
    {
        responseToUser(false, errorMessage);
    }
    else
    {
        cout << response << endl;
    }
}

void CommandLineInterface::deleteForm(bool display, istream &in, bool doReturnCommand)
{
    vector<string> nameList;
    string currentName;
    string errorMessage = "";
    string stringNameList = "";
    string deletedFormInformation = "";

    while (in.peek() != '\n' && in.peek() != '\r')
    {
        in >> currentName;
        nameList.push_back(currentName);
        stringNameList += " " +  currentName;
    }

    bool success = draw.Delete(nameList, errorMessage, deletedFormInformation);
    if (success && doReturnCommand)
    {
        stringstream* oppositeCommand = new stringstream(deletedFormInformation);
        stringstream* command = new stringstream("DELETE" + stringNameList + "\r\n");
        CommandUndoRedo* commandUndoRedo = new CommandUndoRedo{oppositeCommand, command};
        addCommandInUndoList(commandUndoRedo);
    }

    if (display)
    {
        responseToUser(success, errorMessage);
    }
}

void CommandLineInterface::move(bool display, istream &in, bool doReturnCommand)
{
    string name;
    string errorMessage = "";
    int dX;
    int dY;

    in >> name >> dX >> dY;

    bool success = draw.Move(name, dX, dY, errorMessage);
    if (success && doReturnCommand)
    {
        stringstream* oppositeCommand = new stringstream();
        stringstream* command = new stringstream();
        *oppositeCommand << "MOVE " << name << " " << -dX << " " << -dY << endl;
        *command << "MOVE " << name << " " << dX << " " << dY << endl;
        CommandUndoRedo* commandUndoRedo = new CommandUndoRedo{oppositeCommand, command};
        addCommandInUndoList(commandUndoRedo);
    }

    if(display)
    {
        responseToUser(success, errorMessage);
    }
}

void CommandLineInterface::listForm()
{
    draw.Enumerate(cout);
}

void CommandLineInterface::undo()
{
    if (undoList.size() == 0)
    {
        responseToUser(false, "Pas de commande a annulee");
        return;
    }

    CommandUndoRedo* command = undoList.front();
    redoList.push_front(command);

    stringstream tmp;
    tmp << command->undo->str();
    load(tmp, true);
    undoList.pop_front();

    responseToUser(true);
}

void CommandLineInterface::redo()
{
    if (redoList.size() == 0)
    {
        responseToUser(false, "Pas de commande a refaire");
        return;
    }
    CommandUndoRedo* command = redoList.front();
    redoList.pop_front();
    undoList.push_front(command);

    stringstream tmp;
    tmp << command->redo->str();
    load(tmp, false);

    responseToUser(true);
}

void CommandLineInterface::load(bool display, istream &in)
{
    string filename;
    in >> filename;

    stringstream* currentLoad = new stringstream();
    draw.Enumerate(*currentLoad);
    stringstream* oppositeCommand = new stringstream("CLEAR\r\nLOAD\r\n");
    stringstream* command = new stringstream("LOAD " + filename + "\r\n");

    CommandUndoRedo* commandUndoRedo = new CommandUndoRedo{oppositeCommand, command, currentLoad};
    addCommandInUndoList(commandUndoRedo);

    ifstream fileIn(filename);
    if (fileIn)
    {
        load(fileIn, false);
        fileIn.close();
    }
    else if (display)
    {
        responseToUser(false, "Nom de fichier inexistant");
        return;
    }

    if (display)
    {
        responseToUser(true);
    }
}

void CommandLineInterface::load(istream &in, bool undo)
{
    string nextAction;
    while (in >> nextAction && !in.eof())
    {
        if(nextAction == "S" )
        {
            createSegment(false, in, false);
        }
        else if( nextAction == "R" )
        {
            createRectangle(false, in, false);
        }
        else if( nextAction == "PC" )
        {
            createConvexPolygone(false, in, false);
        }
        else if( nextAction == "OR" )
        {
            createEnsemble(Ensemble::UNION, false, in, false);
        }
        else if( nextAction == "OI" )
        {
            createEnsemble(Ensemble::INTERSECTION, false, in, false);
        }
        else if(nextAction == "DELETE")
        {
            deleteForm(false, in, false);
        }
        // Les commandes ci-dessous (MOVE, LOAD et CLEAR) ne sont accessible que
        // depuis les commandes UNDO et REDO
        else if(nextAction == "MOVE")
        {
            move(false, in, false);
        }
        else if (nextAction == "LOAD")
        {
            if (undo)
            {
                stringstream tmp;
                tmp << undoList.front()->load->str();
                load(tmp, false);
            }
            else
            {
                load(false, in);
            }
        }
        else if(nextAction == "CLEAR")
        {
            clear(false, false);
        }
    }
}

void CommandLineInterface::save()
{
    string filename;
    cin >> filename;

    ofstream out(filename);
    draw.Enumerate(out);
    out.close();
    responseToUser(true);
}

void CommandLineInterface::clear(bool display, bool doReturnCommand)
{
    if(doReturnCommand)
    {
        stringstream* currentLoad = new stringstream();
        draw.Enumerate(*currentLoad);
        stringstream* oppositeCommand = new stringstream("LOAD\r\n");
        stringstream* command = new stringstream("CLEAR\r\n");

        CommandUndoRedo* commandUndoRedo = new CommandUndoRedo{oppositeCommand, command, currentLoad};
        addCommandInUndoList(commandUndoRedo);
    }

    draw.Clear();

    if(display)
    {
        responseToUser(true);
    }
}

void CommandLineInterface::responseToUser(bool response, string message)
{
    cout << (response ? "OK" : "ERR") << endl;

    if(message!="")
    {
        cout << "# " << message << endl;
    }
}

void CommandLineInterface::addCommandInUndoList(CommandUndoRedo* command)
{
    undoList.push_front(command);
    if (undoList.size() > 20)
    {
        delete undoList.back();
        undoList.pop_back();
    }
}

void CommandLineInterface::clearRedoList()
{
    //cout << "       " << "Debut clearRedoList" << endl;
    list<CommandUndoRedo*>::iterator itRedoList;
    for (itRedoList = redoList.begin(); itRedoList != redoList.end(); itRedoList++)
    {
        delete *itRedoList;
    }
    redoList.clear();
}












