#include "matiere.h" // Relier la class Matiere externe à ce fichier (entre "" pour les fichier écrit par moi-même)
// Codage des méthode présent dans la Class
string Matiere::getLibelleMatiere()
{
	return libelleMatiere;
}

void Matiere::setLibelleMatiere(string thisMatiere)
{
	libelleMatiere = thisMatiere;
}

void Matiere::display()
{
	cout << ") " << libelleMatiere << endl;
	
}

void Matiere::input()
{ 	
	cout << "\nSaisir le libelle de la matière que vous souhaitez ajouter : " ;
	getline(cin,libelleMatiere); //getline pour les strings
}