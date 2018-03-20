#ifndef NOTE 
	#define NOTE

#include "etudiant.h"
#include "evaluation.h"

class Section;
class Evaluation;
//Création d'une Clas dans un ficher externe .h
class Note
{
	private :
    // Les proritétés 
	int note;
	Etudiant * monEtudiant; 
	Evaluation * monEvaluation;

	public :
	// Les méthodes
	int getNote();

	void setNote(int thisNote);

	void input();  // méthode de saisie par l'utilisateur

	Note(Evaluation*,Etudiant*);
}; 

 #endif