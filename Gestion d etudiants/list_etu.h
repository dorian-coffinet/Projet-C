/* En-tête du module des étudiants */

#ifndef LIST_ETU_H_INCLUS			/* Teste si LIST_ETU_H_INCLUS n'est pas définie */
#define LIST_ETU_H_INCLUS			/* Dans ce cas définition de LIST_ETU_H_INCLUS */

#define MAX_CHAINE 30

/* Définition du type Etudiant */
typedef struct Enregistrement{
	char cnom[MAX_CHAINE];
	char cprenom[MAX_CHAINE];
	char cgroupe;
	struct Enregistrement *suc;
} Etudiant;

/* Définition du type ListeEtudiant, qui est un pointeur sur Etudiant */
typedef Etudiant *ListeEtudiant;

/* Initialisation à NULL de la liste d'étudiants */
ListeEtudiant list_etu_initialiser();

/* Affichage d'un étudiant */
void list_etu_afficher(Etudiant *p);

/* Ajout d'un étudiant en tête de liste */
ListeEtudiant list_etu_ajouter(ListeEtudiant l, char nom[], char prenom[], char groupe);

/* Recherche de nom dans la liste d'étudiants l. La fonction renvoie un pointeur sur l'étudiant cherché s'il existe et NULL sinon */
Etudiant *list_etu_rechercher(ListeEtudiant l,char nom[]);

/* Suppression de nom */
Etudiant *list_etu_supprimer(Etudiant *p, char nom[]);

/* Suppression de la liste dont p est le premier élément */
void list_etu_supprimer_totaleListe(Etudiant *p);

#endif						/* Fin de si (c'est-à-dire de #ifndef) */
