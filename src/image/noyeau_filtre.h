#ifndef NOYEAU_FILTRE
#define NOYEAU_FILTRE

#define DIMENSION 3
#define NB_POINTS 3

typedef struct {       // Nombre de colonnes
    double **data;    // Tableau 2D dynamique contenant les valeurs de la liste
} t_filtre;

t_filtre *filtre_passe_haut();
t_filtre *filtre_passe_bas();
t_filtre *filtre_passe_moyenneur();
t_filtre *filtre_laplacien();
void detruire_filtre(t_filtre *filtre);
#endif