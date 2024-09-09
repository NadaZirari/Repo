#include <stdio.h>
#include <string.h>

// Définition de la structure Étudiant
struct Etudiant {
    char nom[50];
    char prenom[50];
    int notes[5];  // Tableau pour stocker 5 notes
};

int main() {
    // Déclaration d'une variable de type Étudiant
    struct Etudiant etudiant1;

    // Assignation des valeurs aux champs
    strcpy(etudiant1.nom, "Martin");   // Copie du nom
    strcpy(etudiant1.prenom, "Alice"); // Copie du prénom

    // Assignation des notes
    etudiant1.notes[0] = 15;
    etudiant1.notes[1] = 18;
    etudiant1.notes[2] = 12;
    etudiant1.notes[3] = 17;
    etudiant1.notes[4] = 14;

    // Affichage des informations de l'étudiant
    printf("Nom : %s\n", etudiant1.nom);
    printf("Prénom : %s\n", etudiant1.prenom);
    printf("Notes : ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", etudiant1.notes[i]);
    }
    printf("\n");

    return 0;
}
