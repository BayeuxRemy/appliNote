#ifndef SECTION 
	#define SECTION
/**
* @file section.h
* @author BAYEUX Rémy
* @version 0.1
*/
#include "application.h"
#include "etudiant.h"
#include "evaluation.h"
#include "matiere.h"
class Application; //déclaration courte
//Création d'une Clas dans un ficher externe .h
/** @class Section
* @brief classe dont il peux exister plusieur instance dans l'application
* @brief une section est une class d'élèves avec ses propres matières et ses propres élèves
*  / une évalutation est un contrôle au quels les élèves ont participés dans un cours 
*  / un coefficient est un multiplacteur de la note qui dépend de chaques matières
*/
class Section
{
	private :
    // Les proritétés
/** 
* @brief contient ce qu'a entré l'utilisateur lors de l'ajout d'une section et conrrespond au libelle de la section
*/
	string libelleSection;
/**
* @brief permet de relier l'instance de cette section a l'application
*/
	Application * monApplic;
/**
* @brief vide au départ, il contient l'ensemble des coefficient des différents matières qui varie selon la section
*/
	vector <int> vectCoeff;
/**
* @brief vide au départ, il contient l'ensemble des étudiants de la section, ajouter par l'utilisateur
*/
	vector <Etudiant> vectEtudiant;
/**
* @brief vide au départ, il contient l'ensemble des écaluations fait dans la section, ajouter par l'utilisateur
*/
	vector <Evaluation> vectEval;
/**
* @brief vide au départ, il contient l'ensemble des matière propre à cette section, affecter par l'utilisateur
*/
	vector <Matiere *> vectMatiereDeLaSection;
/**
* @brief vide au départ, il contient l'ensemble des bulletins propre à cette section, entré par l'utilisateur
*/
	vector <Bulletin> vectBulletinDeLaSection;
	//********MENU*************
/**
* @brief permet à l'utilisateur de saisir son choix parmit les actions du menu secondaire 
*/
	char saisieChoix(); //méthode de saisie du choix par l'utilisateur
/**
* @brief permet d'appelé la méthode du choix de l'action choisi par l'utilisateur
*/
	void actionChoix(char leChoix); // méthode de récuparation du choix
	//Etudiant
/**
* @brief action qui permet à l'utilisateur d'ajouter un étudiant dans cette section
*/
	void ajouterEtudiant(); // méthode d'ajout d'une Etudiant
/**
* @brief action qui permet d'afficher les élèves de cette section à l'utilisateur
*/
	void afficherEtudiant(); //méthode daffiche des Etudiants

	//Matiere
/**
* @brief action qui permet à l'utilisateur d'affecter dans cette section une, matière existante dans l'application
*/	
	void ajouterMatiere();
/**
* @brief action qui permet d'afficher les matières propre à cette section à l'utilisateur
*/
	void afficherMatiere(); //méthode daffiche des Matieres

	//Evaluation
/**
* @brief action qui permet à l'utilisateur d'ajouter une évaluation dans cette section
*/
	void ajouterEval(); // méthode d'ajout d'une Evaluation
/**
* @brief action qui permet d'afficher les évaluations de cette section à l'utilisateur
*/
	void afficherEval(); //méthode daffiche des Evaluations
/**
* @brief action qui permet d'afficher les bulletins celon l'élève choisie par l'utilisateur
*/
	void afficherBulletin();
/**
**
* @brief action qui permet d'ajouter un bulletin celon l'élève choisie par l'utilisateur
*/
	void ajouterBulletin();
/**
* @brief action qui permet à l'utilisateur de retourner au menu principal
*/
	void retour();

	public : 
/**
* @brief méthode présent dans l'action du choix du menu princpal qui permet d'appeler et faire tourner le menu secondaire de l'application
*/
	void run();
/**
* @brief permet d'afficher le menu secondaire de l'application
*/
	void afficherMenu2();
	// Les méthodes
/**
* @brief methode de getteur qui permet d'aller rechercher la valeur saisie par l'utilisateur lors de la saisi du libelle de la section
*/
	string getLibelleSection();
/**
* @brief methode de getteur qui permet d'aller rechercher la valeur saisie par l'utilisateur lors de la saisi du coefficient de la matière
*/
	int getCoeff();
/**
* @brief methode de setteur qui permet de modifier la valeur saisie par l'utilisateur pour le libelle de la section
*/
	void setLibelleSection(string thisSection);
/**
* @brief methode de setteur qui permet de modifier la valeur saisie par l'utilisateur pour le ceofficient de la matière
*/
	void setCoeff(int thisCoeff);
/**
* @brief methode d'affichage d'une section appelé dans le menu principal
*/
	void display(); // méthode d'affichage
/**
* @brief methode de saisie d'une section appelé dans le menu principal
*/
	void input();  // méthode de saisie par l'utilisateur
/**
* @brief méthode qui permet de récupérer toutes les matières propre à cette section
*/
	vector <Matiere*> getLesMatieresDeLaSection();
/**
* @brief méthode qui permet de récupérer tous les étudiants présent dans cette section
*/
	vector <Etudiant*> getLesEtudiantsDeLaSection();
/**
* @brief constructeur qui permet de relier l'instance de cette section a l'application
*/
	Section(Application*);

}; 

#endif