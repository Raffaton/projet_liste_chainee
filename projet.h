#ifndef PROJET_H
#define PROJET_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char message[100];
    struct Publications* publication_suivante; 
} Publications;

typedef struct {
    int id;
    char pseudo[50];
    struct Publications* premiere_publication;
    struct Utilisateurs* ami_suivant;
    struct Utilisateurs* utilisateur_suivant;
} Utilisateurs;

Utilisateurs* creer_utilisateur(int id, char pseudo[50]);
Publications* creer_message(char texte[100]);
void ajouter_utilisateur(Utilisateurs* premier_utilisateur,int id, char pseudo[50]);
void ajouter_message(Publications* premier_message, char texte[100]);
void afficher_utilisateurs(Utilisateurs* utilisateurs);
void afficher_menu();
void ajouter_publication(Utilisateurs* utilisateurs, int id);
void afficher_info(Utilisateurs* utilisateurs, int id);

#endif