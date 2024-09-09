#include <stdio.h>

// Fonction pour échanger deux éléments
void echanger(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Fonction pour afficher le tableau
void afficherTableau(int tableau[], int taille) {
    for (int i = 0; i < taille; i++) {
        printf("%d ", tableau[i]);
    }
    printf("\n");
}

// Fonction pour partitionner le tableau
int partition(int tableau[], int low, int high) {
    int pivot = tableau[high];  // Choisir le dernier élément comme pivot
    int i = low - 1;            // Index du plus petit élément

    for (int j = low; j < high; j++) {
        if (tableau[j] < pivot) {
            i++;
            echanger(&tableau[i], &tableau[j]);
        }
    }
    echanger(&tableau[i + 1], &tableau[high]); // Placer le pivot à sa position correcte
    return i + 1;
}

// Implémentation de l'algorithme de tri rapide
void triRapide(int tableau[], int low, int high) {
    if (low < high) {
        // pi est l'index du pivot, tableau[pi] est maintenant à sa place correcte
        int pi = partition(tableau, low, high);

        // Appliquer le tri rapide aux sous-tableaux à gauche et à droite du pivot
        triRapide(tableau, low, pi - 1);
        triRapide(tableau, pi + 1, high);
    }
}

int main() {
    int tableau[] = {10, 7, 8, 9, 1, 5};
    int taille = sizeof(tableau) / sizeof(tableau[0]);

    printf("Tableau avant le tri :\n");
    afficherTableau(tableau, taille);

    triRapide(tableau, 0, taille - 1);

    printf("Tableau après le tri :\n");
    afficherTableau(tableau, taille);

    return 0;
}
