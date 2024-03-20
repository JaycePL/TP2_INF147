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
      - sous_tableau           :

*****************************************************************************************/

/****************************************************************************************
*                               DEFINTION DES CONSTANTES                                *
****************************************************************************************/



/****************************************************************************************
*                       DECLARATION DES FONCTIONS PUBLIQUES                             *
****************************************************************************************/

/*
    CREER_TABLEAU2D

    Cette fonction crée un tableau dynamique 2D en allouant la mémoire nécessaire pour que le
    tableau dynamique possède le bon nombre de ligne et de colonne. Finalement, il se
    fait initialiser à 0.

    PARAMÈTRES :
        - nb_ligne     : Le nombre de lignes du un nouveau tableau dynamique 2D.
        - nb_colonne   : Le nombre de colonnes du un nouveau tableau dynamique 2D.

    RETOUR :
        - L'adresse du nouveau tableau dynamique créé.
*/
void* creer_tableau2D(int nb_ligne,int nb_colonne);



/*
    DETRUIRE_TABLEAU2D

    Cette fonction crée un tableau dynamique 2D en allouant la mémoire nécessaire pour que le
    tableau dynamique possède le bon nombre de ligne et de colonne. Finalement, il se
    fait initialiser à 0.

    PARAMÈTRES :
        - pointeur     : Un pointeur vers l'adresse d'un tableau dynamique 2D à détruire.
        - nb_ligne     : Le nombre de lignes de ce tableau.

    RETOUR :
        - Aucun
*/
void detruire_tableau2D(double*** pointeur,int nb_ligne);



/*
    AFFICHER_TABLEAU2D

    Cette fonction affiche les valeurs d'un tableau 2D.

    PARAMÈTRES :
        - tableau      : Le tableau dynamique 2D.
        - nb_ligne     : Le nombre de lignes du tableau dynamique 2D.
        - nb_colonne   : Le nombre de colonnes du tableau dynamique 2D.

    RETOUR :
        - Aucun
*/
void afficher_tableau2D(double** tableau, int nb_ligne, int nb_colonne);



/*
    INITIALISER_TABLEAU2D

    Cette fonction initialise toutes les cases du tableau 2D avec la valeur à assigner.

    PARAMÈTRES :
        - tableau      : Le tableau dynamique 2D à initialiser.
        - nb_ligne     : Le nombre de lignes du tableau dynamique 2D.
        - nb_colonne   : Le nombre de colonnes du tableau dynamique 2D.
        - valeur       : La valeur à assigner à toutes les cases du tableau.

    RETOUR :
        - Aucun
*/
void initialiser_tableau2D(double** tableau, int nb_ligne, int nb_colonne, double valeur);



/*
    SOMME_TABLEAU2D

    Cette fonction parcours toutes les cases du tableau reçu et fait la somme de
    toutes les cases du tableau 2D.

    PARAMÈTRES :
        - tableau      : Le tableau dynamique 2D à analyser.
        - nb_ligne     : Le nombre de lignes du tableau dynamique 2D.
        - nb_colonne   : Le nombre de colonnes du tableau dynamique 2D.

    RETOUR :
        - La somme de toutes les cases du tableau 2D.
*/
double somme_tableau2D(double** tableau, int nb_ligne, int nb_colonne);



/*
    PRODUIT_PAR_SCALAIRE2D

    Cette fonction parcours toutes les cases du tableau reçu et multiplie chacune
    des cases par le facteur multiplicatif reçu.

    PARAMÈTRES :
        - tableau      : Le tableau dynamique 2D à modifier.
        - nb_ligne     : Le nombre de lignes du tableau dynamique 2D.
        - nb_colonne   : Le nombre de colonnes du tableau dynamique 2D.
        - facteur      : Le facteur multiplicatif à appliquer à toutes les cases du tableau.

    RETOUR :
        - Aucun
*/
void produit_par_scalaire2D(double** tableau, int nb_ligne, int nb_colonne, double facteur);



/*
    PUISSANCE_TABLEAU2D

    Cette fonction parcours toutes les cases du tableau reçu et applique la puissance reçue
    à chacune des cases du tableau.

    PARAMÈTRES :
        - tableau      : Le tableau dynamique 2D à modifier.
        - nb_ligne     : Le nombre de lignes du tableau dynamique 2D.
        - nb_colonne   : Le nombre de colonnes du tableau dynamique 2D.
        - puissance    : La puissance à appliquer à toutes les cases du tableau.

    RETOUR :
        - Aucun
*/
void puissance_tableau2D(double** tableau, int nb_ligne, int nb_colonne, double puissance);



/*
    PRODUIT_TABLEAU2D

    Cette fonction parcours tous les éléments du premier tableau reçu et multiplie l'élément courant
    avec l'élément correspondant du second tableau. Finalement, la réponse de la multiplication est
    inscrite dans la case correspondante du tableau de résultat.

    PARAMÈTRES :
        - tableau1      : Le premier tableau 2D.
        - tableau2      : Le deuxieme tableau 2D.
        - nb_ligne      : Le nombre de lignes qui correspond au deux tableaux 2D.
        - nb_colonne    : Le nombre de colonnes qui correspond au deux tableaux 2D.
        - resultat      : Un pointeur vers un tableau 2D qui recevra les résultats de ce calcul.

    RETOUR :
        - Aucun
*/
void produit_tableau2D(double** tableau1, double** tableau2, int nb_ligne, int nb_colonne, double*** resultat);



/*
    SOMMES_DES_COLONNES

    Cette fonction calcule la somme de chacune des colonnes d'un tableau 2D et accumule les résultats dans un tableau
    dynamique 1D.

    PARAMÈTRES :
        - tableau_entree      : Le tableau 2D qui sera analysé.
        - nb_ligne            : Le nombre de lignes qui correspond au tableaux 2D.
        - nb_colonne          : Le nombre de colonnes qui correspond au tableaux 2D.
        - tableau_resultat    : Un pointeur vers un tableau 1D qui recevra les résultats de ce calcul.

    RETOUR :
        - Aucun
*/
void sommes_des_colonnes(double** tableau_entree, int nb_ligne, int nb_colonne, double** tableau_resultat);



/*
    SOMMES_DES_LIGNES

    Cette fonction calcule la somme de chacune des lignes d'un tableau 2D et accumule les résultats dans un tableau
    dynamique 1D.

    PARAMÈTRES :
        - tableau_entree      : Le tableau 2D qui sera analysé.
        - nb_ligne            : Le nombre de lignes qui correspond au tableaux 2D.
        - nb_colonne          : Le nombre de colonnes qui correspond au tableaux 2D.
        - tableau_resultat    : Un pointeur vers un tableau 1D qui recevra les résultats de ce calcul.

    RETOUR :
        - Aucun
*/
void sommes_des_lignes(double** tableau_entree, int nb_ligne, int nb_colonne, double** tableau_resultat);



/*
    SOUS_TABLEAU

    Cette fonction

    PARAMÈTRES :
        - tableau_entree      : Le tableau 2D qui sera analysé.
        - nb_ligne            : Le nombre de lignes qui correspond au tableaux 2D à analyser.
        - nb_colonne          : Le nombre de colonnes qui correspond tableaux 2D à analyser.
        - tableau_resultat    : Un pointeur vers un tableau 2D qui recevra les résultats de ce calcul.
        - no_ligne            : Le numéro de ligne à partir de laquelle la section du sous-tableau sera extraite.
        - no_colonne          : Le numéro de colonne à partir de laquelle la section du sous-tableau sera extraite.
        - taille_ligne        : Le nombre de ligne que le résultat devra avoir.
        - taille_colonne      : Le nombre de colonne que le résultat devra avoir.

    RETOUR :
        - Aucun
*/
void sous_tableau(double** tableau_entree, int nb_ligne, int nb_colonne, double*** tableau_resultat, int no_ligne, int no_colonne, int taille_ligne, int taille_colonne);