//
// Created by flobe on 04/05/2025.
//

#ifndef MENU_H
#define MENU_H

#endif //MENU_H


#include <allegro.h>
#include <stdlib.h>

#define NUM_OPTIONS 3
#define NUM_SUBOPTIONS 3

FONT *big_font;
BITMAP *buffer;
BITMAP *background;
SAMPLE *menu_sound;

typedef enum {
    MENU_PRINCIPAL,
    MENU_OPTIONS,
    MENU_CONTROLES,
    MENU_GUIDE
} MenuState;

void initialisation_allegro() {
    allegro_init();
    install_keyboard();
    install_sound(DIGI_AUTODETECT, MIDI_AUTODETECT, NULL);
    set_color_depth(24);

    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED, 640, 480, 0, 0) != 0) {
        allegro_message("Probleme gfx mode");
        allegro_exit();
        exit(EXIT_FAILURE);
    }

    // Chargement du fond d'espace
    background = load_bitmap("Blueback.bmp", NULL);
    if (!background) {
        allegro_message("Erreur chargement background");
        allegro_exit();
        exit(EXIT_FAILURE);
    }

    buffer = create_bitmap(SCREEN_W, SCREEN_H);
    if (!buffer) {
        allegro_message("Erreur creation bitmaps");
        exit(EXIT_FAILURE);
    }

    menu_sound = load_sample("menusound.wav");
    if (!menu_sound) {
        allegro_message("impossible de charger le son du menu");
    }
}

const char *menu_options[NUM_OPTIONS] = {
    "Nouvelle Partie",
    "Options",
    "Quitter"
};

const char *options_sous_menu[NUM_SUBOPTIONS] = {
    "Controles",
    "Guide",
    "Retour"
};

void afficher_controles(BITMAP *cible) {
    // Utilisez drawing_mode pour la transparence
    drawing_mode(DRAW_MODE_TRANS, NULL, 0, 0);
    set_trans_blender(0, 0, 0, 128); // 128 pour 50% de transparence
    rectfill(cible, 50, 80, SCREEN_W - 50, SCREEN_H - 80, makecol(0, 0, 0));
    drawing_mode(DRAW_MODE_SOLID, NULL, 0, 0);

    textout_centre_ex(cible, font, "CONTROLES DU JEU", SCREEN_W / 2, 100, makecol(0, 255, 0), -1);
    textout_ex(cible, font, "- Deplacement gauche: Fleche GAUCHE", 100, 150, makecol(255, 255, 255), -1);
    textout_ex(cible, font, "- Deplacement droite: Fleche DROITE", 100, 180, makecol(255, 255, 255), -1);
    textout_ex(cible, font, "- Monter: Fleche HAUT", 100, 210, makecol(255, 255, 255), -1);
    textout_ex(cible, font, "- Descendre: Fleche BAS", 100, 240, makecol(255, 255, 255), -1);
    textout_centre_ex(cible, font, "[Retour via le menu Options]", SCREEN_W / 2, 300, makecol(150, 150, 150), -1);
}

void afficher_guide(BITMAP *cible) {
    const char *lignes_guide[] = {
        "Dans Galaxia Classic, ton objectif est de defendre ton",
        "vaisseau spatial contre des vagues d'ennemis venus de",
        "l'espace. Les ennemis attaquent en formation ou foncent",
        "vers toi pour te surprendre, alors reste mobile et tire",
        "avec precision pour les eliminer.",
        "",
        "Chaque ennemi detruit te rapporte 50 points, alors plus",
        "tu en abats, plus ton score grimpe. Survis le plus",
        "longtemps possible, esquive les tirs ennemis et tente",
        "de battre ton propre record a chaque partie."
    };

    // Utilisez drawing_mode pour la transparence
    drawing_mode(DRAW_MODE_TRANS, NULL, 0, 0);
    set_trans_blender(0, 0, 0, 128); // 128 pour 50% de transparence
    rectfill(cible, 50, 80, SCREEN_W - 50, SCREEN_H - 80, makecol(0, 0, 0));
    drawing_mode(DRAW_MODE_SOLID, NULL, 0, 0);

    textout_centre_ex(cible, font, "GUIDE DU JOUEUR", SCREEN_W / 2, 100, makecol(0, 200, 255), -1);

    int y = 150;
    for (int i = 0; i < sizeof(lignes_guide) / sizeof(char*); i++) {
        textout_ex(cible, font, lignes_guide[i], 50, y, makecol(200, 200, 200), -1);
        y += 20;
    }
    textout_centre_ex(cible, font, "[Retour via le menu Options]", SCREEN_W / 2, 400, makecol(150, 150, 150), -1);
}
