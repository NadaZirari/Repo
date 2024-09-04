#include <stdio.h>

int main() {
    int n, i, min;

  
    printf("Entrez le nombre d'éléments dans le tableau : ");
    scanf("%d", &n);

  
    int tableau[n];

    
    printf("Entrez les éléments du tableau :\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &tableau[i]);
    }

 
    min = tableau[0];

   
    for(i = 1; i < n; i++) {
        if(tableau[i] < min) {
            min = tableau[i];
        }
    }

 
    printf("Le plus petit élément du tableau est : %d\n", min);

    return 0;
}

