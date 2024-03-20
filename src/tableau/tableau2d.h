/****************************************************************************************
/*                                     TABLEAU2D.H                                      *
/****************************************************************************************
    Auteurs : C�dric Benoit, Hakim-Anis Hamani et Jasmin Papierz-Lambert
    Date    : 17 mars 2024

    Ce module contient des fonctions pour manipuler des tableaux 2D de r�els.

    Liste des fonctions publiques:
      - creer_tableau2D        : Cr�e un tableau dynamique 2D.
      - detruire_tableau2D     : D�truit un tableau dynamique 2D.
      - afficher_tableau2D     : Affiche les valeurs d'un tableau 2D.
      - initialiser_tableau2D  : Initialise toutes les cases du tableau 2D avec la valeur
                                 assigner.
      - somme_tableau2D        : Retourne la somme de toutes les cases du tableau 2D.
      - produit_par_scalaire2D : Multiplie chacune des cases du tableau 2D avec un
                                 facteur multiplicatif.
      - puissance_tableau2D    : Applique une puissance � chacune des cases du tableau 2D.
      - produit_tableau2D      : Multiplie deux tableaux 2D case par case et inscrit les
                                 r�sultats dans un nouveau tableau 2D.
      - sommes_des_colonnes    : Fait la somme des colonnes d'un tableau 2D et accumule
                                 les r�sultats dans un tableau dynamique 1D.
      - sommes_des_lignes      : Fait la somme des lignes d'un tableau 2D et accumule
                                 les r�sultats dans un tableau dynamique 1D.
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

    Cette fonction cr�e un tableau dynamique 2D en allouant la m�moire n�cessaire pour que le
    tableau dynamique poss�de le bon nombre de ligne et de colonne. Finalement, il se
    fait initialiser � 0.

    PARAM�TRES :
        - nb_ligne     : Le nombre de lignes du un nouveau tableau dynamique 2D.
        - nb_colonne   : Le nombre de colonnes du un nouveau tableau dynamique 2D.

    RETOUR :
        - L'adresse du nouveau tableau dynamique cr��.
*/
void* creer_tableau2D(int nb_ligne,int nb_colonne);



/*
    DETRUIRE_TABLEAU2D

    Cette fonction cr�e un tableau dynamique 2D en allouant la m�moire n�cessaire pour que le
    tableau dynamique poss�de le bon nombre de ligne et de colonne. Finalement, il se
    fait initialiser � 0.

    PARAM�TRES :
        - pointeur     : Un pointeur vers l'adresse d'un tableau dynamique 2D � d�truire.
        - nb_ligne     : Le nombre de lignes de ce tableau.

    RETOUR :
        - Aucun
*/
void detruire_tableau2D(double*** pointeur,int nb_ligne);



/*
    AFFICHER_TABLEAU2D

    Cette fonction affiche les valeurs d'un tableau 2D.

    PARAM�TRES :
        - tableau      : Le tableau dynamique 2D.
        - nb_ligne     : Le nombre de lignes du tableau dynamique 2D.
        - nb_colonne   : Le nombre de colonnes du tableau dynamique 2D.

    RETOUR :
        - Aucun
*/
void afficher_tableau2D(double** tableau, int nb_ligne, int nb_colonne);



/*
    INITIALISER_TABLEAU2D

    Cette fonction initialise toutes les cases du tableau 2D avec la valeur � assigner.

    PARAM�TRES :
        - tableau      : Le tableau dynamique 2D � initialiser.
        - nb_ligne     : Le nombre de lignes du tableau dynamique 2D.
        - nb_colonne   : Le nombre de colonnes du tableau dynamique 2D.
        - valeur       : La valeur � assigner � toutes les cases du tableau.

    RETOUR :
        - Aucun
*/
void initialiser_tableau2D(double** tableau, int nb_ligne, int nb_colonne, double valeur);



/*
    SOMME_TABLEAU2D

    Cette fonction parcours toutes les cases du tableau re�u et fait la somme de
    toutes les cases du tableau 2D.

    PARAM�TRES :
        - tableau      : Le tableau dynamique 2D � analyser.
        - nb_ligne     : Le nombre de lignes du tableau dynamique 2D.
        - nb_colonne   : Le nombre de colonnes du tableau dynamique 2D.

    RETOUR :
        - La somme de toutes les cases du tableau 2D.
*/
double somme_tableau2D(double** tableau, int nb_ligne, int nb_colonne);



/*
    PRODUIT_PAR_SCALAIRE2D

    Cette fonction parcours toutes les cases du tableau re�u et multiplie chacune
    des cases par le facteur multiplicatif re�u.

    PARAM�TRES :
        - tableau      : Le tableau dynamique 2D � modifier.
        - nb_ligne     : Le nombre de lignes du tableau dynamique 2D.
        - nb_colonne   : Le nombre de colonnes du tableau dynamique 2D.
        - facteur      : Le facteur multiplicatif � appliquer � toutes les cases du tableau.

    RETOUR :
        - Aucun
*/
void produit_par_scalaire2D(double** tableau, int nb_ligne, int nb_colonne, double facteur);



/*
    PUISSANCE_TABLEAU2D

    Cette fonction parcours toutes les cases du tableau re�u et applique la puissance re�ue
    � chacune des cases du tableau.

    PARAM�TRES :
        - tableau      : Le tableau dynamique 2D � modifier.
        - nb_ligne     : Le nombre de lignes du tableau dynamique 2D.
        - nb_colonne   : Le nombre de colonnes du tableau dynamique 2D.
        - puissance    : La puissance � appliquer � toutes les cases du tableau.

    RETOUR :
        - Aucun
*/
void puissance_tableau2D(double** tableau, int nb_ligne, int nb_colonne, double puissance);



/*
    PRODUIT_TABLEAU2D

    Cette fonction parcours tous les �l�ments du premier tableau re�u et multiplie l'�l�ment courant
    avec l'�l�ment correspondant du second tableau. Finalement, la r�ponse de la multiplication est
    inscrite dans la case correspondante du tableau de r�sultat.

    PARAM�TRES :
        - tableau1      : Le premier tableau 2D.
        - tableau2      : Le deuxieme tableau 2D.
        - nb_ligne      : Le nombre de lignes qui correspond au deux tableaux 2D.
        - nb_colonne    : Le nombre de colonnes qui correspond au deux tableaux 2D.
        - resultat      : Un pointeur vers un tableau 2D qui recevra les r�sultats de ce calcul.

    RETOUR :
        - Aucun
*/
void produit_tableau2D(double** tableau1, double** tableau2, int nb_ligne, int nb_colonne, double*** resultat);



/*
    SOMMES_DES_COLONNES

    Cette fonction calcule la somme de chacune des colonnes d'un tableau 2D et accumule les r�sultats dans un tableau
    dynamique 1D.

    PARAM�TRES :
        - tableau_entree      : Le tableau 2D qui sera analys�.
        - nb_ligne            : Le nombre de lignes qui correspond au tableaux 2D.
        - nb_colonne          : Le nombre de colonnes qui correspond au tableaux 2D.
        - tableau_resultat    : Un pointeur vers un tableau 1D qui recevra les r�sultats de ce calcul.

    RETOUR :
        - Aucun
*/
void sommes_des_colonnes(double** tableau_entree, int nb_ligne, int nb_colonne, double** tableau_resultat);



/*
    SOMMES_DES_LIGNES

    Cette fonction calcule la somme de chacune des lignes d'un tableau 2D et accumule les r�sultats dans un tableau
    dynamique 1D.

    PARAM�TRES :
        - tableau_entree      : Le tableau 2D qui sera analys�.
        - nb_ligne            : Le nombre de lignes qui correspond au tableaux 2D.
        - nb_colonne          : Le nombre de colonnes qui correspond au tableaux 2D.
        - tableau_resultat    : Un pointeur vers un tableau 1D qui recevra les r�sultats de ce calcul.

    RETOUR :
        - Aucun
*/
void sommes_des_lignes(double** tableau_entree, int nb_ligne, int nb_colonne, double** tableau_resultat);



/*
    SOUS_TABLEAU

    Cette fonction

    PARAM�TRES :
        - tableau_entree      : Le tableau 2D qui sera analys�.
        - nb_ligne            : Le nombre de lignes qui correspond au tableaux 2D � analyser.
        - nb_colonne          : Le nombre de colonnes qui correspond tableaux 2D � analyser.
        - tableau_resultat    : Un pointeur vers un tableau 2D qui recevra les r�sultats de ce calcul.
        - no_ligne            : Le num�ro de ligne � partir de laquelle la section du sous-tableau sera extraite.
        - no_colonne          : Le num�ro de colonne � partir de laquelle la section du sous-tableau sera extraite.
        - taille_ligne        : Le nombre de ligne que le r�sultat devra avoir.
        - taille_colonne      : Le nombre de colonne que le r�sultat devra avoir.

    RETOUR :
        - Aucun
*/
void sous_tableau(double** tableau_entree, int nb_ligne, int nb_colonne, double*** tableau_resultat, int no_ligne, int no_colonne, int taille_ligne, int taille_colonne);