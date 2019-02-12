/*************************************************************************
                           Enregistrement  -  description
                             -------------------
    début                : 25/01/2019
    copyright            : (C) 2019 par PAULETTO Baptiste, LIU Taoyang 
                            & GELFGREN Jan Markus 
    e-mail               : <prenom>.<nom>@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Enregistrement> (fichier Enregistrement.h) ----------------
#if ! defined ( ENREGISTREMENT_H )
#define ENREGISTREMENT_H

//--------------------------------------------------- Interfaces utilisées
#include <string>

using namespace std;
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types
typedef enum {SUCCES = 200, MISSING = 404} Status;

typedef struct Date {
	int heure;
       	int minutes;
       	int secondes;
       	int jour;
       	string mois;
       	int annee;
	string difGW; //Différence avec le méridien de Greenwich 
	Date (int h = 0, int min = 0, int s = 0, int j = 0, string moi = "",
		int a = 0, string d ="") : heure(h), minutes(min), secondes(s), jour(j),
		mois(moi), annee(a), difGW(d) {}
} Date ;
//------------------------------------------------------------------------
// Rôle de la classe <Enregistrement>
// La classe Enregistrement permet de stocker l'intégralité des informations
// contenues dans une ligne d'un fichier journal Apache.
//------------------------------------------------------------------------

class Enregistrement
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    
    string GetAdresseIP();
    // Mode d'emploi :
    //		Cette méthode renvoie la valeur de l'attribut adresseIP.
    // Contrat :
    //

    string GetUserLogname();
    // Mode d'emploi :
    //		Cette méthode renvoie la valeur de l'attribut userLogName.
    // Contrat :
    //

    string GetUsername();
    // Mode d'emploi :
    //		Cette méthode renvoie la valeur de l'attribut userName.
    // Contrat :
    //

    Date GetDate();
    // Mode d'emploi :
    //		Cette méthode renvoie la valeur de l'attribut date.
    // Contrat :
    //
    
    string GetTypeAction();
    // Mode d'emploi :
    //		Cette méthode renvoie la valeur de l'attribut destination.
    // Contrat :
    //
    
    string GetDestination();
    // Mode d'emploi :
    //		Cette méthode renvoie la valeur de l'attribut destination.
    // Contrat :
    //
    
    Status GetStatus();
    // Mode d'emploi :
    //		Cette méthode renvoie la valeur de l'attribut status.
    // Contrat :
    //
    
    string GetQteDonnees();
    // Mode d'emploi :
    //		Cette méthode renvoie la valeur de l'attribut qteDonnees.
    // Contrat :
    //
    
    string GetSource();
    // Mode d'emploi :
    //		Cette méthode renvoie la valeur de l'attribut source.
    // Contrat :
    //
    
    string GetNavigateurClient();
    // Mode d'emploi :
    //		Cette méthode renvoie la valeur de l'attribut navigateurClient.
    // Contrat :
    //

//------------------------------------------------- Surcharge d'opérateurs
    Enregistrement & operator = ( const Enregistrement & unEnregistrement );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Enregistrement ( const Enregistrement & unEnregistrement );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Enregistrement ( string  adresseIP = "NTM", string userLogname = "",
		   string username = "", Date date = Date(), 
		   string typeAction = "", string destination = "",
		   Status status = MISSING, string qteDonnees = "",
	           string source = "", string navigateurClient = "" );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Enregistrement ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    
    string adresseIP;
    string userLogname;
    string username;
    Date date;
    string typeAction;
    string destination;
    Status status;
    string qteDonnees;
    string source;
    string navigateurClient;

};

//-------------------------------- Autres définitions dépendantes de <Enregistrement>

#endif // ENREGISTREMENT_H

