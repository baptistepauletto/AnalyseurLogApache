/*************************************************************************
                           Graphe -  description
                             -------------------
    début                : 25/01/2019
    copyright            : (C) 2019 par PAULETTO Baptiste, LIU Taoyang 
                            & GELFGREN Jan Markus 
    e-mail               : <prenom>.<nom>@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <Graphe> (fichier Graphe.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>

using namespace std;

//------------------------------------------------------ Include personnel
#include "Graphe.h"
#include "Noeud.h"
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void Graphe::AjouterNoeud(Enregistrement e)
// Algorithme :
//
{
	unordered_map<string,int>::iterator itS = tableCorrespondance.find(e.GetSource());
	unordered_map<string,int>::iterator itD = tableCorrespondance.find(e.GetDestination());
	
	if(!(itD == tableCorrespondance.end())) //Si la destination existe.
	{
		unordered_map<int,Noeud>::iterator itND = noeuds.find(itD->second);
		itND->second.IncrementePointeePar();
	} 
	else // Si la destination n'est pas encore disponible, on la créée.
	{
		Noeud nouveauNoeudDest (e.GetDestination(),1);
		tableCorrespondance[e.GetDestination()] = indiceC;
		noeuds[indiceC++] = nouveauNoeudDest;
	} 
	if(!(itS == tableCorrespondance.end())) //Si le noeud source existe.
	{	
		unordered_map<int,Noeud>::iterator itNS = noeuds.find(itS->second);
		itNS->second.AjouterArete(tableCorrespondance.find(e.GetDestination())->second);
	}
	else // Si le noeud n'existe pas, alors, on créé un nouveau noeud.
	{
		Noeud nouveauNoeudSource(e.GetSource(),0,1); 
		nouveauNoeudSource.AjouterArete(tableCorrespondance.find(e.GetDestination())->second);
		tableCorrespondance[e.GetSource()] = indiceC;
		noeuds[indiceC++] = nouveauNoeudSource;
	}

	
} //---- Fin de AjouterNoeud

//------------------------------------------------- Surcharge d'opérateurs
//Graphe & Graphe::operator = ( const Graphe & unGraphe )
// Algorithme :
//
//{
//} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Graphe::Graphe ( const Graphe & unGraphe )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Graphe>" << endl;
#endif
} //----- Fin de Graphe (constructeur de copie)


Graphe::Graphe ( ) : nbNoeuds (0)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Graphe>" << endl;
#endif
} //----- Fin de Graphe


Graphe::~Graphe ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Graphe>" << endl;
#endif
} //----- Fin de ~Graphe


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

