/****************************************************************************************
/*                                     TABLEAU2D.H                                      *
/****************************************************************************************
    Auteurs : Cédric Benoit, Hakim-Anis Hamani et Jasmin Papierz-Lambert
    Date    : 15 mars 2024

    Ce module contient des fonctions pour manipuler des tableaux 2D de réels.

    Liste des fonctions publiques:
      - creer_tableau2D        : Crée un tableau dynamique 2D.
      - detruire_tableau2D     : Détruit un tableau dynamique 2D.
      - afficher_tableau2D     : Affiche les valeurs d'un tableau 2D.
      - initialiser_tableau2D  : Initialise toutes les cases du tableau 2D avec la valeur
                                 assigner.
      - somme_tableau2D        : Retourne la somme de toutes les cases du tableau 2D.
      - produit_par_scalaire2D : Multiplie chacune des cases du tableau 2D avec un
                                 facteur multiplicatif.
      - puissance_tableau2D    : Applique une puissance à chacune des cases du tableau 2D.
      - produit_tableau2D      : Multiplie deux tableaux 2D case par case et inscrit les
                                 résultats dans un nouveau tableau 2D.

*****************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "tableau2d.h"

/****************************************************************************************
*                               DEFINTION DES CONSTANTES                                *
****************************************************************************************/



/****************************************************************************************
*                           DECLARATION DES FONCTIONS PRIVEES                           *
****************************************************************************************/



/****************************************************************************************
*                           DEFINTION DES FONCTIONS PUBLIQUES                            *
****************************************************************************************/

//
//  Cette fonction crée un tableau 2D.
//
void* creer_tableau2D(int nb_ligne,int nb_colonne)
{
    double** tableau;

    tableau = (double**) calloc(nb_ligne, sizeof(double*));
    for(int i = 0; i < nb_ligne; i++)
    {
        tableau[i] = (double*) calloc(nb_colonne, sizeof(double));
    }

    return tableau;
}


//
//  Cette fonction détruit un tableau 2D.
//
void detruire_tableau2D(double*** pointeur,int nb_ligne)
{
    for(int i = 0; i < nb_ligne; i++)
    {
        free((*pointeur)[i]);
        (*pointeur)[i] = NULL;
    }

    free(*pointeur);
    *pointeur = NULL;
}


//
//  Cette fonction affiche les valeurs d'un tableau 2D.
//
void afficher_tableau2D(double** tableau, int nb_ligne, int nb_colonne)
{

    for(int ligne = 0; ligne < nb_ligne; ligne++)
    {

        for(int col = 0; col < nb_colonne; col++)
        {
            if (tableau[ligne][col] < 0) printf("%0.3lf  ",tableau[ligne][col]);
            else printf(" %0.3lf  ",tableau[ligne][col]);
        }

        printf("\n");

    }

}


//
//  Cette fonction initialise toutes les cases du tableau 2D avec une valeur assignée.
//
void initialiser_tableau2D(double** tableau, int nb_ligne, int nb_colonne, double valeur)
{

    for(int ligne = 0; ligne < nb_ligne; ligne++) {

        for (int col = 0; col < nb_colonne; col++) {

            tableau[ligne][col] = valeur;

        }
    }
}


//
//  Cette fonction fait la somme de toutes les cases du tableau 2D.
//
double somme_tableau2D(double** tableau, int nb_ligne, int nb_colonne)
{
    double resultat = 0;

    for(int ligne = 0; ligne < nb_ligne; ligne++) {

        for (int col = 0; col < nb_colonne; col++) {

            resultat += tableau[ligne][col];

        }
    }

    return resultat;
}


//
//  Cette fonction multiplie chacune des cases du tableau 2D avec un facteur multiplicatif.
//
void produit_par_scalaire2D(double** tableau, int nb_ligne, int nb_colonne, double facteur)
{

    for(int ligne = 0; ligne < nb_ligne; ligne++) {

        for (int col = 0; col < nb_colonne; col++) {

            tableau[ligne][col] = tableau[ligne][col] * facteur;

        }
    }

}


//
//  Cette fonction applique une puissance à chacune des cases du tableau 2D.
//
void puissance_tableau2D(double** tableau, int nb_ligne, int nb_colonne, double puissance)
{

    for(int ligne = 0; ligne < nb_ligne; ligne++) {

        for (int col = 0; col < nb_colonne; col++) {

            tableau[ligne][col] = pow(tableau[ligne][col],puissance);

        }
    }

}


//
//  Cette fonction multiplie deux tableaux 2D case par case et inscrit les
//  résultats dans un nouveau tableau 2D.
//
void produit_tableau2D(double** tableau1, double** tableau2, int nb_ligne, int nb_colonne, double*** resultat)
{

    for(int ligne = 0; ligne < nb_ligne; ligne++) {

        for (int col = 0; col < nb_colonne; col++) {

            (*resultat)[ligne][col] = tableau1[ligne][col] * tableau2[ligne][col];

        }
    }

}