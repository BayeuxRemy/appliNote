#include "note.h"
#include "section.h"
#include "evaluation.h"

Note::Note(Evaluation * lEvaluation, Etudiant * lEtudiant)
{
	monEvaluation=lEvaluation;
	monEtudiant = lEtudiant;
}

int Note::getNote()
{
	return note;
}
void Note::setNote(int thisNote)
{
	thisNote = note;
}
void Note::input()
{
	vector <Etudiant *> vectLesEtudiants=monEvaluation->getPSection()->getLesEtudiantsDeLaSection();
	if(vectLesEtudiants.size() == 0)
	{
		cout << "!!!!!! Erreur ! Il n'y à pas encore d'Etudiants dans la Section !!!!!!!!!!"<<endl;
	}
	else 
	{
		cin >> note;

	}
}

