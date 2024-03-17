/****************************************************************************************
/*                                      IMAGE_GRIS.H                                    *
/****************************************************************************************
    Auteurs : C�dric Benoit, Hakim-Anis Hamani et Jasmin Papierz-Lambert
    Date    : 15 mars 2024

    Ce module contient la d�finition d'un nouveau type de m�me que 4 fonctions pour
    manipuler des tableaux 2D de r�els.

    Liste des fonctions publiques:
      - negatif      : Remplace tous les pixels de l�image re�ue par le n�gatif de ces pixels.
      - seuiller     : Remplace tous les pixels de l�image re�ue par 0 ou par 1.
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

    Cette fonction remplace tous les pixels de l�image re�ue par le n�gatif de ces pixels.
    On calcule le n�gatif d�un pixel avec la formule : 1-valeur_pixel.

    PARAM�TRE :
        - image        : Une image en teinte de gris.
        - nb_lignes    : Le nombre de ligne de cette image.
        - nb_colonnes  : Le nombre de colonne de cette image.

    RETOUR :
        - Aucun
*/
void negatif(double** image, int nb_lignes, int nb_colonnes);



/*
    SEUILLER

    Cette fonction remplace tous les pixels de l�image re�ue par 0 ou par 1.
    Lorsque la valeur originale du pixel est inf�rieure au seuil, il est remplac� par un pixel noir.
    Lorsque la valeur originale du pixel est sup�rieure ou �gale au seuil, il est remplac� par un pixel blanc.

    PARAM�TRE :
        - image        : Une image en teinte de gris.
        - nb_lignes    : Le nombre de ligne de cette image.
        - nb_colonnes  : Le nombre de colonne de cette image.
        - seuil        : Un r�el repr�sentant un seuil.

    RETOUR :
        - Aucun
*/
void seuiller(double** image, int nb_lignes, int nb_colonnes, double seuil);



/*
    HISTOGRAMME

    Cette fonction calcule l'histogramme d'un tableau re�u et d�termine la cat�gorie de chaque pixel
    pour finalement en faire un d�compte.

    PARAM�TRE :
        - image         : Une image en teinte de gris.
        - nb_lignes     : Le nombre de ligne de cette image.
        - nb_colonnes   : Le nombre de colonne de cette image.
        - nb_categories : Un entier repr�sentant un nombre de cat�gories.

    RETOUR :
        - Un tableau 1D contenant la distribution des pixels en fonction du nombre de cat�gorie de couleur re�ue.
*/
double* histogramme(double** image, int nb_lignes, int nb_colonnes, int nb_categories);



/*
    FILTRER

    Cette fonction permet de cr�er une image � partir de l'image original et d'utiliser l'image originale pour
    calculer la valeur de chaque pixel filtr�. La valeur des pixels filtr�s sont enregistr�s dans la nouvelle image.

    PARAM�TRE :
        - image        : Un pointeur vers une image en teinte de gris.
        - nb_lignes    : Le nombre de ligne de cette image.
        - nb_colonnes  : Le nombre de colonne de cette image.
        - t_filtre     : Le filtre appliqu� sur l'image.

    RETOUR :
        - Aucun
*/
void filtrer(double** image, int nb_lignes, int nb_colonnes, t_filtre *filtre);

#endif