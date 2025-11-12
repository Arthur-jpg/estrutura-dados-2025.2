#include <stdio.h>
#include <iostream>

using namespace std;

struct No {
    int dado;
    No* ant;
    No* prox;

    No() {
        prox = nullptr;
        ant = nullptr;
    }

    No(int valor) {
        dado = valor;
        prox = nullptr;
    }
};

class Fila {
private:
    No* head;

public:
    Fila() {
        head = new No();

    }

    void inserir(int valor) {
        No* novo = new No(valor);

        if (head -> prox == nullptr) {
            head -> prox = novo;
            head -> ant = novo;
        } else {
            head -> ant -> prox = novo;
            head -> ant = novo;
        }
    }

    void dequeue() {
        if (head -> prox == nullptr) {
            cout << "Erro, fila vazia" << endl;
        }
        No* remover = head -> prox;
        head -> prox = head -> prox -> prox;
        delete remover;


    }


};
