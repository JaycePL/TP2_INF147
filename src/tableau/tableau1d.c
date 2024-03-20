/****************************************************************************************
/*                                     TABLEAU1D.C                                      *
/****************************************************************************************
    Auteurs : Cédric Benoit, Hakim-Anis Hamani et Jasmin Papierz-Lambert
    Date    : 15 mars 2024

    Ce module contient des fonctions pour manipuler des tableaux 1D de réels.

    Liste des fonctions publiques:
      - afficher_tableau1D  : Retourne l'affichage des valeurs d'un tableau 1D.
      - somme_tableau1D     : Retourne la somme de chacunes des cases d'un tableau 1D.
      - produit_tableau1D   : Retourne le produit de chacunes des cases avec un facteur
                              multiplicatif.
      - produit_scalaire1D  : Retourne la somme des produits scalaires de chaque case
                              entre deux tableaux 1D.
      - creer_tableau1D     : Retourne l'adresse d'un nouveau tableau dynamique.
      - detruire_tableau1D  : Libère le tableau dynamique et remplace son adresse par
                              un pointeur nul.

*****************************************************************************************/
#include <stdio.h>
#include <stdlib.h>

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


//
//  Cette fonction affiche les valeurs d'un tableau 1D.
//
void afficher_tableau1D(double tableau[],int nb_element)
{
    int i;              // Itérateur pour consulter chaque case du tableau.

    // On affiche chaque case du tableau.
    for(i = 0; i < nb_element; i++)
    {
        printf("%0.3lf   ",tableau[i]);
    }
}


//
//  Cette fonction fait la somme de toutes les cases d'un tableau 1D.
//
double somme_tableau1D(double tableau[],int nb_element)
{
    double somme = 0;   // Sommation des valeurs des cases du tableau 1D.
    int i;              // Itérateur pour consulter chaque case du tableau.

    // On fait une sommation de toutes les valeurs des cases.
    for(i = 0; i < nb_element; i++)
    {
        somme = somme + tableau[i];
    }

    return somme;
}


//
//  Cette fonction multiple chacune des cases par un facteur multiplicatif.
//
void produit_tableau1D(double tableau[],int nb_element,double valeur)
{
    double produit = 0;     // Produit entre la valeur de la case et le facteur multiplicatif.
    int i;                  // Itérateur pour consulter chaque case du tableau.

    // On fait le produit de chaque case par le facteur multiplicatif.
    for(i = 0; i < nb_element; i++)
    {
        produit = tableau[i] * valeur;
        tableau[i] = produit;
    }
}


//
//  Cette fonction fait la somme du produit scalaire entre deux tableaux 1D.
//
double produit_scalaire1D(double tableau1[],double tableau2[],int nb_element)
{
    double produit_scalaire = 0;    // Sommation des produits scalaires.
    int i;                          // Itérateur pour consulter chaque case du tableau.

    // On fait le produit scalaire entre les deux tableaux 1D et on fait la sommation de chacune des cases.
    for (i = 0; i < nb_element; i++)
    {
        produit_scalaire = produit_scalaire + tableau1[i] * tableau2[i];
    }

    return produit_scalaire;
}


//
//  Cette fonction alloue la mémoire pour qu'un tableau dynamique possède le bon nombre
//  d'éléments et l'initialise à 0.
//
void* creer_tableau1D(int nb_element)
{
    // On alloue la mémoire pour que le tableau dynamique possède le bon nombre d'éléments et on l'initialise à 0 avec calloc.
    double *tableau = (double*) calloc(nb_element, sizeof(double));

    return tableau;
}


//
//  Cette fonction libère un tableau dynamique en remplaçant l'adresse du tableau
//  dynamique par un pointeur nul.
//
void detruire_tableau1D(double **pointeur)
{
    // Libère le tableau dynamique.
    free(*pointeur);

    // Remplace l'adresse du tableau dynamique par un pointeur nul.
    *pointeur = NULL;
}


/****************************************************************************************
*                           DEFINTION DES FONCTIONS PRIVEES                            *
****************************************************************************************/
