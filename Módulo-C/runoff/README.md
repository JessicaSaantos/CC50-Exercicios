# Ronoff

**Objetivo:** Programa que executa uma eleição com base em um sistema de votação por escolha ranqueada. Chamando o arquivo e digitando o nome dos candidatos, logo em seguida digitando o número de eleitores que irão votar, assim se inicia a votação dando a oportunidade de cada eleitor escolher o seu rank, e por fim o programa imprime o vencedor(a). 

Em um sistema de escolha ranqueada, os eleitores podem votar em mais de um candidato. Em vez de apenas votar na primeira escolha, eles podem classificar os candidatos em ordem de preferência. 

```

./runoff Alice Bob Charlie
Número de eleitores: 5
Rank 1: Alice
Rank 2: Bob
Rank 3: Charlie

Rank 1: Alice
Rank 2: Charlie
Rank 3: Bob

Rank 1: Bob
Rank 2: Charlie
Rank 3: Alice

Rank 1: Bob
Rank 2: Alice
Rank 3: Charlie

Rank 1: Charlie
Rank 2: Alice
Rank 3: Bob

Alice

```

**Desenvolvimento:**

As implementações de runoff.c que forão completadas para o exercício: as funções vote , tabulate , print_winner , find_min , is_tie e eliminate.

* vote
	- A função leva os argumentos voter , rank e name . Se o name corresponder ao nome de um candidato válido, a matriz de preferências globais é atualizada para indicar que o eleitor voter tem aquele candidato como sua preferência de rank (onde 0 é a primeira preferência, 1 é a segunda preferência, etc. )
	- Se a preferência for registrada com sucesso, a função retorna true ; caso contrário, a função deve retorna false (se, por exemplo, nome não for o nome de um dos candidatos).
	- A variável do tipo inteiro candidate_count armazena o número de candidatos na eleição.
	- E preferences [i] [j] armazenam o índice do candidato que é a j ésima preferência classificada para o i ésimo eleitor.