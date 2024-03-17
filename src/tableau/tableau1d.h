/****************************************************************************************
/*                                     TABLEAU1D.H                                      *
/****************************************************************************************
    Auteurs : Cédric Benoit, Hakim-Anis Hamani et Jasmin Papierz-Lambert
    Date    : 17 mars 2024

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

/****************************************************************************************
*                               DEFINTION DES CONSTANTES                                *
****************************************************************************************/



/****************************************************************************************
*                       DECLARATION DES FONCTIONS PUBLIQUES                             *
****************************************************************************************/

/*
    AFFICHER_TABLEAU1D

    Cette fonction affiche les valeurs d'un tableau 1D.

    PARAMÈTRES :
        - tableau[]    : Le tableau 1D à afficher.
        - nb_element   : Le nombre d'éléments du tableau à afficher.

    RETOUR :
        - Aucun
*/
void afficher_tableau1D(double tableau[],int nb_element);



/*
    SOMME_TABLEAU1D

    Cette fonction parcours tous les éléments d'un tableau 1D et fait la somme de chacune
    de ses cases.

    PARAMÈTRES :
        - tableau[]    : Le tableau 1D à additionner.
        - nb_element   : Le nombre d'éléments du tableau à additionner.

    RETOUR :
        - La somme de chacunes des cases du tableau reçu.
*/
double somme_tableau1D(double tableau[], int nb_element);



/*
    PRODUIT_TABLEAU1D

    Cette fonction parcours tous les éléments d'un tableau 1D et multiplie chacune des
    cases par un facteur multiplicatif.

    PARAMÈTRES :
        - tableau[]    : Le tableau 1D à multiplier avec le facteur multiplicatif.
        - nb_element   : Le nombre d'éléments du tableau à multiplier avec le facteur
                         multiplicatif.
        - valeur       : Le facteur multiplicatif.

    RETOUR :
        - Le produit de chacunes des cases avec le facteur multiplicatif.
*/

void produit_tableau1D(double tableau[],int nb_element,double valeur);



/*
    PRODUIT_SCALAIRE1D

    Cette fonction parcours tous les éléments d'un premier tableau 1D et multiplie
    l'élément courant avec l'élément correspondant d'un deuxième tableau 1D.
    Finalement, elle fait la somme de chacune des cases.

    PARAMÈTRES :
        - tableau1[]    : Le premier tableau 1D.
        - tableau2[]    : Le deuxième tableau 1D.
        - nb_element    : Le nombre d'éléments des deux tableaux 1D.
                          (Les deux tableaux doivent être de la même taille)

    RETOUR :
        - La somme des produits scalaires de chacunes des cases.
*/
double produit_scalaire1D(double tableau1[],double tableau2[],int nb_element);



/*
    CREER_TABLEAU1D

    Cette fonction permet d'allouer la mémoire nécessaire pour que le tableau
    dynamique possède le bon nombre d'éléments et initialise chacune des cases
    à 0.

    PARAMÈTRES :
        - nb_element    : Le nombre d'éléments que doit posséder le tableau.

    RETOUR :
        - L'adresse d'un nouveau tableau dynamique.
*/
void* creer_tableau1D(int nb_element);



/*
    DETRUIRE_TABLEAU1D

    Cette fonction libère le tableau dynamique et remplace son adresse par
    un pointeur nul.

    PARAMÈTRES :
        - pointeur    : Un pointeur vers l'adresse d'un tableau dynamique à
                        détruire.

    RETOUR :
        - Aucun
*/
void detruire_tableau1D(double** pointeur);