#include<stdio.h>
#include<stdlib.h>
int main(){

int i,n,temp;
printf("entrer le nombre des elements que vous souhaiter entrer");
scanf("%d",&n);
int T[n];
for (i=0;i<n;i++){
printf("entrer le %d nombre \n",i+1);
scanf("%d",&T[i]);

}
for (i=0;i<n;i++){

printf(" le %d nombre est %d \n",i+1, T[i]);
}

for (i=0;i<n-1;i++){
    
if(T[i]>T[i+1]){
temp =T[i];
T[i]=T[i+1];
T[i+1]=temp;
}}
printf("Les éléments du tableau après tri sont :\n");
for (i=0;i<n;i++){

printf(" le %d nombre est %d \n",i+1, T[i]);



}



  return 0;

}
