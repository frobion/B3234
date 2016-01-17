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

//------------------------------------------------------------ Include personnel
#include "CommandLineInterface.h"
#include "point.h"
#include "segment.h"
#include "rectangle.h"
#include "convexpolygone.h"
#include "union.h"
#include "intersection.h"

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
//        else if( nextAction == "PC" )
//        {
//            createConvexPolygone();
//        }
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
//        else if( nextAction == "LIST" )
//        {
//            listForm();
//        }
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
    Segment* s;
    string messageErreur = "";
    bool constructionPossible = false;

    if(Segment::IsConstructionPossible(p1, p2, messageErreur))
    {
        s = new Segment(name, p1, p2);
        constructionPossible = draw.AddForm(name, s, messageErreur);

    }
    responseToUser(constructionPossible, messageErreur);
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
    Rectangle* r;
    string messageErreur = "";
    bool constructionPossible = false;

    if(Rectangle::IsConstructionPossible(p1, p2, messageErreur))
    {
        r = new Rectangle(name, p1, p2);
        constructionPossible = draw.AddForm(name, r, messageErreur);

    }
    responseToUser(constructionPossible, messageErreur);
}

//void CommandLineInterface::createConvexPolygone()
//{
//    string read;
//    string name;
//    int buffer=0;
//    unsigned int counter=0;
//    vector<Point> parametersArray;

//    do{
//        getline(cin, read, ' ');
//        counter++;
//        if(counter==1)
//        {
//            name = read;
//        }
//        else if(counter!=1 && counter&1==true) // Compteur impair
//        {
//            parametersArray.push_back(Point(buffer, read));
//        }
//        buffer = read;

//    }while(read != ' ');

//    if(!counter&1)  // Si on a un nombre total pair de parametres
//    {
//       responseToUser(false, "Le nombre de paramètres est incorrect");
//    }

//    Rectangle* r;
//    string messageError = "";
//    bool constructionPossible = false;

//    if(ConvexPolygone::isConstructionPossible(p1, p2, messageError))
//    {
//        r = new ConvexPolygone(name, p1, p2);
//        constructionPossible = draw.AddForm(name, r, messageError);

//    }
//    responseToUser(constructionPossible, messageErreur);
//}
