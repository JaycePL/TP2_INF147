/****************************************************************************************
*                                      MAIN.C                                          *
****************************************************************************************
    Auteurs : Cédric Benoit, Hakim-Anis Hamani et Jasmin Papierz-Lambert
    Date    : 17 mars 2024

    Contient le programme principal du TP.

    Liste des fonctions publiques:
      - tester_tableau1d        : Permet de tester nos fonctions dans tableau1d.c et .h
      - tester_tableau2d        : Permet de tester nos fonctions dans tableau2d.c et .h
      - tester_noyau            : Permet de tester nos fonctions dans noyeau_filtre.c et .h
      - tester_image_gris       : Permet de tester nos fonctions dans image_gris.c et .h

*****************************************************************************************/
#include <stdlib.h>
#include <stdio.h>

#include "image/bitmap.h"
#include "image/image_gris.h"
#include "image/noyeau_filtre.h"
#include "tableau/tableau1d.h"
#include "tableau/tableau2d.h"

#define TAILLE_TABLEAU1D    5
#define TABLEAU1D_1         {1, 2, 3, 4, 5}
#define TABLEAU1D_2         {1.1, 2.5, 3.0, 4.25, 5.123}
#define TABLEAU1D_3         {1.0, 1.0, 1.0, 1.0, 1.0}
#define TABLEAU1D_4         {1, 2, 3, 4, 5}
#define TABLEAU1D_5         {1.5, 2.0, 1.25, 0.5, 0}
#define TABLEAU1D_6         {0, 0, 0, 0, 0}

#define NB_LIGNES_T1_2D     3
#define NB_LIGNES_T2_2D     3
#define NB_LIGNES_T3_2D     3
#define NB_COLONNES_T1_2D   2
#define NB_COLONNES_T2_2D   4
#define NB_COLONNES_T3_2D   2
#define TABLEAU2D_1         {{1,2},{4,5},{7,8}}
#define TABLEAU2D_2         {{1.1,2.1,3.1,0.25},{4.1,5.1,6.1,0.33},{7.1,8.1,9.1,0.80}}
#define TABLEAU2D_3         {{0.25,0.50},{0.75,1.0},{0.33,0.66}}


void tester_tableau1d(void);
void tester_tableau2d(void);
void tester_noyeau(void);
void tester_image_gris(void);


int main(void){

    printf("*********************************************************\n");
    printf("*                      TEST TABLEAU1D                   *\n");
    printf("*********************************************************\n\n");

    tester_tableau1d();

    printf("*********************************************************\n");
    printf("*                      TEST TABLEAU2D                   *\n");
    printf("*********************************************************\n\n");

    tester_tableau2d();

    printf("*********************************************************\n");
    printf("*                        TEST NOYAU                     *\n");
    printf("*********************************************************\n\n");

    tester_noyeau();

    printf("*********************************************************\n");
    printf("*                      TEST IMAGE GRIS                  *\n");
    printf("*********************************************************\n\n");

    tester_image_gris();

    return EXIT_SUCCESS;
}

void tester_tableau1d(void)
{
    double tableau1[TAILLE_TABLEAU1D] = TABLEAU1D_1;
    double tableau2[TAILLE_TABLEAU1D] = TABLEAU1D_2;
    double tableau3[TAILLE_TABLEAU1D] = TABLEAU1D_3;
    double tableau4[TAILLE_TABLEAU1D] = TABLEAU1D_4;
    double tableau5[TAILLE_TABLEAU1D] = TABLEAU1D_5;
    double tableau6[TAILLE_TABLEAU1D] = TABLEAU1D_6;


    printf("FONCTION AFFICHER_TABLEAU1D \n");
    printf("T1 : ");
    afficher_tableau1D(tableau1,5);
    printf("\nT2 : ");
    afficher_tableau1D(tableau2,5);
    printf("\nT3 : ");
    afficher_tableau1D(tableau5,3);

    printf("\n\n\nFONCTION SOMME \n");
    double somme_tableau1 = somme_tableau1D(tableau1,5);
    printf("T1 : %0.3lf \n",somme_tableau1);
    double somme_tableau2 = somme_tableau1D(tableau2,5);
    printf("T2 : %0.3lf \n",somme_tableau2);
    double somme_tableau3 = somme_tableau1D(tableau2,0);
    printf("T3 : %0.3lf \n",somme_tableau3);

    printf("\n\nFONCTION PRODUIT \n");
    printf("T1 : ");
    produit_tableau1D(tableau1,5,5);
    printf("\nT2 : ");
    produit_tableau1D(tableau2,5,0.1);
    printf("\nT3 : ");
    produit_tableau1D(tableau3,3,0);

    printf("\n\n\nFONCTION PRODUIT SCALAIRE \n");
    double produit_scalaire_tableau4_et_5 = produit_scalaire1D(tableau4,tableau5,5);
    printf("T1 : %0.3lf \n",produit_scalaire_tableau4_et_5);
    double produit_scalaire_tableau4_et_6 = produit_scalaire1D(tableau4,tableau6,5);
    printf("T2 : %0.3lf \n",produit_scalaire_tableau4_et_6);

    int nb_element_T1 = 5;
    int nb_element_T2 = 3;
    printf("\n\nFONCTION CREER TABLEAU \n");
    printf("\nT1 : ");
    double* T1 = creer_tableau1D(nb_element_T1);
    for (int i = 0; i < nb_element_T1; i++)
    {
        double cellule = T1[i];
        printf("%0.3lf  ",cellule);
    }
    printf("\nT2 : ");
    double* T2 = creer_tableau1D(nb_element_T2);
    for (int i = 0; i < nb_element_T2; i++)
    {
        double cellule = T2[i];
        printf("%0.3lf  ",cellule);
    }

    detruire_tableau1D(&T1);
    detruire_tableau1D(&T2);
    printf("\n\nFONCTION DETRUIRE TABLEAU \n");
    printf("\n T1 : %0.lf",&*T1);
    printf("\n T2 : %0.lf",&*T2);
    printf("\n\n");
}

void tester_tableau2d(void)
{
    double tableau1[NB_LIGNES_T1_2D][NB_COLONNES_T1_2D]= TABLEAU2D_1;
    double tableau2[NB_LIGNES_T2_2D][NB_COLONNES_T2_2D]= TABLEAU2D_2;
    double tableau3[NB_LIGNES_T3_2D][NB_COLONNES_T3_2D]= TABLEAU2D_3;

    double** T1 = creer_tableau2D(NB_LIGNES_T1_2D,NB_COLONNES_T1_2D);
    double** T2 = creer_tableau2D(NB_LIGNES_T2_2D,NB_COLONNES_T2_2D);
    double** T3 = creer_tableau2D(NB_LIGNES_T3_2D,NB_COLONNES_T3_2D);

    for(int ligne = 0; ligne < NB_LIGNES_T1_2D; ligne++)
    {

        for (int col = 0; col < NB_COLONNES_T1_2D; col++)
        {

            T1[ligne][col] = tableau1[ligne][col];

        }
    }

    for(int ligne = 0; ligne < NB_LIGNES_T2_2D; ligne++)
    {

        for (int col = 0; col < NB_COLONNES_T2_2D; col++)
        {

            T2[ligne][col] = tableau2[ligne][col];

        }
    }

    for(int ligne = 0; ligne < NB_LIGNES_T3_2D; ligne++)
    {

        for (int col = 0; col < NB_COLONNES_T3_2D; col++)
        {

            T3[ligne][col] = tableau3[ligne][col];

        }
    }

    printf("\nFONCTION AFFICHER_TABLEAU2D \n");
    printf("\nT1 : \n");
    afficher_tableau2D(T1,NB_LIGNES_T1_2D,NB_COLONNES_T1_2D);
    printf("\nT2 : \n");
    afficher_tableau2D(T2,NB_LIGNES_T2_2D,NB_COLONNES_T2_2D);
    printf("\nT3 : \n");
    afficher_tableau2D(T3,NB_LIGNES_T3_2D,NB_COLONNES_T3_2D);

    detruire_tableau2D(&T1, NB_LIGNES_T1_2D);
    detruire_tableau2D(&T2, NB_LIGNES_T2_2D);
    detruire_tableau2D(&T3, NB_LIGNES_T3_2D);

    T1 = creer_tableau2D(NB_LIGNES_T1_2D,NB_COLONNES_T1_2D);
    T2 = creer_tableau2D(NB_LIGNES_T2_2D,NB_COLONNES_T2_2D);
    T3 = creer_tableau2D(NB_LIGNES_T3_2D,NB_COLONNES_T3_2D);

    initialiser_tableau2D(T2,NB_LIGNES_T2_2D,NB_COLONNES_T2_2D,8);

    printf("\nFONCTION INITIALISER TABLEAU \n");
    printf("\nT1 : \n");
    afficher_tableau2D(T2,NB_LIGNES_T2_2D,NB_COLONNES_T2_2D);

    for(int ligne = 0; ligne < NB_LIGNES_T2_2D; ligne++)
    {

        for (int col = 0; col < NB_COLONNES_T2_2D; col++)
        {

            T2[ligne][col] = tableau2[ligne][col];

        }
    }

    for(int ligne = 0; ligne < NB_LIGNES_T1_2D; ligne++)
    {

        for (int col = 0; col < NB_COLONNES_T1_2D; col++)
        {

            T1[ligne][col] = tableau1[ligne][col];

        }
    }

    double resultat_tableau1 = somme_tableau2D(T1,NB_LIGNES_T1_2D,NB_COLONNES_T1_2D);
    double resultat_tableau2 = somme_tableau2D(T2,NB_LIGNES_T2_2D,NB_COLONNES_T2_2D);

    printf("\n\nFONCTION SOMME \n");
    printf("\nT1 : %0.3lf",resultat_tableau1);
    printf("\nT2 : %0.3lf",resultat_tableau2);

    produit_par_scalaire2D(T1,NB_LIGNES_T1_2D,NB_COLONNES_T1_2D,0.1);
    produit_par_scalaire2D(T2,NB_LIGNES_T2_2D,NB_COLONNES_T2_2D,10);

    printf("\n\nFONCTION PRODUIT PAR SCALAIRE \n");
    printf("\nT1 : \n");
    afficher_tableau2D(T1,NB_LIGNES_T1_2D,NB_COLONNES_T1_2D);
    printf("\nT2 : \n");
    afficher_tableau2D(T2,NB_LIGNES_T2_2D,NB_COLONNES_T2_2D);

    for(int ligne = 0; ligne < NB_LIGNES_T1_2D; ligne++)
    {

        for (int col = 0; col < NB_COLONNES_T1_2D; col++)
        {

            T1[ligne][col] = tableau1[ligne][col];

        }
    }

    for(int ligne = 0; ligne < NB_LIGNES_T2_2D; ligne++)
    {

        for (int col = 0; col < NB_COLONNES_T2_2D; col++)
        {

            T2[ligne][col] = tableau2[ligne][col];

        }
    }

    printf("\n\nFONCTION PUISSANCE \n");
    printf("\nT1 : \n");
    puissance_tableau2D(T1,NB_LIGNES_T1_2D,NB_COLONNES_T1_2D,2);
    afficher_tableau2D(T1,NB_LIGNES_T1_2D,NB_COLONNES_T1_2D);
    printf("\nT2 : \n");
    puissance_tableau2D(T2,NB_LIGNES_T2_2D,NB_COLONNES_T2_2D,0.5);
    afficher_tableau2D(T2,NB_LIGNES_T2_2D,NB_COLONNES_T2_2D);

    for(int ligne = 0; ligne < NB_LIGNES_T1_2D; ligne++)
    {

        for (int col = 0; col < NB_COLONNES_T1_2D; col++)
        {

            T1[ligne][col] = tableau1[ligne][col];

        }
    }

    for(int ligne = 0; ligne < NB_LIGNES_T2_2D; ligne++)
    {

        for (int col = 0; col < NB_COLONNES_T2_2D; col++)
        {

            T2[ligne][col] = tableau2[ligne][col];

        }
    }


    printf("\n\nFONCTION PRODUIT \n");
    double** T4 = creer_tableau2D(3,2);
    produit_tableau2D(T1,T2,NB_LIGNES_T1_2D,NB_COLONNES_T1_2D,&T4);
    printf("\nT1 : \n");
    afficher_tableau2D(T1,NB_LIGNES_T1_2D,NB_COLONNES_T1_2D);

    //detruire_tableau2D()

    printf("\n\nFONCTION SOMMES DES COLONNES");
    double* T5 = creer_tableau1D(4);
    sommes_des_colonnes(T2,NB_LIGNES_T2_2D,NB_COLONNES_T2_2D,&T5);
    printf("\nT1 : \n");
    afficher_tableau1D(T5,4);



    printf("\n\nFONCTION SOMMES DES LIGNES");
    double* T6 = creer_tableau1D(4);
    sommes_des_lignes(T2,NB_LIGNES_T2_2D,NB_COLONNES_T2_2D,&T6);
    printf("\nT1 : \n");
    afficher_tableau1D(T6,4);


    printf("\n\nFONCTION SOUS TABLEAU\n");
    double** T7 = creer_tableau2D(2,3);
    sous_tableau(T2,NB_LIGNES_T2_2D,NB_COLONNES_T2_2D,&T7,1,0,2,3);
    printf("\nT1 : \n");
    afficher_tableau2D(T7,2,3);

/*
    detruire_tableau2D(&T1, NB_LIGNES_T1_2D);
    detruire_tableau2D(&T2, NB_LIGNES_T2_2D);
    detruire_tableau2D(&T3, NB_LIGNES_T3_2D);

    printf("\nFONCTION DETRUIRE TABLEAU \n");
    printf("\nT1 : %i",(void*)T1);
    printf("\nT2 : %i",(void*)T2);
    printf("\nT3 : %i\n",(void*)T3);
*/
}

void tester_noyeau(void) {
    printf("PASSE HAUT\n");
    t_filtre *filtre_haut = filtre_passe_haut();
    afficher_tableau2D(filtre_haut->data, 3,3);

    printf("\n\nPASSE BAS\n");

    t_filtre *filtre_bas = filtre_passe_bas();
    afficher_tableau2D(filtre_bas->data, 3,3);

    printf("\n\nMOYEN\n");

    t_filtre *moyenneur = filtre_passe_moyenneur();
    afficher_tableau2D(moyenneur->data, 3,3);

    printf("\n\nLAPLACIEN\n");

    t_filtre *laplacien = filtre_laplacien();
    afficher_tableau2D(laplacien->data, 3,3);

    detruire_filtre(laplacien);
    detruire_filtre(moyenneur);
    detruire_filtre(filtre_bas);
    detruire_filtre(filtre_haut);


}

void tester_image_gris(void) {
    void* image;
    int   a_ete_charger;
    int   nb_lignes;
    int   nb_colonnes;

    printf("Charger plaque_test_1.bmp\n");
    a_ete_charger = lire("..\\data\\plaque_test_1.bmp", &image,&nb_lignes,&nb_colonnes);
    if(a_ete_charger)
    {
        printf("Appliquer la fonction negatif.\n");
        negatif(image, nb_lignes,nb_colonnes);
        printf("Enregistrer sous.\n");
        ecrire("..\\data\\resultat_negatif1.bmp", image, nb_lignes,nb_colonnes);
        printf("resultat_negatif1.bmp\n");
    }
    detruire(image, nb_lignes, nb_colonnes);

    printf("Charger plaque_test_1.bmp\n");

    a_ete_charger = lire("..\\data\\plaque_test_2.bmp", &image, &nb_lignes, &nb_colonnes);

    if(a_ete_charger)
    {
        printf("Appliquer la fonction negatif.\n");
        negatif(image, nb_lignes,nb_colonnes);
        printf("Enregistrer sous.\n");
        ecrire("..\\data\\resultat_negatif2.bmp", image, nb_lignes,nb_colonnes);
        printf("resultat_negatif1.bmp\n");
    }

    detruire(image, nb_lignes, nb_colonnes);

    a_ete_charger = lire("..\\data\\plaque_test_1.bmp", &image, &nb_lignes, &nb_colonnes);

    if(a_ete_charger)
    {
        printf("Seuillez avec un seuil 0.5 \n");
        seuiller(image, nb_lignes,nb_colonnes,0.5);
        printf("Enregistrer sous.\n");
        ecrire("..\\data\\resultat_seuil1.bmp", image, nb_lignes,nb_colonnes);
       printf("resultat_seuillez1.bmp\n");
    }

    detruire(image, nb_lignes, nb_colonnes);

    a_ete_charger = lire("..\\data\\plaque_test_2.bmp", &image, &nb_lignes, &nb_colonnes);

    if(a_ete_charger)
    {
        printf("Seuillez avec un seuil 0.25 \n");
        seuiller(image, nb_lignes,nb_colonnes,0.25);
        printf("Enregistrer sous.\n");
        ecrire("..\\data\\resultat_seuil2.bmp", image, nb_lignes,nb_colonnes);
        printf("resultat_seuillez1.bmp\n");
    }
    a_ete_charger = lire("..\\data\\plaque_test_1.bmp", &image, &nb_lignes, &nb_colonnes);

    if(a_ete_charger)
    {
        double *histo = histogramme(image, nb_lignes,nb_colonnes,10);
        printf("plaques1 - 10 classes : ");
        afficher_tableau1D(histo,10);
        detruire_tableau1D(&histo);
    }

    a_ete_charger = lire("..\\data\\plaque_test_1.bmp", &image, &nb_lignes, &nb_colonnes);

    if(a_ete_charger)
    {
        double *histo = histogramme(image, nb_lignes,nb_colonnes,15);
        printf("\n \nplaques1 - 15 classes : ");
        afficher_tableau1D(histo,15);
        detruire_tableau1D(&histo);
    }

    a_ete_charger = lire("..\\data\\plaque_test_1.bmp", &image, &nb_lignes, &nb_colonnes);

    if(a_ete_charger)
    {
        t_filtre *filtre_bas = filtre_passe_bas();
        filtrer(image, nb_lignes,nb_colonnes,filtre_bas);
        printf("Enregistrer sous.\n");
        ecrire("..\\data\\resultat_passe_bas1.bmp", image, nb_lignes,nb_colonnes);
        printf("resultat_passe_bas1.bmp\n");
    }

    a_ete_charger = lire("..\\data\\plaque_test_2.bmp", &image, &nb_lignes, &nb_colonnes);

    if(a_ete_charger)
    {
        t_filtre *filtre_haut = filtre_passe_haut();
        filtrer(image, nb_lignes,nb_colonnes,filtre_haut);
        printf("Enregistrer sous.\n");
        ecrire("..\\data\\resultat_passe_haut2.bmp", image, nb_lignes,nb_colonnes);
        printf("resultat_passe_haut2.bmp\n");
    }

    a_ete_charger = lire("..\\data\\plaque_test_1.bmp", &image, &nb_lignes, &nb_colonnes);
    if(a_ete_charger)
    {
        t_filtre *filtre_lapl = filtre_laplacien();
        seuiller(image, nb_lignes,nb_colonnes,0.5);
        filtrer(image, nb_lignes,nb_colonnes,filtre_lapl);
        negatif(image, nb_lignes,nb_colonnes);
        printf("Enregistrer sous.\n");
        ecrire("..\\data\\resultat_laplacien1.bmp", image, nb_lignes,nb_colonnes);
        printf("resultat_laplacien1.bmp\n");
    }

    a_ete_charger = lire("..\\data\\plaque_test_2.bmp", &image, &nb_lignes, &nb_colonnes);
    if(a_ete_charger)
    {
        t_filtre *filtre_lapl = filtre_laplacien();
        seuiller(image, nb_lignes,nb_colonnes,0.25);
        filtrer(image, nb_lignes,nb_colonnes,filtre_lapl);
        printf("Enregistrer sous.\n");
        ecrire("..\\data\\resultat_laplacien2.bmp", image, nb_lignes,nb_colonnes);
        printf("resultat_laplacien1.bmp\n");
    }

}
