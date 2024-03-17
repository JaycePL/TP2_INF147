/****************************************************************************************
/*                                     NOYAU_FILTRE.H                                   *
/****************************************************************************************
    Auteurs : Cédric Benoit, Hakim-Anis Hamani et Jasmin Papierz-Lambert
    Date    : 17 mars 2024

    Ce module contient la définition d'un nouveau type de même que 5 fonctions pour
    manipuler des tableaux 2D de réels.

    Liste des fonctions publiques:
      - filtre_passe_haut    : Retourne le tableau 3x3 décrivant le filtre passe-haut.
      - filtre_passe_bas     : Retourne le tableau 3x3 décrivant le filtre passe-bas.
      - filtre_moyenneur     : Retourne le tableau 3x3 décrivant le filtre moyenneur.
      - filtre_laplacien     : Retourne le tableau 3x3 décrivant le filtre laplacien.
      - detruire_filtre      : Libère la mémoire qu'occupait le filtre.

*****************************************************************************************/

#ifndef NOYEAU_FILTRE
#define NOYEAU_FILTRE


typedef struct {       // Nombre de colonnes
    double **data;    // Tableau 2D dynamique contenant les valeurs de la liste
} t_filtre;

/****************************************************************************************
*                               DEFINTION DES CONSTANTES                                *
****************************************************************************************/

//
#define DIMENSION 3

//
#define NB_POINTS 3

/****************************************************************************************
*                       DECLARATION DES FONCTIONS PUBLIQUES                             *
****************************************************************************************/

/*
    FILTRE_PASSE_HAUT

    Cette fonction affiche le noyau du filtre passe-haut ayant comme valeur : 1  1  1
                                                                              1  4  1
                                                                              1  1  1
    PARAMÈTRE :
        - Aucun

    RETOUR :
        - Le tableau 3x3 décrivant le filtre passe-haut.
*/
t_filtre *filtre_passe_haut();



/*
    FILTRE_PASSE_BAS

    Cette fonction affiche le noyau du filtre passe-bas ayant comme valeur :   0 -1  0
                                                                              -1  5 -1
                                                                               0 -1  0
    PARAMÈTRE :
        - Aucun

    RETOUR :
        - Le tableau 3x3 décrivant le filtre passe-bas.
*/
t_filtre *filtre_passe_bas();



/*
    FILTRE_PASSE_MOYENNEUR

    Cette fonction affiche le noyau du filtre moyenneur ayant comme valeur :   1/9 1/9 1/9
                                                                               1/9 1/9 1/9
                                                                               1/9 1/9 1/9
    PARAMÈTRE :
        - Aucun

    RETOUR :
        - Le tableau 3x3 décrivant le filtre moyenneur.
*/
t_filtre *filtre_passe_moyenneur();



/*
    FILTRE_LAPLACIEN

    Cette fonction affiche le noyau du filtre laplacien ayant comme valeur :  1   1   1
                                                                              1  -8   1
                                                                              1   1   1
    PARAMÈTRE :
        - Aucun

    RETOUR :
        - Le tableau 3x3 décrivant le filtre laplacien.
*/
t_filtre *filtre_laplacien();



/*
    DETRUIRE_FILTRE

    Cette fonction libère la mémoire qu'occupe le filtre libéré.

    PARAMÈTRE :
        - t_filtre   : Un filtre créé par une des fonctions précédente.

    RETOUR :
        - Aucun
*/
void detruire_filtre(t_filtre *filtre);
#endif