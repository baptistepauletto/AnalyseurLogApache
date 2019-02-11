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

//------------------------------------------------------------------------
// Rôle de la classe <GestionnaireFichier>
// La classe GestionnaireFichier a pour objectif de permettre certaines
// interactions avec le fichier de log Apache, en effet, il fait office 
// de singleton permettant d'ouvrir le fichier et d'en lire une ligne,
// qui sont les briques de base de l'application. D'autre part, il 
// permet également d'écrire dans un fichier en sortie selon les directives
// du cahier des charges (génération de graphe notamment).
//------------------------------------------------------------------------

class GestionnaireFichier 
{
//----------------------------------------------------------------- PUBLIC

public:
    static ifstream fichierEntree;
    static ofstream fichierSortie;
//----------------------------------------------------- Méthodes publiques
    void OuvrirFichier(const string & nomDeFichier);
    // Mode d'emploi :
    //       const string & nomDeFichier : Ouvre le fichier nomDeFichier
    //       en lecture.
    // Contrat :
    //

    Enregistrement LireLigneSuivante();
    // Mode d'emploi :
    //       	Cette méthode met à jour l'enregistrement courant,
    //       	suite à la lecture de la prochaine ligne du fichier journal.
    // Contrat :
    //		Le fichier a du être ouvert au préalable.
    
    int LigneSuivanteExiste();
    
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
    //
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

};

//-------------------------------- Autres définitions dépendantes de <GestionnaireFichier>

#endif // GESTIONNAIREFICHIER_H

