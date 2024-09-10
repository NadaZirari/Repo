#include <stdio.h>

// Fonction pour fusionner deux sous-tableaux
void fusion(int tableau[], int gauche, int milieu, int droite) {
    int taille1 = milieu - gauche + 1;
    int taille2 = droite - milieu;

    // Créer des tableaux temporaires
    int gaucheTableau[taille1], droiteTableau[taille2];

    // Copier les données dans les tableaux temporaires
    for (int i = 0; i < taille1; i++)
        gaucheTableau[i] = tableau[gauche + i];
    for (int j = 0; j < taille2; j++)
        droiteTableau[j] = tableau[milieu + 1 + j];

    // Fusionner les tableaux temporaires
    int i = 0, j = 0, k = gauche;
    while (i < taille1 && j < taille2) {
        if (gaucheTableau[i] <= droiteTableau[j]) {
            tableau[k] = gaucheTableau[i];
            i++;
        } else {
            tableau[k] = droiteTableau[j];
            j++;
        }
        k++;
    }

    // Copier les éléments restants de gaucheTableau (s'il en reste)
    while (i < taille1) {
        tableau[k] = gaucheTableau[i];
        i++;
        k++;
    }

    // Copier les éléments restants de droiteTableau (s'il en reste)
    while (j < taille2) {
        tableau[k] = droiteTableau[j];
        j++;
        k++;
    }
}

// Fonction pour implémenter le tri par fusion
void triFusion(int tableau[], int gauche, int droite) {
    if (gauche < droite) {
        int milieu = gauche + (droite - gauche) / 2;

        // Trier la première et la seconde moitié
        triFusion(tableau, gauche, milieu);
        triFusion(tableau, milieu + 1, droite);

        // Fusionner les deux moitiés triées
        fusion(tableau, gauche, milieu, droite);
    }
}

// Fonction pour afficher le tableau
void afficherTableau(int tableau[], int taille) {
    for (int i = 0; i < taille; i++) {
        printf("%d ", tableau[i]);
    }
    printf("\n");
}

int main() {
    int tableau[] = {12, 11, 13, 5, 6, 7};
    int taille = sizeof(tableau) / sizeof(tableau[0]);

    printf("Tableau avant le tri :\n");
    afficherTableau(tableau, taille);

    triFusion(tableau, 0, taille - 1);

    printf("Tableau après le tri :\n");
    afficherTableau(tableau, taille);

    return 0;
}
