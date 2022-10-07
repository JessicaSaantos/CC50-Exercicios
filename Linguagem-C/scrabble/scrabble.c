#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Pontos atribuídos a cada letra do alfabeto
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1,
                3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10
               };

int compute_score(string word);

int main(void)
{
    // Obter palavras de entrada de ambos os jogadores
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Pontue as duas palavras
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    //Imprima o vencedor
    if (score1 > score2)
    {
        printf("Jogador 1 Vence!\n");
    }
    else if (score2 > score1)
    {
        printf("Jogador 2 Vence!\n");
    }
    else
    {
        printf("Empate!\n");
    }
}

int compute_score(string word)
{
    //Calcular e retornar pontuação
    int pontos = 0;

    for (int i = 0, n = strlen(word); i < n; i ++)
    {
        // verificar se é maiúsculo ou minúsculo
        if (isupper(word[i]))
        {
            // cálculo de acordo com a tabela ASCII
            pontos += POINTS[word[i] - 65];
        }
        else if (islower(word[i]))
        {
            pontos += POINTS[word[i] - 97];
        }

    }
    return pontos;
}

