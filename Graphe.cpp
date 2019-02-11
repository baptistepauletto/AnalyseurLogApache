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
#include <fstream>
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
		nbNoeuds++;
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
		nbNoeuds++;
	}

	
} //---- Fin de AjouterNoeud

void Graphe::ExportGraph(string nomFichier)
{
	ofstream os;
	os.open(nomFichier);
	os<<"digraph{"<<endl;
	for(unordered_map<int,Noeud>::iterator it=noeuds.begin();it!=noeuds.end();it++)
	{
			os<<"node"<<it->first<<" [label=\""<<it->second.getIdentifiant()<<"\"];"<<endl;
	}
	for(unordered_map<int,Noeud>::iterator it=noeuds.begin();it!=noeuds.end();it++)
	{
			for(unsigned int i=0;i<nbNoeuds;i++)
			{
				if(it->second.getNbhits(i)>0)
					os<<"node"<<it->first<<" -> "<<"node"<<i<<" [label=\""<<it->second.getNbhits(i)<<"\"];"<<endl;
			} 
	}
	os<<"}"<<endl;
	os.close();
}

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

