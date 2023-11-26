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

int main(int argc, char const *argv[])
{
    int testes;
    scanf("%d%*c", &testes); // Consome e ignora o \n

    while (testes > 0)
    {
        char* listaPalavras[MAX_LIST_SIZE];

        char entrada[MAX_INPUT_SIZE];
        scanf("%[^\n]s%*c", entrada);

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
                listaPalavras[palavras - 1] = malloc(strlen(buffer) + 1);
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

        printf("A quantidade de palavras encontradas é %d\n", palavras);

        limpaMemoria(listaPalavras, palavras);

        testes--;
    }
    return 0;
}