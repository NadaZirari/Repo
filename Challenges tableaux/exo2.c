#include <stdio.h>
#define MAX 300

int main() {
    int nb;
    int T[MAX];

    printf("Entrer le nombre des éléments du tableau (maximum %d) : ", MAX);
    scanf("%d", &nb);

   
    if (nb > MAX) {
        printf("Le nombre d'éléments dépasse la taille maximale du tableau.\n");
        return 1; 
    }

        for (int i = 0; i < nb; i++) {
        printf("Entrer le %dème nombre : ", i + 1);
        scanf("%d", &T[i]);
    }
    for (int i = 0; i < nb; i++) {
        printf("Le %dème nombre est : %d\n", i + 1, T[i]);
    }

    return 0;
}
