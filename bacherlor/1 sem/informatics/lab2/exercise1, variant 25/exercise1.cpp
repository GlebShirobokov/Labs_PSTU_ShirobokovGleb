#include <iostream>
#include<cmath>

using namespace std;

int main() {
    setlocale(LC_ALL, ".65001");
    double sum{0};
    const double e = 2.71828182845904523536;
    for(int i = 1; i <= 7; ++i){
        double an = (i*i)*pow(e, -sqrt(i));
        sum += an;
    }
    cout << "Сумма 7 членов ряда равна " << sum;
    return 0;
}