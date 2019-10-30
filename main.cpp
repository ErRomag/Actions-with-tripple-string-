#include <iostream>
#include <iomanip>
#include <conio.h>
#include <windows.h>

using namespace std;

int n, m; // n - строки, m - столбцы
int k, l; // k - строки, l - столбцы
char** matrixOne;  // n строк в массиве
char** matrixTwo;  // k строк в массиве

void setcolor(WORD color);  // Изменение цвета текста

//  Действия над матрицами (ВВОД, УНИЧТОЖЕНИЕ, ПРОВЕРКА, ПЕЧАТЬ)
void enterMatrix();  // Ввод матриц
void destroyMatrix(char** destroyMatrix, int numberString); // Удаление матриц (матрица, которую удаляем, кол-во строк)
void checkMatrix(); // Проверка на наличие неправильных символов
void printMatrix(char** printMatrix, int numberString, int numberColumns);  // Вывод матрицы на экран матрица, которую
                                                                            // удаляем, кол-во строк, кол-во столбцов)

//  Операции над матрицами (СЛОЖЕНИЕ, УМНОЖЕНИЕ, ОТРИЦАНИЕ)
void addTrippleMatrix(); // Сложение двух троичных матриц (строк)
void multiplicationTrippleMatrix(char** matrixOne, char** matrixTwo); // Умножение двух троичных матриц (строк)
                                                                      // (матрицы, которые умножаем)
void negationTrippleMatrix();  // Отрицание трочной матрицы


int main()
{
    setlocale(LC_CTYPE,"Russian");
    char ch;              // Символ между размерностями матриц (*)
    int numberOperation;  // Номер выбранной пользователем операции

    do {
        //cout << "\nEnter number operation:";
        //        cout << "\n1. Logical addition tripple string.";
        //        cout << "\n2. Logical multiplication tripple string.";
        //        cout << "\n3. Logical addition DNF.";
        //        cout << "\n4. Logical multiplication DNF.";

        cout << "\nВведите номер оперции:";
        cout << "\n1 - Логическое СЛОЖЕНИЕ трочных матриц (векторов).";
        cout << "\n2 - Логическое УМНОЖЕНИЕ трочных матриц (векторов).";
        cout << "\n3 - Логическое ОТРИЦАНИЕ трочных матриц (векторов).";
        cout << "\n4 - ВВЕСТИ трочные матрицы (вектора)." << endl;
        cout << "Номер операции: ";
        cin >> numberOperation;
        cout << "-----------------------------------------------------------" << endl;

        if (numberOperation == 1){
            //            cout << "\nLogical addition tripple string:" << endl;
            cout << "\nРезультат логического сложения троичных матриц (векторов):" << endl;
            addTrippleMatrix();
            cout << "-----------------------------------------------------------" << endl;
        }
        else if (numberOperation == 2) {
            cout << "\nРезультат логического умножения троичных матриц (векторов):" << endl;
            multiplicationTrippleMatrix(matrixOne, matrixTwo);
            cout << "-----------------------------------------------------------" << endl;
        }
        else if (numberOperation == 3) {
            cout << "\nРезультат логического отрицания ПЕРВОГО троичного вектора:" << endl;
            negationTrippleMatrix();
            cout << "-----------------------------------------------------------" << endl;
        }
        else if (numberOperation == 4) {
            cout << "\nВведите троичные матрицы (вектора):" << endl;
            destroyMatrix(matrixOne, n); // Удаление старых матриц
            destroyMatrix(matrixTwo, k); // Удаление старых матриц
            enterMatrix();   // Ввод новых матриц
            checkMatrix();   // Проверка новых матриц
            cout << "-----------------------------------------------------------" << endl;
        }
        else {
            setcolor(12);
            //cout << "ERROR: Wrong operation number. Change the number of operation." << endl;
            cout << "ОШИБКА: Неправильный номер операции. Выберете новый номер." << endl;
            setcolor(7);
        }

        //cout << "\nCalculate again? (y/n)\n";
        cout << "\nПродолжить вычисления? (y/n)\n";
        cin >> ch;
        cout << "-----------------------------------------------------------" << endl;
    } while ( ch != 'n');

    destroyMatrix(matrixOne, n);
    destroyMatrix(matrixTwo, k);
    setcolor(10);
    //cout << "\nSuccessful completion of the program." << endl;
    cout << "\nУспешное завершение программы." << endl;
    setcolor(7);
    //cout << "EXIT. Press ENTER key";
    //cout << "Выход. Нажмите клавишу ENTER.";
    system("pause");
    return 0;
}

void setcolor(WORD color) // Изменение цвета текста
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color);
    return;
}

void enterMatrix()  // Ввод матриц
{
    char dummychar;
    dummychar = '*'; // Символ разделения между размерностями

    //cout << "Enter first matrix size - n * m:" << endl;
    cout << "Введите размерность первой матрицы (вектора) в формате: n * m:" << endl;
    cin >> n >> dummychar >> m;
    //cout << "Enter first matrix:" << endl;
    cout << "Введите первую матрицу:" << endl;

    matrixOne = new char*[n];  // n строк в массиве
    for (int i = 0; i < n; i++)
        matrixOne[i] = new char[m];  // m столбцов в массиве

    // заполнение массива
    for (int i = 0; i < n; i++) // ввод
        for (int j = 0; j < m; j++){
            cin >> matrixOne[i][j];
        }

    cout << "-----------------------------------------------------------" << endl;


    //cout << "Enter second matrix size - k * l:" << endl;
    cout << "Введите размерность второй матрицы (вектора) в формате: k * l:" << endl;
    cin >> k >> dummychar >> l;
    //cout << "Enter second matrix:" << endl;
    cout << "Введите вторую матрицу:" << endl;

    matrixTwo = new char*[k];  // k строк в массиве
    for (int i = 0; i < k; i++)
        matrixTwo[i] = new char[l];

    for (int i = 0; i < k; i++) // ввод
        for (int j = 0; j < l; j++){
            cin >> matrixTwo[i][j];
        }
}

void destroyMatrix(char** deleteMatrix, int numberString) // Удаление введенных матриц
{
    // удаление первой матрицы
    for (int i = 0; i < numberString; i++) {
        delete [] deleteMatrix[i];
    }
    delete [] deleteMatrix;
}

void checkMatrix() // Проверка правильности введенных матриц
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if ((matrixOne[i][j] != '-') && (matrixOne[i][j] != '1') && (matrixOne[i][j] != '0')) {
                setcolor(12);
                cout << "ОШИБКА: ПЕРВАЯ матрица содержит неправильный символ A[" << i << "]" << "[" << j << "]" << ". "
                     << "Введите матрицу заново." << endl;
                setcolor(7);
                break;
            }
        }
    }

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < l; j++) {
            if ((matrixTwo[i][j] != '-') && (matrixTwo[i][j] != '1') && (matrixTwo[i][j] != '0')) {
                setcolor(12);
                cout << "ОШИБКА: ВТОРАЯ матрица содержит неправильный символ A[" << i << "]" << "[" << j << "]" << ". "
                     << "Введите матрицу заново." << endl;
                setcolor(7);
                break;
            }
        }
    }
}

void printMatrix(char** printMatrix, int numberString, int numberColumns)  // Вывод матрицы на экран
{
    // Вывод полученной троичной матрицы сложения
    for (int i = 0; i < numberString; i++){
        cout << "|";
        for ( int j = 0; j < numberColumns; j++){
            cout << " " << printMatrix[i][j] << " ";
        }
        cout << "|";
        cout << endl;
    }
}

void addTrippleMatrix() // Сложение двух трочнхых матриц
{
    int sumString = n + k;
    // Создание новой матрицы для результатов сложения
    char** addTripStrArr = new char*[sumString];
    for (int i = 0; i < sumString; i++) // строки
        addTripStrArr[i] = new char[m];  // столбцы создаем m ячеек для i строки

    // Добавление первой строке матрицы первой троичной строки ,
    // а второй строке втрой троичной строке
    // записываем первую матрицу в первую часть массива
    for (int i = 0; i < n; i++) { // строки
        for (int j = 0; j < m; j++) {  // столбцы
            addTripStrArr[i][j] = matrixOne[i][j];
        }
    }

    // вторую матрицу записываем под первой
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < m; j ++) {
            addTripStrArr[n + i][j] = matrixTwo[i][j];
        }
    }

    printMatrix(addTripStrArr, sumString, m);
    destroyMatrix(addTripStrArr, sumString);
}

void multiplicationTrippleMatrix(char** matrixOne, char** matrixTwo) // Умножение двух троичных матриц
{
    int multString = n * k;
    int countString = 0;
    // Создание новой матрицы для результатов умножения
    char** multTripMatrixArr = new char*[multString];
    for (int i = 0; i < multString; i++) // строки
        multTripMatrixArr[i] = new char[m];  // столбцы создаем m ячеек для i строки

    for (int i = 0; i < n; i++) {
        for (int a = 0; a < k; a++) {
            for (int j = 0; j < m; j++) {  // взяли элемент первой матрицы

                if (matrixOne[i][j] == '-' && matrixTwo[a][j] == '-'){
                    multTripMatrixArr[countString][j] = '-';
                }
                else if ( (matrixOne[i][j] == '1' && matrixTwo[a][j] == '1') |
                          (matrixOne[i][j] == '1' && matrixTwo[a][j] == '-') |
                          (matrixOne[i][j] == '-' && matrixTwo[a][j] == '1')) {

                    multTripMatrixArr[countString][j] = '1';
                }
                else if ( (matrixOne[i][j] == '0' && matrixTwo[a][j] == '0') |
                          (matrixOne[i][j] == '0' && matrixTwo[a][j] == '-') |
                          (matrixOne[i][j] == '-' && matrixTwo[a][j] == '0') ) {

                    multTripMatrixArr[countString][j] = '0';
                }
                else if ( (matrixOne[i][j] == '1' && matrixTwo[a][j] == '0') |
                          (matrixOne[i][j] == '0' && matrixTwo[a][j] == '1') ) {
                    for (int j = 0; j < m; j++) {
                        multTripMatrixArr[countString][j] = '*';
                    }
                    break;
                }
            }
            countString++;
        }
    }


    printMatrix(multTripMatrixArr, multString, m);
    destroyMatrix(multTripMatrixArr, multString);
}

void negationTrippleMatrix()  // Отрицание троичной матрицы
{
    int countDash = 0;  // Счетчик дефисов
    int numberString;  // Количество строк в новой матрице (-1 так как элементы массива начинаются с 0)
    int stringCount = 0;

    // Считаем количество дефисов в строке
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrixOne[i][j] == '-') {
                countDash++;
            }
        }
    }

    // Выбираем количество строк в зависимости от количества символов '-'
    if (countDash == 0) {
        numberString = m;
    } else {
        numberString = m - countDash;
    }

    // Создание новой матрицы для результатов отрицания
    char** negationTripMatrixArr = new char*[numberString];
    for (int i = 0; i < numberString; i++) // строки
        negationTripMatrixArr[i] = new char[m];  // столбцы создаем m ячеек для i строки

    for (int j = 0; j < m; j++)  {
        if (matrixOne[0][j] == '1') {
            for (int j= 0; j < m; j++) {
                negationTripMatrixArr[stringCount][j] = '-';
            }
            negationTripMatrixArr[stringCount][j] = '0';
            stringCount++; // Переходим на новую строку
        }
        else if (matrixOne[0][j] == '0') {
            for (int j = 0; j < m; j++) {
                negationTripMatrixArr[stringCount][j] = '-';
            }
            negationTripMatrixArr[stringCount][j] = '1';
            stringCount++;
        }
        else if (matrixOne[0][j] == '-') {
        }
    }

    printMatrix(negationTripMatrixArr, stringCount, m);
    destroyMatrix(negationTripMatrixArr, stringCount);
}

void newNegationTrippleMatrix(char** matrixOne, char** matrixTwo) {
    char** matrix123;

    //return matrix123;
}


