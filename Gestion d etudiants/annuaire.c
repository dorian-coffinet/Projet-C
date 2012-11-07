/* Implantation du module d'annuaire */

/* Inclusion des bibliothèques standards */
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

/* Inclusion des bibliothèques personnelles */
#include "list_etu.h"
#include "annuaire.h"

int fonction_hachage(char nom[]){
	int i;
	int long_nom;
	int somme_ASCII=0;
	
	long_nom=strlen(nom);
	for(i=0;i<long_nom;i++){
		somme_ASCII=somme_ASCII+(int)nom[i];
	}

	return(somme_ASCII%100);
}
		

void annuaire_initialiser(ListeEtudiant agenda[], int taille){
	int i;
	
	for(i=0;i<taille;i++)
		agenda[i]=list_etu_initialiser();
}		

void annuaire_ajouter(ListeEtudiant agenda[], char nom[], char prenom[], char groupe){
	int rang;
	rang=fonction_hachage(nom);
	agenda[rang]=list_etu_ajouter(agenda[rang], nom, prenom, groupe);
}

void annuaire_supprimer(ListeEtudiant agenda[], char nom[]){
	int rang;
	rang=fonction_hachage(nom);
	agenda[rang]=list_etu_supprimer(agenda[rang], nom);
}

Etudiant *annuaire_rechercher(ListeEtudiant agenda[], char nom[]){
	int rang;
	Etudiant *p;
	rang=fonction_hachage(nom);
	p=list_etu_rechercher(agenda[rang], nom);
	
	return(p);
}
void annuaire_afficher(ListeEtudiant agenda[], int taille){
	int rang;
	Etudiant *p;
	
	for(rang=0;rang<taille;rang++){
		printf("%d : \n", rang);
		for(p=agenda[rang];p != NULL; p=p->suc)
			list_etu_afficher(p);
	}
}
	
void annuaire_charger(ListeEtudiant agenda[], FILE *fic){
	char groupe, nom[MAX_CHAINE], prenom[MAX_CHAINE];
	
	while((fscanf(fic,"%c %s %s \n", &groupe, nom, prenom) != EOF))
		annuaire_ajouter(agenda, nom, prenom, groupe);
}
		
void annuaire_sauver(ListeEtudiant agenda[], int taille, FILE *fic){
	int i;
	Etudiant *p;
	
	for(i=0;i<taille;i++){
		for(p=agenda[i];p != NULL;p=p->suc)
			fprintf(fic,"%c %s %s \n",p->cgroupe, p->cnom, p->cprenom);
	}		
}
void annuaire_quitter(ListeEtudiant agenda[], int taille){
	int rang;
	for(rang=0;rang<taille;rang++){
		list_etu_supprimer_totaleListe(agenda[rang]);
	}	
}	
				
