//
// Created by flobe on 14/05/2025.
//
#include <allegro.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "GestionJoueur_Partie.h"

char* saisirPseudo(BITMAP* fond) {
    static char pseudo[MAX_PSEUDO] = "";
    int index = 0;
    int touche;

    blit(fond, screen, 0, 0, 0, 0, fond->w, fond->h);
    textprintf_ex(screen, font, 100, 100, makecol(255,255,255), -1, "Entrez votre pseudo :");

    while (1) {
        if (keypressed()) {
            touche = readkey();
            char carac = (char)touche;

            if ((carac >= 'a' && carac <= 'z') || (carac >= 'A' && carac <= 'Z') || (carac >= '0' && carac <= '9')) {
                if (index < MAX_PSEUDO - 1) {
                    pseudo[index++] = carac;
                    pseudo[index] = '\0';
                }
            } else if (carac == 8 && index > 0) {
                index--;
                pseudo[index] = '\0';
            } else if (carac == '\r') {
                break;
            }
            blit(fond, screen, 0, 0, 0, 0, fond->w, fond->h);
            textprintf_ex(screen, font, 100, 100, makecol(255,255,255), -1, "Entrez votre pseudo :");
            textprintf_ex(screen, font, 100, 120, makecol(255,255,0), -1, "%s", pseudo);
        }
        rest(20);
    }
    return pseudo;
}
int verifierPseudo(const char* pseudo) {
    char filename[50];
    sprintf(filename, "%s.txt", pseudo);

    FILE* f = fopen(filename, "r");
    if (f != NULL) {
        fclose(f);
        return 1; // joueur connu
    } else {
        return 0; // nouveau joueur
    }
}

void afficherMessageTemporaire(BITMAP* fond, const char* message, int duree) {
    blit(fond, screen, 0, 0, 0, 0, fond->w, fond->h); // Affiche le fond
    textprintf_ex(screen, font, 100, 300, makecol(255, 255, 255), -1, "%s", message);
    rest(duree);
}
