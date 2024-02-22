/****************************************************************************************
    TABLEAU_2D

*****************************************************************************************/
#include <stdio.h>
#include <stdlib.h>

/****************************************************************************************
*                               DEFINTION DES CONSTANTES                                *
****************************************************************************************/



/****************************************************************************************
*                           DECLARATION DES FONCTIONS PRIVEES                           *
****************************************************************************************/



/****************************************************************************************
*                           DEFINTION DES FONCTIONS PUBLIQUES                            *
****************************************************************************************/
void* creer_tableau2D(int nb_lignes,int nb_colonnes)
{
    double** tableau;

    tableau = (double**) calloc(nb_lignes, sizeof(double*));
    for(int i = 0; i < nb_lignes; i++)
    {
        tableau[i] = (double*) calloc(nb_colonnes, sizeof(double));
    }

    return tableau;
}

void detruire_tableau2D(double** pointeur,int nb_lignes)
{
    for(int i = 0; i < nb_lignes; i++)
    {
        free(pointeur[i]);
    }

    free(pointeur);
}