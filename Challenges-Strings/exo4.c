
#include <stdio.h>
#include<string.h>
#define MAX 200
int main(){
    char ch1[500];
     char ch2[500];

printf("entrer la premiere chaine");
scanf("%s",ch1);
printf("entrer la deuxieme chaine");
scanf("%s",ch2);
int v=strcmp(ch1,ch2);
if(v==0){
    printf("les chaines se rasemble");
    
}else{ 
printf("les chaines ne se rasemble pas");
    
}
    return 0;
}