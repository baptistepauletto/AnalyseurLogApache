#include <iostream>
#include <fstream>
#include <string>
#include "GestionnaireFichier.h"
#include "Graphe.h"
using namespace std;

string ext[]={"css","gif","jpg","js"};           //! extensions de fichier a exclure ( pas sûr si c'est complet )

/* cette méthode permet d'identifier s'il faut exclure le fichier par son extension 
 * elle prend en paramètre une adresse, soit une source ou une destination */
bool Exclure_Par_Extension(string a)					
{
	if(a.find('.')!=string::npos) 
	{
		int pos = a.rfind('.');
		a = a.substr(pos+1,a.length());          // on prend la partie après le dernier point dans la chaine
	}
	for(int i=0;i<4;i++)
	{
			if(a==ext[i]) return true;           // si c'est un fichier à exclure, on retourne vrai
	}
	return false;                                // sinon on retourne faux
}//-----fin de méthode



int main(int argc,char *argv[])
{
	bool e,g,t = false;			                 // les variables deviendront vraies si les options correspondantes ont été choisies
	int heure = 0;								 // heure suivant -t
	string nomDotFichier = "";                   // nom du fichier .dot généré
	Graphe graphe;
	string nomLogFichier = argv[argc-1];         // le nom du fichier qu'on lit
	GestionnaireLog.OuvrirFichier(nomLogFichier);		   
	
	//! il faut prendre en compte d'autres exceptions auxquelles j'ai pas pense
	if(argc==1) 								 //si on ne donne aucun argument
		cerr<<"donnez un nom de fichier!"<<endl;
	
	/* identfication des options */
	if(argc>2)                                   // si on donne plusieurs parametres
	{
		for(int i=1;i<argc-1;i++)
		{
			if(argv[i][0]=='-')
			{
				switch(argv[i][1])
				{
					case 'e':
						if(e) 
							cerr<<"option -e donnée plusieurs fois"<<endl;
						else
							e=true;
						break;
					
					case 'g':
						if(g) 
							cerr<<"option -g donnée plusieurs fois"<<endl;
						else
						{
							nomDotFichier=argv[i+1];
							cout<<"Dot-file "<<nomDotFichier<<" generated"<<endl;
							g=true;
						}
						break;
					
					case 't':
						if(t) 
							cerr<<"option -t donnée plusieurs fois"<<endl;
						else
						{
							heure=stoi(argv[i+1])%24;  // le système va lancer une exception si le paramètre de stoi n'est pas bon
							t=true;
						}
						break;
					
					default:
						cerr<<"option inconnue"<<endl;
						break;
				}
			}
		}
	} // fin identification des options
	
	/* lecture des enregistements */
	while(GestionnaireLog.LigneSuivanteExiste()!=-1)     // si on n'a pas touché la fin du texte
	{
		Enregistrement EC(GestionnaireLog.LireLigneSuivante());
		bool Ajouter_Enregistrement = true;              // verifier si l'engistrement courant peut etre ajouter dans le graphe
		if(e)                                            // si on a choisi l'option -e
		{
				if(Exclure_Par_Extension(EC.GetSource())||Exclure_Par_Extension(EC.GetDestination()))  // si l'un des deux fichiers a une extension qui ne convient pas
						Ajouter_Enregistrement = false;
		}
		if(t)											 // si on a choisi l'option -t
		{
				if(heure!=EC.GetHeure())                 // si l'heure de l'enregistrement ne convient pas
						Ajouter_Enregistrement = false;
		}
		if(Ajouter_Enregistrement)
		{    
				graphe.AjouterNoeud(EC);
		}
	}//------fin de lecture

	// lister les top10 à partir du graphe filtré
	graphe.GenererTop10();
	
	if(g)
		graphe.ExportGraphe(nomDotFichier);
		
	return 0;
}
