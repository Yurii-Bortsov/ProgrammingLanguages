#include <iostream>
using namespace std;

int main()
{
    double m = 0;
    double S = 0;
    double P = 0;
    const double g = 9.80665;
    double F = 0;

    cout << "Введите массу плиты (в кг):" << endl;
    cin >> m;
    cout << "Введите площадь опоры (в м^2)" << endl;
    cin >> S;

    F = g * m;
    P = F / S;
    cout << P;



    return 0;
}

