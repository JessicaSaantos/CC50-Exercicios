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

 * tabulate
	- A função atualiza o número de votes que cada candidato possui nesta fase do segundo turno.
	- Lembrando que em cada estágio do segundo turno, cada eleitor vota efetivamente em seu candidato preferido que ainda não foi eliminado.
	- Cada voter_count armazena o número de eleitores na eleição.
	- Lembrando que, para um eleitor i , seu candidato de primeira escolha é representado por preferences [i][0] , seu candidato de segunda escolha por preferences [i][1] , etc.
	- A estrutura do candidato possui um campo denominado eliminado , o que será true caso o candidato tenha sido eliminado da eleição.
	- A struct do candidate tem um campo chamado votes , que você provavelmente desejará atualizar para o candidato preferido de cada eleitor.

 * print_winner
	- Se algum candidato tiver mais da metade dos votos, seu nome deve ser impresso em stdout e a função deve retornar true .
	- Se ninguém ganhou a eleição ainda, a função deve retornar falso .
	- Lembre-se de que voter_count armazena o número de eleitores na eleição.

 * find_min
	- A função deve retornar o total mínimo de votos para qualquer candidato que ainda esteja na eleição.
	- É necessário percorrer os candidatos para encontrar aquele que ainda está na eleição e tem o menor número de votos. 

 * is_tie
	- A função leva um argumento min , que será o número mínimo de votos que alguém na eleição tem atualmente.
	- A função retorna verdadeiro se todos os candidatos restantes na eleição tiverem o mesmo número de votos, e retorna falso caso contrário.
	- O empate ocorre se todos os candidatos ainda na eleição tiverem o mesmo número de votos. Observe também que a função is_tie leva um argumento min , que é o menor número de votos que qualquer candidato possui atualmente.

 * eliminate
	- A função leva um argumento min , que será o número mínimo de votos que alguém na eleição tem atualmente.
	- A função deve eliminar o candidato (ou candidatos) com número mín de votos.
