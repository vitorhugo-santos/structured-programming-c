#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void aloca(char **p, int tam);
void recebe(char *p, int tam);
void imprime(char *p, int tam);
void altera(char *p, int tam);

int main()
{
    char *ptr = NULL;
    int tam = 10;

    aloca(&ptr, tam);
    recebe(ptr, tam);
    imprime(ptr, tam);
    altera(ptr, tam);
    printf("\nREIMPRESSAO COM OS VALORES ALTERADOS:\n");
    imprime(ptr, tam);

    free(ptr);
    ptr = NULL;

    return 0;
}

void aloca(char **p, int tam)
{

    *p = (char *)malloc(tam * sizeof(char));

    if (*p == NULL)
    {
        printf("ALOCACAO FALHOU ");
        free(*p);
        exit(1);
    }
}

void recebe(char *p, int tam)
{
    int i;
    for (i = 0; i < tam; i++)
    {
        printf("\nDigite o %d CARACTERE: ", i + 1);
        scanf(" %c", p + i);
    }
}

void imprime(char *p, int tam)
{
    int i;
    for (i = 0; i < tam; i++)
    {
        printf("\nENDERECO %d: %p    |    VALOR %d: %c ", i + 1, (void *)(p + i), i + 1, *(p + i));
    }
}

void altera(char *p, int tam)
{
    int i;

    for (i = 0; i < tam; i++)
    {
        if (*(p + i) >= 'A' && *(p + i) <= 'Z')
        {
            *(p + i) = *(p + i) + 32;
        }
        else if (*(p + i) >= 'a' && *(p + i) <= 'z')
        {
            *(p + i) = *(p + i) - 32;
        }
        else
        {
            printf("\nTIVEMOS UM PROBLEMA COM O VALOR %d, pois ele nao e uma LETRA.", i + 1);
        }
    }
}
