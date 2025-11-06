#include <iostream>
#include <vector>
using namespace std;

class No {
public:
    int dado;
    No *proximo;

    No(int d, No *p = nullptr) {
        dado = d;
        proximo = p;
    }
};

class ListaEncadeada {
    No *head;

public:
    ListaEncadeada() {
        head = new No(0);
    }

    void addFim(int valor) {
        No *novo = new No(valor);
        No *p = head;

        while (p->proximo != nullptr)
            p = p->proximo;

        p->proximo = novo;
    }

    bool temCicloVector() {
        vector<No*> visitados;
        No *p = head->proximo;

        while (p != nullptr) {
            // verifica se o nó atual já foi visitado
            for (No* v : visitados) {
                if (v == p)
                    return true; // ciclo detectado
            }

            // adiciona o nó no vetor
            visitados.push_back(p);

            p = p->proximo;
        }

        return false; // percorreu tudo → sem ciclo
    }

    // cria um ciclo artificial para testar
    void criarCiclo() {
        No *p = head->proximo;
        No *ultimo = nullptr;
        No *segundo = nullptr;
        int contador = 0;

        while (p != nullptr) {
            if (contador == 1) segundo = p; // guarda o segundo nó
            ultimo = p;
            p = p->proximo;
            contador++;
        }

        if (ultimo != nullptr && segundo != nullptr)
            ultimo->proximo = segundo; // cria ciclo
    }
};

int main() {
    ListaEncadeada lista;

    lista.addFim(10);
    lista.addFim(20);
    lista.addFim(30);
    lista.addFim(40);

    cout << "Ciclo antes? " << (lista.temCicloVector() ? "Sim" : "Não") << endl;

    lista.criarCiclo();

    cout << "Ciclo depois? " << (lista.temCicloVector() ? "Sim" : "Não") << endl;

    return 0;
}
