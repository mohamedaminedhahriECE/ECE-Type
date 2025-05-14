//
// Created by flobe on 14/05/2025.
//

#include <allegro.h>
#include <stdio.h>
#include "GestionJoueur_Partie.h"

// Fonction simple pour afficher un message temporaire à l'écran
void afficherMessageTemporaire(const char* message, int secondes) {
    clear_to_color(screen, makecol(0, 0, 0));
    textout_ex(screen, font, message, 300, 280, makecol(255, 255, 255), -1);
    rest(secondes * 1000);
}

int main() {
    allegro_init();                // Initialise Allegro
    install_keyboard();           // Active le clavier
    set_color_depth(24);          // Profondeur de couleur
    set_gfx_mode(GFX_AUTODETECT_WINDOWED, 800, 600, 0, 0);  // Fenêtre 800x600

    t_joueur joueur;
    char* pseudo = saisirPseudo();

    if (verifierPseudo(pseudo)) {
        afficherMessageTemporaire("Joueur reconnu !", 2);
    } else {
        afficherMessageTemporaire("Nouveau joueur", 2);
    }

    initialiserJoueur(&joueur, pseudo);

    printf("Pseudo : %s\n", joueur.pseudo);
    printf("Vies restantes : %d\n", viesRestantes(&joueur));

    readkey(); // Pause avant de fermer

    return 0;
}
END_OF_MAIN();



/*
#include <allegro.h>
#include <stdio.h>
#include "joueur.h"

int main() {
    allegro_init();
    install_keyboard();
    set_color_depth(24);
    set_gfx_mode(GFX_AUTODETECT_WINDOWED, 800, 600, 0, 0);

    t_joueur joueur;
    char* pseudo = saisirPseudo();

    if (verifierPseudo(pseudo)) {
        afficherMessageTemporaire("Joueur reconnu !", 2);
    } else {
        afficherMessageTemporaire("Nouveau joueur", 2);
    }

    initialiserJoueur(&joueur, pseudo);

    printf("Pseudo : %s\n", joueur.pseudo);
    printf("Vies restantes : %d\n", viesRestantes(&joueur));

    return 0;
}
END_OF_MAIN();
*/