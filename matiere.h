#ifndef MATIERE 
	#define MATIERE
/**
* @file matiere.h
* @author BAYEUX Rémy
* @version 0.1
*/
#include <vector>
#include <iostream>
using namespace std;

//Création d'une Clas dans un ficher externe .h
/** @class Matiere
* @brief classe dont il peux exister plusieur instance dans l'application
* @brief une matière est un cours au quels les élèves participent selon leur section (ex: Mathématique) 
*/
class Matiere
{
	private :
    // Les proritétés 
 /** 
* @brief contient ce qu'a entré l'utilisateur lors de l'ajout d'une matière et conrrespond au libelle de la matière
*/
	string libelleMatiere;

	public :
	// Les méthodes
/**
* @brief methode de getteur qui permet d'aller rechercher la valeur saisie par l'utilisateur lors de la saisi du libelle de la matière
*/
	string getLibelleMatiere();
/**
* @brief methode de setteur qui permet de modifier la valeur saisie par l'utilisateur pour le libelle de la matière
*/
	void setLibelleMatiere(string thisMatiere);
/**
* @brief methode d'affichage d'une matière appelé dans le menu principal
*/
	void display(); // méthode d'affichage
/**
* @brief methode de saisie d'une section appelé dans le menu principal
*/
	void input();  // méthode de saisie par l'utilisateur
}; 

#endif