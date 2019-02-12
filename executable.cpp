#include<iostream>
#include "GestionnaireFichier.h"
#include "Graphe.h"
using namespace std;

int main(){
	string bjr ("test.log");
	//GestionnaireFichier::GetInstance();
	GestionnaireLog.OuvrirFichier(bjr);
	//Enregistrement e = gestionnaire.LireLigneSuivante();
	//cout << e.GetAdresseIP() << " " << e.GetUserLogname() << " " << e.GetUsername() << " " <<
	//e.GetDestination() << " " << e.GetStatus() << " " << e.GetQteDonnees() << " " << e.GetSource()
	//<< " " << e.GetNavigateurClient();
	Graphe g;
	g.ChargerGraphe();
	g.ExportGraphe("blabla.dot");
	cout << g ;
	return 0;
}
