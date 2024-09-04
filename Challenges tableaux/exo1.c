#include <stdio.h>

#define SIZE 10 
int main() {
    int T[SIZE] = {0}; 
    int i;

        for (i = 0; i < SIZE; i++) {
        T[i] = i + 1;     }

       for (i = 0; i < SIZE; i++) {
        printf("%d ", T[i]);
    }
    printf("\n"); 
    return 0;
}
