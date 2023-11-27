#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define MAX_INPUT_SIZE 1024
#define MAX_WORD_SIZE 256
#define MAX_LIST_SIZE 50

void limpaMemoria(char** lista, int tamanho)
{
    for (int i = 0; i < tamanho; i++)
    {
        free(lista[i]);
    }
}

void ordenaPalavrasSelectionSort(char** lista, int tamanho)
{
    for (int j = 0; j < tamanho; j++)
    {
        int tamanhoMaiorPalavra = strlen(lista[j]);
        int indiceMaiorPalavra = j;
        
        for (int i = j + 1; i < tamanho; i++)
        {   
            if (strlen(lista[i]) > tamanhoMaiorPalavra)
            {
                tamanhoMaiorPalavra = strlen(lista[i]);
                indiceMaiorPalavra = i;
            }
        }

        char aux[MAX_WORD_SIZE];
        strcpy(aux, lista[j]);
        strcpy(lista[j], lista[indiceMaiorPalavra]);
        strcpy(lista[indiceMaiorPalavra], aux);

    }

}

void ordenaPalavrasBubbleSort(char** lista, int tamanho)
{
    bool trocou = false;

    do
    {
        trocou = false;
        char aux[MAX_WORD_SIZE];
        for (int i = 0; i < tamanho - 1; i++)
        {
            if (strlen(lista[i]) < strlen(lista[i + 1]))
            {
                strcpy(aux, lista[i]);
                strcpy(lista[i], lista[i + 1]);
                strcpy(lista[i + 1], aux);
                trocou = true;
            }
        }
    } while (trocou);
    
}

void imprimeLista(char** lista, int tamanho)
{
    char sep = '\0';
    for (int i = 0; i < tamanho; i++)
    {
        if (sep != '\0') printf("%c%s", sep, lista[i]);
        else printf("%s", lista[i]);
        sep = ' ';
    }
    printf("\n");
}


int main(int argc, char const *argv[])
{
    int testes;
    scanf("%d%*c", &testes); // Consome e ignora o \n

    while (testes > 0)
    {
        char* listaPalavras[MAX_LIST_SIZE];

        char entrada[MAX_INPUT_SIZE];
        scanf("%[^\n]%*c", entrada);

        char buffer[MAX_WORD_SIZE]; // Para armazenar temporariamente a palavra
        int cursorEntrada = 0, cursorBuffer = 0, palavras = 0;
        bool isPalavra = false;
        bool leuNUL = false;
        while (!leuNUL)
        {

            if (entrada[cursorEntrada] != ' ' && !isPalavra)
            {
                buffer[cursorBuffer] = entrada[cursorEntrada];
                isPalavra = true;
                palavras += 1;
                cursorBuffer += 1;
            }
            else if ((entrada[cursorEntrada] == ' ' || entrada[cursorEntrada] == '\0') && isPalavra)
            {
                isPalavra = false;

                buffer[cursorBuffer] = '\0';
                // A linha abaixo estava como malloc(strlen(buffer) + 1).
                // Por algum motivo estava dando SEGFAULT.
                listaPalavras[palavras - 1] = malloc(sizeof(buffer)); 
                if (listaPalavras[palavras - 1] == NULL) exit(EXIT_FAILURE); // alocação falhou
                strcpy(listaPalavras[palavras - 1], buffer);
                

                cursorBuffer = 0;
                
            }
            else if (isPalavra)
            {
                buffer[cursorBuffer] = entrada[cursorEntrada];
                cursorBuffer += 1;
            }
            
            if (entrada[cursorEntrada] == '\0') leuNUL = true;
            
            cursorEntrada += 1;
            
            
        }

        ordenaPalavrasBubbleSort(listaPalavras, palavras);

        imprimeLista(listaPalavras, palavras);

        limpaMemoria(listaPalavras, palavras);

        testes--;
    }
    return 0;
}