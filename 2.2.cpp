#include <iostream>
#include <cmath>
using namespace std;

/**
 * \brief Рассчитывает значение функции при x > a.
 * \param x Значение пермененной x.
 * \return Значение функции при x > a.
 */
const double getAnswer1(const double x);

/**
 * \brief Рассчитывает значение функции при x <= a.
 * \param x Значение пермененной x.
 * \return Значение функции при x <= a.
 */
const double getAnswer2(const double x);

/**
 * \brief Считывает переменную из консоли.
 * \param message Побуждающее сообщение для пользователя.
 * \return Значение переменной.
 */
double getVariable(const string& message);


/**
 * \brief Точка входа в программу.
 * \return Возвращает 0 в случае успеха.
 */
 
int main()
{   
    const double a = 2.5;
    const double x = getVariable("Введите значение перменной x: ");
    cout << "\n";   

    if (x > a)
    {
        const double y = getAnswer1(x);
        cout << y;
    }
    else
    {
        const double y = getAnswer2(x);
        cout << y;
    }
    
    return 0;
}

double getVariable(const string& message)
{
    cout << message;
    double variable = 0.0;
    cin >> variable;
    return variable;
}

const double getAnswer1(const double x)
{
    const double t = (x * (sin(x)*sin(x)));
    return t;
}

const double getAnswer2(const double x)
{
    const double t = (x * (cos(x)*cos(x)));
    return t;
}