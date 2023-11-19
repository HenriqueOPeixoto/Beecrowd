#include <stdio.h>

typedef struct Palavra
{
    char* texto;
    int tamanho;
} palavra;

int main(int argc, char const *argv[])
{
    int testes;
    scanf("%d%*c", &testes); // Consome e ignora o \0

    while (testes > 0)
    {
        char buffer[51]; //string + \0
        scanf("%[^\n]s%*c", buffer);
        //printf("%s\n", buffer);


        // TODO
        // Ajustar os casos onde há mais de um espaço sequencial
        // Ajustar casos onde há espaços no começo e no final
        int cursor = 0, contador = 1;
        while (buffer[cursor] != '\0')
        {
            if (buffer[cursor] == ' ') contador += 1;
            cursor += 1;
        }

        printf("A quantidade de palavras encontradas é %d\n", contador);

        testes--;
    }
    return 0;
}