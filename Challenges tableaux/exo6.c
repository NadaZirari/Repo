#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, fact;

    
    printf("Entrez le nombre d'éléments dans le tableau : ");
    scanf("%d", &n);

    
    printf("Entrez le facteur : ");
    scanf("%d", &fact);

   
    int T[n];

    
    printf("Entrez les éléments du tableau :\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &T[i]);
    }

    
    for(i = 0; i < n; i++) {
        T[i] = T[i] * fact;
    }

   
    printf("Les éléments du tableau après multiplication :\n");
    for(i = 0; i < n; i++) {
        printf("%d\n", T[i]);
    }

    return 0;
}


 