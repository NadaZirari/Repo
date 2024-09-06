#include <stdio.h>
#define MAX 200
int main() {
    char chaine1[MAX], chaine2[MAX], chaine3[MAX];
    int i = 0, j = 0;


    printf("Entrez la première chaîne de caractères : ");
    scanf("%s", chaine1);
    printf("Entrez la deuxième chaîne de caractères : ");
    scanf("%s", chaine2);


    strcpy(chaine3,chaine1);
     strcat(chaine3,chaine2);


    printf("La chaîne concaténée est : %s\n", chaine3);


    return 0;
}