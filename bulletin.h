#ifndef BULLETIN 
	#define BULLETIN

#include <vector>
#include <iostream>

class Section;
class Etudiant;
class Matiere;
using namespace std;
//Création d'une Clas dans un ficher externe .h
class Bulletin
{
	private :
    // Les proritétés 
	vector <string> vectApreciation;
	vector<float> vectMoyenneParMatiere;
	double moyenneG;

	Section * maSection;
	Etudiant * monEtudiant;

	public :

	void display(); // méthode d'affichage
	void input();  // méthode de saisie par l'utilisateur

	Bulletin(Section*, Etudiant*);
}; 

#endif