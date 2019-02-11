/*************************************************************************
                           Noeud -  description
                             -------------------
    début                : 25/01/2019
    copyright            : (C) 2019 par PAULETTO Baptiste, LIU Taoyang 
                            & GELFGREN Jan Markus 
    e-mail               : <prenom>.<nom>@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <Noeud> (fichier Noeud.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>

using namespace std;

//------------------------------------------------------ Include personnel
#include "Noeud.h"
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void Noeud::AjouterArete(int id)
// Algorithme :
//
{
	++aretes[id];
	++pointe;
}

void Noeud::IncrementePointeePar()
// Algorithme :
//
{
	++pointeePar;
}

string Noeud::getIdentifiant()
{
		return identifiant;
}

unsigned int Noeud::getPointeePar()
{
		return pointeePar;
}

unsigned int Noeud::getPointe()
{
		return pointe;
}

int Noeud::getNbhits(int id)
{
		return aretes[id];
}

//------------------------------------------------- Surcharge d'opérateurs
//Noeud & Noeud::operator = ( const Noeud & unNoeud )
// Algorithme :
//
//{
//} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Noeud::Noeud ( const Noeud & unNoeud )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Noeud>" << endl;
#endif
} //----- Fin de Noeud (constructeur de copie)


Noeud::Noeud (string id, int pp, int p) : identifiant(id),
pointeePar(pp), pointe(p)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Noeud>" << endl;
#endif
} //----- Fin de Noeud


Noeud::~Noeud ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Noeud>" << endl;
#endif
} //----- Fin de ~Noeud


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

