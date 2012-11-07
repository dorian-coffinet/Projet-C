/* Implantation du module des étudiants */

/* Inclusion des bibliothèques standards */
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/* Inclusion des bibliothèques personnelles */
#include "list_etu.h"

ListeEtudiant list_etu_initialiser(){
	return NULL;
}

ListeEtudiant list_etu_ajouter(ListeEtudiant p, char nom[], char prenom[], char groupe){
	Etudiant *pnouv;
		
	pnouv=(Etudiant *) malloc(sizeof(Etudiant));
	strcpy(pnouv->cnom, nom);
	strcpy(pnouv->cprenom, prenom);
	pnouv->cgroupe=groupe;
	pnouv->suc=p;
		
	return(pnouv);
}

Etudiant *list_etu_rechercher(ListeEtudiant l,char nom[]){
	Etudiant *p;
			
	p=l;
	while((p != NULL)&&(strcmp(p->cnom,nom) != 0))
		p=p->suc;
			
	return(p);
}

void list_etu_afficher(Etudiant *p){
	printf("Groupe %c : %s %s \n", p->cgroupe, p->cprenom, p->cnom);
}

Etudiant *list_etu_supprimer(Etudiant *p, char nom[]){
	Etudiant *q, *r;

	r=p;
	q=NULL;

	while((r != NULL)&&(strcmp(r->cnom, nom) != 0)){
		q=r;
		r=r->suc;
	}

	if(r != NULL){
		if(q==NULL)
			p=r->suc;
		else
			q->suc=r->suc;
		free(r);
	}

	return(p);
}	

void list_etu_supprimer_totaleListe(Etudiant *p){
	Etudiant *q, *r;
	r=p;
	q=NULL;
	while((r != NULL)) {
		q=r;
		r= r->suc;
		free(q);
	}
}		
