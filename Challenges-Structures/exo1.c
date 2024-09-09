#include <stdio.h>
#include <string.h>


struct Personne {
    char nom[50];
    char prenom[50];
    int age;
};

int main() {
    
    struct Personne p1;

    
    strcpy(p1.nom, "Dupont");  
    strcpy(p1.prenom, "Jean"); 
    p1.age = 30;               
    
    printf("Nom : %s\n", p1.nom);
    printf("Prénom : %s\n", p1.prenom);
    printf("Âge : %d\n", p1.age);

    return 0;
}
