#include <stdio.h>
#include <stdlib.h>

void aloca(int **p, int tam);
void recebe(int *p, int tam);
void percorre(int *p, int *maior, int *menor, int tam);

int main()
{
    int *ptr = NULL;
    int maior, menor, tam, i;

    printf("Digite quantos espacos para inteiros deseja reservar: ");
    scanf("%d", &tam);

    aloca(&ptr, tam);
    recebe(ptr, tam);
    percorre(ptr, &maior, &menor, tam);

    printf("\n\nQUANTIDADE DE VALORES: %d", tam);
    printf("\n\nVALORES ARMAZENADOS: \n");

    for (i = 0; i < tam; i++)
    {
        printf("\nENDERECO %d: %p  |  VALOR %d: %d ", i + 1, (void *)(ptr + i), i + 1, *(ptr + i));
    }

    printf("\n\nMAIOR VALOR: %d", maior);
    printf("\nMENOR VALOR: %d", menor);

    free(ptr);
    ptr = NULL;
    return 0;
}
void aloca(int **p, int tam)
{
    *p = (int *)calloc(tam, sizeof(int));
    if (*p == NULL)
    {
        printf("ALOCACAO FALHOU");
        exit(1);
    }
}
void recebe(int *p, int tam)
{
    int i;
    for (i = 0; i < tam; i++)
    {
        printf("\nDigite o %d valor: ", i + 1);
        scanf(" %d", p + i);
    }
}
void percorre(int *p, int *maior, int *menor, int tam)
{
    int i;
    *maior = *p;
    *menor = *p;

    for (i = 0; i < tam; i++)
    {
        if (*(p + i) > *maior)
        {
            *maior = *(p + i);
        }
        if (*(p + i) < *menor)
        {
            *menor = *(p + i);
        }
    }
}