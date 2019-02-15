#include <iostream>
#include <fstream>
#include <string>
#include "GestionnaireFichier.h"
#include "Graphe.h"
using namespace std;

int main(int argc,char *argv[])
{
	bool e = false,g = false,t = false,error = false;   // les variables deviendront vraies, si les options correspondantes ont été choisies
	int heure = 0;		    			    // heure suivant -t
	string nomDotFichier = "graphe.dot";  			    // nom du fichier .dot généré
	Graphe graphe;
	string nomLogFichier(argv[argc-1]);         
	
	if(argc==1) 		   // Si on ne donne aucun argument
	{
		cerr<<"Utilisation sans arguments impossible, rappel d'utilisation : " << endl
		<< "./analog [-e,-g,-t] [nomFichierDot] <nomFichierLogSource> " <<endl;
		exit(EXIT_FAILURE);
	}
	/* Début de l'identfication des options */
	if(argc >= 2)                                   // Si plusieurs parametres sont donnés.
	{
		for(int i=1;i<argc-1;i++)
		{
			if(argv[i][0]=='-')
			{
				switch(argv[i][1])
				{
					case 'e':
						if(e) 
							cerr<<"Option -e répétée !"<<endl;
						else
						{
							cout << "Option d'exclusion d'extension activée ! " << endl;
							e=true;
						}
						break;
					
					case 'g':
						if(g) 
							cerr<<"Option -g répétée !"<<endl;
						else
						{
							if(argv[i+1][0]=='-')                 //si le nom de fichier.dot n'est pas spécifié
							{
								cerr << "Utilisation impossible de l'option -g sans nom du fichier,rappel d'utilisation" << endl;
								cerr << "./analog [-e,-g,-t] [nomFichierDot] <nomFichierLogSource> " <<endl;
								exit(EXIT_FAILURE);
							}
							else
							{
							nomDotFichier=argv[i+1];
							cout<<"Le dot-file : "<< nomDotFichier <<" a été généré (pour GraphViz)."<<endl;
							g=true;
							}
						}
						break;
					
					case 't':
						if(t) 
							cerr<<"Option -t répétée !"<<endl;
						else
						{
							heure=stoi(argv[i+1])%24; // Le système lancera une exception si le paramètre de stoi() incorrect
							cout <<"Option de spécification horaire (heure = " << heure << ") activée ! "<< endl;
							t=true;
						}
						break;
					
					default:
						cerr<<"Option inconnue, options disponibles : -e, -g, -t"<<endl;
						error = true;
						exit(EXIT_FAILURE);
						break;
				}
			}
		}
	} //-- Fin de l'identification des options dans la ligne de commande
	
	// Si aucune erreur n'a eu lieu, nous chargeons le fichier en considérant les potentielles options.
	if(!error)
	{
		GestionnaireLog.OuvrirFichier(nomLogFichier);		   
		graphe.ChargerGrapheConditionnel(e,t,heure);
		graphe.GenererTop10(); // Le top 10 est généré dans tous les cas, c'est un choix de notre part.
		if(g) 		       // Si l'utilisateur souhaite exporter le graphe , c'est ici que ce sera réalisé.
			graphe.ExportGraphe(nomDotFichier);	
		exit(EXIT_SUCCESS);
	}
}
