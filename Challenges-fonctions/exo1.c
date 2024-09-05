// Online C compiler to run C program online
#include <stdio.h>
int sommedeuxnombres(int a,int b){
    int s=0;
    s=a+b;
    return s;
    
    
}
int main() {
 int a,b,s;
    printf("entrer le nombre 1");
    scanf("%d",&a);
    printf("entrer le nombre 2");
    scanf("%d",&b);
    s=sommedeuxnombres(a,b);
    printf("somme=%d",s);

    return 0;
}