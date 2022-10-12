/**
 * РЕШЕНИЕ НЕПРАВИЛЬНОЕ, У ТЕБЯ ТОЧКИ МОГУТ ЛЕЖАТЬ НА ПРЯМОЙ И НЕ ПРОХОДИТЬ ЧЕРЕЗ (0, 0)
*/

#include <iostream>
#include <cmath>
using namespace std;

/**
 * \brief Считывает значение координаты из консоли.
 * \param message Побуждающее сообщение для пользователя.
 * \return Значение координаты.
 */
double getCoordinate(const string& message);

/**
 * \brief Определяет, лежат ли точки A, B и C на одной прямой.
 * \param xA координата оси X точки A.
 * \param yA координата оси Y точки A.
 * \param xB координата оси X точки B.
 * \param yA координата оси Y точки B.
 * \param xC координата оси X точки C.
 * \param yA координата оси Y точки C.
 * \return true, если точки лежат на одной прямой и false, если не лежат на одной прямой.
 */
bool ifOneLine(const double xA,const double yA,const double xB, 
            const double yB, const double xC, const double yC);

/**
 * \brief Вычисляет угол между точкой и осью 
 * \param message Побуждающее сообщение для пользователя.
 * \return Значение координаты.
 */
double getAngle(xB, yB);

/**
 * \brief Точка входа в программу.
 * \return Возвращает 0 в случае успеха.
 */
int main()
{
    const double xA = getCoordinate("Введите координату оси X точки А: ");
    const double yA = getCoordinate("Введите координату оси Y точки А: ");
    const double xB = getCoordinate("Введите координату оси X точки B: ");
    const double yB = getCoordinate("Введите координату оси Y точки B: ");
    const double xC = getCoordinate("Введите координату оси X точки C: ");
    const double yC = getCoordinate("Введите координату оси Y точки C: ");

    if (ifOneLine(xA, yA, xB, yB, xC, yC) == true)
    {
        cout << "Точки A, B и C лежат на одной прямой";
    }
    else
    {
        double B = getAngle(xB, yB);

        cout << "Точки A, B и C не лежат на одной прямой." << endl;
        cout << "Угол B = " << B;
    }

    return 0;
}

double getCoordinate(const string& message)
{
    cout << message;
    double variable = 0.0;
    cin >> variable;
    return variable;
}


bool ifOneLine(const double xA,const double yA,const double xB, 
            const double yB, const double xC, const double yC)
{
    double t = 0.0;
    t = xB/yB;

    if (((xA/yA) == t)&&((xC/yC) == t))
    {
        return true;
    }

    else
    {
        return false;
    }
        
}

