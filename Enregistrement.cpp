/*************************************************************************
                           Enregistrement  -  description
                             -------------------
    début                : 25/01/2019
    copyright            : (C) 2019 par PAULETTO Baptiste, LIU Taoyang 
    			    & GELFGREN Jan Markus 
    e-mail               : <prenom>.<nom>@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <Enregistrement> (fichier Enregistrement.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Enregistrement.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
string Enregistrement::GetAdresseIP ( )
// Algorithme :
//
{
	return adresseIP;
} //----- Fin de Méthode

string Enregistrement::GetUserLogname ( )
// Algorithme :
//
{
	return userLogname;
} //----- Fin de Méthode

string Enregistrement::GetUsername ( )
// Algorithme :
//
{
	return username;
} //----- Fin de Méthode

Date Enregistrement::GetDate( )
// Algorithme :
//
{
	return date;
} //----- Fin de Méthode

string Enregistrement::GetTypeAction( )
// Algorithme :
//
{
	return typeAction;
} //----- Fin de Méthode

string Enregistrement::GetDestination( )
// Algorithme :
//
{
	return destination;
} //----- Fin de Méthode

Status Enregistrement::GetStatus( )
// Algorithme :
//
{
	return status;
} //----- Fin de Méthode

int Enregistrement::GetQteDonnees( )
// Algorithme :
//
{
	return qteDonnees;
} //----- Fin de Méthode


string Enregistrement::GetSource( )
// Algorithme :
//
{
	return source;
} //----- Fin de Méthode

string Enregistrement::GetNavigateurClient( )
// Algorithme :
//
{
	return navigateurClient;
} //----- Fin de Méthode

//------------------------------------------------- Surcharge d'opérateurs
Enregistrement & Enregistrement::operator = ( const Enregistrement & unEnregistrement )
// Algorithme :
//
{
	adresseIP = unEnregistrement.adresseIP; 
	return *this;
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Enregistrement::Enregistrement ( const Enregistrement & unEnregistrement )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Enregistrement>" << endl;
#endif
} //----- Fin de Enregistrement (constructeur de copie)


Enregistrement::Enregistrement ( string adresseIP, string userLogname,
                 string username, Date date, string typeAction,
                 string destination,  Status status,
                 int qteDonnees, string source,
                 string navigateurClient ) 
	: adresseIP(adresseIP), userLogname(userLogname),
	 username(username), date(date), typeAction(typeAction),
	 destination(destination), status(status), 
	 qteDonnees(qteDonnees), source(source),
	 navigateurClient(navigateurClient)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Enregistrement>" << endl;
#endif
} //----- Fin de Enregistrement


Enregistrement::~Enregistrement ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Enregistrement>" << endl;
#endif
} //----- Fin de ~Enregistrement


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

