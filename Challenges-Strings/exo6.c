#include <stdio.h>
#include<string.h>
#define MAX 200
int main(){
    char ch1[500];
    char c;
     int counter=0;

printf("entrer la  chaine\n");
scanf("%s",ch1);
getchar();

printf("entrer le caractere a chercher");
scanf("%c",&c);

 for (int i = 0; i < strlen(ch1); i++){
    if(ch1[i]==c){
        counter++;


    }

printf("loccurence est/ %d",counter);
 }
 

    return 0;
}