/*************************************************************************
                           Graphe -  description
                             -------------------
    début                : 25/01/2019
    copyright            : (C) 2019 par PAULETTO Baptiste, LIU Taoyang 
                            & GELFGREN Jan Markus 
    e-mail               : <prenom>.<nom>@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Graphe> (fichier Graphe.h) ----------------
#if ! defined ( GRAPHE_H )
#define GRAPHE_H

//--------------------------------------------------- Interfaces utilisées
#include <unordered_map>
#include <string>
#include "Noeud.h"
#include "Enregistrement.h"
using namespace std;
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------------
// Rôle de la classe <Graphe>
// La classe Graphe a pour objectif de faire l'interaction entre le 
// gestionnaire de fichier et la partie graphe destinée à être
// exploitée grace au format GraphViz. Nous allons donc mettre en place
// la liste des noeuds ainsi que garder une information quant aux nombres
// de noeuds. De plus, afin d'en optimiser l'utilisation sur un grand
// nombre de noeuds, nous allons réaliser une indexation des sites
// par un entier, cette information étant stockée dans la table resp.
//------------------------------------------------------------------------

class Graphe 
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    void AjouterNoeud(Enregistrement e);
    // Mode d'emploi :
    //		Enregistrement e : Enregistrement contenant les infos
    // minimales nécessaires à la création d'un Noeud.
    // Ce noeud, s'il est nouveau sera alors ajouté au graphe.	
    // Contrat :
    //	   
    
    void ExportGraph(string nomFichier);    

//------------------------------------------------- Surcharge d'opérateurs
 //   Graphe & operator = ( const Graphe & unGraphe );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Graphe ( const Graphe & unGraphe );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Graphe ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Graphe ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées
	unsigned int nbNoeuds;
	unsigned int indiceC;
	unordered_map<string,int> tableCorrespondance;
	unordered_map<int,Noeud> noeuds;		
//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <Graphe>

#endif // GRAPHE_H

