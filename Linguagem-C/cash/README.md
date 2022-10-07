# Cash
## Objetivo:
<p>
	<strong>Exercício Operação de Caixa:</strong> Objetivo capturar a informação da quantia de troco e retornar o número mínimo de moedas que será necessária para a operação, usando algoritmos ambiciosos, também conhecidos como gulosos ou gananciosos. 
</p>

### Algoritmos Ambiciosos:
<p>
	Ao dar o troco, é provável que você queira minimizar o número de moedas que está distribuindo para cada cliente, para não acabar com o estoque (ou irritar o cliente!). Felizmente, a ciência da computação deu aos caixas em todos os lugares maneiras de minimizar o número de moedas devidas.	
</p>
<p>
	De acordo com o Instituto Nacional de Padrões e Tecnologia (NIST), um algoritmo ambicioso é aquele “que sempre pega a melhor solução imediata, ou local, enquanto encontra uma resposta. Algoritmos ambiciosos encontram a solução geral ou globalmente ideal para alguns problemas de otimização, mas podem encontrar soluções menos do que ideais para algumas instâncias de outros problemas.”	
</p>

### Funcionalidade: 

<p>
	Suponha que se algum cliente deve pagar 41 centavos, a maior “mordida”(ou seja, melhor “mordida” imediata ou local) que pode ser feita é 25 centavos. (Essa mordida é "melhor" na medida em que nos deixa mais perto de 0 ¢ mais rápido do que qualquer outra moeda faria.) Observe que uma mordida desse tamanho reduziria o que era um problema de 41 ¢ a um problema de 16 ¢, já que 41 - 25 = 16. Ou seja, o restante é um problema semelhante, mas menor. Desnecessário dizer que outra mordida de 25 centavos seria muito grande (supondo que o caixa prefere não perder dinheiro), e assim nosso caixa ganancioso mudaria para uma mordida de 10 centavos, deixando-o com um problema de 6 centavos. Nesse ponto, a ganância pede uma mordida de 5 centavos seguida de uma mordida de 1 centavo, ponto em que o problema é resolvido. O cliente recebe um quarto, um centavo, um centavo e um centavo: quatro moedas no total. Acontece que essa abordagem gananciosa (do algoritmo) não é apenas ótima localmente, mas também globalmente para a moeda dos Estados Unidos (e também da União Europeia). Ou seja, desde que o caixa tenha o suficiente de cada moeda, essa abordagem do maior para o menor renderá o menor número possível de moedas.
</p>
