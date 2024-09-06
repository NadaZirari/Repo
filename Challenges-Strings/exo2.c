#include <stdio.h>

int main() {
    char chaine[100];
    int longueur = 0;
    printf("Entrez une chaîne de caractères : ");
    scanf("%s", chaine); 
    
    
    while (chaine[longueur] != '\0') {
        longueur++;
    }

    
    printf("La longueur de la chaîne est : %d\n", longueur);

    return 0;
}