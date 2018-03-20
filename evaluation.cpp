#include "evaluation.h"
#include "section.h"
#include "note.h"

Evaluation::Evaluation(Section * laSection)
{
	maSection=laSection;
}

string Evaluation::getRefEval() 
{
	return refEval;
}
int Evaluation::getSemestreEval()
{
	return semestreEval;
}
void Evaluation::setRefEval(string thisRefEval)
{
	thisRefEval = refEval;
}
void Evaluation::setSemestreEval(int thisSemestre)
{
	semestreEval = thisSemestre;
}

void Evaluation::display()
{
	cout << endl << refEval <<" fait au "<<semestreEval << "e semestre"<<" en " << pLaMatiere->getLibelleMatiere()<<endl;
	cout <<endl<<"Les notes : "<<endl<<endl;
	vector <Etudiant *> vectLesEtudiants=maSection->getLesEtudiantsDeLaSection();
	for(unsigned int noNote=0;noNote<vectNote.size();noNote++)
		{	

			cout << noNote+1 << ") " << vectLesEtudiants[noNote]->getNom() <<" "<< vectLesEtudiants[noNote]->getPrenom()<< " : "<< vectNote[noNote].getNote()<<"/20"<<endl<<endl;
		}

}

void Evaluation::input()
{

	cout << "---------Vous souhaitez ajouter une Evaluation----------"<<endl<<endl;

	//on demande la liste de toutes les matières à la Section
	vector <Matiere*> vectLesMatieres=maSection->getLesMatieresDeLaSection();
	vector <Etudiant *> vectLesEtudiants=maSection->getLesEtudiantsDeLaSection();
	if(vectLesMatieres.size() == 0 || vectLesEtudiants.size() == 0 )
	{
		cout << "!!!!!! Erreur ! Il n'y à pas encore de de Matière(s) ou d'Etudiant(s) affectés à la Section !!!!!!!!!!"<<endl;
	}
	else
	{
		cout << "Choisissez la matière de l'évaluation : "<<endl;
		unsigned int choixMatiere;
		//affichage des matieres precedees d'un numéro
		for(unsigned int noMat=0;noMat<vectLesMatieres.size();noMat++)
		{
			cout << noMat+1 << "- " << vectLesMatieres[noMat]->getLibelleMatiere() <<endl;
		}

		cout << "\nSaisir le numéro de la matière de l'évaluation : ";
		cin >> choixMatiere;
		choixMatiere--;
		cin.ignore(1);

		if(choixMatiere<vectLesMatieres.size())
		{
			pLaMatiere = vectLesMatieres[choixMatiere];
			cout << "Entrez le sujet de l'évaluation : (ex: matrice1) ";
			getline(cin,refEval);
			cout << "Entrez le semestre (1 ou 2) : ";
			cin >> semestreEval;

			cout << endl << endl << "Vous devez maitenant saisir les notes par élève : "<<endl;
			for(unsigned int noEtudiant=0;noEtudiant<vectLesEtudiants.size();noEtudiant++)
			{
				cout << noEtudiant+1 << ") " << vectLesEtudiants[noEtudiant]->getNom() <<" "<< vectLesEtudiants[noEtudiant]->getPrenom()<<" : ";
				Note NoteAAjouter(this,vectLesEtudiants[noEtudiant]);
				NoteAAjouter.input();
				vectNote.push_back(NoteAAjouter);
			}
		}

		else 
		{	
			cout << "!!!!! Erreur ! Vous n'avez pas choisi le bon numéro !!!!!";
		}
	}
}
Section * Evaluation::getPSection()
{	//Renvoie la section dans lequelle l'évaluation a été effectué
	return maSection;
}