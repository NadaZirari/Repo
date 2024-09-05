
#include <stdio.h>
int Minimumdeuxnombres(int a,int b){
   
   if(a<b){
       return a;
   }
   return b;
    
}
int main() {
 int a,b,min;
    printf("entrer le nombre 1");
    scanf("%d",&a);
    printf("entrer le nombre 2");
    scanf("%d",&b);
    min=Minimumdeuxnombres(a,b);
    printf("Le max est=%d",min);

    return 0;
}