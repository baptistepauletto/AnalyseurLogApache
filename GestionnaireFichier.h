/*************************************************************************
                           GestionnaireFichier -  description
                             -------------------
    début                : 25/01/2019
    copyright            : (C) 2019 par PAULETTO Baptiste, LIU Taoyang 
                            & GELFGREN Jan Markus 
    e-mail               : <prenom>.<nom>@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <GestionnaireFichier> (fichier GestionnaireFichier.h) ----------------
#if ! defined ( GESTIONNAIREFICHIER_H )
#define GESTIONNAIREFICHIER_H

//--------------------------------------------------- Interfaces utilisées
#include <fstream>
#include "Enregistrement.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <GestionnaireFichier>
//
//
//------------------------------------------------------------------------

class GestionnaireFichier 
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    void OuvrirFichier(const string & nomDeFichier);
    // Mode d'emploi :
    //       const string & nomDeFichier : Ouvre le fichier nomDeFichier
    //       en lecture.
    // Contrat :
    //

    void LireLigneSuivante();
    // Mode d'emploi :
    //       	Cette méthode met à jour l'enregistrement courant,
    //       	suite à la lecture de la prochaine ligne du fichier journal.
    // Contrat :
    //		Le fichier a du être ouvert au préalable.
    
    Enregistrement getEnregistrementCourant();
    // Mode d'emploi :
    //       Cette méthode renvoie l'attribut enregistrementCourant.
    // Contrat :
    //		L'enregistrement courant a du être initialisé 
    //		(lecture d\'au moins une ligne). 

//------------------------------------------------- Surcharge d'opérateurs
 //   GestionnaireFichier & operator = ( const GestionnaireFichier & unGestionnaireFichier );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    GestionnaireFichier ( const GestionnaireFichier & unGestionnaireFichier );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    GestionnaireFichier ( );
    // Mode d'emploi :
    //		Le constructeur est inline car très simple (par défaut vide).
    // Contrat :
    //

    virtual ~GestionnaireFichier ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées
		
//----------------------------------------------------- Attributs protégés
	static ifstream fichierEntree;
	static ofstream fichierSortie;
	Enregistrement enregistrementCourant;

};

//-------------------------------- Autres définitions dépendantes de <GestionnaireFichier>

#endif // GESTIONNAIREFICHIER_H

