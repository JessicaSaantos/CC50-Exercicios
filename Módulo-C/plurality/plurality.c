#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Número máximo de candidatos
#define MAX 9

// Candidatos têm nome e contagem de votos
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array de candidatos
candidate candidates[MAX];

// Número de candidatos
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Verifique se há uso inválido
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Preencher matriz de candidatos
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Faça um loop sobre todos os eleitores
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Verifique se há voto inválido
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    //Exibir vencedor da eleição
    print_winner();
}

//Atualizar os totais de votos com um novo voto
bool vote(string name)
{
    for (int i = 0; i < candidate_count; i ++)
    {
        //strcmp = compara duas strings
       if (strcmp(name, candidates[i].name) == 0)
       {
           candidates[i].votes ++;
           return true;
       }
    }
    return false;
}

//Imprima o vencedor (ou vencedores) da eleição
void print_winner(void)
{
    int maxvotes = 0;
    for (int i = 0; i < candidate_count; i ++)
    {
        if (candidates[i].votes > maxvotes)
        {
            maxvotes = candidates[i].votes;
        }
    }
    for (int i = 0; i < candidate_count; i ++)
    {
        if (candidates[i].votes == maxvotes)
        {
            printf("Vencedor: %s\n", candidates[i].name);
            printf("Número de votos: %i\n", candidates[i].votes);
        }
    }

}

