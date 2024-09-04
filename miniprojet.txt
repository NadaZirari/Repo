#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

#define MAX 500

char Titre[MAX][MAX];
char Auteur[MAX][MAX];
float prix[MAX];
int Quantite[MAX]; 
int nb = 0;

void menu() {
    printf("**********Mini Projet************\n");
    printf("1: Ajouter Livre \n");
    printf("2: Afficher Livres \n");
    printf("3: Rechercher Livre \n");
    printf("4: Mise à jour Livre \n");
    printf("5: Supprimer Livre \n");
    printf("6: Afficher Nombre Total Livre \n");
}

void ajouterLivre() {
    printf("Entrer le titre: ");
    scanf("%s", Titre[nb]);
    printf("Entrer l'auteur: ");
    scanf("%s", Auteur[nb]);
    printf("Entrer le prix: ");
    scanf("%f", &prix[nb]);
    printf("Entrer la quantité: ");
    scanf("%d", &Quantite[nb]);
    nb++;
}

void afficherLivres() {
    for (int i = 0; i < nb; i++) {
        printf("Le nom de livre est: %s\n", Titre[i]);
        printf("L'auteur de livre est: %s\n", Auteur[i]);
        printf("Le prix de livre est: %.2f\n", prix[i]);
        printf("La quantité de livre est: %d\n", Quantite[i]);
    }
}

void rechercherLivre() {
    char titre2[MAX]; 
    printf("Entrer le titre que vous voulez chercher: ");
    scanf("%s", titre2);
    for (int i = 0; i < nb; i++) {
        if (strcmp(Titre[i], titre2) == 0) { 
            printf("Livre trouvé : %s de %s\n", Titre[i], Auteur[i]);
            return;
        }
    }
    printf("Livre non trouvé\n");
}

void miseAJourLivre() { 
    char titre[MAX];
    int nouvelleQuantite;
    printf("Entrer le titre du livre à mettre à jour: ");
    scanf("%s", titre);
    for (int i = 0; i < nb; i++) {
        if (strcmp(Titre[i], titre) == 0) {
            printf("Entrer la nouvelle quantité: ");
            scanf("%d", &nouvelleQuantite);
            Quantite[i] = nouvelleQuantite;
            printf("Quantité mise à jour\n");
            return;
        }
    }
    printf("Livre non trouvé\n");
}

void supprimerLivre() {
    char titre3[MAX];
    int position = -1;
    printf("Entrer le titre du livre que vous voulez supprimer: ");
    scanf("%s", titre3);
    for (int i = 0; i < nb; i++) {
        if (strcmp(Titre[i], titre3) == 0) {
            position = i;
            break;
        }
    }
    if (position != -1) {
        for (int i = position; i < nb - 1; i++) { 
            strcpy(Titre[i], Titre[i + 1]);
            strcpy(Auteur[i], Auteur[i + 1]);
            prix[i] = prix[i + 1];
            Quantite[i] = Quantite[i + 1];
        }
        nb--;
        printf("Livre supprimé\n");
    } else {
        printf("Livre non trouvé\n");
    }
}

void afficherNombreTotalLivre() {
    printf("Le nombre total des livres en stock est: %d\n", nb);
}

int main() {
    int proposition;
    menu();
    printf("Entrer votre choix d'après le menu: ");
    scanf("%d", &proposition);

    switch (proposition) {
        case 1:
            ajouterLivre();
            break;
        case 2:
            afficherLivres();
            break;
        case 3:
            rechercherLivre();
            break;
        case 4:
            miseAJourLivre(); 
            break;
        case 5:
            supprimerLivre();
            break;
        case 6:
            afficherNombreTotalLivre();
            break;
        default:
            printf("Choix invalide\n");
            break;
    }

    return 0;
}
