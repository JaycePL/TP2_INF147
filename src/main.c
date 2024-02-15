#include <stdlib.h>
#include <stdio.h>

void tester_tableau1d(void);
void tester_tableau2d(void);
void tester_noyau(void);
void tetser_image_gris(void);


int main(){

    printf("*********************************************************\n");
    printf("*                      TEST TABLEAU1D                   *\n");
    printf("*********************************************************\n\n\n");

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
    int     tableau1[5] = {1, 2, 3, 4, 5};
    double  tableau2[5] = {1.1, 2.5, 3.0, 4.25, 5.123 };
    double  tableau3[5] = {1.0, 1.0, 1.0, 1.0, 1.0};
    int     tableau4[5] = {1, 2, 3, 4, 5};
    double  tableau5[5] = {1.5, 2.0, 1.25, 0.5, 0};
    int     tableau6[5] = {0, 0, 0, 0, 0};

}
