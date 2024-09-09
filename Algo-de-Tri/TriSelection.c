#include <stdio.h>


void afficherTableau(int tableau[], int taille) {
    for (int i = 0; i < taille; i++) {
        printf("%d ", tableau[i]);
    }
    printf("\n");
}


void triParSelection(int tableau[], int taille) {
    for (int i = 0; i < taille - 1; i++) {
        int minIndex = i; // On suppose que le premier élément est le minimum

        // Trouver l'index de l'élément minimum dans le sous-tableau restant
        for (int j = i + 1; j < taille; j++) {
            if (tableau[j] < tableau[minIndex]) {
                minIndex = j;
            }
        }

        // Échanger l'élément minimum trouvé avec le premier élément de la sous-liste
        if (minIndex != i) {
            int temp = tableau[i];
            tableau[i] = tableau[minIndex];
            tableau[minIndex] = temp;
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


    printf("Tableau avant le tri :\n");
    afficherTableau(tableau, taille);

    triParSelection(tableau, taille);

    printf("Tableau après le tri :\n");
    afficherTableau(tableau, taille);

    return 0;
}
