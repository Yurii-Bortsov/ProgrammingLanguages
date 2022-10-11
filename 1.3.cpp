#include <iostream>
using namespace std;

/**
 * \brief Рассчитывает давление, производимое плитой массой m и площадью S.
 * \param m масса плиты.
 * \param S площадь плиты.
 * \return Возвращает давление, производимое плитой массой m и площадью S.
 */

const double getPressure(const double m, const double S);

/**
 * \brief Точка входа в программу.
 * \return Возвращает 0 в случае успеха.
 */

int main()
{   
    cout << "Введите массу плиты (в кг):" << endl;
    double m = 0.0;
    cin >> m;
    
    cout << "Введите площадь опоры (в м^2):" << endl;
    double S = 0;
    cin >> S;

    const double pressure = getPressure(m, S);
    
    cout << "Давление, производимое бетонной плитой = " << pressure << endl;
    
    return 0;
}

 const double getPressure(const double m, const double S)
 {
    const double g = 9.80665;
    
    return((g * m) / S);
 }