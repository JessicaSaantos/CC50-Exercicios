#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    //Verifica a quantidade de argumentos na linha de comando
    if (argc != 2)
    {
        printf("Use: ./caesar key\n"); // Retorna mensagem de erro se não for 2
        return 1;
    }
    //Verifica a extenção do argumento na linha de comando
    for (int i = 0, n = strlen(argv[1]); i < n; i ++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Use: ./caesar key\n"); // Retorna mensagem de erro se não número
            return 1;
        }
    }
    //converter uma string em um int
    int k = atoi(argv[1]);
    //captura o texto do usuário
    string plaintext = get_string("Texto Simples: ");
    printf("Texto Cifrado: ");
    
    //Calcúlos para resolução
    for (int i = 0, n = strlen(plaintext); i < n; i ++)
    {
        if (isupper(plaintext[i]))
        {
            printf("%c", (plaintext[i] - 65 + k) % 26 + 65); 
        }
        else if (islower(plaintext[i]))
        {
            printf("%c", (plaintext[i] - 97 + k) % 26 + 97); 
        }
        else
        {
            printf("%c", plaintext[i]);
        }
    }
    
    printf("\n");
   
}
