/****************************************************************************************
Noyeau_filtre.c

*****************************************************************************************/
#include "noyeau_filtre.h"

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
T_liste *filtre_passe_haut(){

    T_liste *filtre_passe_haut = malloc(sizeof(T_liste));
    filtre_passe_haut->data = creer_tableau2D(DIMENSION,NB_POINTS);
    for (int i = 0; i < DIMENSION; ++i) {
        for (int j = 0; j < NB_POINTS; ++j) {
            if(i == 1 && j == 1 ) {
                filtre_passe_haut->data[i][j] = 4;
            }
            else filtre_passe_haut->data[i][j] = 1;
        }
    }
    return filtre_passe_haut;
}

T_liste *filtre_passe_bas(){

    T_liste *filtre_passe_bas = malloc(sizeof(T_liste));
    filtre_passe_bas->data = creer_tableau2D(DIMENSION,NB_POINTS);
    int conteurImpair = 0;
    for (int i = 0; i < DIMENSION; ++i) {
        for (int j = 0; j < NB_POINTS; ++j) {

            if(i == 1 && j == 1 ) {
                filtre_passe_bas->data[i][j] = 5;
            }
            if (conteurImpair % 2 == 1) filtre_passe_bas->data[i][j] = -1;
            else filtre_passe_bas->data[i][j] = 0;
            conteurImpair++;
        }
    }
    return filtre_passe_bas;
}

T_liste *filtre_passe_moyenneur(){

    T_liste *filtre_passe_moyenneur= malloc(sizeof(T_liste));
    filtre_passe_moyenneur->data = creer_tableau2D(DIMENSION,NB_POINTS);
    for (int i = 0; i < DIMENSION; ++i) {
        for (int j = 0; j < NB_POINTS; ++j) {
            filtre_passe_moyenneur->data[i][j] = 1.0/9.0;
        }
    }
    return filtre_passe_moyenneur;
}

T_liste *filtre_laplacien(){

    T_liste *filtre_laplacien = malloc(sizeof(T_liste));
    filtre_laplacien->data = creer_tableau2D(DIMENSION,NB_POINTS);
    for (int i = 0; i < DIMENSION; ++i) {
        for (int j = 0; j < NB_POINTS; ++j) {
            if(i == 1 && j == 1 ) {
                filtre_laplacien->data[i][j] = -8;
            }
            else filtre_laplacien->data[i][j] = 1;
        }
    }
    return filtre_laplacien;
}

void detruire_filtre(T_liste *filtre) {
    free(filtre);
    filtre = NULL;
}

