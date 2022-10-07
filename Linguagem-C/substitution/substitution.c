#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    //Verifica a quantidade de argumentos na linha de comando
    if (argc != 2)
    {
        printf("Use: ./ chave de substituição\n"); // Retorna mensagem de erro 
        return 1;
    }
    
    //Faz loop na extenção do argumento na linha de comando
    string key = argv[1];
    for (int i = 0, n = strlen(key); i < n; i ++)
    {
        //validar que a chave consiste apenas em letras
        if (!isalpha(key[i]))
        {
            printf("Use: ./ chave deve ser alfabética\n"); // Retorna mensagem de erro 
            return 1;
        }
    }
    
    //Validar se a chave contém 26 carcteres
    if (strlen(key) != 26)
    {
        printf("A chave deve conter 26 caracteres.\n"); // Retorna mensagem de erro 
        return 1;
    }
        
    //validar que cada alfabeto na chave é único
    for (int i = 0, n = strlen(key); i < n; i ++)
    {
        for (int j = i + 1; j < n; j ++)
        {
            if (toupper(key[i]) == toupper(key[j]))
            {
                printf("Use: ./ chave de substituição\n"); // Retorna mensagem de erro 
                return 1;
            }
        }
    }
    
    //solicitar ao usuário o texto simples
    string plaintext = get_string("Texto simples: ");
    
    //converter todos os alfabetos na chave para maiúsculas
    for (int i = 0, n = strlen(key); i < n; i ++)
    {
        if (islower(key[i]))
        {
            key[i] -= 32;
        }
    }
    
    //imprimir o texto cifrado
    printf("Texto Cifrado: ");
    for (int i = 0, n = strlen(plaintext); i < n; i ++)
    {
        if (isupper(plaintext[i]))
        {
            int letter = plaintext[i] - 65;
            printf("%c", key[letter]);
        }
        else if (islower(plaintext[i]))
        {
            int letter = plaintext[i] - 97;
            printf("%c", key[letter] + 32);
        }
        else
        {
            printf("%c", plaintext[i]);
        }
    }
    printf("\n");
    
}