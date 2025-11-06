#include <iostream>
#include <vector>
using namespace std;

class No {
public:
    int dado;
    No *proximo;

    No(int d, No *p = nullptr) {
        this->dado = d;
        this->proximo = p;
    }
};

class ListaEncadeada {
    No *head;

public:
    ListaEncadeada() {
        this->head = new No(0); // nó cabeça
    }

    void addFim(int info) {
        No *novo = new No(info);
        No *p = this->head;

        while (p->proximo != nullptr) {
            p = p->proximo;
        }

        p->proximo = novo;
    }

    void imprimir() {
        No *p = this->head->proximo;
        while (p != nullptr) {
            cout << p->dado << " ";
            p = p->proximo;
        }
        cout << endl;
    }

    bool ehPalindromo() {
        vector<int> elementos;
        No *p = this->head->proximo;

        // Passo 1: copiar todos os elementos para um vetor
        while (p != nullptr) {
            elementos.push_back(p->dado);
            p = p->proximo;
        }

        // Passo 2: verificar se o vetor é igual quando lido ao contrário
        int i = 0;
        int j = elementos.size() - 1;

        while (i < j) {
            if (elementos[i] != elementos[j]) {
                return false;
            }
            i++;
            j--;
        }

        return true;
    }
};

int main() {
    ListaEncadeada lista1;
    lista1.addFim(10);
    lista1.addFim(20);
    lista1.addFim(30);
    lista1.addFim(20);
    lista1.addFim(10);

    cout << "Lista: ";
    lista1.imprimir();

    if (lista1.ehPalindromo())
        cout << "✅ A lista é um palíndromo!" << endl;
    else
        cout << "❌ A lista não é um palíndromo." << endl;

    // Exemplo não-palíndromo
    ListaEncadeada lista2;
    lista2.addFim(1);
    lista2.addFim(2);
    lista2.addFim(3);

    cout << "\nLista: ";
    lista2.imprimir();

    if (lista2.ehPalindromo())
        cout << "✅ A lista é um palíndromo!" << endl;
    else
        cout << "❌ A lista não é um palíndromo." << endl;

    return 0;
}
