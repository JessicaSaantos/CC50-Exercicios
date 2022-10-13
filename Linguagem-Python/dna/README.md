# DNA

## Objetivo:

Programa que identifica uma pessoa com base em seu DNA, conforme abaixo.

	$ python dna.py databases/large.csv sequences/5.txt
	Harry

## Compreensão:

O DNA, o portador da informação genética nos seres vivos, tem sido usado na justiça criminal há décadas. Mas como, exatamente, o perfil de DNA funciona? Dada uma sequência de DNA, como os investigadores podem identificar a quem ela pertence?

Bem, o DNA é realmente apenas uma sequência de moléculas chamadas nucleotídeos, organizadas em uma forma particular (uma dupla hélice). Cada célula humana tem bilhões de nucleotídeos dispostos em sequência. Cada nucleotídeo de DNA contém uma das quatro bases diferentes: adenina (A), citosina (C), guanina (G) ou timina (T). Algumas porções dessa sequência (isto é, genoma) são as mesmas, ou pelo menos muito semelhantes, em quase todos os seres humanos, mas outras porções da sequência têm uma diversidade genética maior e, portanto, variam mais na população.

Um lugar onde o DNA tende a ter alta diversidade genética é em Short Tandem Repeats (STRs). Um STR é uma sequência curta de bases de DNA que tende a se repetir várias vezes consecutivas em locais específicos dentro do DNA de uma pessoa. O número de vezes que uma determinada STR se repete varia muito entre os indivíduos. Nas amostras de DNA abaixo, por exemplo, Alice tem o STR AGAT repetido quatro vezes em seu DNA, enquanto Bob tem o mesmo STR repetido cinco vezes.

<img width="811" alt="strs" src="https://user-images.githubusercontent.com/98659450/195481682-4e5c6848-94bb-4741-8940-adb86cfb5d85.png">

O uso de vários STRs, em vez de apenas um, pode melhorar a precisão do perfil de DNA. Se a probabilidade de duas pessoas terem o mesmo número de repetições para um único STR for de 5%, e o analista observar 10 STRs diferentes, então a probabilidade de que duas amostras de DNA coincidam puramente por acaso é de cerca de 1 em 1 quatrilhão (assumindo que todos os STRs são independentes entre si). Portanto, se duas amostras de DNA corresponderem no número de repetições para cada um dos STRs, o analista pode ter certeza de que vieram da mesma pessoa. CODIS, o banco de dados de DNA do FBI , usa 20 STRs diferentes como parte de seu processo de perfil de DNA.

Como seria esse banco de dados de DNA? Bem, em sua forma mais simples, você poderia imaginar a formatação de um banco de dados de DNA como um arquivo CSV, em que cada linha corresponde a um indivíduo e cada coluna corresponde a um STR específico.

	name,AGAT,AATG,TATC
	Alice,28,42,14
	Bob,17,22,19
	Charlie,36,18,25

Os dados no arquivo acima sugerem que Alice tem a sequência AGAT repetida 28 vezes consecutivas em algum lugar de seu DNA, a sequência AATG repetida 42 vezes e TATC repetida 14 vezes. Bob, enquanto isso, tem esses mesmos três STRs repetidos 17 vezes, 22 vezes e 19 vezes, respectivamente. E Charlie tem esses mesmos três STRs repetidos 36, 18 e 25 vezes, respectivamente.

Então, dada uma sequência de DNA, como você pode identificar a quem ela pertence? Bem, imagine que você olhou através da sequência de DNA para a sequência consecutiva mais longa de AGATs repetidos e descobriu que a sequência mais longa tinha 17 repetições. Se você descobrir que a sequência mais longa de AATG tem 22 repetições e a sequência mais longa de TATC tem 19 repetições, isso forneceria uma boa evidência de que o DNA era de Bob. 

Nesse programa podemos a funcionalidade é capturar uma sequência de DNA e um arquivo CSV contendo contagens de STR para uma lista de indivíduos e, em seguida, imprimir na saída a quem o DNA (provavelmente) pertence.

## Funcionalidade:

 * O programa exige como seu primeiro argumento de linha de comando o nome de um arquivo CSV contendo as contagens de STR para uma lista de indivíduos e também como seu segundo argumento o nome de um arquivo de texto contendo a sequência de DNA a ser identificada.

	- Se o programa for executado com o número incorreto de argumentos de linha de comando, imprime uma mensagem de erro (com print). 

 * Em seguida, abre o arquivo CSV e lê o conteúdo na memória.
	- Já supondo que a primeira linha do arquivo CSV serão os nomes das colunas. A primeira coluna será a palavra name e as colunas restantes serão as próprias sequências STR.

 * Depois o programa abre a sequência de DNA e lê o conteúdo na memória.

 * Para cada um dos STRs (da primeira linha do arquivo CSV), o programa calcula a execução mais longa de repetições consecutivas do STR na sequência de DNA a ser identificada. Com uso da função auxiliar, longest_match, que fará exatamente isso!

 * Se as contagens de STR corresponderem exatamente a qualquer um dos indivíduos no arquivo CSV, o programa imprime o nome do indivíduo correspondente.