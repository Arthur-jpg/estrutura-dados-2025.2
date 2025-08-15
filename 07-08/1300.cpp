// #include <iostream>
// #include <stdio.h>

// using namespace std;

// int main() {

//     int angulo;

//     cin >> angulo;

//     if (angulo >= 0 && angulo <= 180 && (angulo == 0 || angulo % 6 == 0 || (2 * angulo) % 11 == 0)) {
//         printf("Y\n");
//     } else {
//         printf("N\n");
//     }


//     return 0;
// }

// #include <iostream>

// using namespace std;

// int main(){
//     int A;

//     while(cin >> A){
//         cout << (char) (A % 6 ? 'N' : 'Y') << endl;
//     }

//     return 0;
// }


#include <iostream>
#include <stdio.h>

using namespace std;

int main() {

    int angulo;

    while(cin >> angulo) {
        int resto = angulo % 6;

        if (resto == 0 && angulo >= 0 && angulo <= 180) {
            printf("Y\n");
        } else {
            printf("N\n");
        }
    }




    return 0;
}