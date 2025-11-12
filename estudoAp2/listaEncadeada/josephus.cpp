#include <iostream>

using namespace std;

class Node {
public:
    int dado;
    Node* proximo;

    Node (int x) {
        this -> dado = x;
        this -> proximo = nullptr;
    }
};


class ListaCircular {
public:
    Node* head;
    ListaCircular() {
        head = new Node(0);
    }

    int josephus(int k) {
        Node* p = head;
        Node* anterior = nullptr;

        while (p -> proximo != head) {
            for (int i = 1; i < k; i++) {
                anterior = p;
                p = p -> proximo;
            }

            anterior -> proximo = p -> proximo;
            delete p;
            p = anterior -> proximo;

        }
    }

};

int main () {
    return 0;
}