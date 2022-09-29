/** 
* НЕ ДЛЯ ПРОВЕРКИ, ТУТ КООРДИНАТНАЯ ПРЯМАЯ
*/ 

#include <iostream>
using namespace std;

int main()
{
    int x1 = 0;
    int x2 = 0;
    int s = 0;


    cout << "Введите первую координату:" << endl;
    cin >> x1;
    cout << "Введите вторую координату:" << endl;
    cin >> x2;


    if (x1 > x2)
    {

        s = x1 - x2;
    }
    else if (x2 > x1)
    {

        s = x2 - x1;
    }
    else
    {
        s = 0;
    }

    cout << "Расстояние между координатами = " << s << endl;

    return 0;
}
