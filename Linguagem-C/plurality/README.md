# Plurality

**Objetivo:** Programa que executa uma eleição de pluralidade, conforme a seguir. Chamando o arquivo e digitando o nome dos candidatos, logo em seguida digitando o número de eleitores, assim se inicia a votação, e por fim o programa imprime o vencedor(a).

```

$ ./plurality Alice Bob Charlie
Número de eleitores: 4
Voto: Alice
Voto: Bob
Voto: Charlie
Voto: Alice
Alice

```
**Desenvolvimento:**

 * A linha #define MAX 9 é alguma sintaxe usada aqui para significar que MAX é uma constante (igual a 9) que pode ser usada em todo o programa. Aqui, ele representa o número máximo de candidatos que uma eleição pode ter.

 * O arquivo então define uma struct chamada candidate. Cada candidate tem dois campos: uma string chamada name representando o nome do candidato e um int chamado votes representando o número de votos que o candidato possui. Em seguida, o arquivo define uma matriz global de candidates, em que cada elemento é ele próprio um candidate.

 *  candidate_count representando o número de candidatos na eleição, copia os argumentos da linha de comando para a vetor candidates e pede ao usuário para digitar o número de eleitores. Em seguida, o programa permite que cada eleitor digite um voto, acionando a função de vote em cada candidato votado. Finalmente, main faz uma chamada para a função print_winner para imprimir o vencedor (ou vencedores) da eleição.

 * Função de vote.
	- vote leva um único argumento, uma string chamada name , que representa o nome do candidato que foi votado.
	- Se o name corresponder a um dos nomes dos candidatos na eleição, o total de votos é atualizado para contabilizar a nova votação. A função de votação(vote) neste caso deve retornar true para indicar uma votação bem-sucedida.
	- Se o name não corresponder ao nome de nenhum dos candidatos na eleição, nenhum total de votos muda e a função de voto(vote) retorna false para indicar uma cédula inválida.

 * Função print_winner.
	- A função imprime o nome do candidato que recebeu mais votos na eleição e, em seguida, imprime uma nova linha.
	- É possível que a eleição termine em empate se vários candidatos tiverem, cada um, o número máximo de votos. Nesse caso, imprime os nomes de cada um dos candidatos vencedores, cada um em uma linha separada.