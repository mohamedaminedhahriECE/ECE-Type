#ifndef JOUEUR_H
#define JOUEUR_H

#define MAX_PSEUDO 20

char* saisirPseudo();
int verifierPseudo(const char* pseudo);
void afficherMessageTemporaire(BITMAP* fond, const char* message, int duree);


#endif
