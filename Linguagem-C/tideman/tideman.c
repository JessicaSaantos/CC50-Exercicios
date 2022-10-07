#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Número máximo de candidatos
#define MAX 9

// preferências[i][j] é o número de eleitores que preferem i a j
int preferences[MAX][MAX];

// locked[i][j] significa que i está bloqueado sobre j
bool locked[MAX][MAX];

// Cada par tem um vencedor, um perdedor
typedef struct
{
    int winner;
    int loser;
}
pair;

// Array de candidatos
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Funções prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);
int get_index(string name);
bool has_cycle(int winner, int loser);

int main(int argc, string argv[])
{
    // Verifique se há uso inválido
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
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
        candidates[i] = argv[i + 1];
    }

    // Gráfico claro de travado em pares
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Consulta de votos
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] é a preferência i-ésima do eleitor
        int ranks[candidate_count];

        // Consulta para cada classificação
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}
//função para descobrir o índice de cada candidato
int get_index(string name)
{
    for (int i = 0; i < candidate_count; i ++)
    {
        if (strcmp(name, candidates[i]) == 0)
        {
            return i;
        }
    }
    return -1;
}

// Atualizar classificações com um novo voto
bool vote(int rank, string name, int ranks[])
{
    int candidate_index = get_index(name);
    if (candidate_index != -1)
    {
        ranks[rank] = candidate_index;
        return true;
    }
    return false;
}

// Atualizar preferências de acordo com as classificações de um eleitor
void record_preferences(int ranks[])
{
    for (int line = 0; line < candidate_count; line ++)
    {
        for (int col = line + 1; col < candidate_count; col ++)
        {
            preferences[ranks[line]][ranks[col]] ++;
        }
    }
    return;
}

// Registre pares de candidatos em que um é preferido em relação ao outro
void add_pairs(void)
{
    for (int i = 0; i < candidate_count; i ++)
    {
        for (int j = 0; j < candidate_count; j ++)
        {
            if (preferences[i][j] > preferences[j][i])
            {
                pair new_pair = {i, j};
                pairs[pair_count++] = new_pair;
            }
        }
    }
    return;
}
// ordem de seleção reversa, então temos ordem decrescente
int compare(const void * elem1, const void * elem2)
{
    pair f = *((pair*) elem1);
    pair s = *((pair*) elem2);
    int first_margin = preferences[f.winner][f.loser] - preferences[f.loser][f.winner];
    int second_margin = preferences[s.winner][s.loser] - preferences[s.loser][s.winner];
    return second_margin - first_margin;
}

// Classifique os pares em ordem decrescente pela força da vitória
void sort_pairs(void)
{
    
    qsort(pairs, pair_count, sizeof(pair), compare);
}
//verificando se há um ciclo constante de vencedor e perdedor
bool has_cycle(int winner, int loser)
{
    if (locked[loser][winner] == true)
    {
        return true;
    }
    for (int i = 0; i < candidate_count; i ++)
    {
        if (locked[loser][i] == true && has_cycle(winner, i))
        {
            return true;
        }
    }
    return false;
}

// Bloqueie os pares no gráfico candidato em ordem, sem criar ciclos
void lock_pairs(void)
{
    for (int i = 0; i < pair_count; i ++)
    {
        int winner = pairs[i].winner;
        int loser = pairs[i].loser;
        if (!has_cycle(winner, loser))
        {
            locked[winner][loser] = true;
        }
    }
    return;
}

// Imprima o vencedor da eleição
void print_winner(void)
{
    for (int row = 0; row < candidate_count; row ++)
    {
        for (int col = 0; col < candidate_count; col ++)
        {
            if (locked[row][col] == true)
            {
                break;
            }
            else if (col == candidate_count - 1)
            {
                printf("%s\n", candidates[col]);
            }
        }
    }
    return;
}
