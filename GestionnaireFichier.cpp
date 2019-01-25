/*************************************************************************
                           GestionnaireFichier -  description
                             -------------------
    début                : 25/01/2019
    copyright            : (C) 2019 par PAULETTO Baptiste, LIU Taoyang 
                            & GELFGREN Jan Markus 
    e-mail               : <prenom>.<nom>@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <GestionnaireFichier> (fichier GestionnaireFichier.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <fstream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "GestionnaireFichier.h"
#include "Enregistrement.h"
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type GestionnaireFichier::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
//GestionnaireFichier & GestionnaireFichier::operator = ( const GestionnaireFichier & unGestionnaireFichier )
// Algorithme :
//
//{
//} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
GestionnaireFichier::GestionnaireFichier ( const GestionnaireFichier & unGestionnaireFichier )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <GestionnaireFichier>" << endl;
#endif
} //----- Fin de GestionnaireFichier (constructeur de copie)


GestionnaireFichier::GestionnaireFichier ( ) 
// Algorithme :
//
{
	enregistrementCourant = Enregistrement();
#ifdef MAP
    cout << "Appel au constructeur de <GestionnaireFichier>" << endl;
#endif
} //----- Fin de GestionnaireFichier


GestionnaireFichier::~GestionnaireFichier ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <GestionnaireFichier>" << endl;
#endif
} //----- Fin de ~GestionnaireFichier


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

