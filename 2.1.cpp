#include <iostream>
using namespace std;


/**
 * \brief Считывает переменную из консоли.
 * \param message Побуждающее сообщение для пользователя.
 * \return Значение переменной.
 */

double getVariable(const string& message);


void MySwap(double *a, double *b);

enum class userInput
{
    WITH_C,
    WITHOUT_C
};

/**
 * \brief Точка входа в программу.
 * \return Возвращает 0 в случае успеха.
 */
 
int main()
{
    double a = getVariable("Введите значение перменной a: ");
    double b = getVariable("Введите значение перменной b: ");
    cout << "\n";


    cout << "Введите число, соответствующее заданию:\n"
    << static_cast<int>(userInput::WITH_C) << " - меняет значение a и b между собой с помощью третьей переменной.\n"
    << static_cast<int>(userInput::WITHOUT_C) << " - меняет значение a и b между собой без помощи третьей переменной.\n\n";

    int input = 0;
    cin >> input;
    const auto choice = static_cast<userInput>(input);
    cout << "\n";

    switch(choice)
    {
        case userInput::WITH_C:
        {
            MySwap(&a, &b);
            cout << "a = " << a << "\n" << "b = " << b << endl;
            break;
        }

        case userInput::WITHOUT_C:
        {
            swap(a, b);
            cout << "a = " << a << "\n" << "b = " << b << endl;
            break;
        }
        
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

void MySwap(double *a, double *b)
{
    double temp = *a;
    *a = *b;
    *b = temp;
}
