#ifndef ETUDIANT 
	#define ETUDIANT
/**
* @file etudiant.h
* @author BAYEUX Rémy
* @version 0.1
*/
#include "bulletin.h"

//Création d'une Clas dans un ficher externe .h
/** @class Etudiant
* @brief classe dont il peux exister plusieur instance dans la section
* @brief un élève est une personne, un élève qui fait partie d'une section et participe à plusieurs matières
* / nbAbsance est le nombre d'absence d'un élève selon les evaluation qu'il à loupé
*/
class Evaluation;
class Etudiant
{
	private :
    // Les proritétés
/** 
* @brief contient ce qu'a entré l'utilisateur lors de l'ajout d'un étudiant et conrrespond au nom de famille de l'étudiant
*/    
	string nom;
/** 
* @brief contient ce qu'a entré l'utilisateur lors de l'ajout d'un étudiant et conrrespond au prénom de l'étudiant
*/ 
	string prenom;
/** 
* @brief contient ce qu'a entré l'utilisateur lors de l'ajout d'un étudiant et conrrespond a la date de naissance (JJ/MM/AAA) de l'étudiant
*/ 
	string dateNaissance;
/** 
* @brief contient le nombre d'absence de l'étudiant selon les évaluation loupé, saisie par l'utilisateurs lors d'un ajout d'une évaluation
*/ 
	int nbAbsence;
/**
* @brief vide au départ, il contient les deux bulletin de l'étudiant de l'année (1 par semestre), qui varie selon l'étudiant
*/
	Bulletin * sonBulletin;

	public :
	// Les méthodes
/**
* @brief methode de getteur qui permet d'aller rechercher la valeur saisie par l'utilisateur lors de la saisi du nom de l'étudiant
*/
	string getNom();
/**
* @brief methode de getteur qui permet d'aller rechercher la valeur saisie par l'utilisateur lors de la saisi du prénom de l'étudiant
*/
	string getPrenom();
/**
* @brief methode de getteur qui permet d'aller rechercher la valeur saisie par l'utilisateur lors de la saisi de la date de naissance de l'étudiant
*/
	string getDateNaissance();
/**
* @brief methode de getteur qui permet d'aller rechercher la valeur saisie par l'utilisateur lors de la saisi d'un évaluation que l'étudiant a loupé
*/
	int getNbAbsence();
/**
* @brief methode de setteur qui permet de modifier la valeur saisie par l'utilisateur pour le nom de l'étudiant
*/
	void setNom(string thisNom);
/**
* @brief methode de setteur qui permet de modifier la valeur saisie par l'utilisateur pour le prénom de l'étudiant
*/
	void setPrenom(string thisPrenom);
/**
* @brief methode de setteur qui permet de modifier la valeur saisie par l'utilisateur pour la date de naissance de l'étudiant
*/
	void setOld(string thisDateNaissance);
/**
* @brief methode de setteur qui permet de modifier la valeur des absences de l'étudiant
*/
	void setNbAbsence(int thisNbAbsebce);
/**
* @brief methode d'affichage d'un étudiant appelé dans le menu secondaire
*/
	void display(); // méthode d'affichage
/**
* @brief methode de saisie d'un étudiant appelé dans le menu secondaire
*/
	void input();  // méthode de saisie par l'utilisateur
};

#endif