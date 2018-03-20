#include "application.h"
#include <cstdlib>

void Application::run()
{	
	char sonChoix;
	do {
		afficherMenu1();
		sonChoix=saisieChoix();
		actionChoix(sonChoix);
	   }
	while(sonChoix!='q');
}
void Application::afficherMenu1() 
{	
	cout <<endl<<"_______________________________________________________________";
	cout <<endl<<"_______________________Menu principal__________________________"<<endl<<endl;
	cout <<"Liste des commandes :"<<endl<<endl;
	cout <<"-------------------------AJOUTER-------------------------"<<endl<<endl;
	cout <<"  - 1 pour ajouter une Section"<<endl<<endl;
	cout <<"  - 2 pour ajouter une Matière"<<endl<<endl;
	cout <<"---------------------------------------------------------"<<endl<<endl;
	if (!(vectSection.size() == 0 and vectMatiere.size() == 0))
	{
		cout <<"-------------------------AFFICHER------------------------"<<endl<<endl;
		if (!(vectSection.size() == 0))
		{
			cout <<"  - 3 pour afficher les différentes Sections"<<endl<<endl;
		}
		if (!(vectMatiere.size() == 0))
		{
			cout <<"  - 4 pour afficher les différentes Matières"<<endl<<endl;
		}
	    cout <<"---------------------------------------------------------"<<endl<<endl;
		if (!(vectSection.size() == 0))
		{
			cout <<"-------------------------SELECTIONNER--------------------"<<endl<<endl;
			cout <<"  - 0 pour selectionner une Section"<<endl<<endl;
			cout << "---------------------------------------------------------"<<endl<<endl;
		}
		
	}
	cout <<"-------------------------QUITTER-------------------------"<<endl<<endl;
	cout <<"  - q pour Quitter l'application"<<endl<<endl;
	cout <<"---------------------------------------------------------"<<endl<<endl;
}
char Application::saisieChoix()
{
	char choix;
	do{
		cout << "Choisissez votre action : ";
		cin >> choix;
		cin.ignore(1); //je bouffe le "entrée" qu'il a tapé après! MIAM MIAM MIAM
		cout << endl; 
		if (!(choix=='1' || choix=='2' || choix=='3' || choix=='4'|| choix=='0' || choix=='q'))
		{
		system("clear");
		cout<<"!!!!Vous n'avez pas rentré une commande valable, veuillez réessayer!!!!"<< endl;
		afficherMenu1();
		}
	}
	while (!(choix=='1' || choix=='2' || choix=='3' || choix=='4'|| choix=='0' || choix=='q'));

	return choix;
}
void Application::actionChoix(char leChoix)
{
	Section * sectionChoisie;
	switch(leChoix)
	{
		case '1': system("clear"); 
			 cout << "-----Vous avez choisi l'action d'ajout d'une Section-----"<<endl<<endl;
			ajouterSection();
			break;

		case '2':  system("clear");
		 	cout << "-----Vous avez choisi l'action d'ajout d'une Matière-----"<<endl<<endl;
			ajouterMatiere();
			break;

		case '3': system("clear");
			 cout << "----Vous avez choisi l'action d'affichage des Sections---"<<endl<<endl;
			afficherSection();
			break;

		case '4': system("clear");
		 	cout << "----Vous avez choisi l'action d'affichage des Matières---"<<endl<<endl;
			afficherMatiere();
			break;

		case '0': system("clear");
		 	 cout << "---Vous avez choisi l'action de selection d'une Section--"<<endl<<endl;
		     sectionChoisie=selectSection();
		     if(sectionChoisie!=NULL)
		     {
		     	sectionChoisie->run();
		     }
		break;

		case 'q': system("clear"); quitter(); system("clear"); 
			break;
		}
}
void Application::ajouterSection()
{
	Section sectionAAjouter(this);
	sectionAAjouter.input();
	vectSection.push_back(sectionAAjouter);
}	
void Application::afficherSection()
{	
	unsigned int nbSection=vectSection.size(); 
	for (unsigned int noSection=0; noSection<nbSection;noSection++) 
	{
		cout <<noSection+1;
		vectSection[noSection].display();
	}
	if (nbSection==0) 
	{
		cout<<"!!! Il n'y à pas de section(s) enregistrée(s) !!!"<<endl;
	}
}
void Application::ajouterMatiere()
{
	Matiere matiereAAjouter;
	matiereAAjouter.input();
	vectMatiere.push_back(matiereAAjouter);
}
void Application::afficherMatiere()
{
	unsigned int nbMatiere=vectMatiere.size(); 
	for (unsigned int noMatiere=0; noMatiere<nbMatiere;noMatiere++) 
	{
		cout <<noMatiere+1;
		vectMatiere[noMatiere].display();
	}
	if (nbMatiere==0) 
	{
		cout<<"!!! Il n'y à pas de matière(s) enregistrée(s) !!!"<<endl;
	}
}
void Application::quitter()
{
	cout << "Êtes vous sûr(e) de vouloir quitter l'application? (y/n)"<<endl;
	char quitter;
			cin >> quitter;
			cin.ignore(1);
			if (quitter=='n') 
			{
				run();
			}	
}
// Afficher les sections avec un numéro, saisie controlé et renvoie la section choisi
Section * Application::selectSection ()
{
	unsigned int nbSection = vectSection.size();
	if (nbSection > 0)
	{
		Section * sectionChoisie;
		afficherSection();
		cout << "\nEntrez le numéro de la section que vous souhaitez : ";
		unsigned int choixSection;
		cin >> choixSection;
		choixSection--;
		//si c'est un numero OK
		if(choixSection<nbSection)
		{
			sectionChoisie = &vectSection[choixSection];
			return sectionChoisie;
		}
		else 
		{	
			cout << "!!!!! Erreur ! Vous n'avez pas choisi le bon numéro !!!!!";
			return NULL;
		}
				
	}
	else 
	{ 
		cout << "!!!!! Erreur ! Il n'y pas encore de Section, veuillez ajouter une Section !!!!!";
		return NULL;
	}

}
vector <Matiere*> Application::getLesMatieres()
{
	vector <Matiere*> resultat;
	for (unsigned int noMatiere=0; noMatiere<vectMatiere.size();noMatiere++) 
	{
		resultat.push_back(&vectMatiere[noMatiere]);
	}
	return resultat;
}