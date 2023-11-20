#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define MAX_INPUT_SIZE 1024

int main(int argc, char const *argv[])
{
    int testes;
    scanf("%d%*c", &testes); // Consome e ignora o \0

    while (testes > 0)
    {
        char* listaPalavras[50];

        char entrada[MAX_INPUT_SIZE]; //string + \0
        scanf("%[^\n]s%*c", entrada);
        //printf("%s\n", buffer);

        char buffer[256]; // Para armazenar temporariamente a palavra
        int cursorEntrada = 0, contador = 0, cursorBuffer = 0, palavras = 0;
        bool isPalavra = false;
        do
        {
            if (entrada[cursorEntrada] != ' ' && !isPalavra)
            {
                buffer[cursorBuffer] = entrada[cursorEntrada];
                isPalavra = true;
                palavras += 1;
                contador += 1;
                cursorBuffer += 1;
            }
            else if (entrada[cursorEntrada] == ' ' && isPalavra)
            {
                isPalavra = false;

                // adiciona \0 no buffer, reinicia o cursorBuffer e adiciona a palavra na lista.
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
            
            cursorEntrada += 1;
            
        } while (entrada[cursorEntrada] != '\0');

        if (isPalavra) // Então terminou o loop com uma palavra pendente
        {
            isPalavra = false;

            // adiciona \0 no buffer, reinicia o cursorBuffer e adiciona a palavra na lista.
            buffer[cursorBuffer] = '\0';
            listaPalavras[palavras - 1] = malloc(strlen(buffer) + 1);
            strcpy(listaPalavras[palavras - 1], buffer);

            cursorBuffer = 0;
        }

        printf("A quantidade de palavras encontradas é %d\n", contador);

        testes--;
    }
    return 0;
}