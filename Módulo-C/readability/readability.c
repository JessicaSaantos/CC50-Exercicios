#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(void)
{
    //solicitar texto ao usuário
    string texto = get_string("Texto: ");

    //contar o número de letras que há no texto
    int letras = 0;
    for (int i = 0, n = strlen(texto); i < n; i ++) // strlen = calcula o comprimento de uma string
    {
        if (isalpha(texto[i])) // verificar se um caractere é alfabético
        {
            letras ++;
        }
    }

    //contar o número de palavras
    int palavras = 1;
    for (int i = 0, n = strlen(texto); i < n; i ++)
    {
        if (isspace(texto[i])) //verifique se um caractere é um espaço em branco
        {
            palavras ++;  
        }
        
    }

    //contar o número de sentenças
    int sentences = 0;
    for (int i = 0, n = strlen(texto); i < n; i ++)
    {
        if (texto[i] == '.' || texto[i] == '!' || texto[i] == '?')
        {
            sentences ++;
        }
    }
    
    //Usando índice Coleman-Liau para determinar o nível de leitura
    float calculation = (0.0588 * letras / palavras * 100) - 
                        (0.296 * sentences / palavras * 100) -
                        15.8;
    int index = round(calculation);
    
    //Verificando o nível de leitura
    if (index < 1)
    {
        printf("Before Grade 1\n");
        return 0;
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
        return 0;
    }
    else
    {
        printf("Grade %i\n", index);
    }
}
