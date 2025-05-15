//
// Created by flobe on 14/05/2025.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Sauvegarde_Chargement.h"


void sauvegarderProgression(const char* pseudo, int niveau) {
    char filename[50];
    sprintf(filename, "%s.txt", pseudo);

    FILE* f = fopen(filename, "w");
    if (f != NULL) {
        fprintf(f, "%d", niveau);
        fclose(f);
    }
}

int chargerProgression(const char* pseudo) {
    char filename[50];
    sprintf(filename, "%s.txt", pseudo);

    FILE* f = fopen(filename, "r");
    int niveau = 1; // niveau par défaut

    if (f != NULL) {
        fscanf(f, "%d", &niveau);
        fclose(f);
    }

    return niveau;
}