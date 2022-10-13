#include <iostream>
using namespace std;

/**
 * \brief Считывает значение числа из консоли.
 * \param message Побуждающее сообщение для пользователя.
 * \return Число.
 */
int getNumber(const string& message);

enum class userInput
{
    USER_INPUT,
    RANDOM_INPUT
};

/**
 * \brief Точка входа в программу.
 * \return Возвращает 0 в случае успеха.
 */
int main()
{
    const int ROWS = getNumber("Введите количество строк массива: ");
    const int COLS = getNumber("Введите количество столбцов массива: ");

    cout << "Введите число, соответствующее заданию:\n"
    << static_cast<int>(userInput::USER) << " - меняет значение a и b между собой с помощью третьей переменной.\n"
    << static_cast<int>(userInput::WITHOUT_C) << " - меняет значение a и b между собой без помощи третьей переменной.\n\n";


    int arr[ROWS][COLS];

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            arr[i][j] = rand() % 10;
        }
    }

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            cout << arr[i][j] << "\t";
        }
        cout << "\n";
    }


    return 0;
}

int getNumber(const string& message)
{
    cout << message;
    int variable = 0;
    cin >> variable;
    return variable;
}