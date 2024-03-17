/****************************************************************************************
/*                                      IMAGE_GRIS.H                                    *
/****************************************************************************************
    Auteurs : Cédric Benoit, Hakim-Anis Hamani et Jasmin Papierz-Lambert
    Date    : 15 mars 2024

    Ce module contient la définition d'un nouveau type de même que 4 fonctions pour
    manipuler des tableaux 2D de réels.

    Liste des fonctions publiques:
      - negatif      : Remplace tous les pixels de l’image reçue par le négatif de ces pixels.
      - seuiller     : Remplace tous les pixels de l’image reçue par 0 ou par 1.
      - histogramme  : Calcule l'histogramme d'un tableau.
      - filtrer      : Permet de filtrer les pixels de l'image originale et de les stocker
                       dans une nouvelle image.

*****************************************************************************************/

#ifndef IMAGE_GRIS
#define IMAGE_GRIS

#include "noyeau_filtre.h"

typedef struct {       // Nombre de colonnes
    double **data;    // Tableau 2D dynamique contenant les valeurs de la liste
} t_image_gris;


/****************************************************************************************
*                               DEFINTION DES CONSTANTES                                *
****************************************************************************************/


/****************************************************************************************
*                       DECLARATION DES FONCTIONS PUBLIQUES                             *
****************************************************************************************/

/*
    NEGATIF

    Cette fonction remplace tous les pixels de l’image reçue par le négatif de ces pixels.
    On calcule le négatif d’un pixel avec la formule : 1-valeur_pixel.

    PARAMÈTRE :
        - image        : Une image en teinte de gris.
        - nb_lignes    : Le nombre de ligne de cette image.
        - nb_colonnes  : Le nombre de colonne de cette image.

    RETOUR :
        - Aucun
*/
void negatif(double** image, int nb_lignes, int nb_colonnes);



/*
    SEUILLER

    Cette fonction remplace tous les pixels de l’image reçue par 0 ou par 1.
    Lorsque la valeur originale du pixel est inférieure au seuil, il est remplacé par un pixel noir.
    Lorsque la valeur originale du pixel est supérieure ou égale au seuil, il est remplacé par un pixel blanc.

    PARAMÈTRE :
        - image        : Une image en teinte de gris.
        - nb_lignes    : Le nombre de ligne de cette image.
        - nb_colonnes  : Le nombre de colonne de cette image.
        - seuil        : Un réel représentant un seuil.

    RETOUR :
        - Aucun
*/
void seuiller(double** image, int nb_lignes, int nb_colonnes, double seuil);



/*
    HISTOGRAMME

    Cette fonction calcule l'histogramme d'un tableau reçu et détermine la catégorie de chaque pixel
    pour finalement en faire un décompte.

    PARAMÈTRE :
        - image         : Une image en teinte de gris.
        - nb_lignes     : Le nombre de ligne de cette image.
        - nb_colonnes   : Le nombre de colonne de cette image.
        - nb_categories : Un entier représentant un nombre de catégories.

    RETOUR :
        - Un tableau 1D contenant la distribution des pixels en fonction du nombre de catégorie de couleur reçue.
*/
double* histogramme(double** image, int nb_lignes, int nb_colonnes, int nb_categories);



/*
    FILTRER

    Cette fonction permet de créer une image à partir de l'image original et d'utiliser l'image originale pour
    calculer la valeur de chaque pixel filtré. La valeur des pixels filtrés sont enregistrés dans la nouvelle image.

    PARAMÈTRE :
        - image        : Un pointeur vers une image en teinte de gris.
        - nb_lignes    : Le nombre de ligne de cette image.
        - nb_colonnes  : Le nombre de colonne de cette image.
        - t_filtre     : Le filtre appliqué sur l'image.

    RETOUR :
        - Aucun
*/
void filtrer(double** image, int nb_lignes, int nb_colonnes, t_filtre *filtre);

#endif