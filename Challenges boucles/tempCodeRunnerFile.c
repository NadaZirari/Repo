int main() {
    int n, i=0, p, rslt=1;
    
    printf("Donner la base: ");
    scanf("%d", &n);
    
    printf("Donner l'exposant: ");
    scanf("%d", &p);
    
    while (i < p) {
        rslt *= n;
        i++;
    }
    printf("Le résultat final est: %d", rslt);
    
    return 0;