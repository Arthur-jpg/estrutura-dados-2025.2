// Implementação mínima para permitir compilar e testar rotacaoDireita
#include <iostream>
#include <algorithm>

using namespace std;

// Estrutura do nó (em português, conforme seu projeto)
struct No {
    int chave;
    No* esquerdo;
    No* direito;
    int altura;

    No(int k) : chave(k), esquerdo(nullptr), direito(nullptr), altura(1) {}
};

class ArvoreAVL {
public:
    // Retorna a altura segura (0 se n == nullptr)
    int obterAltura(No* n) {
        return n ? n->altura : 0;
    }

    // Rotação à direita: retorna nova raiz (x)
    No* rotacaoDireita(No* y) {
        // y é o C
        // x é o B
        No* x = y->esquerdo;

        // ponteiro para filho a direita de B
        No* T2 = x->direito;

        // executar rotação
        x->direito = y;
        y->esquerdo = T2;

        // atualizar alturas
        y->altura = max(obterAltura(y->esquerdo), obterAltura(y->direito)) + 1;
        x->altura = max(obterAltura(x->esquerdo), obterAltura(x->direito)) + 1;

        return x;
    }

    No* rotacaoEsquerda(No* y) {
        if (!y || !y->direito) return y; // proteção básica

        No* x = y->direito;
        No* T2 = x->esquerdo;

        // executar rotação
        x->esquerdo = y;
        y->direito = T2;

        // atualizar alturas
        y->altura = max(obterAltura(y->esquerdo), obterAltura(y->direito)) + 1;
        x->altura = max(obterAltura(x->esquerdo), obterAltura(x->direito)) + 1;

        return x;
    }

    // Encontra o menor nó na subárvore (esquerda mais profunda)
    No* encontrarMinimo(No* node) {
        No* atual = node;
        while (atual && atual->esquerdo) {
            atual = atual->esquerdo;
        }
        return atual;
    }

    // Retorna o fator de balanceamento: altura(esquerdo) - altura(direito)
    int obterBalanco(No* n) {
        if (!n) return 0;
        return obterAltura(n->esquerdo) - obterAltura(n->direito);
    }

    // Função auxiliar para remover um nó e rebalancear a árvore (AVL)
    No* remover(No* no, int valor) {

        // --- Parte 1: Remoção padrão da BST ---

        // Caso base: Nó não encontrado
        if (no == nullptr) {
            return no;
        }

        // Procura o nó recursivamente
        if (valor < no->chave) {
            no->esquerdo = remover(no->esquerdo, valor);
        } else if (valor > no->chave) {
            no->direito = remover(no->direito, valor);
        }
        // Nó encontrado
        else {

            // Caso 1 ou 2: Nó com 0 ou 1 filho
            if (no->esquerdo == nullptr || no->direito == nullptr) {

                // Encontra o filho único (ou nullptr se for folha)
                No* temp = no->esquerdo ? no->esquerdo : no->direito;

                // Caso 1: Nó é uma folha (0 filhos)
                if (temp == nullptr) {
                    temp = no;
                    no = nullptr; // O nó será nulo para o pai
                }
                // Caso 2: Nó tem 1 filho
                else {
                    *no = *temp; // Copia o conteúdo do filho para este nó
                }
                delete temp; // Deleta o nó folha ou o filho original
            }
            // Caso 3: Nó com 2 filhos
            else {
                // Encontra o sucessor (menor valor da subárvore direita)
                No* temp = encontrarMinimo(no->direito);

                // Copia o valor do sucessor para este nó
                no->chave = temp->chave;

                // Remove o sucessor da subárvore direita
                no->direito = remover(no->direito, temp->chave);
            }
        }

        // Se a árvore ficou vazia após a remoção (era o único nó)
        if (no == nullptr) {
            return no;
        }

        // --- Parte 2: Balanceamento da AVL ('Continuação') ---

        // 1. Atualiza a altura do nó atual
        no->altura = 1 + max(obterAltura(no->esquerdo), obterAltura(no->direito));

        // 2. Calcula o fator de balanceamento
        int balanco = obterBalanco(no);

        // 3. Verifica os 4 casos de desbalanceamento

        // Caso 1: Rotação Simples Direita (LL)
        if (balanco > 1 && obterBalanco(no->esquerdo) >= 0) {
            return rotacaoDireita(no);
        }

        // Caso 2: Rotação Dupla Direita (LR)
        if (balanco > 1 && obterBalanco(no->esquerdo) < 0) {
            no->esquerdo = rotacaoEsquerda(no->esquerdo);
            return rotacaoDireita(no);
        }

        // Caso 3: Rotação Simples Esquerda (RR)
        if (balanco < -1 && obterBalanco(no->direito) <= 0) {
            return rotacaoEsquerda(no);
        }

        // Caso 4: Rotação Dupla Esquerda (RL)
        if (balanco < -1 && obterBalanco(no->direito) > 0) {
            no->direito = rotacaoDireita(no->direito);
            return rotacaoEsquerda(no);
        }

        // 4. Retorna o nó (potencialmente) balanceado
        return no;
    }

    // Função de inserção AVL: insere uma chave e rebalanceia a árvore
    No* inserir(No* no, int chave) {
        // 1. Inserção padrão BST
        if (no == nullptr) {
            return new No(chave);
        }

        if (chave < no->chave) {
            no->esquerdo = inserir(no->esquerdo, chave);
        } else if (chave > no->chave) {
            no->direito = inserir(no->direito, chave);
        } else {
            // chaves duplicadas: não inserir
            return no;
        }

        // 2. Atualiza a altura deste nó
        no->altura = 1 + max(obterAltura(no->esquerdo), obterAltura(no->direito));

        // 3. Verifica o fator de balanceamento
        int balanco = obterBalanco(no);

        // 4. Casos de rotação
        // Left Left
        if (balanco > 1 && chave < no->esquerdo->chave)
            return rotacaoDireita(no);

        // Right Right
        if (balanco < -1 && chave > no->direito->chave)
            return rotacaoEsquerda(no);

        // Left Right
        if (balanco > 1 && chave > no->esquerdo->chave) {
            no->esquerdo = rotacaoEsquerda(no->esquerdo);
            return rotacaoDireita(no);
        }

        // Right Left
        if (balanco < -1 && chave < no->direito->chave) {
            no->direito = rotacaoDireita(no->direito);
            return rotacaoEsquerda(no);
        }

        // retorna o ponteiro do nó (sem mudanças se já balanceado)
        return no;
    }

    
};

// Função auxiliar para imprimir em pre-order (raiz, esquerda, direita)
void imprimirPreOrdem(No* raiz) {
    if (!raiz) return;
    std::cout << raiz->chave << " ";
    imprimirPreOrdem(raiz->esquerdo);
    imprimirPreOrdem(raiz->direito);
}

int main() {
    // Montando uma pequena árvore para demonstrar rotação à direita
    // Estrutura antes:
    //      30 (y)
    //     /
    //   20 (x)
    //     \
    //     25 (T2)

    No* y = new No(30);
    No* x = new No(20);
    No* T2 = new No(25);

    x->direito = T2;
    y->esquerdo = x;

    // definir alturas manualmente para demonstração
    T2->altura = 1;
    x->altura = std::max(0, 1) + 1; // 2
    y->altura = std::max(x->altura, 0) + 1; // 3

    ArvoreAVL avl;

    std::cout << "Antes da rotacao (pre-ordem): ";
    imprimirPreOrdem(y);
    std::cout << "\n";

    No* novaRaiz = avl.rotacaoDireita(y);

    std::cout << "Depois da rotacao (pre-ordem): ";
    imprimirPreOrdem(novaRaiz);
    std::cout << "\n";

    // Limpeza simples (não percorre toda a árvore para deletes em exemplos pequenos)
    delete T2;
    delete x;
    delete y; // note: se a rotação mudou os ponteiros, em exemplos reais cuidar da liberação correta

    return 0;
}