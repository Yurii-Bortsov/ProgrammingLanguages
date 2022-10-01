#define _USE_MATH_DEFINES // for C++
#include <cmath>
#include <iostream>
using namespace std;


int main()
{
    int x1 = 0;
    int y1 = 0;
    int x2 = 0;
    int y2 = 0;
    int sx = 0;
    int sy = 0;
    int s_final = 0;


    cout << "Введите координату оси абсцисс первой точки:" << endl;
    cin >> x1;
    cout << "Введите координату оси ординат первой точки:" << endl;
    cin >> y1;
    cout << "Введите координату оси абсцисс второй точки:" << endl;
    cin >> x2;
    cout << "Введите координату оси ординат второй точки:" << endl;
    cin >> y2;


        if (x1 > x2)
        {
        sx = x1 - x2;
        }
        
        else if (x2 > x1)
        {
        sx = x2 - x1;
        }
        
        else
        {
        sx = 0;
        }


        if (y1 > y2)
        {
        sy = y1 - y2;
        }
        
        else if (y2 > y1)
        {
        sy = y2 - y1;
        }
        
        else
        {
        sy = 0;
        }
    
    s_final = sqrt((sx * sx) + (sy * sy));


    cout << "Расстояние между координатами = " << s_final << endl;


    return 0;
}