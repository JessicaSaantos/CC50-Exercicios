# Credit

## Objetivo:

<p>
	<strong>Exercício Cartão de Crédito:</strong> Tem como principal funcionalidade identificar se o número do cartão digitado é válido e retornar qual a sua bandeira. Usando soma de verificação, de acordo com o algoritmo de Luhn.
</p>

### Algoritmo de Luhn 

<p>
	 A maioria dos cartões usa um algoritmo inventado por Hans Peter Luhn, da IBM. De acordo com o algoritmo de Luhn, você pode determinar se um número de cartão de crédito é (sintaticamente) válido da seguinte maneira:
	
</p>

1) Multiplique cada segundo digito por 2, começando com o penúltimo dígito do número e, em seguida, some os dígitos desses produtos.
2) Adicione essa soma à soma dos dígitos que não foram multiplicados por 2.
3) Se o último dígito do total for 0 (ou, mais formalmente, se o módulo total 10 for congruente com 0), o número é válido!

#### vamos tentar um exemplo com o cartão Visa: 4003600000000014.

* *Para fins de discussão, vamos primeiro destacar todos os outros dígitos, começando com o penúltimo dígito do número:*
**4**0**0**3**6**0**0**0**0**0**0**0**0**0**1**4
    - Ok, vamos multiplicar cada um dos dígitos destacados por 2:

        (1 x 2) + (0 x 2) + (0 x 2) + (0 x 2) + (0 x 2) + (6 x 2) + (0 x 2) + (4 x 2)

        Isso nos dá:

        2 + 0 + 0 + 0 + 0 + 12 + 0 + 8

    - Agora vamos adicionar os dígitos desses produtos (ou seja, não os próprios produtos):

        2 + 0 + 0 + 0 + 0 + 1 + 2 + 0 + 8 = **13**
* *Agora vamos adicionar essa soma (13) à soma dos dígitos que não foram multiplicados por 2 (começando do final):*

    13 + 4 + 0 + 0 + 0 + 0 + 0 + 3 + 0 = **20**
* *Sim, o último dígito dessa soma (20) é 0, então o cartão é legítimo!*
    
    Passando a lógica para o código é possível validar números de cartão de crédito.

### Funcionalidade:
<p>
	 O programa solicita ao usuário um número de cartão de crédito e, em seguida, informe (via printf ) se é um número de cartão American Express, MasterCard ou Visa válido , de acordo com as definições de formato de cada um neste documento.
</p>
<p>
	 Estrutura dos cartões de crédito, todos os números American Express começam com 34 ou 37; a maioria dos números do MasterCard começa com 51, 52, 53, 54 ou 55; e todos os números Visa começam com 4.
</p>