#include <stdio.h>
#include <stdlib.h>

void aloca(char **p, int tam);

int main()
{
    int tam = 0;
    char *ptr = NULL;
    char opcao;
    int i;
    int contA = 0;

    do
    {
        tam++;

        aloca(&ptr, tam);

        printf("\nDIGITE O %d nome: ", tam);
        scanf(" %49s", ptr + ((tam - 1) * 50));

        printf("DESEJA CONTINUAR ? S/N ");
        scanf(" %c", &opcao);

    } while (opcao == 'S' || opcao == 's');

    for (i = 0; i < tam; i++)
    {
        if (*(ptr + (i * 50)) == 'A')
        {
            contA++;
        }
    }

    printf("\n\nQUANTIDADE DE NOMES: %d\n", tam);
    printf("COMECADOS COM A: %d", contA);

    free(ptr);
    ptr = NULL;
    return 0;
}

void aloca(char **p, int tam)
{
    char *aux = NULL;
    aux = (char *)realloc(*p, tam * 50 * sizeof(char));

    if (aux == NULL)
    {
        printf("ALOCACAO FALHOU ");
        free(*p);
        exit(1);
    }

    *p = aux;
}