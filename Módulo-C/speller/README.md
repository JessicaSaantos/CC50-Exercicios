# Speller

## Objetivo: 

Escrever um corretor ortográfico que pode pegar um texto e todas as palavras desse texto e verificar a ortografia, ou seja, se a palavra está escrita corretamente, e realizar o desenvolvimento usando tabela de hash.

## Compreensão:

Teoricamente, na entrada de tamanho n , um algoritmo com um tempo de execução de n é “assintoticamente equivalente,” em termos de O , a um algoritmo com um tempo de execução de 2n . Na verdade, ao descrever o tempo de execução de um algoritmo, normalmente nos concentramos no termo dominante (ou seja, mais impactante) (ou seja, n neste caso, uma vez que n pode ser muito maior do que 2). No mundo real, porém, o fato é que 2n parece duas vezes mais lento que n .

O desafio é implementar o corretor ortográfico mais rápido possível! 

Em speller.c, criamos um programa projetado para verificar a ortografia de um arquivo após carregar um dicionário de palavras do disco para a memória. Esse dicionário, entretanto, é implementado em um arquivo chamado dictionary.c. Os protótipos para as funções nele, entretanto, são definidos não no próprio dictionary.c, mas em dictionary.h ao invés disso. Dessa forma, tanto speller.c quanto dictionary.c podem #include o arquivo.

## Funcionalidade: 

![speller](https://user-images.githubusercontent.com/98659450/194643127-0f1a188f-de07-4a1e-b5e7-82b09925643e.gif)


