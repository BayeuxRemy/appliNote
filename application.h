#ifndef APPLICATION 
	#define APPLICATION
/**
* @file application.h
* @author BAYEUX Rémy
* @version 0.1
*/
#include "section.h"
#include "matiere.h"

class Section;
//Création d'une Clas Application dans un ficher externe .h
/**
* @class Application
* @brief classe instanciée une fois dans le main
* @brief une section est une class d'élèves avec ses propres matières et ses propres élèves
*  / une matière est un cours au quels les élèves participent selon leur section
*/
class Application
{
	private :
/**
* @brief vide au départ, il contient l'ensemble des sections ajouté par l'utilisateur
*/
	vector <Section> vectSection;
/**
* @brief vide au départ, il contient l'ensemble de toutes les matières ajouté par l'utilisateur
*/
	vector <Matiere> vectMatiere;
/**
* @brief permet d'afficher le menu principal de l'application
*/
	void afficherMenu1(); //méthode d'affichage du Menu
/**
* @brief permet à l'utilisateur de saisir son choix parmit les actions du menu principal
*/
	char saisieChoix(); //méthode de saisie du choix par l'utilisateur
/**
* @brief permet d'appelé la méthode du choix de l'action choisi par l'utilisateur
*/
	void actionChoix(char leChoix); // méthode de récuparation du choix

	//Section
/**
* @brief action qui permet à l'utilisateur d'ajouter une section
*/
	void ajouterSection(); // méthode d'ajout d'une Section
/**
* @brief action qui permet d'afficher toutes les sections à l'utilisateur
*/
	void afficherSection(); //méthode daffiche des Sections
/**
* @brief action qui permet de selectionner la section choisi afin d'acceder au menu secondaire de la section
*/
	Section * selectSection(); //méthode de selection d'une Section

	//Matiere
/**
* @brief action qui permet à l'utilisateur d'ajouter une matière
*/
	void ajouterMatiere(); // méthode d'ajout d'une Matiere


	//Quitter l'application 
/**
* @brief action qui permet à l'utilisateur de quitter l'application
*/
	void quitter();

	public :
/**
* @brief action qui permet d'afficher toutes les matières à l'utilisateur
*/
	void afficherMatiere(); //méthode daffiche des Matieres
/**
* @brief méthode présent dans le main qui permet au menu principal de l'application de tourner
*/
	void run();
/**
* @brief méthode qui permet de récupérer toutes les matières ajouter par l'utilisateur dans le menu secondaire de la section
*/
	vector <Matiere*> getLesMatieres();
};

#endif