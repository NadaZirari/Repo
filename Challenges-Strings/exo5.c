#include <stdio.h>
#include<string.h>
#define MAX 200
int main(){
    char ch1[500];
     

printf("entrer la  chaine");
scanf("%s",ch1);

  strrev(ch1);

    printf("La chaîne inversée est : %s\n", ch1);

    return 0;
}