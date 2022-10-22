#include <iostream>
using namespace std;
#include <ctime>
#include <random>

/**
 * \brief Считывает значение числа из консоли.
 * \param message Побуждающее сообщение для пользователя.
 * \return Число.
 */
size_t get_size(const string& message);

/**
 * \brief Создаёт двумерный массив.
 * \param rows Количество строк в массиве.
 * \param columns Количество столбцов массива.
 * \return Возвращает указатель на массив.
 */
int** getArray(const size_t rows, const size_t columns);

/**
 * \brief Создает массив чисел, которые вводит пользователь.
 * \param rows Число строк массива.
 * \param columns Число столбцов массива.
 * \return Возвращает указатель на массив, заполненный пользовательскими числами.
 */
int** getUserArray(const size_t rows, const size_t columns);

/**
 * \brief Заполняет массив случайными числами от -100 до 100.
 * \param rows Количество строк в массиве.
 * \param columns Количество столбцов в массиве.
 * \return Возвращает указатель на массив, заполненный случайными числами.
 */
int** getRandomArray(const size_t rows, const size_t columns);

/**
 * \brief Выводит массив в консоли.
 * \param array Указатель на массив.
 * \param rows Количество строк в массиве.
 * \param columns  Количество столбцов в массиве.
 */
void printArray(int** array, const size_t rows, const size_t  columns);

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
 * \param columns  Количество столбцов в массиве.
 * \return Возвращает указатель на массив, с замененными числами.
 */
int** getArrayWithReplaceMax(int** array, const size_t rows, const size_t  columns);

/**
 * \brief Копирует массив.
 * \param array Указатель на массив.
 * \param rows Количество строк в массиве.
 * \param columns  Количество столбцов в массиве.
 * \return Возвращает указатель на скопированный массив.
 */
int** arrayCopy(int** array, const size_t rows, const size_t  columns);

/**
 * \brief Выводит на экран массив, в котором перед строками, первый элемент которых делится на 3, вставлена строка нулей.
 * \param array Указатель на массив.
 * \param rows Количество строк в массиве.
 * \param columns  Количество столбцов в массиве.
 * \return Возвращает 0 в случае успеха.
 */
void printArrayWithNullRows(int** array, const size_t rows, const size_t  columns);

/**
 * \brief Точка входа в программу.
 * \return Возвращает 0 в случае успеха.
 */
int main()
{
    size_t rows = 0;
    size_t columns = 0;
    try
    {
        rows = get_size("Введите количество строк массива: ");
        columns = get_size("Введите количество столбцов массива: ");
    }
    catch (std::out_of_range& e)
    {
         std::cerr << e.what();
         return 1;
    }

    cout << "\n";
    cout << "Введите число, соответствующее вашему желанию заполнения массива:\n" << "\n"
    << static_cast<int>(userInput::USER_INPUT) << " - вы заполняете массив вручную.\n"
    << static_cast<int>(userInput::RANDOM_INPUT) << " - заполняет массив случайными числами.\n\n";

    int input = 0;
    cout << "Ваше число выбора варианта заполнения массива: ";
    cin >> input;
    const auto choice = static_cast<userInput>(input);
    cout << "\n";

    int** array = nullptr;

    switch(choice)
    {
        case userInput::USER_INPUT:
        {
            array = getUserArray(rows, columns);
            
            break;
        }
        
        case userInput::RANDOM_INPUT:
        {
            array = getRandomArray(rows, columns);

            break;
        }
        
        default:
        {
            cerr << "Введено неверное значение\n";
        }
    }

    // Вывод начального массива
    cout << "Начальный массив:" << "\n" << "\n";
            
    printArray(array, rows, columns);
            
    cout << "\n";

    // Вывод массива, в котором каждый максимальный элемент строки заменен нулем.
    cout << "Массив, в котором каждый максимальный элемент строки заменен нулем: " << "\n" << "\n";
            
    int** array_with_replace_max = getArrayWithReplaceMax(array, rows, columns);
    printArray(array_with_replace_max, rows, columns);
            
    cout << "\n";

    // Вывод массива, в котором перед строками, первый элемент которых делится на 3, вставлена строка нулей.
    cout << "Массив, в котором перед строками, первый элемент которых делится на 3, вставлена строка нулей: " << "\n" << "\n";

    printArrayWithNullRows(array, rows, columns);

    return 0;
}

size_t get_size(const string& message)
{
    int size = -1;
    cout << message;
    cin >> size;

    if (size < 0)
    {
        throw out_of_range("Incorrect size. Value has to be greater or equal zero.");
    }

    return static_cast<size_t>(size);
}

int** getArray(const size_t rows, const size_t columns)
{
    int** array = new int *[rows];
    
    for (int i = 0; i < rows; i++)
    {
        array[i] = new int[columns];
    }
    return array;
}

void printArray(int** array, const size_t rows, const size_t  columns)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            cout.width(3);
            cout << array[i][j] << "\t";
        }
        cout << "\n" << "\n";
    }
}

int** getUserArray(const size_t rows, const size_t columns)
{
    int** array = getArray(rows, columns);
    
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < columns; j++)
        {
            cin >> array[i][j];
        }
        cout << "\n";
    }
    return array;
}

int** getRandomArray(const size_t rows, const size_t columns)
{
    const int minValue = -100;
    const int maxValue = 100;
    
    int** array = getArray(rows, columns);
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> uniformIntDistribution(minValue, maxValue);
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < columns; j++)
        {
            array[i][j] = uniformIntDistribution(gen);
        }
    }
    return array;
}

int** getArrayWithReplaceMax(int** array, const size_t rows, const size_t  columns)
{
    int** arrayReplaced = arrayCopy(array, rows, columns);

    int indexMaxInRow[rows];

    int max = arrayReplaced[0][0];
    for (size_t i = 0; i < rows; i++)
    {
        max = arrayReplaced[i][0];
        for (size_t j = 0; j < columns; j++)
        {
            if (arrayReplaced[i][j] > max)
            {
                max = arrayReplaced[i][j];
            }
        }
        indexMaxInRow[i] = max;
    }

    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < columns; j++)
        {
            if (arrayReplaced[i][j] == indexMaxInRow[i])
            {
                arrayReplaced[i][j] = 0;
            }
        }
    }

    return arrayReplaced;
}

int** arrayCopy(int** array, const size_t rows, const size_t  columns)
{
    int** arrayCopied = getArray(rows, columns);

    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < columns; j++)
        {
            arrayCopied[i][j] = array[i][j];
        }
    }
    return arrayCopied;
}

void arrayDestroyer(int**& array, const size_t rows)

{
    for (int i = 0; i < rows; i++) 
    {
        delete[] array[i];
    }
    if (array != nullptr)
    {
        delete[] array;
        array = nullptr;
    }
}

void printArrayWithNullRows(int** array, const size_t rows, const size_t  columns)
{
    size_t newrows = 0;

    for (size_t i = 0; i < rows; i++)
    {
        if ((array[i][0] % 3) == 0)
        {
            newrows++;
        }
    }

    int arraydiv3[newrows];

    size_t temp2 = 0;
    for (size_t i = 0; i < rows; i++)
    {
        if ((array[i][0] % 3) == 0)
        {
            arraydiv3[temp2] = array[i][0];
            temp2++;
        }
    }

    int** newArray = getArray(rows+newrows,columns);
    size_t temp3 = 0;
    cout << "\n";
   
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < columns; j++)
        {
            if ((arraydiv3[temp3] == array[i][j]) and (j == 0))
            {
                temp3 = temp3 + 1;
                for (size_t g = 0; g < columns; g++)
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
    
    printArray(newArray, rows+newrows, columns);
    arrayDestroyer(newArray, newrows + rows);
    
    for (int i = 0; i < newrows; i++) 
    {
        delete[] array[i];
    }
}