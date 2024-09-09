#include <stdio.h>

// Fonction pour échanger deux éléments sans pointeurs
void echanger(int tableau[], int i, int j) {
    int temp = tableau[i];
    tableau[i] = tableau[j];
    tableau[j] = temp;
}

// Fonction pour afficher le tableau
void afficherTableau(int tableau[], int taille) {
    for (int i = 0; i < taille; i++) {
        printf("%d ", tableau[i]);
    }
    printf("\n");
}

// Implémentation de l'algorithme de tri à bulles
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
    int tableau[] = {64, 34, 25, 12, 22, 11, 90};
    int taille = sizeof(tableau) / sizeof(tableau[0]);

    printf("Tableau avant le tri :\n");
    afficherTableau(tableau, taille);

    triABulles(tableau, taille);

    printf("Tableau après le tri :\n");
    afficherTableau(tableau, taille);

    return 0;
}
