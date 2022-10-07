# Recover

## Objetivo:

Programa desenvolvido com objetivo de recuperar arquivos JPEGs. Basicamente recuperar fotos que foram excluidas.

## Compreensão:

JPEGs têm “assinaturas”, padrões de bytes que podem distingui-los de outros formatos de arquivo. Especificamente, os primeiros três bytes de JPEGs são

	0xff 0xd8 0xff

do primeiro para o terceiro byte, da esquerda para a direita. O quarto byte, entretanto, é **0xe0 , 0xe1 , 0xe2 , 0xe3 , 0xe4 , 0xe5 , 0xe6 , 0xe7 , 0xe8 , 0xe9 , 0xea , 0xeb , 0xec , 0xed , 0xee ou 0xef** . Dito de outra forma, os primeiros quatro bits do quarto byte são 1110 .

As probabilidades são de que, se você encontrar esse padrão de quatro bytes,  eles demarcam o início de um JPEG. Então o programa itera sobre uma cópia do cartão de memória, procurando assinaturas de JPEGs. Cada vez que encontrar uma assinatura, é possével abrir um novo arquivo para escrever e começar a preencher esse arquivo com bytes do cartão de memória, fechando esse arquivo apenas quando encontrar outra assinatura.

## Funcionalidade

 * O programa aceita exatamente um argumento de linha de comando, o nome de uma imagem forense da qual recuperar JPEGs.
	
		$ ./recover card.raw

 * Se o programa não é executado com exatamente um argumento de linha de comando, ele lembra o usuário do uso correto e main retorna 1.

		$ Usage: ./recover IMAGE

 * Quando a imagem forense não pode ser aberta para leitura, o programa informa isso ao usuário, e main retorna 1.

 * Cada um dos arquivos gerados são nomeado como ###.jpg , onde ### é um número decimal de três dígitos, começando com 000 para a primeira imagem e aumentando.

## Demonstração:

![Animação](https://user-images.githubusercontent.com/98659450/192909172-4830bcba-ad75-4309-8b5a-735fb4f4ab11.gif)

![recover](https://user-images.githubusercontent.com/98659450/192909615-c4e87693-2c28-48ab-84e3-335fa8f6c803.gif)



