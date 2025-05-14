#ifndef JOUEUR_H
#define JOUEUR_H

typedef struct {
    char pseudo[20];
    int vies;
    int niveau;
} t_joueur;

char* saisirPseudo();
int verifierPseudo(const char* pseudo);
void initialiserJoueur(t_joueur* j, const char* pseudo);
void perdreVie(t_joueur* j);
int viesRestantes(t_joueur* j);
void afficherMessageTemporaire(const char* message, int duree);

#endif
