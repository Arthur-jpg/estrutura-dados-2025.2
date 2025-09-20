# Análise de Complexidade - Sequência de Fibonacci

## 4. (1 Ponto) Considere o problema de calcular o n-ésimo termo da sequência de Fibonacci, definido como:

F(0) = 0
F(1) = 1
F(n) = F(n-1) + F(n-2) para n > 1

Responda às perguntas abaixo com base na análise de complexidade de algoritmos para o cálculo de Fibonacci:

### (a) Qual é a complexidade temporal do algoritmo iterativo que calcula o n-ésimo termo de Fibonacci?

**Resposta:** O algoritmo iterativo tem complexidade temporal **O(n)**.

**Justificativa:** No algoritmo iterativo, utilizamos um loop que executa exatamente (n-1) iterações (de 2 até n), onde cada iteração realiza operações de soma e atribuição em tempo constante O(1). Portanto, a complexidade total é O(n).

```cpp
// Exemplo: Complexidade O(n)
for(int i = 2; i <= N; i++){
    F[i] = F[i-1] + F[i-2];  // O(1) cada operação
}
```

### (b) Existe uma diferença de complexidade entre o algoritmo iterativo e o recursivo para calcular Fibonacci? Explique.

**Resposta:** **Sim, existe uma GRANDE diferença de complexidade entre os algoritmos.**

**Explicação detalhada:**

#### Algoritmo Recursivo Simples:
- **Complexidade Temporal:** O(2^n) - exponencial
- **Complexidade Espacial:** O(n) - devido à pilha de recursão

```cpp
// Fibonacci recursivo simples - MUITO INEFICIENTE
int fibo_rec(int x) {
    if (x <= 1) return x;
    return fibo_rec(x-1) + fibo_rec(x-2);  // Recalcula os mesmos valores várias vezes
}
```

**Por que O(2^n)?** Porque cada chamada gera duas novas chamadas, criando uma árvore binária de profundidade n. Muitos valores são calculados repetidamente.

#### Algoritmo Iterativo:
- **Complexidade Temporal:** O(n) - linear
- **Complexidade Espacial:** O(1) - se não armazenarmos todos os valores

#### Algoritmo Recursivo com Memoização:
- **Complexidade Temporal:** O(n) - linear
- **Complexidade Espacial:** O(n) - para armazenar os valores calculados

### (c) Implemente os três algoritmos principais para o cálculo de Fibonacci (iterativo, recursivo simples e recursivo com memoização).

## Resumo das Complexidades:

| Algoritmo | Complexidade Temporal | Complexidade Espacial | Eficiência |
|-----------|----------------------|---------------------|------------|
| **Recursivo Simples** | O(2^n) | O(n) | Muito Ineficiente |
| **Iterativo** | O(n) | O(1) | Eficiente |
| **Recursivo c/ Memoização** | O(n) | O(n) | Eficiente |

## Comparação de Performance:

Para calcular F(40):
- **Recursivo Simples:** ~1.6 bilhão de operações
- **Iterativo:** ~40 operações
- **Recursivo c/ Memoização:** ~40 operações

**Conclusão:** O algoritmo recursivo simples é dramaticamente menos eficiente que as outras abordagens para valores grandes de n.