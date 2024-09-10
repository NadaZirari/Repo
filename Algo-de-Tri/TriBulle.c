#include <stdio.h>


void echanger(int tableau[], int i, int j) {
    int temp = tableau[i];
    tableau[i] = tableau[j];
    tableau[j] = temp;
}




void triABulles(int tableau[], int taille) {
    for (int i = 0; i < taille - 1; i++) {
        for (int j = 0; j < taille - i - 1; j++) {
            if (tableau[j] > tableau[j + 1]) {
                echanger(tableau, j, j + 1);
            }
        }
    }
}

int main() {
    int taille ;
     printf("entrer la taille du tableau");
     scanf("%d",&taille);
int tableau[taille];
               for (int i = 0; i < taille; i++){
                  printf("entrer le %d elements du tableau\n",i+1);
                  scanf("%d",&tableau[i]);
                  }

   //appel de fonction
        triABulles(tableau, taille);



    printf("Tableau après le tri :\n");


    for (int i = 0; i < taille; i++) {
        printf("%d ", tableau[i]);
    }
    printf("\n");


    return 0;
}
