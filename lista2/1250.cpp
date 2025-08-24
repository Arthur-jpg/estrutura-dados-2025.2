#include <iostream>
#include <stdio.h>

using namespace std;

int main() {

    int numeroDeCasosTeste;
    cin >> numeroDeCasosTeste;

    for (int i = 0; i < numeroDeCasosTeste; i++) {

        int numeroDeTiros;
        cin >> numeroDeTiros;

        int tiross[numeroDeTiros];
        char movimento[numeroDeTiros];

        for(int i = 0; i < numeroDeTiros; i++) {
            int tiro;
            cin >> tiro;
            tiross[i] = tiro;
        }
        for(int i = 0; i < numeroDeTiros; i++) {
            char move;
            cin >> move;
            movimento[i] = move;
        }
        int itsbeenhit = 0;
        for(int i = 0; i < numeroDeTiros; i++) {
            if (tiross[i] <= 2 && movimento[i] == 'S') {
                itsbeenhit++;
            } else if (tiross[i] > 2 && movimento[i] == 'J') {
                itsbeenhit++;
            }
        }

        printf("%d\n", itsbeenhit);

        



    }


    return 0;
}