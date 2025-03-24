#ifndef PROJET_H
#define PROJET_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char message[100];
} Publications;

typedef struct {
    int id;
    char pseudo[50];
    struct Publications* publication_suivante;
    struct Utilisateurs* ami_suivant;
    struct Utilisateurs* utilisateur_suivant;
} Utilisateurs;

#endif