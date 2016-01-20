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
#include <vector>

//------------------------------------------------------------ Include personnel
#include "CommandLineInterface.h"
#include "point.h"
#include "segment.h"
#include "rectangle.h"
#include "convexpolygone.h"
#include "ensemble.h"


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
            createSegment();
        }
        else if( nextAction == "R" )
        {
            createRectangle();
        }
        else if( nextAction == "PC" )
        {
            createConvexPolygone();
        }
//        else if( nextAction == "OR" )
//        {
//            createReunion();
//        }
//        else if( nextAction == "OI" )
//        {
//            createIntersection();
//        }
//        else if( nextAction == "HIT" )
//        {
//            hit();
//        }
//        else if( nextAction == "DELETE" )
//        {
//            deleteForm();
//        }
//        else if( nextAction == "MOVE" )
//        {
//            move();
//        }
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
//        else if( nextAction == "LOAD" )
//        {
//            load();
//        }
//        else if( nextAction == "SAVE" )
//        {
//            save();
//        }
//        else if( nextAction == "CLEAR" )
//        {
//            clear();
//        }
        else if( nextAction == "EXIT" )
        {
            return 0;
        }

    }
    return 1;  // Si on sort pas normalement, erreur.
}


//------------------------------------------------------- Surcharge d'operateurs

//-------------------------------------------------- Constructeurs - destructeur

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

void CommandLineInterface::createSegment()
{
    string name;
    int x1;
    int y1;
    int x2;
    int y2;

    cin >> name >> x1 >> y1 >> x2 >> y2;

    Point p1(x1,y1);
    Point p2(x2,y2);
    string errorMessage = "";
    bool isConstructionPossible = false;
    Segment* s = Segment::GetSegment(name, p1, p2, errorMessage);

    if(s != nullptr)
    {
        isConstructionPossible = draw.AddForm(name, s, errorMessage);
    }
    responseToUser(isConstructionPossible, errorMessage);
}

void CommandLineInterface::createRectangle()
{
    string name;
    int x1;
    int y1;
    int x2;
    int y2;

    cin >> name >> x1 >> y1 >> x2 >> y2;

    Point p1(x1,y1);
    Point p2(x2,y2);
    string errorMessage = "";
    bool isConstructionPossible = false;
    Rectangle* r = Rectangle::GetRectangle(name, p1, p2, errorMessage);

    if(r != nullptr)
    {
        isConstructionPossible = draw.AddForm(name, r, errorMessage);
    }
    responseToUser(isConstructionPossible, errorMessage);
}

void CommandLineInterface::createConvexPolygone()
{

//    string read;
//    string name;
//    int buffer=0;
//    int read2;
//    unsigned int counter=0;
//    vector<Point> parametersArray;

//    do{
//        getline(cin, read, ' ');
//        counter++;
//        if(counter==1)
//        {
//            name = read;
//        }
//        else if(counter!=1 && (counter&1) == true) // Compteur impair
//        {
//            read2 = stoi(read);
//            parametersArray.push_back(Point(buffer, read2));
//        }
//        buffer = read2;

//    }while(read != "\n");

//    if(!counter&1)  // Si on a un nombre total pair de parametres
//    {
//       responseToUser(false, "Le nombre de paramètres est incorrect");
//    }

    string name;
    int x;
    int y;
    vector<Point> parametersArray;

    cin >> name;
    while(cin.peek() != '\n')
    {
        cin >> x >> y;
        parametersArray.push_back(Point(x, y));
    }

    string errorMessage = "";
    bool constructionPossible = false;
    ConvexPolygone* cP = ConvexPolygone::GetConvexPolygone(name, parametersArray, errorMessage);

    if(cP != nullptr)
    {
        constructionPossible = draw.AddForm(name, cP, errorMessage);
    }
    responseToUser(constructionPossible, errorMessage);
}

void CommandLineInterface::listForm()
{
    draw.Enumerate(cout);
}
