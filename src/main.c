#include <stdlib.h>
#include <stdio.h>

#include "image/bitmap.h"
#include "image/image_gris.h"
#include "image/noyeau_filtre.h"
#include "tableau/tableau1d.h"
#include "tableau/tableau2d.h"


void tester_tableau1d(void);
void tester_tableau2d(void);
void tester_noyeau(void);
void tester_image_gris(void);


int main(void){

   /* printf("*********************************************************\n");
    printf("*                      TEST TABLEAU1D                    *\n");
    printf("*********************************************************\n\n");

    tester_tableau1d();

    printf("*********************************************************\n");
    printf("*                      TEST TABLEAU2D                   *\n");
    printf("*********************************************************\n\n");*/

    /*tester_tableau2d();*/

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
    double tableau1[5] = {1, 2, 3, 4, 5};
    double tableau2[5] = {1.1, 2.5, 3.0, 4.25, 5.123 };
    double tableau3[5] = {1.0, 1.0, 1.0, 1.0, 1.0};
    double tableau4[5] = {1, 2, 3, 4, 5};
    double tableau5[5] = {1.5, 2.0, 1.25, 0.5, 0};
    double tableau6[5] = {0, 0, 0, 0, 0};


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
    printf("\n\nFONCTION CREER TABLEAU1D \n");
    printf("\nT1 : ");
    double* T1 = creer_tableau1D(nb_element_T1);
    for (int i = 0; i < nb_element_T1; i++)
    {
        double cellule = T1[i];
        printf("%lf  ",cellule);
    }
    printf("\nT2 : ");
    double* T2 = creer_tableau1D(nb_element_T2);
    for (int i = 0; i < nb_element_T2; i++)
    {
        double cellule = T2[i];
        printf("%lf  ",cellule);
    }

    detruire_tableau1D(&T1);
    detruire_tableau1D(&T2);
    printf("\n\nFONCTION DETRUIRE TABLEAU1D \n");
    printf("\n T1 : %p",&*T1);
    printf("\n T2 : %p",&*T2);
    printf("\n\n");
}

void tester_tableau2d(void)
{
    double tableau1[3][2]={{1,2},{4,5},{7,8}};
    double tableau2[3][4]={{1.1,2.1,3.1,0.25},{4.1,5.1,6.1,0.33},{7.1,8.1,9.1,0.80}};
    double tableau3[3][2]={{0.25,0.50},{0.75,1.0},{0.33,0.66}};

    double** T1 = creer_tableau2D(3,2);
    double** T2 = creer_tableau2D(3,4);
    double** T3 = creer_tableau2D(3,2);

    for(int ligne = 0; ligne < 3; ligne++) {

        for (int col = 0; col < 2; col++) {

            T1[ligne][col] = tableau1[ligne][col];

        }
    }

    for(int ligne = 0; ligne < 3; ligne++) {

        for (int col = 0; col < 4; col++) {

            T2[ligne][col] = tableau2[ligne][col];

        }
    }

    for(int ligne = 0; ligne < 3; ligne++) {

        for (int col = 0; col < 2; col++) {

            T3[ligne][col] = tableau3[ligne][col];

        }
    }

    printf("\nFONCTION AFFICHER_TABLEAU2D \n");
    printf("\nT1 : \n");
    afficher_tableau2D(T1,3,2);
    printf("\nT2 : \n");
    afficher_tableau2D(T2,3,4);
    printf("\nT3 : \n");
    afficher_tableau2D(T3,3,2);

    detruire_tableau2D(&T1, 3);
    detruire_tableau2D(&T2, 3);
    detruire_tableau2D(&T3, 3);

    printf("\nFONCTION AFFICHER_TABLEAU2D \n");
    printf("\nT1 : %p\n",(void*)T1);
    printf("\nT2 : %p\n",(void*)T2);
    printf("\nT3 : %p\n",(void*)T3);

    T1 = creer_tableau2D(3,2);
    T2 = creer_tableau2D(3,4);
    T3 = creer_tableau2D(3,2);

    initialiser_tableau2D(T2,3,4,8);

    printf("\nFONCTION INITIALISER_TABLEAU2D \n");
    printf("\nT1 : \n");
    afficher_tableau2D(T2,3,4);

    for(int ligne = 0; ligne < 3; ligne++) {

        for (int col = 0; col < 4; col++) {

            T2[ligne][col] = tableau2[ligne][col];

        }
    }

    double resultat_tableau1 = somme_tableau2D(T1,3,2);
    double resultat_tableau2 = somme_tableau2D(T2,3,4);

    printf("\n\nFONCTION SOMME_TABLEAU2D \n");
    printf("\nT1 : %lf",resultat_tableau1);
    printf("\nT1 : %lf",resultat_tableau2);

    produit_par_scalaire2D(T1,3,2,0.1);
    produit_par_scalaire2D(T2,3,4,10);

    printf("\n\nFONCTION PRODUIT_PAR_SCALAIRE2D \n");
    printf("\nT1 : \n");
    afficher_tableau2D(T1,3,2);
    printf("\nT2 : \n");
    afficher_tableau2D(T2,3,4);

    for(int ligne = 0; ligne < 3; ligne++) {

        for (int col = 0; col < 2; col++) {

            T1[ligne][col] = tableau1[ligne][col];

        }
    }

    for(int ligne = 0; ligne < 3; ligne++) {

        for (int col = 0; col < 4; col++) {

            T2[ligne][col] = tableau2[ligne][col];

        }
    }

    printf("\n\nFONCTION PUISSANCE_TABLEAU2D \n");
    printf("\nT1 : \n");
    puissance_tableau2D(T1,3,2,2);
    afficher_tableau2D(T1,3,2);
    printf("\nT2 : \n");
    puissance_tableau2D(T2,3,4,0.5);
    afficher_tableau2D(T2,3,4);

    for(int ligne = 0; ligne < 3; ligne++) {

        for (int col = 0; col < 2; col++) {

            T1[ligne][col] = tableau1[ligne][col];

        }
    }

    for(int ligne = 0; ligne < 3; ligne++) {

        for (int col = 0; col < 4; col++) {

            T2[ligne][col] = tableau2[ligne][col];

        }
    }



    printf("\n\nFONCTION PRODUIT_TABLEAU2D \n");
    double** T4 = creer_tableau2D(3,2);
    produit_tableau2D(T1,T2,3,2,&T4);
    printf("\nT4 : \n");
    afficher_tableau2D(T4,3,2);

    detruire_tableau2D(&T4, 3);
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
    a_ete_charger = lire("C:\\Users\\Hakim\\Documents\\GitHub\\TP2_INF147\\data\\plaque_test_1.bmp", &image,&nb_lignes,&nb_colonnes);
    if(a_ete_charger)
    {
        printf("Appliquer la fonction negatif.\n");
        negatif(image, nb_lignes,nb_colonnes);
        printf("Enregistrer sous.\n");
        ecrire("C:\\Users\\Hakim\\Documents\\GitHub\\TP2_INF147\\data\\resultat_negatif1.bmp", image, nb_lignes,nb_colonnes);
        printf("resultat_negatif1.bmp\n");
    }
    detruire(image, nb_lignes, nb_colonnes);

    printf("Charger plaque_test_1.bmp\n");

    a_ete_charger = lire("C:\\Users\\Hakim\\Documents\\GitHub\\TP2_INF147\\data\\plaque_test_2.bmp", &image, &nb_lignes, &nb_colonnes);

    if(a_ete_charger)
    {
        printf("Appliquer la fonction negatif.\n");
        negatif(image, nb_lignes,nb_colonnes);
        printf("Enregistrer sous.\n");
        ecrire("C:\\Users\\Hakim\\Documents\\GitHub\\TP2_INF147\\data\\resultat_negatif2.bmp", image, nb_lignes,nb_colonnes);
        printf("resultat_negatif1.bmp\n");
    }

    detruire(image, nb_lignes, nb_colonnes);

    a_ete_charger = lire("C:\\Users\\Hakim\\Documents\\GitHub\\TP2_INF147\\data\\plaque_test_1.bmp", &image, &nb_lignes, &nb_colonnes);

    if(a_ete_charger)
    {
        printf("Seuillez avec un seuil 0.5 \n");
        seuiller(image, nb_lignes,nb_colonnes,0.5);
        printf("Enregistrer sous.\n");
        ecrire("C:\\Users\\Hakim\\Documents\\GitHub\\TP2_INF147\\data\\resultat_seuil1.bmp", image, nb_lignes,nb_colonnes);
       printf("resultat_seuillez1.bmp\n");
    }

    detruire(image, nb_lignes, nb_colonnes);

    a_ete_charger = lire("C:\\Users\\Hakim\\Documents\\GitHub\\TP2_INF147\\data\\plaque_test_2.bmp", &image, &nb_lignes, &nb_colonnes);

    if(a_ete_charger)
    {
        printf("Seuillez avec un seuil 0.25 \n");
        seuiller(image, nb_lignes,nb_colonnes,0.25);
        printf("Enregistrer sous.\n");
        ecrire("C:\\Users\\Hakim\\Documents\\GitHub\\TP2_INF147\\data\\resultat_seuil2.bmp", image, nb_lignes,nb_colonnes);
        printf("resultat_seuillez1.bmp\n");
    }
    a_ete_charger = lire("C:\\Users\\Hakim\\Documents\\GitHub\\TP2_INF147\\data\\plaque_test_1.bmp", &image, &nb_lignes, &nb_colonnes);

    if(a_ete_charger)
    {
        double *histo = histogramme(image, nb_lignes,nb_colonnes,10);
        printf("plaques1 - 10 classes : ");
        afficher_tableau1D(histo,10);
        detruire_tableau1D(&histo);
    }

    a_ete_charger = lire("C:\\Users\\Hakim\\Documents\\GitHub\\TP2_INF147\\data\\plaque_test_1.bmp", &image, &nb_lignes, &nb_colonnes);

    if(a_ete_charger)
    {
        double *histo = histogramme(image, nb_lignes,nb_colonnes,15);
        printf("\n \nplaques1 - 15 classes : ");
        afficher_tableau1D(histo,15);
        detruire_tableau1D(&histo);
    }

    a_ete_charger = lire("C:\\Users\\Hakim\\Documents\\GitHub\\TP2_INF147\\data\\plaque_test_1.bmp", &image, &nb_lignes, &nb_colonnes);

    if(a_ete_charger)
    {
        t_filtre *filtre_bas = filtre_passe_bas();
        filtrer(image, nb_lignes,nb_colonnes,filtre_bas);
        printf("Enregistrer sous.\n");
        ecrire("C:\\Users\\Hakim\\Documents\\GitHub\\TP2_INF147\\data\\resultat_passe_bas2.bmp", image, nb_lignes,nb_colonnes);
        printf("resultat_passe_bas1.bmp\n");
    }

    a_ete_charger = lire("C:\\Users\\Hakim\\Documents\\GitHub\\TP2_INF147\\data\\plaque_test_2.bmp", &image, &nb_lignes, &nb_colonnes);

    if(a_ete_charger)
    {
        t_filtre *filtre_haut = filtre_passe_haut();
        filtrer(image, nb_lignes,nb_colonnes,filtre_haut);
        printf("Enregistrer sous.\n");
        ecrire("C:\\Users\\Hakim\\Documents\\GitHub\\TP2_INF147\\data\\resultat_passe_haut2.bmp", image, nb_lignes,nb_colonnes);
        printf("resultat_passe_bas1.bmp\n");
    }

    a_ete_charger = lire("C:\\Users\\Hakim\\Documents\\GitHub\\TP2_INF147\\data\\plaque_test_1.bmp", &image, &nb_lignes, &nb_colonnes);
    if(a_ete_charger)
    {
        t_filtre *filtre_lapl = filtre_laplacien();
        seuiller(image, nb_lignes,nb_colonnes,0.5);
        filtrer(image, nb_lignes,nb_colonnes,filtre_lapl);
        negatif(image, nb_lignes,nb_colonnes);
        printf("Enregistrer sous.\n");
        ecrire("C:\\Users\\Hakim\\Documents\\GitHub\\TP2_INF147\\data\\resultat_laplacien1.bmp", image, nb_lignes,nb_colonnes);
        printf("resultat_laplacien1.bmp\n");
    }

    a_ete_charger = lire("C:\\Users\\Hakim\\Documents\\GitHub\\TP2_INF147\\data\\plaque_test_2.bmp", &image, &nb_lignes, &nb_colonnes);
    if(a_ete_charger)
    {
        t_filtre *filtre_lapl = filtre_laplacien();
        seuiller(image, nb_lignes,nb_colonnes,0.25);
        filtrer(image, nb_lignes,nb_colonnes,filtre_lapl);
        printf("Enregistrer sous.\n");
        ecrire("C:\\Users\\Hakim\\Documents\\GitHub\\TP2_INF147\\data\\resultat_laplacien2.bmp", image, nb_lignes,nb_colonnes);
        printf("resultat_laplacien1.bmp\n");
    }

}
