# Filter-More

## Objetivo: 

Programa que aplica filtros nas imagens, semelhante a resolução do filter-less, diferença do filtro **edges**. A edges função deve pegar uma imagem e destacar as bordas entre os objetos, de acordo com o operador Sobel.

### Compreensão:

Em algoritmos de inteligência artificial para processamento de imagens, muitas vezes é útil detectar bordas em uma imagem: linhas na imagem que criam um limite entre um objeto e outro. Uma maneira de obter esse efeito é aplicando o operador Sobel à imagem.

Assim como o desfoque da imagem, a detecção de borda também funciona pegando cada pixel e modificando-o com base na grade de pixels 3x3 que circunda esse pixel. Mas, em vez de apenas obter a média dos nove pixels, o operador de Sobel calcula o novo valor de cada pixel obtendo uma soma ponderada dos valores dos pixels ao redor. E como as arestas entre objetos podem ocorrer tanto na direção vertical quanto na horizontal, na verdade você calculará duas somas ponderadas: uma para detectar arestas na direção x e outra para detectar arestas na direção y. Em particular, você usará os dois “kernels” a seguir:

<img width="300" alt="sobel" src="https://user-images.githubusercontent.com/98659450/192666747-7735a699-2d2a-4e2b-8bcf-59d78d3344d7.png">

Como interpretar esses kernels? Resumindo, para cada um dos três valores de cor de cada pixel, calcularemos dois valores Gx e Gy. Para calcular Gx o valor do canal vermelho de um pixel, por exemplo, pegaremos os valores vermelhos originais para os nove pixels que formam uma caixa 3x3 ao redor do pixel, multiplicaremos cada um deles pelo valor correspondente no Gx kernel e obteremos a soma dos valores resultantes.

Por que esses valores específicos para o kernel? Na Gx direção, por exemplo, estamos multiplicando os pixels à direita do pixel de destino por um número positivo e multiplicando os pixels à esquerda do pixel de destino por um número negativo. Quando fazemos a soma, se os pixels da direita tiverem uma cor semelhante aos pixels da esquerda, o resultado será próximo de 0 (os números se cancelam). Mas se os pixels à direita forem muito diferentes dos pixels à esquerda, o valor resultante será muito positivo ou muito negativo, indicando uma mudança de cor que provavelmente é resultado de um limite entre os objetos. E um argumento semelhante vale para o cálculo de arestas na y direção.

Usando esses kernels, podemos gerar um valor Gx e Gy para cada um dos canais vermelho, verde e azul para um pixel. Mas cada canal só pode assumir um valor, não dois: então precisamos de alguma maneira de combinar Gx e Gy em um único valor. O algoritmo do filtro Sobel combina Gx e Gy em um valor final calculando a raiz quadrada de Gx^2 + Gy^2. E como os valores de canal só podem assumir valores inteiros de 0 a 255, certifique-se de que o valor resultante seja arredondado para o inteiro mais próximo e limitado a 255!

E quanto ao manuseio de pixels na borda ou no canto da imagem? Existem muitas maneiras de lidar com pixels na borda, mas para os propósitos deste problema, pediremos que você trate a imagem como se houvesse uma borda preta sólida de 1 pixel ao redor da borda da imagem: portanto, tentar acessar um pixel além da borda da imagem deve ser tratado como um pixel preto sólido (valores de 0 para cada vermelho, verde e azul). Isso ignorará efetivamente esses pixels de nossos cálculos de Gx e Gy.

**Resultado**

![edges](https://user-images.githubusercontent.com/98659450/192667706-d38d8862-fe48-462f-bab3-8b9b24351bb0.png)

