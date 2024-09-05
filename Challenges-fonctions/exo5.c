#include <stdio.h>
int Factoriel(int f) {
    int s = 1; 
    for (int i = f; i >= 1; i--) {
        s *= i;  
    }
    return s;
}

int main() {
    int fact;
    
    printf("Entrez le nombre pour que vous voulez calculer la factorielle: ");
    scanf("%d", &fact);

   
    printf("Le factoriel de %d est = %d\n", fact, Factoriel(fact));

    return 0;
}