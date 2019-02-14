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
#define GestionnaireLog GestionnaireFichier::GetInstance()
//------------------------------------------------------------------------
// Rôle de la classe <GestionnaireFichier>
// La classe GestionnaireFichier a pour objectif de permettre certaines
// interactions avec le fichier de log Apache, en effet, il fait office 
// de singleton permettant d'ouvrir le fichier et d'en lire une ligne,
// qui sont les briques de base de l'application. D'autre part, il 
// a l'intégrale responsabilité de fournir toutes les données pour la 
// classe mère de l'application, soit la classe Graphe.
// Le desing pattern Singleton est mis en place.
//------------------------------------------------------------------------

class GestionnaireFichier 
{
//----------------------------------------------------------------- PUBLIC

public:
    static ifstream fichierEntree;
    static GestionnaireFichier & GetInstance()
    {
	static GestionnaireFichier instance;
	return instance;
    }

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
    // Mode d'emploi :
    //		Retourne -1 si la ligne suivante n'existe pas.
    // 
   
//------------------------------------------------- Surcharge d'opérateurs
GestionnaireFichier & operator = ( const GestionnaireFichier & unGestionnaireFichier ) = delete;
    // Note :
    // La surcharge d'opérateur doit être interdite dans le cas d'un singleton.

//-------------------------------------------- Constructeurs - destructeur
    GestionnaireFichier ( const GestionnaireFichier & unGestionnaireFichier ) = delete;
    // Note : 
    // La création par copie doit être interdite dans le cas d'un singleton.

    virtual ~GestionnaireFichier ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées
		
    GestionnaireFichier ( ) ;
    // Note : 
    // Le constructeur est placé dans la zone protégée afin d'empêcher l'
    // utilisateur d'instancier plusieurs fois le GestionnaireFichier.

//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <GestionnaireFichier>

#endif // GESTIONNAIREFICHIER_H

