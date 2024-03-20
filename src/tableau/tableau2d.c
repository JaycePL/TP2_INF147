/****************************************************************************************
/*                                     TABLEAU2D.H                                      *
/****************************************************************************************
    Auteurs : Cédric Benoit, Hakim-Anis Hamani et Jasmin Papierz-Lambert
    Date    : 17 mars 2024

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
      - sommes_des_colonnes    : Fait la somme des colonnes d'un tableau 2D et accumule
                                 les résultats dans un tableau dynamique 1D.
      - sommes_des_lignes      : Fait la somme des lignes d'un tableau 2D et accumule
                                 les résultats dans un tableau dynamique 1D.
      - sous_tableau           : Crée un tableau dynamique avec la bonne taille et parcours
                                 les cases du tableau 2D puis copiez dans le sous-tableau
                                 le bon nombre d'élément.

*****************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "tableau2d.h"
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
//  Cette fonction crée un tableau 2D.
//
void* creer_tableau2D(int nb_ligne,int nb_colonne)
{
    // On créé un tableau de réels.
    double** tableau;

    // On alloue en mémoire l'espace requis pour le type de tableau et le nb de lignes nécessaire.
    // On initialise les cases créé a 0 pour bonne mesure.
    tableau = (double**) calloc(nb_ligne, sizeof(double*));

    // Après l'allocation de base, on alloue la mémoire pour le nb de cases comprisent dans nb_colonne.
    // On initialise les cases créé a 0 pour bonne mesure.
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
    // On parcours l'adresse de chaque ligne du tableau en mémoire.
    for(int i = 0; i < nb_ligne; i++)
    {
        // On libère la mémoire a cette adresse.
        free((*pointeur)[i]);
        // On modifie le pointeur de la ligne pour qu'il pointe nulle part.
        (*pointeur)[i] = NULL;
    }

    // On libère la mémoire du tableau lorsque toute les lignes ont été fait.
    free(*pointeur);

    // On modifie le pointeur du tableau pour qu'il pointe nulle part.
    *pointeur = NULL;
}


//
//  Cette fonction affiche les valeurs d'un tableau 2D.
//
void afficher_tableau2D(double** tableau, int nb_ligne, int nb_colonne)
{

    // On parcourt chque ligne du tableau.
    for(int i = 0; i < nb_ligne; i++)
    {
        // On parcourt chaque case selon le nb de colonnes.
        for(int j = 0; j < nb_colonne; j++)
        {
            // on vérifie si la case est dans le négatif et on applique le format adéquat.
            if (tableau[i][j] < 0) printf("%0.3lf  ",tableau[i][j]);
            //sinon on applique le format standard.
            else printf(" %0.3lf  ",tableau[i][j]);
        }

        // On créé une nouvelle ligne lorsque toutes les cases d'une ligne on été affiché.
        printf("\n");

    }

}


//
//  Cette fonction initialise toutes les cases du tableau 2D avec une valeur assignée.
//
void initialiser_tableau2D(double** tableau, int nb_ligne, int nb_colonne, double valeur)
{

    // On parcourt chaque ligne du tableau.
    for(int i = 0; i < nb_ligne; i++)
    {
        // On parcourt chaque colonne du tableau.
        for (int j = 0; j < nb_colonne; j++)
        {
            // On modifie la case pour y mettre la valeur spécifié dans le paramètre valeur.
            tableau[i][j] = valeur;

        }
    }
}


//
//  Cette fonction fait la somme de toutes les cases du tableau 2D.
//
double somme_tableau2D(double** tableau, int nb_ligne, int nb_colonne)
{
    double resultat = 0; // Ce paramètre en format réel nous sert a faire la somme des résultats.

    // On parcourt chaque ligne du tableau.
    for(int i = 0; i < nb_ligne; i++)
    {

        // On parcourt chaque colonne du tableau.
        for (int j = 0; j < nb_colonne; j++)
        {
            // On fait la somme de la valeur de resultat et de la valeur réelle dans la case actuelle.
            resultat += tableau[i][j];

        }
    }

    return resultat;
}


//
//  Cette fonction multiplie chacune des cases du tableau 2D avec un facteur multiplicatif.
//
void produit_par_scalaire2D(double** tableau, int nb_ligne, int nb_colonne, double facteur)
{
    // On parcourt chaque ligne du tableau.
    for(int i = 0; i < nb_ligne; i++)
    {
        // On parcourt chaque colonne du tableau.
        for (int j = 0; j < nb_colonne; j++)
        {
            // On modifie la case en multipliant la valeure actuelle avec le paramètre facteur.
            tableau[i][j] = tableau[i][j] * facteur;

        }
    }

}


//
//  Cette fonction applique une puissance à chacune des cases du tableau 2D.
//
void puissance_tableau2D(double** tableau, int nb_ligne, int nb_colonne, double puissance)
{
    // On parcourt chaque ligne du tableau.
    for(int i = 0; i < nb_ligne; i++)
    {
        // On parcourt chaque colonne du tableau.
        for (int j = 0; j < nb_colonne; j++)
        {
            // On modifie la case en faisant mettant la valeur actuelle a la puissance du paramètre puissance.
            tableau[i][j] = pow(tableau[i][j],puissance);

        }
    }

}


//
//  Cette fonction multiplie les cases correspondantes de deux tableaux 2D et inscrit les
//  résultats dans un nouveau tableau 2D.
//
void produit_tableau2D(double** tableau1, double** tableau2, int nb_ligne, int nb_colonne, double*** resultat)
{
    // On parcourt chaque ligne des tableaux.
    for(int i = 0; i < nb_ligne; i++)
    {
        // On parcourt chaque colonne des tableaux.
        for (int j = 0; j < nb_colonne; j++)
        {
            // On entre dans le troisième tableau, le résultat du produit des deux premiers tableaux a la case actuelle.
            (*resultat)[i][j] = tableau1[i][j] * tableau2[i][j];

        }
    }

}


//
//  Cette fonction calcule la somme de chacune des colonnes d'un tableau 2D et accumule les résultats dans un tableau
//    dynamique 1D.
//
void sommes_des_colonnes(double** tableau_entree, int nb_ligne, int nb_colonne, double** tableau_resultat)
{
    // On parcourt chaque colonne du tableau.
    for(int j = 0; j < nb_colonne; j++)
    {
        double sommes_colonnes = 0; // Ce paramètre en format réel nous sert a faire la somme des colonnes.

        // On parcourt chaque ligne des tableaux.
        for(int i = 0; i < nb_ligne; i++)
        {
            // Sommation des colonnes.
            sommes_colonnes += tableau_entree[i][j];
        }

        //On entre dans le tableau dynamique 1D, le résultat des sommes des colonnes du tableau 2D reçu.
        *tableau_resultat[j] = sommes_colonnes;
    }
}


//
//  Cette fonction calcule la somme de chacune des lignes d'un tableau 2D et accumule les résultats dans un tableau
//    dynamique 1D.
//
void sommes_des_lignes(double** tableau_entree, int nb_ligne, int nb_colonne, double** tableau_resultat)
{
    // On parcourt chaque ligne des tableaux.
    for(int i = 0; i < nb_ligne; i++)
    {
        double somme_lignes = 0; // Ce paramètre en format réel nous sert a faire la somme des lignes.

        // On parcourt chaque colonne des tableaux.
        for(int j = 0; j < nb_colonne; j++)
        {
            // Sommation des lignes.
            somme_lignes += tableau_entree[i][j];
        }

        //On entre dans le tableau dynamique 1D, le résultat des sommes des lignes du tableau 2D reçu.
        *tableau_resultat[i] = somme_lignes;
    }
}


//
//  Cette fonction crée un tableau dynamique avec la bonne taille reçu en paramètre et parcours les cases du tableau 2D
//     à partir du numéro de ligne et de colonne reçu, puis copiez dans le sous-tableau le bon nombre d'élément.
//
void sous_tableau(double** tableau_entree, int nb_ligne, int nb_colonne, double*** tableau_resultat, int no_ligne, int no_colonne, int taille_ligne, int taille_colonne)
{
    // On parcourt chaque ligne des tableaux.
    for(int i = no_ligne; i <= taille_ligne; i++)
    {
        // On parcourt chaque colonne des tableaux.
        for(int j = no_colonne; j <= taille_colonne; j++)
        {
            //On copie dans le sous tableau les éléments qu'on veut.
            *tableau_resultat[i][j] = tableau_entree[i][j];
        }
    }
}

