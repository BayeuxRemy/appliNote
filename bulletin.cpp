#include "bulletin.h"
#include "section.h"


Bulletin::Bulletin(Section* laSection, Etudiant* lEtudiant)
{
	maSection=laSection;
	monEtudiant = lEtudiant;
}

void Bulletin::input()
{	
	cout <<endl<<"Entrez les appréciation de chaque matière "<<endl<<endl;
	string appreciation;
	vector <Matiere*> vectMatiereSection = maSection->getLesMatieresDeLaSection();
	for (unsigned int noMat=0; noMat<vectMatiereSection.size();noMat++) 
	{
		cout << vectMatiereSection[noMat]->getLibelleMatiere() <<" : ";
		getline(cin,appreciation);
		vectApreciation.push_back(appreciation);
		cout << endl;
	}
	
	
}

void Bulletin::display ()
{	
	cout << "Les appréciation de chaque matière :"<<endl<<endl;
	vector <Matiere*> vectMatiereSection = maSection->getLesMatieresDeLaSection();
	for (unsigned int noAppre=0; noAppre<vectApreciation.size();noAppre++) 
	{
		cout << vectMatiereSection[noAppre]->getLibelleMatiere() <<" : " << vectApreciation[noAppre]<<endl;
	}
}
