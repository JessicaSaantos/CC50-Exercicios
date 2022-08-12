# Substituição

## Objetivo:
O programa tem como objetivo implementar a cifra de substituição para criar criptografia, alterando a ordem do alfabeto, ou seja, a chave para criptografar o texto original será a sequência que o usuário escolher do alfabeto.

## Funcionalidade: 
* O programa aceita um único argumento de linha de comando, a chave a ser usada para a substituição. A chave em si faz distinção entre maiúsculas e minúsculas, portanto, se algum caractere na chave estiver em maiúscula ou minúscula, isso não deve afeta o comportamento do programa.
* Se o programa for executado sem nenhum argumento de linha de comando ou com mais de um argumento de linha de comando, irá imprimir uma mensagem de erro (com printf ) e retornar de main um valor de 1 (o que tende a significar um erro ) imediatamente.
* Se a chave for inválida (por não conter 26 caracteres, conter qualquer caractere que não seja um caractere alfabético, ou não conter cada letra exatamente uma vez), o programa imprime uma mensagem de erro (com printf) e retorna do main um valor de 1 imediatamente.
* O programa produz na saída plaintext: - que significa texto simples: (sem uma nova linha) e então solicita ao usuário uma string de texto simples (usando get_string ).
* O programa tem na saída o seguinte texto ciphertext: - que significa texto cifrado - (sem uma nova linha) seguido pelo texto cifrado correspondente do texto simples, com cada caractere alfabético no texto simples substituído pelo caractere correspondente no texto cifrado; os caracteres não alfabéticos devem ser reproduzidos inalterados.
* O programa preserva maiúsculas e minúsculas.