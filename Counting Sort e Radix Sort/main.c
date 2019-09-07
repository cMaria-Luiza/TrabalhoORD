#include <stdio.h>
#include <stdlib.h>
#include "library.h"

int main()
{
    int v[10] = {5, 4, -12, 11, -3, 0, 1, 6, 8, 10};

    int menor = menorValor(v, 10);
    if(menor < 0)
        arrayPositivo(v, 10, menor);

    radixSort(v, 10);

    voltarArrayOriginal(v, 10, menor);

    for(int i = 0; i < 10; i++)
        printf("\n%d", v[i]);
    return 0;
}

void countingSort(int *A, int tam, int k)
{
    int aux[tam], cont[10];

    for(int i = 0; i < 10; i++)
        cont[i] = 0;

    for (int i = 0; i < tam; i++)
        cont[(A[i]/k)%10]++;

    for (int i = 1; i < 10; i++)
        cont[i] += cont[i-1];

    for (int i = tam-1; i >= 0; i--)
    {
        aux[cont[(A[i]/k)%10]-1] = A[i];
        cont[(A[i]/k)%10]--;
    }

    for (int i = 0; i < tam; i++)
        A[i] = aux[i];
}

void radixSort(int *A, int tam)
{
    int m = maiorValor(A, tam);
    for (int exp = 1; m/exp > 0; exp *= 10)
        countingSort(A, tam, exp);
}


int maiorValor(int *A, int tam)
{
    int maior = A[0];
    for(int i = 1; i < tam; i++) {
        if(A[i] > maior)
            maior = A[i];
    }

    return maior;
}

int menorValor(int *A, int tam)
{
    int menor = A[0];
    for(int i = 1; i < tam; i++) {
        if(A[i] < menor)
            menor = A[i];
    }

    return menor;
}

void arrayPositivo(int *A, int tam, int menor)
{
    menor = -menor;
    for(int i = 0; i < tam; i++) {
        A[i] += menor;
    }
}

void voltarArrayOriginal(int *A, int tam, int menor)
{
    for(int i = 0; i < tam; i++)
        A[i] += menor;
}





