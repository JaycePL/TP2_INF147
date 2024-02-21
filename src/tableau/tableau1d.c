/****************************************************************************************
    TABLEAU_1D

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
void afficher_tableau1D(double tableau[],int nb_element)
{
    for(int index = 0; index < nb_element; index++)
    {
        printf("%0.3lf   ",tableau[index]);
    }
}

double somme_tableau1D(double tableau[],int nb_element)
{
    double somme = 0;
    int i;

    for(i = 0; i < nb_element; i++)
    {
        somme = somme + tableau[i];
    }

    return somme;
}

void produit_tableau1D(double tableau[],int nb_element,double valeur)
{
    double produit = 0;
    int i;

    for(i = 0; i < nb_element; i++)
    {
        produit = tableau[i] * valeur;

        printf("%0.3lf   ",produit);
    }
}

double produit_scalaire1D(double tableau1[],double tableau2[],int nb_element)
{
    double produit_scalaire = 0;
    int i;

    for (i = 0; i < nb_element; i++)
    {
        produit_scalaire = produit_scalaire + tableau1[i] * tableau2[i];
    }

    return produit_scalaire;
}

double* creer_tableau1D(int nb_element)
{
    double* tableau = (double*) calloc(nb_element, sizeof(double));

    return tableau;
}

void detruire_tableau1D(void* pointeur)
{

    free(pointeur);

}


/****************************************************************************************
*                           DEFINTION DES FONCTIONS PRIVEES                            *
****************************************************************************************/
