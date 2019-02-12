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
#include <sstream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "GestionnaireFichier.h"
#include "Enregistrement.h"
//------------------------------------------------------------- Constantes
#define TAILLE 500
#define Entree GestionnaireFichier::fichierEntree 
#define Sortie GestionnaireFichier::fichierSorite 
//----------------------------------------------------------------- PUBLIC
ifstream Entree;
//----------------------------------------------------- Méthodes publiques

void GestionnaireFichier::OuvrirFichier(const string & nomDeFichier)
// Algorithme :
//
{
	Entree.open(nomDeFichier.c_str());
	if (!Entree){
		cerr << "Erreur d'ouverture du fichier : " << nomDeFichier <<endl;
	}	
} //----- Fin d'OuvrirFichier

Enregistrement GestionnaireFichier::LireLigneSuivante( )
// Algorithme :
// Extraction étape après étape de chacune des informations d'une ligne de log.
// Note : le tampon est utilisé pour permettre de sauter les caractères qui
// ne nous sont pas utiles ([, ", ]).
{
	string ligne, adresseIP, userLogname, username,chaineDate,typeAction, destination, status,
	qteDonnees, source, navigateurClient, difGW, tampon;
	string heure, minutes, secondes, jour, mois, annee;
	getline(Entree,ligne);

	//Gestion de l'ensemble des données de l'enregistrement
	istringstream iss (ligne);  //Utilisation du istringstream pour "tokeniser" la chaine
	getline(iss,adresseIP,' '); //Extraction token après token (type strtok() en c)
	getline(iss,userLogname,' ');
	getline(iss,username,' ');
	getline(iss,tampon,'[');
	getline(iss,chaineDate,' ');
	getline(iss,difGW,']'); 
	getline(iss,tampon,'"'); 
	getline(iss,typeAction,' ');  
	getline(iss,destination,'"');  
	iss.ignore();
	getline(iss,status,' '); 
	getline(iss,qteDonnees,' ');
	getline(iss,tampon,'"');  
	getline(iss,source,'"');
	getline(iss,tampon,'"');
	getline(iss,navigateurClient,'"');
	
	// Gestion de la structure Date
	istringstream issDate (chaineDate);
	getline(issDate ,jour,'/');
	getline(issDate ,mois,'/');
	getline(issDate ,annee,':');
	getline(issDate ,heure,':');
	getline(issDate ,minutes,':');
	getline(issDate ,secondes,':');
	
	//cout << adresseIP << ' ' << userLogname << " " << username << " " << chaineDate << " " << difGW 
	//<< " " << typeAction <<" "<< destination <<" "<< status << " " << qteDonnees << " " <<
	//source << " " << navigateurClient << endl;
	Date date (stoi(secondes),stoi(minutes),stoi(heure),stoi(jour),mois,stoi(annee),difGW);
	Enregistrement e (adresseIP,userLogname,username,date,typeAction,
	destination,(Status) stoi(status),qteDonnees,source,navigateurClient);
	return e;
} //----- Fin de LireLigneSuivante

int GestionnaireFichier::LigneSuivanteExiste()
// Algorithme :
//
{
	return Entree.peek();
}

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

