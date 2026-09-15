#include <stdio.h>
#include <stdlib.h>

void aloca(float **p, int tam);

int main()
{
    float *ptr = NULL;
    int dias = 0;
    int i;
    float maior;
    int diaMaior;

    printf("Quantos dias serao registrados ? ");
    scanf("%d", &dias);

    aloca(&ptr, dias);

    for (i = 0; i < dias; i++)
    {
        printf("\nDigite a %d temperatura: ", i + 1);
        scanf("%f", ptr + i);

        if (i == 0 || *(ptr + i) > maior)
        {
            maior = *(ptr + i);
            diaMaior = i + 1;
        }
        printf("\nMaior temperatura: %.2f ", maior);
        printf("\nRegistrada no dia: %d \n", diaMaior);
    }

    printf("\n\nRESULTADO FINAL:\n\n ");
    printf("Maior temperatura registrada: %.2f \n", maior);
    printf("No dia: %d ", diaMaior);
}

void aloca(float **p, int tam)
{
    *p = (float *)calloc(tam, sizeof(float));

    if (*p == NULL)
    {
        printf("ALOCACAO FALHOU");
        free(*p);
        exit(1);
    }
}