# Legibilidade
## Objetivo:

Programa com objetivo de calcular o nível (representado a partir de uma série, como na escola) aproximado necessário para compreender algum texto, conforme a seguir, assim readability que pega um texto e determina seu nível de leitura.

Teste de legibilidade baseado no índice Coleman-Liau. O índice Coleman-Liau de um texto é projetado para mostrar qual nível escolar (EUA) é necessário para entender o texto. A fórmula é:

índice = 0,0588 * L - 0,296 * S - 15,8
Aqui, L é o número médio de letras por 100 palavras no texto e S é o número médio de sentenças por 100 palavras no texto.

## Funcionalidade
* O programa solicita ao usuário uma string de texto (usando get_string ).
* O programa conta o número de letras, palavras e frases do texto. 
*  Imprimi como saída "Grade X", onde X é o nível de grau calculado pela fórmula de Coleman-Liau, arredondado para o número inteiro mais próximo.
* O número do índice resultante for 16 ou superior (equivalente ou superior ao nível de leitura de graduação sênior), o programa produz "Grade 16+" em vez de fornecer o número do índice exato. Se o número do índice for menor que 1, seu programa imprime "Before Grade 1". 