#include<iostream>
#include "GestionnaireFichier.h"
#include "Graphe.h"
using namespace std;

int main(){
	string bjr ("test.log");
	GestionnaireFichier gestionnaire;
	gestionnaire.OuvrirFichier(bjr);
	//Enregistrement e = gestionnaire.LireLigneSuivante();
	//cout << e.GetAdresseIP() << " " << e.GetUserLogname() << " " << e.GetUsername() << " " <<
	//e.GetDestination() << " " << e.GetStatus() << " " << e.GetQteDonnees() << " " << e.GetSource()
	//<< " " << e.GetNavigateurClient();
	Graphe g;
	g.AjouterNoeud(gestionnaire.LireLigneSuivante());
	return 0;
}
