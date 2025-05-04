//
// Created by flobe on 04/05/2025.
//

#include "Menu.h"

int main() {
    initialisation_allegro();

    big_font = load_font("big_fontp.ttf", NULL, NULL);
    if (!big_font) big_font = font;

    int selected = 0;
    int key_pressed;
    MenuState menu_state = MENU_PRINCIPAL;

    while (!key[KEY_ESC]) {
        // Affichage du fond d'espace
        blit(background, buffer, 0, 0, 0, 0, SCREEN_W, SCREEN_H);

        // Affichage du titre directement sur le buffer (sans carré noir)
        textout_centre_ex(buffer, big_font, "GALAXIA CLASSIC", SCREEN_W / 2, 50, makecol(255, 0, 0), -1);

        switch (menu_state) {
            case MENU_PRINCIPAL:
                for (int i = 0; i < NUM_OPTIONS; i++) {
                    int color = (i == selected) ? makecol(255, 255, 0) : makecol(255, 255, 255);
                    textout_ex(buffer, font, menu_options[i], SCREEN_W / 2 - 100, 150 + i * 30, color, -1);
                }
                break;

            case MENU_OPTIONS:
                for (int i = 0; i < NUM_SUBOPTIONS; i++) {
                    int color = (i == selected) ? makecol(0, 255, 255) : makecol(200, 200, 200);
                    textout_ex(buffer, font, options_sous_menu[i], SCREEN_W / 2 - 100, 150 + i * 30, color, -1);
                }
                break;

            case MENU_CONTROLES:
                afficher_controles(buffer);
                break;

            case MENU_GUIDE:
                afficher_guide(buffer);
                break;
        }

        blit(buffer, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);

        if (keypressed()) {
            key_pressed = readkey() >> 8;

            switch (menu_state) {
                case MENU_PRINCIPAL:
                    if (key_pressed == KEY_DOWN) {
                        if (menu_sound) play_sample(menu_sound, 255, 128, 1000, 0);
                        selected = (selected + 1) % NUM_OPTIONS;
                    } else if (key_pressed == KEY_UP) {
                        if (menu_sound) play_sample(menu_sound, 255, 128, 1000, 0);
                        selected = (selected - 1 + NUM_OPTIONS) % NUM_OPTIONS;
                    } else if (key_pressed == KEY_ENTER) {
                        if (menu_sound) play_sample(menu_sound, 255, 128, 1000, 0);
                        if (selected == 0) allegro_message("Nouvelle Partie !");
                        else if (selected == 1) {
                            if (menu_sound) play_sample(menu_sound, 255, 128, 1000, 0);
                            menu_state = MENU_OPTIONS;
                            selected = 0;
                        } else if (selected == 2) {
                            if (menu_sound) play_sample(menu_sound, 255, 128, 1000, 0);
                            goto end_program;
                        }
                    }
                    break;

                case MENU_OPTIONS:
                    if (key_pressed == KEY_DOWN) {
                        if (menu_sound) play_sample(menu_sound, 255, 128, 1000, 0);
                        selected = (selected + 1) % NUM_SUBOPTIONS;
                    } else if (key_pressed == KEY_UP) {
                        if (menu_sound) play_sample(menu_sound, 255, 128, 1000, 0);
                        selected = (selected - 1 + NUM_SUBOPTIONS) % NUM_SUBOPTIONS;
                    } else if (key_pressed == KEY_ENTER) {
                        if (menu_sound) play_sample(menu_sound, 255, 128, 1000, 0);
                        if (selected == 0) menu_state = MENU_CONTROLES;
                        else if (selected == 1) menu_state = MENU_GUIDE;
                        else if (selected == 2) {
                            if (menu_sound) play_sample(menu_sound, 255, 128, 1000, 0);
                            menu_state = MENU_PRINCIPAL;
                            selected = 0;
                        }
                    }
                    break;

                case MENU_CONTROLES:
                case MENU_GUIDE:
                    if (key_pressed == KEY_ENTER) {
                        if (menu_sound) play_sample(menu_sound, 255, 128, 1000, 0);
                        menu_state = MENU_OPTIONS;
                        selected = 2;
                    }
                    break;
            }
        }

        rest(50);
    }

end_program:
    destroy_bitmap(background);
    destroy_bitmap(buffer);
    destroy_font(big_font);
    destroy_sample(menu_sound);

    return 0;
}
END_OF_MAIN()