/* En-tête du module d'annuaire */

#ifndef ANNUAIRE_H_INCLUS			/* Teste si ANNUAIRE_H_INCLUS n'est pas définie */
#define ANNUAIRE_H_INCLUS			/* Dans ce cas définition de ANNUAIRE_H_INCLUS */

#include "list_etu.h"

/* Initialisation : inscription de NULL dans les taille cases du tableau agenda */
void annuaire_initialiser(ListeEtudiant agenda[], int taille);

/* Ajout d'un nouvel étudiant à l'agenda */
void annuaire_ajouter(ListeEtudiant agenda[], char nom[], char prenom[], char groupe);

/* Suppression de nom dans agenda */
void annuaire_supprimer(ListeEtudiant agenda[], char nom[]);

/* Recherche de nom dans agenda. La fonction renvoie un pointeur sur cet enregistrement s'il existe et NULL sinon */
Etudiant *annuaire_rechercher(ListeEtudiant agenda[], char nom[]);

/* Affichage de l'agenda */
void annuaire_afficher(ListeEtudiant agenda[], int taille);

/* Chargement du fichier étudiant dans agenda en utilisant la fonction annuaire_ajouter */
void annuaire_charger(ListeEtudiant agenda[], FILE *fic);

/* Sauvegarde l'agenda dans un fichier texte */
void annuaire_sauver(ListeEtudiant agenda[], int taille, FILE *fic);

/* Associe à chaque clé(le nom) un index compris entre 0 et 99. L'index correspond à la somme des codes ASCII des lettres du nom de famille modulo 100 */
int fonction_hachage(char nom[]);

/* Permet la suppression de tous les éléments de agenda afin qu'à la fermeture de l'éxecutable, toutes les allocations de mémoire soient restituées au système */
void annuaire_quitter(ListeEtudiant agenda[], int taille);

#endif						/* Fin de si (c'est-à-dire de #ifndef) */
