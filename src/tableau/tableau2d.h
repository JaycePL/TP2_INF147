/****************************************************************************************
    TABLEAU 2D

 *****************************************************************************************/

/****************************************************************************************
*                               DEFINTION DES CONSTANTES                                *
****************************************************************************************/



/****************************************************************************************
*                       DECLARATION DES FONCTIONS PUBLIQUES                             *
****************************************************************************************/
void* creer_tableau2D(int nb_ligne,int nb_colonne);
void detruire_tableau2D(double*** pointeur,int nb_ligne);
void afficher_tableau2D(double** tableau, int nb_ligne, int nb_colonne);
void initialiser_tableau2D(double** tableau, int nb_ligne, int nb_colonne, double valeur);
double somme_tableau2D(double** tableau, int nb_ligne, int nb_colonne);
void produit_par_scalaire2D(double** tableau, int nb_ligne, int nb_colonne, double facteur);
void puissance_tableau2D(double** tableau, int nb_ligne, int nb_colonne, double puissance);
void produit_tableau2D(double** tableau1, double** tableau2, int nb_ligne, int nb_colonne, double*** resultat);