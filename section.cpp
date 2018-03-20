#include "section.h"
#include "evaluation.h"
#include "bulletin.h" // Relier la class Section externe à ce fichier (entre "" pour les fichier écrit par moi-même)
#include <algorithm>
#include <cstdlib>
// Codage des méthode présent dans la Class
Section::Section(Application * lApplic)
{
	monApplic=lApplic;
}
void Section::run() 
{
	char sonChoix;
	do {
		afficherMenu2();
		sonChoix=saisieChoix();
		actionChoix(sonChoix);
	}while(sonChoix!='r');
}
void Section::afficherMenu2()
{	cout <<endl<<"___"<<libelleSection<<"____________________________________________________";
	cout <<endl<<"_______________________Menu secondaire_____________________"<<endl<<endl;
	cout <<"Liste des commandes :"<<endl<<endl;
	cout <<"-------------------------AJOUTER-------------------------"<<endl<<endl;
	cout <<"  - 1 pour ajouter un Etudiant"<<endl<<endl;
	if (!(vectMatiereDeLaSection.size() == 0 || vectEtudiant.size() == 0))
	{
		cout <<"  - 2 pour ajouter une Contrôle"<<endl<<endl;
	}
	if (!(vectMatiereDeLaSection.size() == 0 || vectEtudiant.size() == 0 ))
	{
		cout <<"  - 3 pour ajouter un Bulletin"<<endl<<endl;
	}
	cout << "---------------------------------------------------------"<<endl<<endl;
	vector <Matiere*> vectToutesLesMatieres=monApplic->getLesMatieres();
	if (!(vectToutesLesMatieres.size()==0))
	{
		cout <<"-------------------------AFFECTER------------------------"<<endl<<endl;
		cout <<"  - 4 pour affecter une Matière à la Section"<<endl<<endl;
	}
	cout << "---------------------------------------------------------"<<endl<<endl;
	if (!(vectEtudiant.size() == 0 and vectEval.size() == 0 and vectMatiereDeLaSection.size() == 0))
	{
		cout <<"-------------------------AFFICHER------------------------"<<endl<<endl;
		if (!(vectEtudiant.size() == 0 ))
		{
			cout <<"  - 5  pour afficher les différents Etudiants"<<endl<<endl;
		}
		if (!(vectEval.size() == 0))
		{
			cout <<"  - 6 pour afficher les différents Contrôles"<<endl<<endl;
		}
		if (!(vectMatiereDeLaSection.size() == 0))
		{
		cout <<"  - 7 pour afficher les différentes Matières de la Section"<<endl<<endl;
		}
		if (!(vectBulletinDeLaSection.size() == 0))
		{
		cout <<"  - 8 pour afficher Bulletin d'un élève"<<endl<<endl;
		}
		cout << "---------------------------------------------------------"<<endl<<endl;
	}
	cout <<"-------------------------RETOUR--------------------------"<<endl<<endl;
	cout <<"  - r pour Retour au menu principal"<<endl<<endl;
	cout <<"---------------------------------------------------------"<<endl<<endl;
}
char Section::saisieChoix()
{
	char choix;
	do{
		cout << "Choisissez votre action : ";
		cin >> choix;
		cin.ignore(1); //je bouffe le "entrée" qu'il a tapé après! MIAM MIAM MIAM
		cout << endl; 
		if (!(choix=='1' || choix=='2' || choix=='3' || choix=='4'|| choix=='5' || choix=='6'|| choix=='7' || choix=='8' || choix=='r'))
		{
		system("clear");
		cout<< "!!!!! Erreur ! Vous n'avez pas rentré une commande valable, veuillez réessayer !!!!!"<< endl << endl;
		afficherMenu2();
		}
	}
	while (!(choix=='1' || choix=='2' || choix=='3' || choix=='4'|| choix=='5' || choix=='6'|| choix=='7' || choix=='8' || choix=='r'));

	return choix;
}
void Section::actionChoix(char leChoix)
{
	switch(leChoix)
	{
		case '1': system("clear");
			 cout << "-----Vous avez choisi l'action d'ajout d'un Etudiant-----"<<endl<<endl;
			ajouterEtudiant();
			break;

		case '2': system("clear");
			cout << "-----Vous avez choisi l'action d'ajout d'un Contrôle-----"<<endl<<endl;
			ajouterEval();
			break;

		case '3': system("clear");
			cout << "-----Vous avez choisi l'action d'ajout d'un Bulletin-----"<<endl<<endl;
			ajouterBulletin();
			break;

		case '4': system("clear");
			 cout << "--Vous avez choisi l'action d'effectation d'une Matière--"<<endl<<endl;
			ajouterMatiere();
			break;

		case '5': system("clear"); 
			cout << "---Vous avez choisi l'action d'affichage des Etudiants---"<<endl<<endl;
			afficherEtudiant();
			break;

		case '6': system("clear");
			cout << "---Vous avez choisi l'action d'affichage des Contrôles---"<<endl<<endl;
			afficherEval();
		    break;

		case '7': system("clear"); 
			 cout << "----Vous avez choisi l'action d'affichage des Matières---"<<endl<<endl;
			afficherMatiere();
		    break;
		case '8': system("clear");
			 cout << "----Vous avez choisi l'action d'affichage d'un bulletin---"<<endl<<endl;
			afficherBulletin();
		    break;
		case 'r': system("clear");
		
		    break;
		}
}
void Section::ajouterEtudiant()
{
	Etudiant etudiantAAjouter;
	etudiantAAjouter.input();
	vectEtudiant.push_back(etudiantAAjouter);
}
void Section::afficherEtudiant()
{	
	 unsigned int nbEtudiant=vectEtudiant.size(); 
	for (unsigned int noEtudiant=0; noEtudiant<nbEtudiant;noEtudiant++) 
	{
		cout <<noEtudiant+1;
		vectEtudiant[noEtudiant].display();
	}
	if (nbEtudiant==0) 
	{
		cout<<"!!! Il n'y à pas d'étudiant(s) enregistré(s) dans cette section !!!"<<endl;
	}
}

void Section::ajouterEval()
{
	Evaluation evalAAjouter(this);
	evalAAjouter.input();
	vectEval.push_back(evalAAjouter);
}

void Section::afficherEval()
{	
	unsigned int nbEval = vectEval.size();
	if (nbEval==0) 
	{
		cout<<"!!! Il n'y à pas d'évalutation(s) enregistrée(s) dans cette section !!!"<<endl;
	}
	else 
	{
		unsigned int choixEval;
		for(unsigned int noEval=0;noEval<nbEval;noEval++)
		{
			cout << noEval+1 << "- " << vectEval[noEval].getRefEval() << " du "<< vectEval[noEval].getSemestreEval() << "e semestre" << endl;
		}
		cout << "\nSaisir le numéro de l'évaluation que vous souhaitez voir : ";
		cin >> choixEval;
		choixEval--;
		if(choixEval<vectEval.size())
		{
				vectEval[choixEval].display();
		}
		else 
		{	
			cout << "!!!!! Erreur ! Vous n'avez pas choisi le bon numéro !!!!!";
		}
	}
}


void Section::ajouterMatiere()
{
	int coeff;
	//on demande la liste de toutes les matières à l'application
	vector <Matiere*> vectToutesLesMatieres=monApplic->getLesMatieres();
	if (vectToutesLesMatieres.size()==0)
	{
		cout << "Vous n'avez pas ajouter de matière, veuillez retourner au menu principale (r) pour en y ajouter !";
	}
	else 
	{
		//on construit un vecteur des matières pouvant être ajoutées
		vector <Matiere*> vectLesMatieresPossibles;
		for(unsigned int noMat=0;noMat<vectToutesLesMatieres.size();noMat++)
		{
			 vector<Matiere*>::iterator itMat;
			 //recherche de la matiere dans le vecteur des matieres de la section pour voir si elle n'y est pas déjà
			 itMat = find (vectMatiereDeLaSection.begin(), vectMatiereDeLaSection.end(), vectToutesLesMatieres[noMat]);
			 //si on ne l'a pas trouvee l'itérateur est à la fin du vecteur
 			 if (itMat == vectMatiereDeLaSection.end())
			{
				//alors on ajoute la matiere aux matières possibles pour la section
				vectLesMatieresPossibles.push_back(vectToutesLesMatieres[noMat]);
			}
		}
		if (vectLesMatieresPossibles.size()==0)
		{
			cout << "Vous avez ajouter toutes les matières possibles, veuillez retourner au menu principale (r) pour en rajouter !";
		}
		else 
		{
			Matiere * matiereChoisie;
			unsigned int choixMatiere;
			for(unsigned int noMat=0;noMat<vectLesMatieresPossibles.size();noMat++)
			{
				cout << noMat+1 << "- " << vectLesMatieresPossibles[noMat]->getLibelleMatiere() << endl;
			}
			cout << "\nSaisir le numéro de la matière que vous souhaitez affecter à la section : ";
			cin >> choixMatiere;
			choixMatiere--;
			if(choixMatiere<vectLesMatieresPossibles.size())
				{
					matiereChoisie = vectLesMatieresPossibles[choixMatiere];
					cout << "Saisir le coefficient de la matière choisie : ";
					cin >> coeff;
					vectMatiereDeLaSection.push_back(matiereChoisie);
					vectCoeff.push_back(coeff);
				}
				else 
				{	
				cout << "!!!!! Erreur ! Vous n'avez pas choisi le bon numéro !!!!!";
				}
		}
	}
}

void Section::afficherMatiere() 
{
	for(unsigned int noMat=0;noMat<vectMatiereDeLaSection.size();noMat++)
	{
		cout << noMat+1 << ") " << vectMatiereDeLaSection[noMat]->getLibelleMatiere()<< " (coeff "<<vectCoeff[noMat]<<")"<<endl;
	}
	if (vectMatiereDeLaSection.size()==0) 
	{
		cout<<"!!! Il n'y à pas d'étudiant(s) enregistré(s) dans cette section !!!"<<endl;
	}
}

vector <Matiere*> Section::getLesMatieresDeLaSection()
{
	vector <Matiere*> resultat;
	for (unsigned int noMatiere=0; noMatiere<vectMatiereDeLaSection.size();noMatiere++) 
	{
		resultat.push_back(vectMatiereDeLaSection[noMatiere]);
	}
	return resultat;
}


vector <Etudiant*> Section::getLesEtudiantsDeLaSection() 
{
	vector <Etudiant*> resultat;
	for (unsigned int noEtudiant=0; noEtudiant<vectEtudiant.size();noEtudiant++) 
	{
		resultat.push_back(&vectEtudiant[noEtudiant]);
	}
	return resultat;
}

void Section::ajouterBulletin()
{	
	cout << "De quel étudiant souhaitez vous ajouter un bulletin : "<<endl<<endl;
	for (unsigned int noEtudiant=0; noEtudiant<vectEtudiant.size();noEtudiant++) 
	{
		cout << noEtudiant+1 <<"- "<< vectEtudiant[noEtudiant].getNom() << " " << vectEtudiant[noEtudiant].getPrenom() << endl;
	}
	unsigned int choixEtudiant;
	cout <<endl<< "Entrez le numéro de l'étudiant : ";
	cin >> choixEtudiant;
	choixEtudiant--;
	cin.ignore(1);
	Bulletin bulletinAAjouter(this, &vectEtudiant[choixEtudiant]);
	bulletinAAjouter.input();
	vectBulletinDeLaSection.push_back(bulletinAAjouter);
}
void Section::afficherBulletin()
{
	cout << "De quel étudiant souhaitez vous afficher son bulletin : "<<endl<<endl;
	for (unsigned int noEtudiant=0; noEtudiant<vectEtudiant.size();noEtudiant++) 
	{
		cout << noEtudiant+1 <<"- "<< vectEtudiant[noEtudiant].getNom() << " " << vectEtudiant[noEtudiant].getPrenom() << endl;
	}
	unsigned int choixEtudiant;
	cout <<endl<<"Entrez le numéro de l'étudiant : ";
	cin >> choixEtudiant;
	choixEtudiant--;
	cout << endl << endl << "Bulletin de " << vectEtudiant[choixEtudiant].getNom() << " " << vectEtudiant[choixEtudiant].getPrenom()  << endl <<endl;;
	cin.ignore(1);
	vectBulletinDeLaSection[choixEtudiant].display();
}

string Section::getLibelleSection()
{
	return libelleSection;
}

void Section::setLibelleSection(string thisSection)
{
	libelleSection = thisSection;
}

void Section::display()
{
	cout << "- " << libelleSection << endl;
	
}

void Section::input()
{ 	
	cout << "\nSaisir le libelle de la section que vous souhaitez ajouter : " ;
	getline(cin,libelleSection); //getline pour les strings
}
