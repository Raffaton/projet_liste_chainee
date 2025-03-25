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

int verifier_id(Utilisateurs* utilisateurs, int id) {
    if (utilisateurs == NULL) {
        return 1;
    }
    else {
        Utilisateurs* courant = utilisateurs;
        while (courant != NULL) {
            if (courant->id == id) {
                printf("\nCet ID a deja ete utilise, reessayez avec une autre\n");
                return 0;
            }
            courant = courant->utilisateur_suivant;
        }
    }

    return 1;
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

void ajouter_ami(Utilisateurs* utilisateurs, int id) {
    if (utilisateurs == NULL) {
        return;
    }

    Utilisateurs* courant = utilisateurs;
    while (courant != NULL && courant->id != id) {
        courant = courant->utilisateur_suivant;
    }
    if (courant == NULL) {
        printf("Utilisateur (ID %d) non trouve !\n", id);
        return;
    }

    int choix;
    afficher_utilisateurs(utilisateurs);
    printf("Quel est l'ID d'utilisateur que voulez vous ajouter en ami (pas vous): ");
    scanf("%d", &choix);
    getchar();

    if (choix == id) {
        printf("\nVous ne pouvez pas vous ajouter vous-meme.\n");
        return;
    }

    Utilisateurs* courant_a_ajouter = utilisateurs;
    while (courant_a_ajouter != NULL && courant_a_ajouter->id != choix) {
        courant_a_ajouter = courant_a_ajouter->utilisateur_suivant;
    }
    if (courant_a_ajouter == NULL) {
        printf("Utilisateur (ID %d) non trouve !\n", choix);
        return;
    }

    if (courant->ami_suivant == NULL) {
        courant->ami_suivant = courant_a_ajouter;
    }
    else {
        while (courant->ami_suivant != NULL) {
            courant = courant->ami_suivant;
        }
        courant->ami_suivant = courant_a_ajouter;
    }
}

void ajouter_publication(Utilisateurs* utilisateurs, int id) {
    if (utilisateurs == NULL) {
        return;
    }

    Utilisateurs* courant = utilisateurs;
    while (courant != NULL && courant->id != id) {
        courant = courant->utilisateur_suivant;
    }
    if (courant == NULL) {
        printf("Utilisateur (ID %d) non trouve !\n", id);
        return;
    }

    char texte[100];
    printf("Entrez votre publication (max 100 char) :\n");
    fgets(texte, 100, stdin);
    texte[strcspn(texte, "\n")] = 0;

    if (courant->premiere_publication == NULL) {
        courant->premiere_publication = creer_message(texte);
    }
    else {
        ajouter_message(courant->premiere_publication, texte);
    }
}

void afficher_utilisateurs(Utilisateurs* utilisateurs) {
    if (utilisateurs == NULL) {
        printf("\nAucun utilisateur enregistre\n");
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
    while (courant != NULL && courant->id != id) {
        courant = courant->utilisateur_suivant;
    }
    if (courant == NULL) {
        printf("Utilisateur (ID %d) non trouve !\n", id);
        return;
    }

    printf("##### Amis de %s #####\n", courant->pseudo);
    Utilisateurs* ami = courant->ami_suivant;
    if (ami == NULL) {
        printf(" - Cet utilisateur n'a pas d'ami\n");
    } else {
        while (ami != NULL) {
            printf(" - ID: %d | Pseudo: %s\n", ami->id, ami->pseudo);
            ami = ami->ami_suivant;
        }
    }

    printf("\n##### Publications de %s #####\n", courant->pseudo);
    Publications* publication = courant->premiere_publication;
    if (publication == NULL) {
        printf(" - Cet utilisateur n'a pas de publications\n");
    }
    else {
        do {
            printf(" - %s\n", publication->message);
            publication = publication->publication_suivante;
            
        } while (publication != NULL);
    }
}

void afficher_menu() {
    printf("\n======= Reseau Social =======\n");
    printf("1. Ajouter un utilisateur\n");
    printf("2. Ajouter un ami\n");
    printf("3. Ajouter une publication\n");
    printf("4. Afficher tous les utilisateurs\n");
    printf("5. Afficher les informations d'un utilisateur\n");
    printf("6. Quitter\n");
}

void liberer_utilisateur(Utilisateurs* utilisateurs) {
    if (utilisateurs == NULL)
        return;
    liberer_utilisateur(utilisateurs->utilisateur_suivant);
    liberer_publication(utilisateurs->premiere_publication);
    free(utilisateurs);
    utilisateurs = NULL;
}

void liberer_publication(Publications* publication) {
    if (publication == NULL)
        return;
    liberer_publication(publication->publication_suivante);
    free(publication);
    publication = NULL;
}