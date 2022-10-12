#include <iostream>
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

const double getDistance(const double x1, const double x2, const double y1, const double y2);

/**
 * \brief Считывает координату из консоли.
 * \param message Побуждающее сообщение для пользователя.
 * \return Координату точки.
 */

double getCoordinate(const string& message);


/**
 * \brief Точка входа в программу.
 * \return Возвращает 0 в случае успеха.
 */
 
int main()
{
    const double x1 = getCoordinate("Введите координату оси абсцисс первой точки:");
    const double y1 = getCoordinate("Введите координату оси ординат первой точки:");
    const double x2 = getCoordinate("Введите координату оси абсцисс второй точки:");
    const double y2 = getCoordinate("Введите координату оси ординат второй точки:");


    const double distance = getDistance(x1, x2, y1, y2);

    cout << "Расстояние между координатами = " << distance << endl;


    return 0;
}


const double getDistance(const double x1, const double x2, const double y1, const double y2)
{
    const double sx = x1 - x2;
    const double sy = y1 - y2;

    return sqrt((sx * sx) + (sy * sy));
}

double getCoordinate(const string& message)
{
    cout << message;
    double coordinate = 0.0;
    cin >> coordinate;
    return coordinate;
}