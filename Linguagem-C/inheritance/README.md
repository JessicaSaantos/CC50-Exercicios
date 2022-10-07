# Herança

## Objetivo: 

Simule a herança de tipos sanguíneos para cada membro de uma família.

	$ ./inheritance
	Generation 0, blood type OO
   		Generation 1, blood type AO
      			Generation 2, blood type OA
      			Generation 2, blood type BO
   		Generation 1, blood type OB
      			Generation 2, blood type AO
      			Generation 2, blood type BO

O tipo sanguíneo de uma pessoa é determinado por dois alelos (isto é, diferentes formas de um gene). Os três alelos possíveis são A, B e O, dos quais cada pessoa tem dois (possivelmente iguais, possivelmente diferentes). Cada um dos pais de uma criança passa aleatoriamente um de seus dois alelos de tipo sanguíneo para o filho. As combinações possíveis de tipo sanguíneo, então, são: OO, OA, OB, AO, AA, AB, BO, BA e BB.

Por exemplo, se um dos pais tem o tipo sanguíneo AO e o outro tem o tipo sanguíneo BB, os possíveis tipos sanguíneos da criança seriam AB e OB, dependendo de qual alelo é recebido de cada pai. Da mesma forma, se um dos pais tem tipo de sangue AO e o outro OB, os possíveis tipos de sangue da criança seriam AO, OB, AB e OO.

## Compreensão:

Foi concluida a implementação de inheritance.c para criar uma família com tamanho de geração especifica e atribuida alelos de tipo sanguíneo a cada membro da família. A geração mais velha terá alelos atribuídos aleatoriamente a eles.

A função create_family leva um inteiro (generations) como input e deve alocar (como via malloc) uma person para cada membro da família daquele número de gerações, retornando um ponteiro para a person na geração mais jovem.

 * exemplo, create_family(3) retorna um ponteiro para uma pessoa com dois pais, onde cada pai também tem dois pais.
 * Cada person deve ter alleles atribuídos a ela. A geração mais velha deve ter alelos escolhidos aleatoriamente (como chamando a função random_allele), e as gerações mais jovens devem herdar um alelo (escolhido aleatoriamente) de cada pai.
 * Cada person deve ter parents designados para ela. A geração mais velha deve ter ambos os parents definidos como NULL, e as gerações mais novas devem ter os parents como uma matriz de dois ponteiros, cada um apontando para um pai diferente.

Foi alocado memória para uma nova pessoa. Usando malloc para alocar memória e sizeof(person) para obter o número de bytes a serem alocados.

Em seguida, a condição para verificar se as generations> 1 .

 * Se generations > 1, então há mais gerações que ainda precisam ser alocadas. Sua função deve definir ambos os parents chamando recursivamente create_family. (Quantas generations devem ser passadas como entrada para cada pai?) A função deve então definir ambos os alleles escolhendo aleatoriamente um alelo de cada pai.
 * Caso contrário (if generations == 1 ), então não haverá dados dos pais para esta pessoa. Ambos os parents devem ser definidos como NULL, e cada allele deve ser gerado aleatoriamente.

Finalmente, a função retorna um ponteiro para a person que foi alocada.

A função free_family aceita como entrada um ponteiro para uma person, libera memória para essa pessoa e, em seguida, libera memória recursivamente para todos os seus ancestrais.

 * Como esta é uma função recursiva, primeiro lida com o caso base. Se a entrada para a função for NULL, não há nada para liberar, então a função pode retornar imediatamente.
 * Caso contrário, libera (free) recursivamente os pais da pessoa antes de liberar a criança.