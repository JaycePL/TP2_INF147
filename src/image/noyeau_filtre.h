#ifndef NOYEAU_FILTRE
#define NOYEAU_FILTRE
#include "../tableau/tableau2d.h"

#define DIMENSION 3
#define NB_POINTS 3

typedef struct {       // Nombre de colonnes
    double **data;    // Tableau 2D dynamique contenant les valeurs de la liste
} T_liste;

T_liste filtre_passe_haut();
T_liste filtre_passe_bas();
T_liste filtre_passe_moyenneur();
T_liste filtre_laplacien();
void detruire_filtre(T_liste *filtre);
#endif