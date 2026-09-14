#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void aloca(char **p, int tam);
void imprime(char *p);
void inverte(char *p, int tam);

int main()
{
    char palavra[50];
    char *ptr = NULL;
    int tam = 0;

    printf("DIGITE UMA PALAVRA: ");
    scanf("%49s", palavra);

    tam = strlen(palavra);

    aloca(&ptr, tam + 1);

    strcpy(ptr, palavra);

    imprime(ptr);

    inverte(ptr, tam);

    printf("\n\nREIMPRESSAO:\n ");

    imprime(ptr);

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
        exit(1);
    }
}

void imprime(char *p)
{
    printf("ENDERECO: %p    |    VALOR: %s", (void *)p, p);
}

void inverte(char *p, int tam)
{
    char auxiliar;
    int i;

    for (i = 0; i < tam / 2; i++)
    {
        auxiliar = *(p + i);
        *(p + i) = *(p + (tam - 1 - i));
        *(p + (tam - 1 - i)) = auxiliar;
    }
}