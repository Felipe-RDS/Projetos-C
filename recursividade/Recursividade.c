/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
int fatorialIterativo(int n);
int fatorialRecursivo(int n);
int fatorialRecursivoCauda(int n, int parcial);

int main(){
    int n = 5;
    printf("\n%d! = %d", n, fatorialIterativo(n));
    printf("\n%d! = %d", n, fatorialRecursivo(n));
    printf("\n%d! = %d", n, fatorialRecursivoCauda(n, 1));
    return 0;
}

int fatorialIterativo(int n){
    int i,
        fat = 1;
    for(i = 2; i <= n; i++) {
        fat *= i;
    }
    return fat;
}

int fatorialRecursivo(int n){
    if (n <= 1) { //Caso base
        return 1;
    } else { //Caso recursivo
        return n * fatorialRecursivo(n-1);
    }
}

int fatorialRecursivoCauda(int n, int parcial) {
    if (n <= 1) {//Caso base
        return parcial;
    } else { //Caso recursivo
        return fatorialRecursivoCauda(n-1, n * parcial);
    }
}
