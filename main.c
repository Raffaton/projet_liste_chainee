#include "projet.h"

int main() {
    system("cls");
    Utilisateurs* liste_utilisateurs = NULL;
    int choix;
    int id;
    char pseudo[50];
    int choix_publication;
    int choix_ami;
    int choix_info;

    do {
        afficher_menu();
        printf("Votre choix : ");
        scanf("%d", &choix);
        getchar(); 

        switch (choix) {
            case 1:
                printf("\nEntrez l'ID de l'utilisateur : ");
                scanf("%d", &id);
                getchar();
        
                printf("Entrez le pseudo de l'utilisateur : ");
                fgets(pseudo, 50, stdin);
                pseudo[strcspn(pseudo, "\n")] = 0;                
                
                if (verifier_id(liste_utilisateurs, id)) {

                    if (liste_utilisateurs == NULL) {
                        liste_utilisateurs = creer_utilisateur(id, pseudo);
                    }
                    else {
                        ajouter_utilisateur(liste_utilisateurs, id, pseudo);
                    }
                }
                break;
            case 2:
                afficher_utilisateurs(liste_utilisateurs);
                if (liste_utilisateurs != NULL) {
                    printf("\nEntrez l'ID de l'utilisateur pour ajouter un ami : ");
                    scanf("%d", &choix_ami);
                    getchar();
                    ajouter_ami(liste_utilisateurs, choix_ami);
                }
                break;
            case 3:
                afficher_utilisateurs(liste_utilisateurs);
                if (liste_utilisateurs != NULL) {
                    printf("Entrez l'ID de l'utilisateur pour faire une publication : ");
                    scanf("%d", &choix_publication);
                    getchar();
                    ajouter_publication(liste_utilisateurs, choix_publication);
                }
                break;
            case 4:
                afficher_utilisateurs(liste_utilisateurs);
                break;
            case 5:
                afficher_utilisateurs(liste_utilisateurs);
                if (liste_utilisateurs != NULL) {
                    printf("\nEntrez l'ID de l'utilisateur pour connaitre ces informations : ");
                    scanf("%d", &choix_info);
                    getchar();
                    afficher_info(liste_utilisateurs, choix_info);
                }
                break;
            case 6:
                liberer_utilisateur(liste_utilisateurs);
                break;
            
            default:
                printf("Choix invalide, veuillez réessayer.\n");
                break;
        }

    } while (choix != 6);

    return 0;
}

