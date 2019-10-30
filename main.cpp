#include <iostream>
#include <iomanip>
#include <conio.h>
#include <windows.h>

using namespace std;

int n, m; // n - ������, m - �������
int k, l; // k - ������, l - �������
char** matrixOne;  // n ����� � �������
char** matrixTwo;  // k ����� � �������

void setcolor(WORD color);  // ��������� ����� ������

//  �������� ��� ��������� (����, �����������, ��������, ������)
void enterMatrix();  // ���� ������
void destroyMatrix(char** destroyMatrix, int numberString); // �������� ������ (�������, ������� �������, ���-�� �����)
void checkMatrix(); // �������� �� ������� ������������ ��������
void printMatrix(char** printMatrix, int numberString, int numberColumns);  // ����� ������� �� ����� �������, �������
                                                                            // �������, ���-�� �����, ���-�� ��������)

//  �������� ��� ��������� (��������, ���������, ���������)
void addTrippleMatrix(); // �������� ���� �������� ������ (�����)
void multiplicationTrippleMatrix(char** matrixOne, char** matrixTwo); // ��������� ���� �������� ������ (�����)
                                                                      // (�������, ������� ��������)
void negationTrippleMatrix();  // ��������� ������� �������


int main()
{
    setlocale(LC_CTYPE,"Russian");
    char ch;              // ������ ����� ������������� ������ (*)
    int numberOperation;  // ����� ��������� ������������� ��������

    do {
        //cout << "\nEnter number operation:";
        //        cout << "\n1. Logical addition tripple string.";
        //        cout << "\n2. Logical multiplication tripple string.";
        //        cout << "\n3. Logical addition DNF.";
        //        cout << "\n4. Logical multiplication DNF.";

        cout << "\n������� ����� �������:";
        cout << "\n1 - ���������� �������� ������� ������ (��������).";
        cout << "\n2 - ���������� ��������� ������� ������ (��������).";
        cout << "\n3 - ���������� ��������� ������� ������ (��������).";
        cout << "\n4 - ������ ������� ������� (�������)." << endl;
        cout << "����� ��������: ";
        cin >> numberOperation;
        cout << "-----------------------------------------------------------" << endl;

        if (numberOperation == 1){
            //            cout << "\nLogical addition tripple string:" << endl;
            cout << "\n��������� ����������� �������� �������� ������ (��������):" << endl;
            addTrippleMatrix();
            cout << "-----------------------------------------------------------" << endl;
        }
        else if (numberOperation == 2) {
            cout << "\n��������� ����������� ��������� �������� ������ (��������):" << endl;
            multiplicationTrippleMatrix(matrixOne, matrixTwo);
            cout << "-----------------------------------------------------------" << endl;
        }
        else if (numberOperation == 3) {
            cout << "\n��������� ����������� ��������� ������� ��������� �������:" << endl;
            negationTrippleMatrix();
            cout << "-----------------------------------------------------------" << endl;
        }
        else if (numberOperation == 4) {
            cout << "\n������� �������� ������� (�������):" << endl;
            destroyMatrix(matrixOne, n); // �������� ������ ������
            destroyMatrix(matrixTwo, k); // �������� ������ ������
            enterMatrix();   // ���� ����� ������
            checkMatrix();   // �������� ����� ������
            cout << "-----------------------------------------------------------" << endl;
        }
        else {
            setcolor(12);
            //cout << "ERROR: Wrong operation number. Change the number of operation." << endl;
            cout << "������: ������������ ����� ��������. �������� ����� �����." << endl;
            setcolor(7);
        }

        //cout << "\nCalculate again? (y/n)\n";
        cout << "\n���������� ����������? (y/n)\n";
        cin >> ch;
        cout << "-----------------------------------------------------------" << endl;
    } while ( ch != 'n');

    destroyMatrix(matrixOne, n);
    destroyMatrix(matrixTwo, k);
    setcolor(10);
    //cout << "\nSuccessful completion of the program." << endl;
    cout << "\n�������� ���������� ���������." << endl;
    setcolor(7);
    //cout << "EXIT. Press ENTER key";
    //cout << "�����. ������� ������� ENTER.";
    system("pause");
    return 0;
}

void setcolor(WORD color) // ��������� ����� ������
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color);
    return;
}

void enterMatrix()  // ���� ������
{
    char dummychar;
    dummychar = '*'; // ������ ���������� ����� �������������

    //cout << "Enter first matrix size - n * m:" << endl;
    cout << "������� ����������� ������ ������� (�������) � �������: n * m:" << endl;
    cin >> n >> dummychar >> m;
    //cout << "Enter first matrix:" << endl;
    cout << "������� ������ �������:" << endl;

    matrixOne = new char*[n];  // n ����� � �������
    for (int i = 0; i < n; i++)
        matrixOne[i] = new char[m];  // m �������� � �������

    // ���������� �������
    for (int i = 0; i < n; i++) // ����
        for (int j = 0; j < m; j++){
            cin >> matrixOne[i][j];
        }

    cout << "-----------------------------------------------------------" << endl;


    //cout << "Enter second matrix size - k * l:" << endl;
    cout << "������� ����������� ������ ������� (�������) � �������: k * l:" << endl;
    cin >> k >> dummychar >> l;
    //cout << "Enter second matrix:" << endl;
    cout << "������� ������ �������:" << endl;

    matrixTwo = new char*[k];  // k ����� � �������
    for (int i = 0; i < k; i++)
        matrixTwo[i] = new char[l];

    for (int i = 0; i < k; i++) // ����
        for (int j = 0; j < l; j++){
            cin >> matrixTwo[i][j];
        }
}

void destroyMatrix(char** deleteMatrix, int numberString) // �������� ��������� ������
{
    // �������� ������ �������
    for (int i = 0; i < numberString; i++) {
        delete [] deleteMatrix[i];
    }
    delete [] deleteMatrix;
}

void checkMatrix() // �������� ������������ ��������� ������
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if ((matrixOne[i][j] != '-') && (matrixOne[i][j] != '1') && (matrixOne[i][j] != '0')) {
                setcolor(12);
                cout << "������: ������ ������� �������� ������������ ������ A[" << i << "]" << "[" << j << "]" << ". "
                     << "������� ������� ������." << endl;
                setcolor(7);
                break;
            }
        }
    }

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < l; j++) {
            if ((matrixTwo[i][j] != '-') && (matrixTwo[i][j] != '1') && (matrixTwo[i][j] != '0')) {
                setcolor(12);
                cout << "������: ������ ������� �������� ������������ ������ A[" << i << "]" << "[" << j << "]" << ". "
                     << "������� ������� ������." << endl;
                setcolor(7);
                break;
            }
        }
    }
}

void printMatrix(char** printMatrix, int numberString, int numberColumns)  // ����� ������� �� �����
{
    // ����� ���������� �������� ������� ��������
    for (int i = 0; i < numberString; i++){
        cout << "|";
        for ( int j = 0; j < numberColumns; j++){
            cout << " " << printMatrix[i][j] << " ";
        }
        cout << "|";
        cout << endl;
    }
}

void addTrippleMatrix() // �������� ���� �������� ������
{
    int sumString = n + k;
    // �������� ����� ������� ��� ����������� ��������
    char** addTripStrArr = new char*[sumString];
    for (int i = 0; i < sumString; i++) // ������
        addTripStrArr[i] = new char[m];  // ������� ������� m ����� ��� i ������

    // ���������� ������ ������ ������� ������ �������� ������ ,
    // � ������ ������ ����� �������� ������
    // ���������� ������ ������� � ������ ����� �������
    for (int i = 0; i < n; i++) { // ������
        for (int j = 0; j < m; j++) {  // �������
            addTripStrArr[i][j] = matrixOne[i][j];
        }
    }

    // ������ ������� ���������� ��� ������
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < m; j ++) {
            addTripStrArr[n + i][j] = matrixTwo[i][j];
        }
    }

    printMatrix(addTripStrArr, sumString, m);
    destroyMatrix(addTripStrArr, sumString);
}

void multiplicationTrippleMatrix(char** matrixOne, char** matrixTwo) // ��������� ���� �������� ������
{
    int multString = n * k;
    int countString = 0;
    // �������� ����� ������� ��� ����������� ���������
    char** multTripMatrixArr = new char*[multString];
    for (int i = 0; i < multString; i++) // ������
        multTripMatrixArr[i] = new char[m];  // ������� ������� m ����� ��� i ������

    for (int i = 0; i < n; i++) {
        for (int a = 0; a < k; a++) {
            for (int j = 0; j < m; j++) {  // ����� ������� ������ �������

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

void negationTrippleMatrix()  // ��������� �������� �������
{
    int countDash = 0;  // ������� �������
    int numberString;  // ���������� ����� � ����� ������� (-1 ��� ��� �������� ������� ���������� � 0)
    int stringCount = 0;

    // ������� ���������� ������� � ������
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrixOne[i][j] == '-') {
                countDash++;
            }
        }
    }

    // �������� ���������� ����� � ����������� �� ���������� �������� '-'
    if (countDash == 0) {
        numberString = m;
    } else {
        numberString = m - countDash;
    }

    // �������� ����� ������� ��� ����������� ���������
    char** negationTripMatrixArr = new char*[numberString];
    for (int i = 0; i < numberString; i++) // ������
        negationTripMatrixArr[i] = new char[m];  // ������� ������� m ����� ��� i ������

    for (int j = 0; j < m; j++)  {
        if (matrixOne[0][j] == '1') {
            for (int j= 0; j < m; j++) {
                negationTripMatrixArr[stringCount][j] = '-';
            }
            negationTripMatrixArr[stringCount][j] = '0';
            stringCount++; // ��������� �� ����� ������
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


