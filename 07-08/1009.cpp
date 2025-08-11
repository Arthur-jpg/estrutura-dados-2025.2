#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
    string name;
    double fixed_salary, sales;

    cin >> name >> fixed_salary >> sales;

    double total = fixed_salary + (0.15*sales);

    printf("TOTAL = R$ %.2f\n", total);

    return 0;
}