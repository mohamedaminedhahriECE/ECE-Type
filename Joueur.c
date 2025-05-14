#include <allegro.h>
#include <stdio.h>
#include <string.h>
#include "joueur.h"

char* saisirPseudo() {
    static char pseudo[20] = "";
    int pos = 0;
    int touche;

    while (!key[KEY_ENTER]) {
        if (keypressed()) {
            touche = readkey();
            char c = touche & 0xff;
            if (c >= 32 && c <= 126 && pos < 19) {
                pseudo[pos++] = c;
                pseudo[pos] = '\0';
            } else if ((touche >> 8) == KEY_BACKSPACE && pos > 0) {
                pseudo[--pos] = '\0';
            }
        }

        clear_to_color(screen, makecol(0, 0, 0));
        textprintf_ex(screen, font, 100, 100, makecol(255, 255, 255), -1, "Pseudo : %s", pseudo);
        rest(30);
    }

    return pseudo;
}

int verifierPseudo(const char* pseudo) {
    char nomFichier[32];
    sprintf(nomFichier, "%s.txt", pseudo);
    FILE* f = fopen(nomFichier, "r");
    if (f) {
        fclose(f);
        return 1;
    }
    return 0;
}

void initialiserJoueur(t_joueur* j, const char* pseudo) {
    strncpy(j->pseudo, pseudo, sizeof(j->pseudo) - 1);
    j->pseudo[sizeof(j->pseudo) - 1] = '\0';
    j->vies = 3;
    j->niveau = 1;
}

void perdreVie(t_joueur* j) {
    if (j->vies > 0)
        j->vies--;
    afficherMessageTemporaire("Tu as perdu une vie", 2);
}

int viesRestantes(t_joueur* j) {
    return j->vies;
}

void afficherMessageTemporaire(const char* message, int duree) {
    clear_to_color(screen, makecol(0, 0, 0));
    textout_ex(screen, font, message, 100, 100, makecol(255, 0, 0), -1);
    rest(duree * 1000);
}


/*
#include "joueur.h"

char* saisirPseudo() {
    static char pseudo[20] = "";
    int pos = 0;
    int key;

    while (!key[KEY_ENTER]) {
        if (keypressed()) {
            key = readkey();
            char c = key & 0xff;
            if (c >= 32 && c <= 126 && pos < 19) {
                pseudo[pos++] = c;
                pseudo[pos] = '\0';
            } else if ((key >> 8) == KEY_BACKSPACE && pos > 0) {
                pseudo[--pos] = '\0';
            }
        }

        clear_to_color(screen, makecol(0, 0, 0));
        textprintf_ex(screen, font, 100, 100, makecol(255, 255, 255), -1, "Pseudo : %s", pseudo);
        rest(30);
    }

    return pseudo;
}

int verifierPseudo(const char* pseudo) {
    char nomFichier[32];
    sprintf(nomFichier, "%s.txt", pseudo);
    FILE* f = fopen(nomFichier, "r");
    if (f) {
        fclose(f);
        return 1;
    }
    return 0;
}

void initialiserJoueur(t_joueur* j, const char* pseudo) {
    strncpy(j->pseudo, pseudo, sizeof(j->pseudo));
    j->vies = 3;
    j->niveau = 1;
}

void perdreVie(t_joueur* j) {
    if (j->vies > 0) j->vies--;
    afficherMessageTemporaire("Tu as perdu une vie", 2);
}

int viesRestantes(t_joueur* j) {
    return j->vies;
}

void afficherMessageTemporaire(const char* message, int duree) {
    clear_to_color(screen, makecol(0, 0, 0));
    textout_ex(screen, font, message, 100, 100, makecol(255, 0, 0), -1);
    rest(duree * 1000);
}
*/