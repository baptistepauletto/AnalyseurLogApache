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
// Note : Nous avons fait le choix de vérifier la présence de la sous chaine
// HTTP/1.1, afin de l'enlever et avoir un traitement plus simple de la destination
// mais il est tout à fait imaginable d'ajouter à l'avenir, sa gestion via une méthode
// (HTTP/0.9 et HTTP/1.0 sont tout de même assez peu utilisés aujourd'hui).
{
	string b = " HTTP/1.1";
	if(destination.length() > b.length())
	{
		if(destination.compare(destination.length()-b.length(),b.length(),b)==0)
			destination = destination.substr(0,destination.length()-b.length());
	}
	return destination;
} //----- Fin de Méthode

Status Enregistrement::GetStatus( )
// Algorithme :
//
{
	return status;
} //----- Fin de Méthode

string Enregistrement::GetQteDonnees( )
// Algorithme :
//
{
	return qteDonnees;
} //----- Fin de Méthode

string Enregistrement::GetSource( )
// Algorithme :
//
{
	string a = "http://intranet-if.insa-lyon.fr";
	if(source.compare(0,a.length(),a)==0)
		source = source.substr(a.length(),source.length());
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
                 string qteDonnees, string source,
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

