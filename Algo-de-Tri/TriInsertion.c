#include <stdio.h>


void afficherTableau(int tableau[], int taille) {
    for (int i = 0; i < taille; i++) {
        printf("%d ", tableau[i]);
    }
    printf("\n");
}


void triParInsertion(int tableau[], int taille) {
    for (int i = 1; i < taille; i++) {
        int element = tableau[i];
        int j = i - 1;

        // Déplacer les éléments plus grands que l'élément actuel d'une position vers la droite
        while (j >= 0 && tableau[j] > element) {
            tableau[j + 1] = tableau[j];
            j = j - 1;
        }
        tableau[j + 1] = element;  // Insérer l'élément à la bonne position
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

    triParInsertion(tableau, taille);

    printf("Tableau après le tri :\n");
    afficherTableau(tableau, taille);

    return 0;
}
