#include <stdio.h>
#include <stdlib.h>

void aloca(float **p, int tam);
float media(float *ptr, int tam);
void imprime(float media);

int main()
{

    int tam = 0;
    float *ptr = NULL;
    char opcao;
    float m;

    do
    {
        tam++;

        aloca(&ptr, tam);

        printf("\nDIGITE O %d VALOR: ", tam);
        scanf("%f", ptr + (tam - 1));

        printf("\n\nDeseja continuar? (S/N)");
        scanf(" %c", &opcao);

    } while (opcao == 'S' || opcao == 's');

    m = media(ptr, tam);

    imprime(m);

    free(ptr);
    ptr = NULL;
    return 0;
}

void aloca(float **p, int tam)
{
    float *aux = NULL;
    aux = (float *)realloc(*p, tam * sizeof(float));

    if (aux == NULL)
    {
        printf("Alocacao FALHOU ");

        free(*p);
        exit(1);
    }

    *p = aux;
}

float media(float *p, int tam)
{
    float soma = 0;
    int i;
    int cont = tam;

    for (i = 0; i < tam; i++)
    {
        if (*(p + i) == 0)
        {
            cont--;
        }
    }

    for (i = 0; i < tam; i++)
    {
        soma = soma + *(p + i);
    }

    if (cont == 0)
    {
        return 0;
    }

    return soma / cont;
}

void imprime(float media)
{
    printf("\n\nA MEDIA DOS VALORES DIGITADOS E: %.2f ", media);
}