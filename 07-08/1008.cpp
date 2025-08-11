#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
    int number, hours;
    float perhour;
    cin >> number >> hours >> perhour;
    float salary = hours * perhour;
    printf("NUMBER = %d\n", number);
    printf("SALARY = U$ %.2f\n", salary);

    return 0;
}