# Copa do Mundo

## Objetivo:

 Programa que executa simulações da Copa do Mundo da FIFA.

	$ python tournament.py 2018m.csv
	Belgium: 20.9% chance of winning
	Brazil: 20.3% chance of winning
	Portugal: 14.5% chance of winning
	Spain: 13.6% chance of winning
	Switzerland: 10.5% chance of winning
	Argentina: 6.5% chance of winning
	England: 3.7% chance of winning
	France: 3.3% chance of winning
	Denmark: 2.2% chance of winning
	Croatia: 2.0% chance of winning
	Colombia: 1.8% chance of winning
	Sweden: 0.5% chance of winning
	Uruguay: 0.1% chance of winning
	Mexico: 0.1% chance of winning

## Compreensão:

Na Copa do Mundo de futebol, a fase eliminatória é composta por 16 equipes. Em cada rodada, cada equipe joga contra outra equipe e as equipes perdedoras são eliminadas. Quando restam apenas duas equipes, o vencedor da partida final é o campeão.

No futebol, as equipes recebem classificações da FIFA , que são valores numéricos que representam o nível de habilidade relativo de cada equipe. Classificações mais altas da FIFA indicam melhores resultados de jogos anteriores e, dadas as classificações da FIFA de duas equipes, é possível estimar a probabilidade de qualquer equipe vencer um jogo com base em suas classificações atuais. As classificações da FIFA de duas Copas do Mundo anteriores estão disponíveis como classificações da FIFA masculinas de maio de 2018 e classificações da FIFA femininas de março de 2019.

Usando essas informações, podemos simular todo o torneio simulando rodadas repetidamente até ficarmos com apenas um time. E se quisermos estimar a probabilidade de uma determinada equipe vencer o torneio, podemos simular o torneio muitas vezes (por exemplo, 1000 simulações) e contar quantas vezes cada equipe vence um torneio simulado. A tarefa deste laboratório foi fazer exatamente isso usando Python!

## Funcionalidade:

Concluindo a implementação de tournament.py, de modo que simula um número de torneios e gera a probabilidade de vitória de cada equipe.
 * O arquivo usado será fornecido como um argumento de linha de comando. Para acessar o nome do arquivo temos sys.argv[1].
 * É possível abrir um arquivo com open(filename), onde filename é uma variável que armazena o nome do arquivo.
 * Depois de ter um arquivo, foi usado csv.DictReader(file) para fornecer um “leitor”: um objeto em Python que pode percorrer para ler o arquivo uma linha de cada vez, tratando cada linha como um dicionário.
 * Por padrão, todos os valores lidos do arquivo são strings. Portanto, primeiro foi convertido a equipe rating para an int().
 * Por fim, foi anexado o dicionário de cada equipe ao arquivo teams. A chamada de função teams.append(team) será anexada team à lista teams.

Em seguida, foi implementado a simulate_tournament função. Esta função aceita como entrada uma lista de equipes e simula rodadas repetidamente até que fique com uma equipe. A função retorna o nome dessa equipe.

 * Chamando a simulate_round função, que simula uma única rodada, aceitando uma lista de times como entrada e retornando uma lista de todos os vencedores.