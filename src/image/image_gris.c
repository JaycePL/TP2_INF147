/****************************************************************************************
/*                                      IMAGE_GRIS.C                                    *
/****************************************************************************************
    Auteurs : Cédric Benoit, Hakim-Anis Hamani et Jasmin Papierz-Lambert
    Date    : 17 mars 2024

    Ce module contient la définition d'un nouveau type de même que 4 fonctions pour
    manipuler des tableaux 2D de réels.

    Liste des fonctions publiques:
      - negatif      : Remplace tous les pixels de l’image reçue par le négatif de ces pixels.
      - seuiller     : Remplace tous les pixels de l’image reçue par 0 ou par 1.
      - histogramme  : Calcule l'histogramme d'un tableau.
      - filtrer      : Permet de filtrer les pixels de l'image originale et de les stocker
                       dans une nouvelle image.

*****************************************************************************************/
#include "image_gris.h"

#include <stdio.h>
#include <stdlib.h>

#include "bitmap.h"
#include "noyeau_filtre.h"
#include "../tableau/tableau1d.h"
#include "../tableau/tableau2d.h"


/****************************************************************************************
*                               DEFINTION DES CONSTANTES                                *
****************************************************************************************/



/****************************************************************************************
*                           DECLARATION DES FONCTIONS PRIVEES                           *
****************************************************************************************/

//
//  Cette fonction privée permet de calculer la valeur filtrée d'un pixel. Pour y parvenir,
//  il se doit de calculer la convolution de ce pixel avec le filtre reçu.
//
static int calculer_valeur_filtre(double** image,double** filtre, int index_ligne_pixel,int index_colonne_pixel )
{
    // On initialise le résultat de la somme a 0.
    int somme_pixel = 0;

    // On parcourt le tableau 2D qui représente le filtre.
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            // On définie la valeur des coordonnées ligne/colonne actuelle.
            int indexi = index_ligne_pixel-1+i;
            int indexj = index_colonne_pixel-1+j;
            // Selon les conditions, on n'ajoute rien a la somme du résultat.
            if (indexi < 0 || indexj < 0 || indexi > index_ligne_pixel || indexj > index_colonne_pixel)somme_pixel = somme_pixel + 0;
            // Sinon, on ajoute la valeur du pixel multiplié par la valeur dans la case actuelle du filtre a la somme du résultat.
            else
            {
                somme_pixel = somme_pixel + image[indexi][indexj] * filtre[i][j];
            }

        }
    }

    return somme_pixel;
}

/****************************************************************************************
*                           DEFINTION DES FONCTIONS PUBLIQUES                            *
****************************************************************************************/

//
//  Cette fonction remplace tous les pixels de l’image reçue par le négatif de ces pixels.
//
void negatif( double **image, int nb_lignes, int nb_colonnes){

    // On parcourt chaque case du tableau 2D de pixel, image.
    for (int i = 0; i < nb_lignes; ++i) {
        for (int j = 0; j < nb_colonnes; ++j)
        {
            // On vient inverser la valeur du pixel dans la case.
            // Si la valeur était élevé, elle sera basse. Sinon, si la valeur était basse, elle sera élevé.
           image[i][j] = 1.0 - image[i][j];
        }
    }

};


//
//  Cette fonction remplace tous les pixels de l’image reçue par 0 ou par 1.
//
void seuiller( double **image, int nb_lignes, int nb_colonnes, double seuil){

    // On parcourt chaque case du tableau 2D de pixel, image.
    for (int i = 0; i < nb_lignes; ++i)
    {
        for (int j = 0; j < nb_colonnes; ++j)
        {
            // Si la valeur du pixel est plus haute ou égale au seul, cette valeur sera 1.
            if(image[i][j] >= seuil) image[i][j] = 1;
            // Sinon, elle sera 0.
            else image[i][j] = 0;
        }
    }
};


//
//  Cette fonction calcule l'histogramme d'un tableau.
//
double* histogramme(double** image, int nb_lignes, int nb_colonnes, int nb_categories) {
    // Le nombre de séparation est déterminé par le paramètre nb_categories.
    double separateur = 1.0 / nb_categories;
    // On créer un nouveau tableau 1D pour y mettre les résultats.
    double *tableau = creer_tableau1D(nb_categories);

    // On passe a travert chaque catégorie.
    for (int g = 0; g < nb_categories; ++g)
    {
        // On parcourt chaque case du tableau 2D de pixel, image.
        for (int i = 0; i < nb_lignes; ++i)
        {
            for (int j = 0; j < nb_colonnes; ++j)
            {
                //Si la valeur du pixel est entre les balises de la catégorie actuelle, on +1 la case du tableau des catégories.
                if(image[i][j] >= separateur * g && image[i][j] < separateur * (g+1) ) {
                    tableau[g]++;
                }
            }
        }
    }

    return tableau;
}


//
//  Cette fonction permet de filtrer les pixels de l'image originale et de les stocker
//  dans une nouvelle image.
//
void filtrer(double** image, int nb_lignes, int nb_colonnes,t_filtre *filtre) {
    double ** image_stockage = creer_tableau2D(nb_lignes, nb_colonnes);

    // Parcourt du tableau 2D image
    for (int i = 0; i < nb_lignes; ++i) {
        for (int j = 0; j < nb_colonnes; ++j)
        {
            // En utilisant la fonction privée calculer_valeur_filtre, on stocke la valeur du pixel modifié dans le nouveau tableau.
            image_stockage[i][j] = calculer_valeur_filtre(image, filtre->data,i,j);
        }
    }
    for (int i = 0; i < nb_lignes; ++i) {
        for (int j = 0; j < nb_colonnes; ++j)
        {
            // On transfert la nouvelle valeur des pixels dans la nouvelle image (tableau 2D)
            image[i][j] = image_stockage[i][j];
        }
    }
}
