/****************************************************************************************
    TABLEAU_1D

*****************************************************************************************/
#include <stdlib.h>
#include <stdio.h>
#include "tableau1d.h"

/****************************************************************************************
*                               DEFINTION DES CONSTANTES                                *
****************************************************************************************/



/****************************************************************************************
*                           DECLARATION DES FONCTIONS PRIVEES                           *
****************************************************************************************/



/****************************************************************************************
*                           DEFINTION DES FONCTIONS PUBLIQUES                            *
****************************************************************************************/
void afficher_tableau1D(double tableau[],int nb_element)
{
    for(int index = 0; index < nb_element; index++)
    {
        printf("%lf  ",tableau[index]);
    }
}

void produit_tableau1D(double tableau[],int nb_element,double valeur)
{
    for(int index = 0; index < nb_element; index++)
    {
        tableau[index] *= tableau[index] * valeur;
    }
}

double produit_scalaire1D(double tableau1[],double tableau2[],int nb_element)
{
    double resultat = 0;

    for(int index = 0; index < nb_element; index++)
    {
        resultat += tableau1[index] * tableau2[index];
    }

    return resultat;
}

/****************************************************************************************
*                           DEFINTION DES FONCTIONS PRIVEES                            *
****************************************************************************************/
