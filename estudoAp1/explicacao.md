Respostas Completas:
(a) Qual é a complexidade temporal do algoritmo iterativo que calcula o fatorial de n?
Resposta: O algoritmo iterativo tem complexidade temporal O(n).

Justificativa: No algoritmo iterativo (como o seu fatorial-it.cpp), utilizamos um loop que executa exatamente n-1 iterações (de 2 até n), onde cada iteração realiza uma operação de multiplicação em tempo constante O(1). Portanto, a complexidade total é O(n).

(b) Existe uma diferença de complexidade entre o algoritmo iterativo e o recursivo para calcular o fatorial? Explique.
Resposta: Não, ambos têm a mesma complexidade temporal O(n), mas diferem na complexidade espacial.

Explicação detalhada:

Complexidade Temporal:

Iterativo: O(n) - executa n-1 multiplicações em um loop
Recursivo: O(n) - faz n chamadas recursivas, cada uma com operação O(1)
Complexidade Espacial:

Iterativo: O(1) - usa apenas variáveis locais (desconsiderando o array de memoização no seu exemplo)
Recursivo: O(n) - cada chamada recursiva adiciona um frame na pilha de execução, criando uma pilha de profundidade n
O algoritmo recursivo consome mais memória devido à pilha de chamadas recursivas, enquanto o iterativo usa espaço constante.

(c) Implemente os dois algoritmos para o cálculo do fatorial (iterativo e recursivo).
Vou criar implementações mais limpas e eficientes:

Created fatorial_implementacoes.cpp

Resumo das Complexidades:
Algoritmo	Complexidade Temporal	Complexidade Espacial	Características
Iterativo	O(n)	O(1)	Mais eficiente em memória
Recursivo	O(n)	O(n)	Mais elegante, mas usa mais memória
Considerações Importantes:
Performance: O algoritmo iterativo é geralmente mais eficiente na prática devido ao menor uso de memória.

Stack Overflow: O algoritmo recursivo pode causar estouro da pilha para valores grandes de n.

Legibilidade: O algoritmo recursivo é mais próximo da definição matemática do fatorial.

Uso de Memória: Para calcular 20!, o recursivo usará 20 frames na pilha, enquanto o iterativo usará espaço constante.

A implementação que criei (fatorial_implementacoes.cpp) demonstra ambos os algoritmos de forma clara e eficiente, incluindo validação de entrada e comparação dos resultados.