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

void ajouter_publication(Utilisateurs* utilisateurs, int id) {
    if (utilisateurs == NULL) {
        return;
    }

    Utilisateurs* courant = utilisateurs;
    while (courant->id != id) {
        courant = courant->utilisateur_suivant;
    }

    char texte[100];
    printf("Entrez votre publication (max 100 char) :\n");
    fgets(texte, 100, stdin);

    if (courant->premiere_publication == NULL) {
        courant->premiere_publication = creer_message(texte);
    }
    else {
        ajouter_message(courant->premiere_publication, texte);
    }
}

void afficher_utilisateurs(Utilisateurs* utilisateurs) {
    if (utilisateurs == NULL) {
        return;
    }

    Utilisateurs* courant = utilisateurs;
    printf("\nListe des utilisateurs :\n");
    while (courant != NULL) {
        printf("ID: %d, Pseudo: %s\n", courant->id, courant->pseudo);
        courant = courant->utilisateur_suivant;
    }
}

void afficher_info(Utilisateurs* utilisateurs, int id) {
    if (utilisateurs == NULL) {
        return;
    }

    Utilisateurs* courant = utilisateurs;
    while (courant->id != id) {
        courant = courant->utilisateur_suivant;
    }

    printf("Amis de %s :\n", courant->pseudo);
    while (courant->ami_suivant != NULL) {
        Utilisateurs* actuel = courant->ami_suivant;
        printf(" - ID: %d, Pseudo: %s\n", actuel->id, actuel->pseudo);
        
    }

}


void afficher_menu() {
    printf("\n=== Reseau Social ===\n");
    printf("1. Ajouter un utilisateur\n");
    printf("2. Ajouter un ami\n");
    printf("3. Ajouter une publication\n");
    printf("4. Afficher tous les utilisateurs\n");
    printf("5. Afficher les informations d'un utilisateur\n");
    printf("6. Quitter\n");
}