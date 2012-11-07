/* Programme de test */

/* Inclusion des bibliothèques standards */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* Inclusion des bibliothèques personnelles */
#include "list_etu.h"
#include "annuaire.h"

#define MAX_TABLE 100				/* Taille de l'agenda (100 car index compris entre 0 et 99) */
#define MAX_FICHIER 300				/* Taille du fichier (arbitraire) */

int main(){
	int choix;
	FILE *fic;
	ListeEtudiant agenda[MAX_TABLE];
	char groupe[MAX_CHAINE], nom[MAX_CHAINE], prenom[MAX_CHAINE];
	char nomfichier[MAX_FICHIER];
	Etudiant *p;
	
	/* initialisation de l'annuaire */
	annuaire_initialiser(agenda, MAX_TABLE);
	
	/* chargement de la liste des étudiants */
	printf("+++ Chargement de la liste des étudiants +++\n");
	printf("Nom du fichier : ");
	scanf("%s", nomfichier);
	fic = fopen(nomfichier, "r");
	if(fic == NULL){
		printf("ouverture du fichier impossible...\n");
		exit(1);
	}

	annuaire_charger(agenda, fic);
	fclose(fic);

	/* affichage du menu */
	choix = -1;
	while(choix != 0){
		printf("Menu :\n");
		printf(" (0) Quitter  \n");
		printf(" (1) Rechercher \n");
		printf(" (2) Insertion d'un nouvel étudiant \n");
		printf(" (3) Suppression \n");
		printf(" (4) Affichage de la liste des étudiants \n");
		printf(" (5) Sauvegarde\n");
		
		scanf("%d", &choix);
		
		switch(choix){
		case 0:
			{
			printf("Programme fermé correctement");
			annuaire_quitter(agenda, MAX_TABLE);
					
			break;
			}
		case 1:
			{
			printf("Quel est le nom de l'étudiant à rechercher ?");
			scanf("%s", nom);
			
			p = annuaire_rechercher(agenda, nom);
			
			if(p != NULL)
				list_etu_afficher(p);
			else
				printf("%s n'est pas un étudiant \n", nom);
				
			break;
			}
		case 2:
			{
			printf("Quel est le nom de l'étudiant à insérer ?");
			scanf("%s", nom);
			printf("Quel est son prénom  ?");
			scanf("%s", prenom);
			printf("Quel est son groupe ?");
			scanf("%s", groupe);
			annuaire_ajouter(agenda, nom, prenom, toupper(groupe[0]));
			break;
			}
		case 3:
			{
			printf("Quel est le nom de l'étudiant à supprimer : ?");
			scanf("%s", nom);
			annuaire_supprimer(agenda, nom);
			break;
			}
		case 4:
			{
			annuaire_afficher(agenda, MAX_TABLE);
			break;
			}
		case 5:
			{
			printf("Sauvegarde de la liste des étudiants\n");
			printf("Nom du fichier : ");
			scanf("%s", nomfichier);
			fic = fopen(nomfichier, "w");
			if(fic == NULL){
				printf("Ouverture du fichier impossible...\n");
				exit(1);
			}
				
			annuaire_sauver(agenda, MAX_TABLE, fic);

			fclose(fic);
			break;
			}
		
		}	
				
	}
	return 0;
}	
	

