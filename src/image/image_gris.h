#ifndef IMAGE_GRIS
#define IMAGE_GRIS
#include "noyeau_filtre.h"

typedef struct {       // Nombre de colonnes
    double **data;    // Tableau 2D dynamique contenant les valeurs de la liste
} t_image_gris;

void negatif(double** image, int nb_lignes, int nb_colonnes);
void seuiller(double** image, int nb_lignes, int nb_colonnes, double seuil);
double* histogramme(double** image, int nb_lignes, int nb_colonnes, int nb_categories);
void filtrer(double** image, int nb_lignes, int nb_colonnes, t_filtre *filtre);

#endif