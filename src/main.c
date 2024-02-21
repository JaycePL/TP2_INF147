#include <stdlib.h>
#include <stdio.h>
#include "tableau/tableau1d.h"


void tester_tableau1d(void);
void tester_tableau2d(void);
void tester_noyau(void);
void tetser_image_gris(void);


int main(void){

    printf("*********************************************************\n");
    printf("*                      TEST TABLEAU1D                   *\n");
    printf("*********************************************************\n\n\n");

    tester_tableau1d();

    printf("*********************************************************\n");
    printf("*                      TEST TABLEAU2D                   *\n");
    printf("*********************************************************\n\n\n");

    printf("*********************************************************\n");
    printf("*                        TEST NOYAU                     *\n");
    printf("*********************************************************\n\n\n");

    printf("*********************************************************\n");
    printf("*                      TEST IMAGE GRIS                  *\n");
    printf("*********************************************************\n\n\n");


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

    printf("\n\nFONCTION CREER TABLEAU1D \n");




}
