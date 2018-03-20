#include "etudiant.h"


string Etudiant::getNom() 
{
	return nom;
}

string Etudiant::getPrenom() 
{
	return prenom;
}


string Etudiant::getDateNaissance() 
{
	return dateNaissance;
}

int Etudiant::getNbAbsence()
{
	return nbAbsence;
}

void Etudiant::setNom(string thisNom)
{
	thisNom = nom;
}
void Etudiant::setPrenom(string thisPrenom)
{
	thisPrenom = prenom;
}
void Etudiant::setOld(string thisDateNaissance)
{
	thisDateNaissance = dateNaissance;
}
void Etudiant::setNbAbsence(int thisNbAbsence)
{
	nbAbsence = thisNbAbsence;
}
void Etudiant::display()
{
	cout << ") " << nom <<" "<< prenom <<" né(e) le "<< dateNaissance << endl << "Il à "<<nbAbsence<<" absence(s)"<<endl;
	
}

void Etudiant::input()
{ 	cout << "vous souhaitez ajouter un étudiant : ";
	cout <<endl<<"\nSaisir le nom : "; 
	getline(cin,nom); //getline pour les strings
	cout <<"\nSaisir le prénom : ";
	getline(cin,prenom);
	cout <<"\nSaisir sa date de naissance \"JJ/MM/AAAA\" : ";
	getline(cin,dateNaissance);
}
