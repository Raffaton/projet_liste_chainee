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
void ajouter_ami(Utilisateurs* utilisateurs, int id_utilisateur, int id_ami) {
	Utilisateurs* utilisateur = trouver_utilisateur(utilisateurs, id_utilisateur);
	Utilisateurs* ami = trouver_utilisateur(utilisateurs, id_ami);


	if (!utilisateur || !ami) {
		printf("Utilisateur ou ami introuvable.\n");
		return;
	}

=	Utilisateurs* courant = utilisateur->ami_suivant;
	while (courant != NULL) {
		if (courant->id == id_ami) {
			printf("Cet utilisateur est déjà un ami.\n");
			return;
		}
		courant = courant->ami_suivant;
	}

	Utilisateurs* nouvel_ami = malloc(sizeof(Utilisateurs));
	if (!nouvel_ami) {
		printf("Erreur mémoire.\n");
		return;
	}
	nouvel_ami->id = ami->id;
	strcpy(nouvel_ami->pseudo, ami->pseudo);
	nouvel_ami->premiere_publication = NULL;
	nouvel_ami->ami_suivant = utilisateur->ami_suivant;
	nouvel_ami->utilisateur_suivant = NULL;
	utilisateur->ami_suivant = nouvel_ami;

	printf("Ami ajouté avec succès.\n");


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

    Utilisateurs* actuel = courant;
    printf("Amis de %s :\n", actuel->pseudo);
    if (actuel->ami_suivant == NULL) {
        printf(" - Cet utilisateur n'a pas d'ami\n");
    }
    else {
        do {
            actuel = actuel->ami_suivant;
            printf(" - ID: %d, Pseudo: %s\n", actuel->id, actuel->pseudo);
            
        } while (actuel != NULL);
    }

    printf("\nPublications de %s :\n", courant->pseudo);
    if (courant->premiere_publication == NULL) {
        printf(" - Cet utilisateur n'a pas de publications\n");
    }
    else {
        do {
            courant = courant->premiere_publication;
            printf(" - ID: %d, Pseudo: %s\n", courant->id, courant->pseudo);
            
        } while (courant != NULL);
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