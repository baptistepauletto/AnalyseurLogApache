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
#include <map>

using namespace std;

//------------------------------------------------------ Include personnel
#include "Graphe.h"
#include "Noeud.h"
#include "GestionnaireFichier.h"
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
		tableCorrespondance.insert(make_pair(e.GetDestination(),indiceC));
		noeuds[indiceC++] = nouveauNoeudDest;
		++nbNoeuds;
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
		tableCorrespondance.insert(make_pair(e.GetSource(),indiceC));
		noeuds[indiceC++] = nouveauNoeudSource;
		++nbNoeuds;
	}

	
} //---- Fin de AjouterNoeud


void Graphe::ExportGraphe(string nomFichier)
// Algorithme :
//
{
	ofstream os;
	os.open(nomFichier);
	os<<"digraph{"<<endl;
	for(unordered_map<int,Noeud>::iterator it=noeuds.begin();it!=noeuds.end();it++)
	{
		os<<"node"<<it->first<<" [label=\""<<it->second.GetIdentifiant()<<"\"];"<<endl;
	}
	for(unordered_map<int,Noeud>::iterator it=noeuds.begin();it!=noeuds.end();it++)
	{
		for(unsigned int i=0;i<nbNoeuds;i++)
			{
				if(it->second.GetNbhits(i)>0)
					os<<"node"<<it->first<<" -> "<<"node"<<i<<" [label=\""<<it->second.GetNbhits(i)<<"\"];"<<endl;
			} 
	}
	os<<"}"<<endl;
	os.close();


}

void Graphe::ChargerGraphe()
{
	while(GestionnaireLog.LigneSuivanteExiste()!=-1)
        	AjouterNoeud(GestionnaireLog.LireLigneSuivante());
}


void Graphe::GenererTop10(ostream & os)
{
	ChargerGraphe();
	multimap<unsigned int,int> classementHits;
	unordered_map<string,int>::iterator itCorrespond;
	int i = 0;
	os << "Classement des 10 sites webs les plus hits" << endl;
	for(unordered_map<int,Noeud>::iterator itHits = noeuds.begin(); itHits !=noeuds.end(); itHits++)
	{
		classementHits.insert(make_pair(itHits->second.GetPointeePar(),itHits->first));
	}
	multimap<unsigned int,int>::reverse_iterator itClassement = classementHits.rbegin(); 
	while ( itClassement != classementHits.rend() && i < 10 )
	{
		for(itCorrespond = tableCorrespondance.begin(); itCorrespond != tableCorrespondance.end(); itCorrespond++)
		{
			if(itCorrespond->second == itClassement->second)
			{
				os << i+1 <<" - " << itCorrespond->first << " => " << itClassement->first << " hit(s) " << endl;
				break;
			}
		}
		++i;
		++itClassement;
	}

}

//------------------------------------------------- Surcharge d'opérateurs

ostream & operator << (ostream & os, Graphe & unGraphe)
// Algorithme :
//
// Contrat : 
//
{
	os << "Nb noeuds : " << unGraphe.nbNoeuds << endl
	<< "Indice C : " << unGraphe.indiceC << endl;
	for(auto it = unGraphe.noeuds.begin(); it != unGraphe.noeuds.end(); it++)
	{
		 os << " -- " << it->first << " -- " << '\n' << it->second << endl;
	}
	os << "Indices d'indexation : " << endl;
	for(auto it = unGraphe.tableCorrespondance.begin(); it != unGraphe.tableCorrespondance.end(); it++)
	{
		os << "--- " << it->second << " => " << it->first << endl;
	}
	return os;
}

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


Graphe::Graphe ( ) : nbNoeuds (0), indiceC (0)
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

