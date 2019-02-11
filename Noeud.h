/*************************************************************************
                           Noeud -  description
                             -------------------
    début                : 25/01/2019
    copyright            : (C) 2019 par PAULETTO Baptiste, LIU Taoyang 
                            & GELFGREN Jan Markus 
    e-mail               : <prenom>.<nom>@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Noeud> (fichier Noeud.h) ----------------
#if ! defined ( NOEUD_H )
#define NOEUD_H

//--------------------------------------------------- Interfaces utilisées
#include <unordered_map>
#include <string>
using namespace std;
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------------
// Rôle de la classe <Noeud>
// La classe Noeud a pour objectif de représenter les entités noeuds
// de notre graphe établi suite à la lecture du fichier de log Apache.
// De plus, il stocke des informations essentielles pour l'établissement
// d'un top 10 des sites (soit, noeuds) les plus consultés (hit). 
//------------------------------------------------------------------------
 
class Noeud 
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

void AjouterArete(int id);
    // Mode d'emploi :
    //
    // Contrat :
    //

void IncrementePointeePar();
    // Mode d'emploi :
    //		Incremente de 1 la valeur de l'attribut pointeePar,
    // ce qui signifie une arete de plus pointant vers ce noeud.
    // Contrat :
    //
string getIdentifiant();
unsigned int getPointeePar();
unsigned int getPointe();
int getNbhits(int id);

//------------------------------------------------- Surcharge d'opérateurs
 //   Noeud & operator = ( const Noeud & unNoeud );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Noeud ( const Noeud & unNoeud );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Noeud (string id = "", int pp = 0, int p = 0);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Noeud ( );
    // Mode d'emploi :
    //
    // Contrat :
    //
    

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
	string identifiant;
	unsigned int pointeePar;
	unsigned int pointe;
	unordered_map<int,int> aretes;

};

//-------------------------------- Autres définitions dépendantes de <Noeud>

#endif // NOEUD_H

