#include "projet.h"


int main() {
    Utilisateur* liste_utilisateurs = NULL;
    int choix;

    do {
        afficher_menu();
        printf("Votre choix : ");
        scanf("%d", &choix);
        getchar(); 

        switch (choix) {
            case 1:
                ajouter_utilisateur(&liste_utilisateurs);
                break;
            case 2:
                afficher_utilisateurs(liste_utilisateurs);
                break;
            case 0:
                printf("Fermeture du programme.\n");
                break;
            default:
                printf("Choix invalide, veuillez réessayer.\n");
        }

    } while (choix != 0);

    return 0;
}

void afficher_menu() {
    printf("\n=== Réseau Social ===\n");
    printf("1. Ajouter un utilisateur\n");
    printf("2. Afficher tous les utilisateurs\n");
    printf("0. Quitter\n");
}

void ajouter_utilisateur(Utilisateur liste) {
    int id;
    char pseudo[51];

    printf("Entrez l'ID de l'utilisateur : ");
    scanf("%d", &id);
    getchar();
} 

    printf("Entrez le pseudo de l'utilisateur : ");
    fgets(pseudo, 51, stdin);
    pseudo[strcspn(pseudo, "\n")] = 0;
Utilisateur* nouveau = malloc(sizeof(Utilisateur));
    if (!nouveau) {
        printf("Erreur d'allocation mémoire.\n");
        return;
    }

    nouveau->id = id;
    strcpy(nouveau->pseudo, pseudo);
    nouveau->liste_amis = NULL;
    nouveau->publications = NULL;
    nouveau->suivant = *liste;
    liste = nouveau;