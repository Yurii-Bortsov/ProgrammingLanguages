#include <iostream>
using namespace std;
#include <ctime>
#include <random>


/**
 * \brief Считывает значение числа из консоли.
 * \param message Побуждающее сообщение для пользователя.
 * \return Число.
 */
int getNumber(const string& message);

/**
 * \brief Создаёт двумерный массив.
 * \param rows Количество строк в массиве.
 * \param col Количество столбцов массива.
 * \return Возвращает указатель на массив.
 */
int** getArray(const size_t rows, const size_t col);

/**
 * \brief Создает массив чисел, которые вводит пользователь.
 * \param rows Число строк массива.
 * \param col Число столбцов массива.
 * \return Массив, заполненный числами пользователя.
 */
int** getUserArray(const size_t rows, const size_t col);

/**
 * \brief Заполняет массив случайными числами от -100 до 100.
 * \param rows Количество строк в массиве.
 * \param col Количество столбцов в массиве.
 * \return Возвращает указатель на заполненный массив.
 */
int** getRandomArray(const size_t rows, const size_t col);

/**
 * \brief Выводит массив в консоли.
 * \param array Указатель на массив.
 * \param rows Количество строк в массиве.
 * \param col  Количество столбцов в массиве.
 */
int printArray(int** array, const size_t rows, const size_t  col);

enum class userInput
{
    USER_INPUT = 1,
    RANDOM_INPUT
};

/**
 * \brief Точка входа в программу.
 * \return Возвращает 0 в случае успеха.
 */
int main()
{
    const int rows = getNumber("Введите количество строк массива: ");
    const int col = getNumber("Введите количество столбцов массива: ");

    cout << endl;
    cout << "Введите число, соответствующее вашему желанию заполнения массива:\n" << "\n"
    << static_cast<int>(userInput::USER_INPUT) << " - вы заполняете массив вручную.\n"
    << static_cast<int>(userInput::RANDOM_INPUT) << " - заполняет массив случайными числами.\n\n";

    int input = 0;
    cout << "Ваше число выбора варианта заполнения массива: ";
    cin >> input;
    const auto choice = static_cast<userInput>(input);
    cout << "\n";

    switch(choice)
    {
        case userInput::USER_INPUT:
        {
            int** array = getUserArray(rows, col);

            cout << "=================================================" << "\n" << endl;

            cout << "Начальный массив:\n" << endl;;
            printArray(array, rows, col);

            break;
        }
        
        case userInput::RANDOM_INPUT:
        {
            int** array = getRandomArray(rows, col);

            cout << "=================================================" << "\n" << endl;

            cout << "Начальный массив:\n" << endl;
            printArray(array, rows, col);

            break;
        }
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

int** getArray(const size_t rows, const size_t col)
{
    int** array = new int* [rows];
    
    for (size_t i = 0; i < rows; i++)
    {
        array[i] = new int[col];
    }
    return array;
}

int printArray(int** array, const size_t rows, const size_t  col)
{
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < col; j++)
        {
            cout << array[i][j] << "\t";
        }
        cout << "\n" << "\n";
    }
    return 0;
}

int** getUserArray(const size_t rows, const size_t col)
{
    int** array = getArray(rows, col);
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < col; j++)
        {
            int x;
            cin >> x;
            array[i][j] = x;
        }
        cout << "\n";
    }
    return array;
}

int** getRandomArray(const size_t rows, const size_t col)
{
    const int minValue = -100;
    const int maxValue = 100;
    
    int** array = getArray(rows, col);
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> uniformIntDistribution(minValue, maxValue);
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < col; j++)
        {
            array[i][j] = uniformIntDistribution(gen);
        }
    }
    return array;
}

