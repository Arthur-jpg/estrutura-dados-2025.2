#include <stdio.h>
#include <iostream>

using namespace std;

struct No {
    int dado;
    No* ant;
    No* prox;

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
        head = new No(0);

    }

    void push(int valor) {
       No* novo = new No(valor);
       novo -> prox = head -> prox;
       head -> prox = novo;
     
    }

    void pop() {
        No* retirar = head -> prox; //2
        head -> prox = retirar -> prox;
        delete retirar;
    }

    void pop() {


    }


};
