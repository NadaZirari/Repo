#include <stdio.h>

// Définition de la structure Rectangle
struct Rectangle {
    float longueur;
    float largeur;
};

// Fonction pour calculer l'aire d'un rectangle
float calculerAire(struct Rectangle r) {
    return r.longueur * r.largeur;
}

int main() {
    // Déclaration d'une variable de type Rectangle
    struct Rectangle rect;

    // Assignation des valeurs pour la longueur et la largeur
    rect.longueur = 10.5;
    rect.largeur = 5.2;

    // Calcul de l'aire
    float aire = calculerAire(rect);

    // Affichage de l'aire
    printf("L'aire du rectangle est : %.2f\n", aire);

    return 0;
}
