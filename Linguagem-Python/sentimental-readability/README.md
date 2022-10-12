# Legibilidade

## Objetivo:

Programa que calcula o nível escolar aproximado necessário para compreender algum texto, conforme a seguir.

	$ python readability.py
	Text: Congratulations! Today is your day. You're off to 	Great Places! You're off and away!
	Grade 3

## Funcionalidade:

 * O programa primeiro pede ao usuário para digitar algum texto e, em seguida, produz o nível de nota para o texto, de acordo com a fórmula de Coleman-Liau, exatamente no Conjunto de Problemas 2 em C, exceto que o programa desta vez está escrito em Python.
  - O índice de Coleman-Liau é calculado como 0.0588 * L - 0.296 * S - 15.8, onde L é o número médio de letras por 100 palavras no texto e S é o número médio de frases por 100 palavras no texto.

 * Em seguida o programa conta o número de letras, palavras e frases no texto. Supondo que uma letra é qualquer caractere minúsculo de a até z ou qualquer caractere maiúsculo de A até Z, qualquer sequência de caracteres separada por espaços conta como uma palavra e que qualquer ocorrência de ponto, ponto de exclamação ou ponto de interrogação indica o fim de uma frase.

 * Depois imprime como saída "Grade X" onde X é o nível de nota calculado pela fórmula de Coleman-Liau, arredondado para o inteiro mais próximo.

 * Se o número de índice resultante for 16 ou superior (equivalente ou superior a um nível de leitura de graduação sênior), o programa produz "Grade 16+" em vez de fornecer o número de índice exato. Se o número do índice for menor que 1, gera "Before Grade 1".