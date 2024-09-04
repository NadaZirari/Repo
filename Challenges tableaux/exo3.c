#include <stdio.h>

#define MAX 100
int main() {
    int nb;
    int T[MAX];
    int s = 0; 
    printf("Entrer le nombre des éléments du tableau (maximum %d): ", MAX);
    scanf("%d", &nb);

    
    if (nb > MAX) {
        printf("Le nombre d'éléments dépasse la taille maximale du tableau.\n");
        return 1; // Sortir du programme avec un code d'erreur
    }

       for (int i = 0; i < nb; i++) {
        printf("Entrer le %dème nombre: ", i + 1);
        scanf("%d", &T[i]);
    }


    for (int i = 0; i < nb; i++) {
        s += T[i];
    }

  
    printf("La somme totale est: %d\n", s);

    return 0;
}
