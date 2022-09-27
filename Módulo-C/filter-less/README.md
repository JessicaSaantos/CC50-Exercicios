# Filter-Less

## Objetivo:

Programa que aplica filtros em imagens BMPs. O que significa filtrar uma imagem? Você pode pensar em filtrar uma imagem como pegar os pixels de alguma imagem original e modificar cada pixel de forma que um efeito específico seja aparente na imagem resultante.

## Funcionalidade:

Talvez a maneira mais simples de representar uma imagem seja com uma grade de pixels (ou seja, pontos), cada um dos quais pode ser de uma cor diferente. Para imagens em preto e branco, precisamos, portanto, de 1 bit por pixel, já que 0 pode representar preto e 1 pode representar branco, como mostrado a seguir.

<img width="300" alt="bitmap" src="https://user-images.githubusercontent.com/98659450/192407086-ac7d6b9a-50f1-4390-8ecc-1b7bd381408c.png">

Nesse sentido, então, uma imagem é apenas um bitmap (ou seja, um mapa de bits). Para imagens mais coloridas, você simplesmente precisa de mais bits por pixel. Um formato de arquivo (como BMP , JPEG ou PNG ) que suporta “cores de 24 bits” usa 24 bits por pixel. (BMP, na verdade, suporta cores de 1, 4, 8, 16, 24 e 32 bits.)

Um BMP de 24 bits usa 8 bits para significar a quantidade de vermelho na cor de um pixel, 8 bits para significar a quantidade de verde na cor de um pixel e 8 bits para significar a quantidade de azul na cor de um pixel. Se você já ouviu falar em cores RGB, bem, aí está: vermelho, verde, azul.

Se os valores R, G e B de algum pixel em um BMP são, digamos, 0xff , 0x00 e 0x00 em hexadecimal, esse pixel é puramente vermelho, pois 0xff (também conhecido como 255 em decimal) implica "muito vermelho , ”Enquanto 0x00 e 0x00 implicam“ sem verde ”e“ sem azul ”, respectivamente.

## Escala de cinza

Um filtro comum é o filtro “escala de cinza”, onde pegamos uma imagem e queremos convertê-la em preto e branco. Como isso funciona?

Lembre-se de que se os valores de vermelho, verde e azul estiverem todos configurados para 0x00 (hexadecimal para 0 ), o pixel é preto. E se todos os valores forem configurados para 0xff (hexadecimal para 255 ), o pixel é branco. Contanto que os valores de vermelho, verde e azul sejam todos iguais, o resultado será tons de cinza variados ao longo do espectro preto e branco, com valores mais altos significando tons mais claros (mais perto de branco) e valores mais baixos significando tons mais escuros (mais perto de Preto).

Portanto, para converter um pixel em tons de cinza, só precisamos ter certeza de que os valores de vermelho, verde e azul são todos iguais. Mas como sabemos que valor devemos criá-los? Bem, provavelmente é razoável esperar que, se os valores originais de vermelho, verde e azul fossem todos muito altos, o novo valor também deveria ser muito alto. E se os valores originais fossem todos baixos, o novo valor também deveria ser baixo.

Na verdade, para garantir que cada pixel da nova imagem ainda tenha o mesmo brilho ou escuridão geral da imagem antiga, podemos obter a média dos valores de vermelho, verde e azul para determinar qual tom de cinza deve ser feito no novo pixel.

Se você aplicar isso a cada pixel da imagem, o resultado será uma imagem convertida em tons de cinza.

![escaladecinza](https://user-images.githubusercontent.com/98659450/192410143-88bee991-a0d2-4de5-a7b1-64648a6d6949.png)

## Sépia

A maioria dos programas de edição de imagem oferece suporte a um filtro “sépia”, que dá às imagens uma aparência antiga, fazendo com que toda a imagem pareça um pouco marrom-avermelhada.

Uma imagem pode ser convertida em sépia tomando cada pixel e computando novos valores de vermelho, verde e azul com base nos valores originais dos três.

Existem vários algoritmos para converter uma imagem em sépia, mas, para esse problema, pediremos que você use o seguinte algoritmo. Para cada pixel, os valores da cor sépia devem ser calculados com base nos valores da cor original conforme a seguir.

	sepiaRed = .393 * originalRed + .769 * originalGreen + .189 * originalBlue
sepiaGreen = .349 * originalRed + .686 * originalGreen + .168 * originalBlue
sepiaBlue = 0,272 * originalRed + 0,534 * originalGreen + 0,131 * originalBlue

Obviamente, o resultado de cada uma dessas fórmulas pode não ser um número inteiro, mas cada valor pode ser arredondado para o número inteiro mais próximo. Também é possível que o resultado da fórmula seja um número maior que 255, o valor máximo para um valor de cor de 8 bits. Nesse caso, os valores de vermelho, verde e azul devem ser limitados a 255. Como resultado, podemos garantir que os valores de vermelho, verde e azul resultantes serão números inteiros entre 0 e 255, inclusive.

![sepia](https://user-images.githubusercontent.com/98659450/192410596-4da2e4fa-cc81-40c9-92bb-743c1880b2f9.png)