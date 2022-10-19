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
 * \return Массив, заполненный числами пользователя.
 */
int **getUserArray(const unsigned int rows, const unsigned int col);

/**
 * \brief Заполняет массив случайными числами от -100 до 100.
 * \param rows Количество строк в массиве.
 * \param col Количество столбцов в массиве.
 * \return Возвращает указатель на заполненный массив.
 */
int **getRandomArray(const unsigned int rows, const unsigned int col);

/**
 * \brief Выводит массив в консоли.
 * \param array Указатель на массив.
 * \param rows Количество строк в массиве.
 * \param col  Количество столбцов в массиве.
 */
int printArray(int **array, const unsigned int rows, const unsigned int  col);

enum class userInput
{
    USER_INPUT = 1,
    RANDOM_INPUT
};

int **getArrayWithReplaceMax(int **array, const unsigned int rows, const unsigned int  col);
int **arrayCopy(int **array, const unsigned int rows, const unsigned int  col);
void **printArrayWithNullRows(int **array, const unsigned int rows, const unsigned int  col);

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

    switch(choice)
    {
        case userInput::USER_INPUT:
        {
            int **array = getUserArray(rows, col);

            cout << "=================================================" << "\n" << endl;

            cout << "Начальный массив:\n" << endl;;
            printArray(array, rows, col);

            break;
        }
        
        case userInput::RANDOM_INPUT:
        {
            int **array = getRandomArray(rows, col);

            cout << "=================================================" << "\n" << endl;

            cout << "Начальный массив:\n" << endl;
            printArray(array, rows, col);

            cout << "=================================================" << "\n" << endl;

            cout << "Массив, в котором каждый максимальный элемент строки заменен нулем: \n" << endl;    

            int **array_with_replace_max = getArrayWithReplaceMax(array, rows, col);
            printArray(array_with_replace_max, rows, col);

            printArrayWithNullRows(array, rows, col);

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

void **printArrayWithNullRows(int **array, const unsigned int rows, const unsigned int  col)
{
    int **arrayWithNullRows = arrayCopy(array, rows, col);

    unsigned int newrows = 0;


    for (unsigned int i = 0; i < rows; i++)
    {
        if ((arrayWithNullRows[i][0] % 3) == 0)
        {
            newrows = newrows + 1;
            cout << arrayWithNullRows[i][0] << endl;

        }
    }

    cout << "колво строк % 3 = " << newrows << endl;
    
    int indexRowsDiv3[newrows];
    unsigned int temp = 0;

    for (unsigned int i = 0; i < rows; i++)
    {
        if ((arrayWithNullRows[i][0] % 3) == 0)
        {
            indexRowsDiv3[temp] = arrayWithNullRows[i][0];
            temp = temp + 1;
        }
    }

    int **NewArray = getArray(rows+newrows, col);
    unsigned int temp2 = 0;

    for (unsigned int i = 0; i < rows+newrows; i++)
    {
        if (indexRowsDiv3[temp2] == i+1)
        {
            for (unsigned int j = 0; j < col; i++)
            {
                NewArray[i][j] = 0;
            }

            temp2 = temp2 + 1;
            
        }
        else if (indexRowsDiv3[temp2] != i+1)
        {
            for (unsigned int j = 0; j < col; i++)
            {
                NewArray[i][j] = arrayWithNullRows[i][j];
            }
        }
    }
    printArray(NewArray, rows+newrows, col);
}