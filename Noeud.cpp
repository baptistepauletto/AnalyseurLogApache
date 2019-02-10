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

//------------------------------------------------- Surcharge d'opérateurs

ostream & operator << ( ostream & os, Noeud & unNoeud)
// Algortihme :
//
{
	os << "id : " << unNoeud.identifiant << endl 
	<< " pointé par : " << unNoeud.pointeePar << endl
	<< " pointe : " << unNoeud.pointe << endl
	<< " aretes  : ";
	for(auto it = unNoeud.aretes.begin();it!=unNoeud.aretes.end() ;it++)
	{
		os << it->first << " => " << it->second << endl;
	} 
	return os;
}

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


Noeud::Noeud (string id, int pp, int p) : 
identifiant(id), pointeePar(pp), pointe(p)
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

