#include "projet.h"

int main() {
    Utilisateurs* liste_utilisateurs = NULL;
    int choix;
    int id;
    char pseudo[50];
    int choix_publication;

    do {
        afficher_menu();
        printf("Votre choix : ");
        scanf("%d", &choix);
        getchar(); 

        switch (choix) {
            case 1:
                printf("Entrez l'ID de l'utilisateur : ");
                scanf("%d", &id);
                getchar();
        
                printf("Entrez le pseudo de l'utilisateur : ");
                fgets(pseudo, 50, stdin);

                if (liste_utilisateurs == NULL) {
                    liste_utilisateurs = creer_utilisateur(id, pseudo);
                }
                else {
                    ajouter_utilisateur(liste_utilisateurs, id, pseudo);
                }
                break;
            case 2:
                // 
                break;
            case 3:
                afficher_utilisateurs(liste_utilisateurs);
                printf("Entrez l'ID de l'utilisateur pour faire une publication : ");
                scanf("%d", &choix_publication);
                getchar();
                ajouter_publication(liste_utilisateurs, choix_publication);
                break;
            case 4:
                afficher_utilisateurs(liste_utilisateurs);
                break;
            case 5:
                afficher_info(liste_utilisateurs);
                break;
            case 6:
                printf("Fermeture du programme.\n");
                break;
            
            default:
                printf("Choix invalide, veuillez réessayer.\n");
        }

    } while (choix != 5);

    return 0;
}

