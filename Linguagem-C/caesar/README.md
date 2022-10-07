# Cifra de César

## Objetivo: 
Programa com objetivo de criptografar mensagens usando a cifra de César. No momento em que o usuário executa o programa, ele deve decidir, fornecendo um argumento de linha de comando, qual deve ser a chave na mensagem secreta que fornecerá no tempo de execução.

O texto não criptografado é geralmente chamado de texto simples . O texto criptografado é geralmente chamado de texto cifrado . E o segredo usado é chamado de chave .

Para ser claro, então, aqui está como criptografar HELLO com uma chave de 1 resulta em IFMMP :
Mais formalmente, o algoritmo de César (isto é, cifra) criptografa mensagens “girando” cada letra em k posições. Mais formalmente, se p é algum texto simples (ou seja, uma mensagem não criptografada), pi é o i-ésimo caractere em p , e k é uma chave secreta (ou seja, um inteiro não negativo), então cada letra, c i , em o texto cifrado, c , é calculado como

c i = (p i + k)% 26

## Funcionalidade: 

* O programa aceita um único argumento de linha de comando, um inteiro não negativo. 
* Quando o programa é executado sem nenhum argumento de linha de comando ou com mais de um argumento de linha de comando, o programa imprime uma mensagem de erro (com printf ) e retorna de main um valor de 1 (o que tende a significa um erro ) imediatamente.
* Se algum dos caracteres do argumento da linha de comando não for um dígito decimal, o programa imprime de aviso.
* O programa deve produzir plaintext: (sem uma nova linha) [texto simples] e então solicita ao usuário uma string de texto simples (usando get_string ).
* O programa produz ciphertext: (sem uma nova linha) [texto cifrado] seguido pelo texto cifrado correspondente do texto simples, com cada caractere alfabético no texto simples “girado” pela chave de posições; os caracteres não alfabéticos devem são reproduzidos inalterados.
* O programa preserva as letras maiúsculas e minúsculas.
* Após a saída do texto cifrado, é impresso uma nova linha. 