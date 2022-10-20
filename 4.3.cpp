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
int **getArray(const unsigned int rows, const unsigned int col);
/**
 * \brief Создает массив чисел, которые вводит пользователь.
 * \param rows Число строк массива.
 * \param col Число столбцов массива.
 * \return Возвращает указатель на массив, заполненный пользовательскими числами.
 */
int **getUserArray(const unsigned int rows, const unsigned int col);
/**
 * \brief Заполняет массив случайными числами от -100 до 100.
 * \param rows Количество строк в массиве.
 * \param col Количество столбцов в массиве.
 * \return Возвращает указатель на массив, заполненный случайными числами.
 */
int **getRandomArray(const unsigned int rows, const unsigned int col);
/**
 * \brief Выводит массив в консоли.
 * \param array Указатель на массив.
 * \param rows Количество строк в массиве.
 * \param col  Количество столбцов в массиве.
 * \return Возвращает 0 в случае успеха.
 */
int printArray(int **array, const unsigned int rows, const unsigned int  col);
/**
 * \brief Выбор варианта заполнения массива.
 * \param USER_INPUT Пользователь заполняет массив.
 * \param RANDOM_INPUT Массив заполняется случайными числами.
 */
enum class userInput
{
    USER_INPUT = 1,
    RANDOM_INPUT
};
/**
 * \brief Передает указатель на массив, в котором самое большое число строки заменяется на ноль.
 * \param array Указатель на массив.
 * \param rows Количество строк в массиве.
 * \param col  Количество столбцов в массиве.
 * \return Возвращает указатель на массив, с замененными числами.
 */
int **getArrayWithReplaceMax(int **array, const unsigned int rows, const unsigned int  col);
/**
 * \brief Копирует массив.
 * \param array Указатель на массив.
 * \param rows Количество строк в массиве.
 * \param col  Количество столбцов в массиве.
 * \return Возвращает указатель на скопированный массив.
 */
int **arrayCopy(int **array, const unsigned int rows, const unsigned int  col);
/**
 * \brief Выводит на экран массив, в котором перед строками, первый элемент которых делится на 3, вставлена строка нулей.
 * \param array Указатель на массив.
 * \param rows Количество строк в массиве.
 * \param col  Количество столбцов в массиве.
 * \return Возвращает 0 в случае успеха.
 */
int printArrayWithNullRows(int **array, const unsigned int rows, const unsigned int  col);

/**
 * \brief Точка входа в программу.
 * \return Возвращает 0 в случае успеха.
 */
int main()
{
    const unsigned int rows = getNumber("Введите количество строк массива: ");
    const unsigned int col = getNumber("Введите количество столбцов массива: ");

    cout << endl;
    cout << "Введите число, соответствующее вашему желанию заполнения массива:\n" << "\n"
    << static_cast<int>(userInput::USER_INPUT) << " - вы заполняете массив вручную.\n"
    << static_cast<int>(userInput::RANDOM_INPUT) << " - заполняет массив случайными числами.\n\n";

    int input = 0;
    cout << "Ваше число выбора варианта заполнения массива: ";
    cin >> input;
    const auto choice = static_cast<userInput>(input);
    cout << "\n";

    int **array;

    switch(choice)
    {
        case userInput::USER_INPUT:
        {
            array = getRandomArray(rows, col);
            
            break;
        }
        
        case userInput::RANDOM_INPUT:
        {
            array = getRandomArray(rows, col);

            break;
        }
    }

    // Вывод начального массива
    cout << "Начальный массив:" << endl << endl;
            
    printArray(array, rows, col);
            
    cout << endl;

    // Вывод массива, в котором каждый максимальный элемент строки заменен нулем.
    cout << "Массив, в котором каждый максимальный элемент строки заменен нулем: " << endl << endl;
            
    int **array_with_replace_max = getArrayWithReplaceMax(array, rows, col);
    printArray(array_with_replace_max, rows, col);
            
    cout << endl;

    // Вывод массива, в котором перед строками, первый элемент которых делится на 3, вставлена строка нулей.
    cout << "Массив, в котором перед строками, первый элемент которых делится на 3, вставлена строка нулей: " << endl << endl;

    printArrayWithNullRows(array, rows, col);


    return 0;
}

int getNumber(const string& message)
{
    cout << message;
    int variable = 0;
    cin >> variable;
    return variable;
}

int **getArray(const unsigned int rows, const unsigned int col)
{
    int **array = new int *[rows];
    
    for (int i = 0; i < rows; i++)
    {
        array[i] = new int[col];
    }
    return array;
}

int printArray(int **array, const unsigned int rows, const unsigned int  col)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout.width(3);
            cout << array[i][j] << "\t";
        }
        cout << "\n" << "\n";
    }
    return 0;
}

int **getUserArray(const unsigned int rows, const unsigned int col)
{
    int **array = getArray(rows, col);
    
    for (unsigned int i = 0; i < rows; i++)
    {
        for (unsigned int j = 0; j < col; j++)
        {
            cin >> array[i][j];
        }
        cout << "\n";
    }
    return array;
}

int **getRandomArray(const unsigned int rows, const unsigned int col)
{
    const int minValue = -100;
    const int maxValue = 100;
    
    int** array = getArray(rows, col);
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> uniformIntDistribution(minValue, maxValue);
    for (unsigned int i = 0; i < rows; i++)
    {
        for (unsigned int j = 0; j < col; j++)
        {
            array[i][j] = uniformIntDistribution(gen);
        }
    }
    return array;
}

int **getArrayWithReplaceMax(int **array, const unsigned int rows, const unsigned int  col)
{
    int **arrayReplaced = arrayCopy(array, rows, col);

    int indexMaxInRow[rows];

    int max = -999;
    for (unsigned int i = 0; i < rows; i++)
    {
        max = -999;
        for (unsigned int j = 0; j < col; j++)
        {
            if (arrayReplaced[i][j] > max)
            {
                max = arrayReplaced[i][j];
            }
        }
        indexMaxInRow[i] = max;
    }

    for (unsigned int i = 0; i < rows; i++)
    {
        for (unsigned int j = 0; j < col; j++)
        {
            if (arrayReplaced[i][j] == indexMaxInRow[i])
            {
                arrayReplaced[i][j] = 0;
            }
        }
    }

    return arrayReplaced;
}

int **arrayCopy(int **array, const unsigned int rows, const unsigned int  col)
{
    int **arrayCopied = getArray(rows, col);

    for (unsigned int i = 0; i < rows; i++)
    {
        for (unsigned int j = 0; j < col; j++)
        {
            arrayCopied[i][j] = array[i][j];
        }
    }
    return arrayCopied;
}

int arrayDestroyer(int **array, unsigned int rows) 

{
    for (int i = 0; i < rows; i++) 
    {
        delete[] array[i];
    }
    delete[] array;
    return 0;
}

int printArrayWithNullRows(int **array, const unsigned int rows, const unsigned int  col)
{
    unsigned int newrows = 0;

    for (unsigned int i = 0; i < rows; i++)
    {
        if ((array[i][0] % 3) == 0)
        {
            newrows = newrows + 1;
        }
    }

    int arraydiv3[newrows];

    unsigned int temp2 = 0;
    for (unsigned int i = 0; i < rows; i++)
    {
        if ((array[i][0] % 3) == 0)
        {
            arraydiv3[temp2] = array[i][0];
            temp2 = temp2 + 1;
        }
    }

    int **newArray = getArray(rows+newrows,col);
    unsigned int temp3 = 0;
    cout << endl;
   
    for (unsigned int i = 0; i < rows; i++)
    {
        for (unsigned int j = 0; j < col; j++)
        {
            if ((arraydiv3[temp3] == array[i][j]) and (j == 0))
            {
                temp3 = temp3 + 1;
                for (unsigned int g = 0; g < col; g++)
                {
                    newArray[i+temp3][g] = array[i][g];
                }
            }
            else
            {
                newArray[i+temp3][j] = array[i][j];
            }
        }   
    }
    
    printArray(newArray, rows+newrows, col);
    arrayDestroyer(newArray, newrows + rows);
    
    for (int i = 0; i < newrows; i++) 
    {
        delete[] array[i];
    }
    
    return 0;
}