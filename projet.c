#include "projet.h"

Utilisateurs* creer_utilisateur(int id, char pseudo[50]) {
    Utilisateurs* nouvel_utilisateur = malloc(sizeof(Utilisateurs));

    if (nouvel_utilisateur == NULL) {
        return NULL;
    }

    nouvel_utilisateur->id = id;
    strcpy(nouvel_utilisateur->pseudo, pseudo);
    nouvel_utilisateur->ami_suivant = NULL;
    nouvel_utilisateur->premiere_publication = NULL;
    nouvel_utilisateur->utilisateur_suivant = NULL;

    return nouvel_utilisateur;
}

Publications* creer_message(char texte[100]) {
    Publications* nouveau_message = malloc(sizeof(Publications));

    if (nouveau_message == NULL) {
        return NULL;
    }

    strcpy(nouveau_message->message, texte);
    nouveau_message->publication_suivante = NULL;

    return nouveau_message;
}

void ajouter_utilisateur(Utilisateurs* premier_utilisateur, int id, char pseudo[50]) {
    if (premier_utilisateur == NULL) {
        return;
    }

    Utilisateurs* nouvel_utilisateur = creer_utilisateur(id, pseudo);
    if (nouvel_utilisateur == NULL) {
        return;
    }

    Utilisateurs* courant = premier_utilisateur;
    while (courant->utilisateur_suivant != NULL) {
        courant = courant->utilisateur_suivant;
    }

    courant->utilisateur_suivant = nouvel_utilisateur;
}

void ajouter_message(Publications* premier_message, char texte[100]) {
    if (premier_message == NULL) {
        return;
    }

    Publications* nouveau_message = creer_message(texte);
    if (nouveau_message == NULL) {
        return;
    }

    Publications* courant = premier_message;
    while (courant->publication_suivante != NULL) {
        courant = courant->publication_suivante;
    }

    courant->publication_suivante = nouveau_message;
}

void afficher_menu() {
    printf("\n=== Réseau Social ===\n");
    printf("1. Ajouter un utilisateur\n");
    printf("2. Afficher tous les utilisateurs\n");
    printf("3. Quitter\n");
}

void afficher_utilisateurs(Utilisateurs* utilisateurs) {
    if (utilisateurs == NULL) {
        printf("Aucun utilisateur enregistré.\n");
        return;
    }

    Utilisateurs* courant = utilisateurs;
    printf("\nListe des utilisateurs :\n");
    while (courant != NULL) {
        printf("ID: %d, Pseudo: %s\n", courant->id, courant->pseudo);
        courant = courant->utilisateur_suivant;
    }
}
