
#include <stdio.h>
int MAximumdeuxnombres(int a,int b){
   
   if(a<b){
       return b;
   }
   return a;
    
}
int main() {
 int a,b,max;
    printf("entrer le nombre 1");
    scanf("%d",&a);
    printf("entrer le nombre 2");
    scanf("%d",&b);
    max=MAximumdeuxnombres(a,b);
    printf("Le max est=%d",max);

    return 0;
}