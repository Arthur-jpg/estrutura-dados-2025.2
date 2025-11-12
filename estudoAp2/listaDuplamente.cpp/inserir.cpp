struct No {
    int dado;
    No* ant;
    No* prox;

    No(int valor) {
        dado = valor;
        ant = nullptr;
        prox = nullptr;
    }
};

class ListaDupla {
private:
    No* head;

public:
    ListaDupla() {
        head = new No(0);

    }

    void inserirFim(int valor) {
        No* novo = new No(valor);

        if (head->prox == nullptr) {
            head -> prox = novo;
            head -> ant = novo;
        } else {
            No* antigoUltimo = head -> ant;
            antigoUltimo -> prox = novo;
            novo -> ant = antigoUltimo;
            head -> ant = novo;
        }


    }

    void remover(int x) {
        No* p = head->prox; // começa no primeiro nó real

        while (p != nullptr) {
            if (p->dado == x) {
                // Caso 1: nó anterior existe (não é o primeiro)
                if (p->ant != nullptr)
                    p->ant->prox = p->prox;
                else
                    head->prox = p->prox; // p era o primeiro nó

                // Caso 2: nó seguinte existe (não é o último)
                if (p->prox != nullptr)
                    p->prox->ant = p->ant;
                else
                    head->ant = p->ant; // p era o último nó

                delete p;
                return;
            }
            p = p->prox;
        }
    }



};
