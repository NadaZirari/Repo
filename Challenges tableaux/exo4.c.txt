#include <stdio.h>

int main() {
    int n, i, max;

        printf("Entrez le nombre d'éléments dans le tableau : ");
    scanf("%d", &n);

        int tableau[n];

        printf("Entrez les éléments du tableau :\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &tableau[i]);
    }

 
    max = tableau[0];

        for(i = 1; i < n; i++) {
        if(tableau[i] > max) {
            max = tableau[i];
        }
    }

        printf("Le plus grand élément du tableau est : %d\n", max);

    return 0;
}
