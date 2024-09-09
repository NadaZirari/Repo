#include <stdio.h>

// Fonction pour afficher le tableau
void afficherTableau(int tableau[], int taille) {
    for (int i = 0; i < taille; i++) {
        printf("%d ", tableau[i]);
    }
    printf("\n");
}

// Implémentation de l'algorithme de tri par insertion
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
    int tableau[] = {12, 11, 13, 5, 6};
    int taille = sizeof(tableau) / sizeof(tableau[0]);

    printf("Tableau avant le tri :\n");
    afficherTableau(tableau, taille);

    triParInsertion(tableau, taille);

    printf("Tableau après le tri :\n");
    afficherTableau(tableau, taille);

    return 0;
}
