/****************************************************************************************
    TABLEAU_2D

*****************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/****************************************************************************************
*                               DEFINTION DES CONSTANTES                                *
****************************************************************************************/



/****************************************************************************************
*                           DECLARATION DES FONCTIONS PRIVEES                           *
****************************************************************************************/



/****************************************************************************************
*                           DEFINTION DES FONCTIONS PUBLIQUES                            *
****************************************************************************************/
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

void afficher_tableau2D(double** tableau, int nb_ligne, int nb_colonne)
{

    for(int ligne = 0; ligne < nb_ligne; ligne++)
    {

        for(int col = 0; col < nb_colonne; col++)
        {

            printf("%0.3lf   ",tableau[ligne][col]);

        }

        printf("\n");

    }

}

void initialiser_tableau2D(double** tableau, int nb_ligne, int nb_colonne, double valeur)
{

    for(int ligne = 0; ligne < nb_ligne; ligne++) {

        for (int col = 0; col < nb_colonne; col++) {

            tableau[ligne][col] = valeur;

        }
    }
}

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

void produit_par_scalaire2D(double** tableau, int nb_ligne, int nb_colonne, double facteur)
{

    for(int ligne = 0; ligne < nb_ligne; ligne++) {

        for (int col = 0; col < nb_colonne; col++) {

            tableau[ligne][col] = tableau[ligne][col] * facteur;

        }
    }

}

void puissance_tableau2D(double** tableau, int nb_ligne, int nb_colonne, double puissance)
{

    for(int ligne = 0; ligne < nb_ligne; ligne++) {

        for (int col = 0; col < nb_colonne; col++) {

            tableau[ligne][col] = pow(tableau[ligne][col],puissance);

        }
    }

}

void produit_tableau2D(double** tableau1, double** tableau2, int nb_ligne, int nb_colonne, double*** resultat)
{

    for(int ligne = 0; ligne < nb_ligne; ligne++) {

        for (int col = 0; col < nb_colonne; col++) {

            (*resultat)[ligne][col] = tableau1[ligne][col] * tableau2[ligne][col];

        }
    }

}