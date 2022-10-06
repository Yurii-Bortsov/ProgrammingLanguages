#include <iostream>
#define _USE_MATH_DEFINES // for C++
#include <cmath>
using namespace std;

/**
 * \brief Рассчитывает дистанцию между двумя точками с заданными координатами.
 * \param x1 координата по оси Х первой точки.
 * \param y1 координата по оси Y первой точки.
 * \param x2 координата по оси X первой точки.
 * \param y2 координата по оси Y первой точки.
 * \return Расстояние между двумя точками.
 */

const double getDistance(double x1, double x2, double y1, double y2);


/**
 * \brief Точка входа в программу.
 * \return Возвращает 0 в случае успеха.
 */
 
int main()
{

    cout << "Введите координату оси абсцисс первой точки:" << endl;
    double x1 = 0;
    cin >> x1;

    cout << "Введите координату оси ординат первой точки:" << endl;
    double y1 = 0;
    cin >> y1;

    cout << "Введите координату оси абсцисс второй точки:" << endl;
    double x2 = 0;
    cin >> x2;

    cout << "Введите координату оси ординат второй точки:" << endl;
    double y2 = 0;
    cin >> y2;


    const double distance = getDistance(x1, x2, y1, y2);

    cout << "Расстояние между координатами = " << distance << endl;


    return 0;
}


const double getDistance(double x1, double x2, double y1, double y2)
{
    double sx = x1 - x2;
    double sy = y1 - y2;

    return sqrt((sx * sx) + (sy * sy));
}