#include <iostream>
using namespace std;

class No {
public:
    int dado;
    No *proximo;

    No(int d) {
        dado = d;
        proximo = nullptr;
    } 
};

class ListaCircular {
    No *head;

public:
    ListaCircular() {
        head = nullptr;
    }

    // Cria uma lista circular com n pessoas numeradas de 1 a n
    void criarLista(int n) {
        if (n <= 0) return;

        No *ultimo = nullptr;

        for (int i = 1; i <= n; i++) {
            No *novo = new No(i);
            if (head == nullptr) {
                head = novo;
                head->proximo = head; // circular
                ultimo = head;
            } else {
                ultimo->proximo = novo;
                novo->proximo = head;
                ultimo = novo;
            }
        }
    }

    // Resolve o problema de Josephus (eliminação a cada k)
    int josephus(int k) {
        if (head == nullptr || k < 1) return -1;

        No *p = head;
        No *anterior = nullptr;

        // enquanto mais de um nó restar
        while (p->proximo != p) {
            // anda k-1 posições
            for (int i = 1; i < k; i++) {
                anterior = p;
                p = p->proximo;
            }

            // elimina o k-ésimo nó
            cout << "Eliminando: " << p->dado << endl;
            anterior->proximo = p->proximo;
            delete p;
            p = anterior->proximo;
        }

        head = p;
        return p->dado; // sobrevivente
    }

    void imprimir() {
        if (head == nullptr) return;

        No *p = head;
        do {
            cout << p->dado << " ";
            p = p->proximo;
        } while (p != head);
        cout << endl;
    }
};

int main() {
    int n, k;
    cout << "Digite o número de pessoas: ";
    cin >> n;
    cout << "Digite o passo de eliminação (k): ";
    cin >> k;

    ListaCircular lista;
    lista.criarLista(n);

    cout << "\nLista inicial: ";
    lista.imprimir();

    int sobrevivente = lista.josephus(k);

    cout << "\n🟢 O sobrevivente é o número: " << sobrevivente << endl;

    return 0;
}
