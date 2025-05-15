#include <allegro.h>
#include "GestionJoueur_Partie.h"
#include "Sauvegarde_Chargement.h"


void initAllegro() {
    allegro_init();
    install_keyboard();
    set_color_depth(32);
    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED, 800, 600, 0, 0) != 0) {
        allegro_message("Erreur mode graphique");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
}


int main() {
    initAllegro();
    BITMAP* fond = NULL;
    fond = load_bitmap("background.bmp", NULL);
    if (!fond) {
        allegro_message("Erreur de chargement du fond !");
        destroy_bitmap(fond);
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    blit(fond, screen, 0, 0, 0, 0, fond->w, fond->h);
    char* pseudo = saisirPseudo();

    if (verifierPseudo(pseudo)) {
        afficherMessageTemporaire(fond, "Joueur reconnu.", 2000);
    } else {
        afficherMessageTemporaire(fond, "Nouveau joueur. Sauvegarde en cours...", 2000);
        sauvegarderProgression(pseudo, 1);  // Crée le fichier avec niveau 1
    }
    readkey();
    allegro_exit();
    return 0;
}
END_OF_MAIN();
