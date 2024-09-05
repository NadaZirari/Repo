#include <stdio.h>
int produitdeuxnombres(int a,int b){
    int p=0;
    p=a*b;
    return p;
    
    
}
int main() {
 int a,b,p;
    printf("entrer le nombre 1");
    scanf("%d",&a);
    printf("entrer le nombre 2");
    scanf("%d",&b);
    p=produitdeuxnombres(a,b);
    printf("produit=%d",p);

    return 0;
}