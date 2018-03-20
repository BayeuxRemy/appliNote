#ifndef EVALUATION 
	#define EVALUATION

#include "matiere.h"
#include "note.h"

class Note;
class Section;
//Création d'une Clas dans un ficher externe .h
class Evaluation
{
	private :
    // Les proritétés 
	string refEval;
	int semestreEval;
	Matiere * pLaMatiere;
	vector <Note> vectNote;
	Section * maSection;
	public :
	// Les méthodes
	string getRefEval();
	int getSemestreEval();

	void setRefEval(string thisEval);
	void setSemestreEval(int thisSemestre);

	void display(); // méthode d'affichage
	void input();  // méthode de saisie par l'utilisateur

	Section * getPSection();
	Evaluation(Section*);
}; 

#endif