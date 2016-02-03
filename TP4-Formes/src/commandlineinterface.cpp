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
            createSegment(true, cin);
        }
        else if( nextAction == "R" )
        {
            createRectangle(true, cin);
        }
        else if( nextAction == "PC" )
        {
            createConvexPolygone(true, cin);
        }
        else if( nextAction == "OR" )
        {
            createEnsemble(Ensemble::UNION, true, cin);
        }
        else if( nextAction == "OI" )
        {
            createEnsemble(Ensemble::INTERSECTION, true, cin);
        }
        else if( nextAction == "HIT" )
        {
            hit();
        }
        else if( nextAction == "DELETE" )
        {
            deleteForm(true, cin);
        }
        else if( nextAction == "MOVE" )
        {
            move();
        }
        else if( nextAction == "LIST" )
        {
            listForm();
        }
//        else if( nextAction == "UNDO" )
//        {
//            undo();
//        }
//        else if( nextAction == "REDO" )
//        {
//            redo();
//        }
        else if( nextAction == "LOAD" )
        {
            load();
        }
        else if( nextAction == "SAVE" )
        {
            save();
        }
        else if( nextAction == "CLEAR" )
        {
            clear();
        }
        else if( nextAction == "EXIT" )
        {
            clear();
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

}

//------------------------------------------------------------------------ PRIVE

//----------------------------------------------------------- Methodes protegees

//------------------------------------------------------------- Methodes privees

void CommandLineInterface::responseToUser(bool response, string message)
{
    cout << (response ? "OK" : "ERR") << endl;

    if(message!="")
    {
        cout << "# " << message << endl;
    }
}

void CommandLineInterface::createSegment(bool display, istream &in)
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
    }

    if (display)
    {
        responseToUser(isConstructionPossible, errorMessage);
    }
}

void CommandLineInterface::createRectangle(bool display, istream &in)
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
    }

    if (display)
    {
        responseToUser(isConstructionPossible, errorMessage);
    }
}

void CommandLineInterface::createConvexPolygone(bool display, istream &in)
{
    string name;
    int x;
    int y;
    vector<Point> parametersArray;

    in >> name;
    while(cin.peek() != '\n')
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
    }

    if (display)
    {
        responseToUser(isConstructionPossible, errorMessage);
    }
}

void CommandLineInterface::createEnsemble(Ensemble::Type type, bool display, istream &in)
{
    vector<Form*> formList;
    string currentName;
    Form* currentForm;

    string ensembleName;
    in >> ensembleName;

    while (cin.peek() != '\n')
    {
        in >> currentName;
        currentForm = draw.GetForm(currentName);
        if (currentForm == nullptr)
        {
            responseToUser(false, currentName + " inexistant");
        }
        formList.push_back(currentForm);
    }

    string errorMessage = "";
    bool isConstructionPossible = false;
    Ensemble * e = Ensemble::GetEnsemble(ensembleName, formList, type, errorMessage);
    if (e != nullptr)
    {
        isConstructionPossible = draw.AddForm(ensembleName, e, errorMessage);
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
    cout << response << endl;
}

void CommandLineInterface::deleteForm(bool display, istream &in)
{
    vector<string> nameList;
    string currentName;
    string errorMessage = "";

    while (cin.peek() != '\n')
    {
        in >> currentName;
        nameList.push_back(currentName);
    }

    if (display)
    {
        bool success = draw.Delete(nameList, errorMessage);
        responseToUser(success, errorMessage);
    }
}

void CommandLineInterface::move()
{
    string name;
    string errorMessage = "";
    int dX;
    int dY;

    cin >> name >> dX >> dY;

    bool success = draw.Move(name, dX, dY, errorMessage);
    responseToUser(success, errorMessage);
}

void CommandLineInterface::listForm()
{
    draw.Enumerate(cout);
}

void CommandLineInterface::load()
{
    string filename;
    cin >> filename;

    ifstream in(filename);

    string nextAction;
    while (in >> nextAction && in.peek() != '\n')
    {
        if(nextAction == "S" )
        {
            createSegment(false, in);
        }
        else if( nextAction == "R" )
        {
            createRectangle(false, in);
        }
        else if( nextAction == "PC" )
        {
            createConvexPolygone(false, in);
        }
        else if( nextAction == "OR" )
        {
            createEnsemble(Ensemble::UNION, false, in);
        }
        else if( nextAction == "OI" )
        {
            createEnsemble(Ensemble::INTERSECTION, false, in);
        }
        else if(nextAction == "DELETE")
        {
            deleteForm(false, in);
        }
    }
    responseToUser(true);
}

void CommandLineInterface::save()
{
    string filename;
    cin >> filename;

    ofstream out(filename);
    draw.Enumerate(out);
    responseToUser(true);
}

void CommandLineInterface::clear()
{
    draw.Clear();
    responseToUser(true);
}









