#include <iostream>
using namespace std;


/**
 * \brief Считывает переменную из консоли.
 * \param message Побуждающее сообщение для пользователя.
 * \return Значение переменной.
 */

double getVariable(const string& message);

/**
 * \brief Меняет значение перменных между собой с помощью тертьей переменной.
 * \param a Значение пермененной a.
 * \param b Значение переменной b.
 * \return Значение перменных a и b после замены их значений.
 */

double getWith_c(double a, double b);

/**
 * \brief Меняет значение перменных между собой без помощи тертьей переменной.
 * \param a Значение пермененной a.
 * \param b Значение переменной b.
 * \return Значение перменных a и b после замены их значений.
 */

double getWithout_c(double a, double b);


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
            double c = 0.0;
            c = a;
            a = b;
            b = c;
            cout << "a = " << a << "\n" << "b = " << b << endl;
            break;
        }

        case userInput::WITHOUT_C:
        {
            double variable_after [2] = {a, b};
            b = variable_after[0];
            a = variable_after[1];
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