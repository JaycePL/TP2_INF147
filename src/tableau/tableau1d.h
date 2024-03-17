/****************************************************************************************
/*                                     TABLEAU1D.H                                      *
/****************************************************************************************
    Auteurs : C�dric Benoit, Hakim-Anis Hamani et Jasmin Papierz-Lambert
    Date    : 17 mars 2024

    Ce module contient des fonctions pour manipuler des tableaux 1D de r�els.

    Liste des fonctions publiques:
      - afficher_tableau1D  : Retourne l'affichage des valeurs d'un tableau 1D.
      - somme_tableau1D     : Retourne la somme de chacunes des cases d'un tableau 1D.
      - produit_tableau1D   : Retourne le produit de chacunes des cases avec un facteur
                              multiplicatif.
      - produit_scalaire1D  : Retourne la somme des produits scalaires de chaque case
                              entre deux tableaux 1D.
      - creer_tableau1D     : Retourne l'adresse d'un nouveau tableau dynamique.
      - detruire_tableau1D  : Lib�re le tableau dynamique et remplace son adresse par
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

    PARAM�TRES :
        - tableau[]    : Le tableau 1D � afficher.
        - nb_element   : Le nombre d'�l�ments du tableau � afficher.

    RETOUR :
        - Aucun
*/
void afficher_tableau1D(double tableau[],int nb_element);



/*
    SOMME_TABLEAU1D

    Cette fonction parcours tous les �l�ments d'un tableau 1D et fait la somme de chacune
    de ses cases.

    PARAM�TRES :
        - tableau[]    : Le tableau 1D � additionner.
        - nb_element   : Le nombre d'�l�ments du tableau � additionner.

    RETOUR :
        - La somme de chacunes des cases du tableau re�u.
*/
double somme_tableau1D(double tableau[], int nb_element);



/*
    PRODUIT_TABLEAU1D

    Cette fonction parcours tous les �l�ments d'un tableau 1D et multiplie chacune des
    cases par un facteur multiplicatif.

    PARAM�TRES :
        - tableau[]    : Le tableau 1D � multiplier avec le facteur multiplicatif.
        - nb_element   : Le nombre d'�l�ments du tableau � multiplier avec le facteur
                         multiplicatif.
        - valeur       : Le facteur multiplicatif.

    RETOUR :
        - Le produit de chacunes des cases avec le facteur multiplicatif.
*/

void produit_tableau1D(double tableau[],int nb_element,double valeur);



/*
    PRODUIT_SCALAIRE1D

    Cette fonction parcours tous les �l�ments d'un premier tableau 1D et multiplie
    l'�l�ment courant avec l'�l�ment correspondant d'un deuxi�me tableau 1D.
    Finalement, elle fait la somme de chacune des cases.

    PARAM�TRES :
        - tableau1[]    : Le premier tableau 1D.
        - tableau2[]    : Le deuxi�me tableau 1D.
        - nb_element    : Le nombre d'�l�ments des deux tableaux 1D.
                          (Les deux tableaux doivent �tre de la m�me taille)

    RETOUR :
        - La somme des produits scalaires de chacunes des cases.
*/
double produit_scalaire1D(double tableau1[],double tableau2[],int nb_element);



/*
    CREER_TABLEAU1D

    Cette fonction permet d'allouer la m�moire n�cessaire pour que le tableau
    dynamique poss�de le bon nombre d'�l�ments et initialise chacune des cases
    � 0.

    PARAM�TRES :
        - nb_element    : Le nombre d'�l�ments que doit poss�der le tableau.

    RETOUR :
        - L'adresse d'un nouveau tableau dynamique.
*/
void* creer_tableau1D(int nb_element);



/*
    DETRUIRE_TABLEAU1D

    Cette fonction lib�re le tableau dynamique et remplace son adresse par
    un pointeur nul.

    PARAM�TRES :
        - pointeur    : Un pointeur vers l'adresse d'un tableau dynamique �
                        d�truire.

    RETOUR :
        - Aucun
*/
void detruire_tableau1D(double** pointeur);