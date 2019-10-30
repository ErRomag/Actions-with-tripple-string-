#include <iostream>
#include <iomanip>
#include <conio.h>
#include <windows.h>

#include <vector>

using namespace std;

int n, m; // n - ������, m - �������
int k, l; // k - ������, l - �������
char** matrixOne;  // n ����� � �������
char** matrixTwo;  // k ����� � �������
char** multTripMatrixArr;
// ����������������

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


void newNegationTrippleMatrix();

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
            //newNegationTrippleMatrix();
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


// ------------------------ ������������ � ���������� ������� ----------------------------------
void negationDoubleMatrix() // ��������� ������� �� ���� �����
{

    int stringCount = 0;

    // �������� ����� ������� ��� ����������� ���������
    char** negationTripMatrixArrOne = new char*[n];
    for (int i = 0; i < n; i++) // ������
        negationTripMatrixArrOne[i] = new char[m];  // ������� ������� m ����� ��� i ������

    // �������� ����� ������� ��� ����������� ���������
    char** negationTripMatrixArrTwo = new char*[n];
    for (int i = 0; i < n; i++) // ������
        negationTripMatrixArrTwo[i] = new char[m];  // ������� ������� m ����� ��� i ������

    // �������� ����� ������� ��� ����������� ���������
    char** negationTripMatrixArrResult = new char*[n];
    for (int i = 0; i < n; i++) // ������
        negationTripMatrixArrResult[i] = new char[m];  // ������� ������� m ����� ��� i ������

    for (int j = 0; j < m; j++)  {
        if (matrixOne[0][j] == '1') {
            for (int j= 0; j < m; j++) {
                negationTripMatrixArrOne[stringCount][j] = '-';
            }
            negationTripMatrixArrOne[stringCount][j] = '0';
            stringCount++; // ��������� �� ����� ������
        }
        else if (matrixOne[0][j] == '0') {
            for (int j = 0; j < m; j++) {
                negationTripMatrixArrOne[stringCount][j] = '-';
            }
            negationTripMatrixArrOne[stringCount][j] = '1';
            stringCount++;
        }
        else if (matrixOne[0][j] == '-') {
        }
    }

    for (int j = 0; j < m; j++)  {
        if (matrixOne[1][j] == '1') {
            for (int j= 0; j < m; j++) {
                negationTripMatrixArrTwo[stringCount][j] = '-';
            }
            negationTripMatrixArrTwo[stringCount][j] = '0';
            stringCount++; // ��������� �� ����� ������
        }
        else if (matrixOne[1][j] == '0') {
            for (int j = 0; j < m; j++) {
                negationTripMatrixArrTwo[stringCount][j] = '-';
            }
            negationTripMatrixArrTwo[stringCount][j] = '1';
            stringCount++;
        }
        else if (matrixOne[1][j] == '-') {
        }
    }

    multiplicationTrippleMatrix(negationTripMatrixArrOne, negationTripMatrixArrTwo);
    printMatrix(multTripMatrixArr, n, m);

//    printMatrix(negationTripMatrixArr, stringCount, m);
//    destroyMatrix(negationTripMatrixArr, stringCount);
}

char** newMultiplicationTrippleMatrix(char** matrixOne, char** matrixTwo) // ��������� ���� �������� ������
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

    return multTripMatrixArr;


    printMatrix(multTripMatrixArr, multString, m);
    destroyMatrix(multTripMatrixArr, multString);
}

void newNegationTrippleMatrix() {

  //  int countDash = 0;  // ������� �������
    //int numberString = n;  // ���������� ����� � ����� ������� (-1 ��� ��� �������� ������� ���������� � 0)
    int stringCount = 0;

    // ������� ���������� ������� � ������
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < m; j++) {
//            if (matrixOne[i][j] == '-') {
//                countDash++;
//            }
//        }
//    }

    // �������� ���������� ����� � ����������� �� ���������� �������� '-'
//    if (countDash == 0) {
//        numberString = m;
//    } else {
//        numberString = m - countDash;
//    }

    size_t  numberString = m;
    size_t  numberColumns = n;

   std::vector<std::vector<char>> negationTripVector(m);  // ������� ������ ����������� n ��� ������
   // vector< vector<char**> > negationTripVector(n, vector<char**>(m));

    //char** negationTripVector[n];

//    for (int i = 0; i < n; i++) {
//        // �������� ����� ������� ��� ����������� ���������
//        char** negationTripMatrixArr = new char*[n];
//        for (int i = 0; i < n; i++) {// ������
//            negationTripMatrixArr[i] = new char[m];  // ������� ������� m ����� ��� i ������
//            }

//        negationTripVector[i] = negationTripMatrixArr;
//    }



   for (size_t a = 0; a < numberString; a++) {
       for ( size_t i = 0; i < numberString;i++) {
           negationTripVector[i].resize(numberColumns);
           for (size_t j = 0; j < numberColumns; j++) {
               if (matrixOne[a][j] == '1') {
                   for (int j= 0; j < m; j++) {
                       negationTripVector[i][j]='-';
                   }
                   negationTripVector[i][j] = '0';
                   a++; // ��������� �� ����� ������
               }
               else if (matrixOne[a][j] == '0') {
                   for (int j = 0; j < m; j++) {
                       negationTripVector[i][j] = '-';
                   }
                   negationTripVector[i][j] = '1';
                   a++;
               }
               else if (matrixOne[a][j] == '-') {
               }
           }
       }
   }



   // ����� ���������� �������� ������� ��������
   for (int i = 0; i < numberString; i++){
       cout << "|";
       for ( int j = 0; j < numberColumns; j++){
           cout << " " << negationTripVector[i][j] << " ";
       }
       cout << "|";
       cout << endl;
   }

   int mult = 0;
   int arr[4] = {1 , 2, 3, 4};

   for (int i = 0; i < 3; i++){
       mult *=arr[i];
   }






    // -----------------------------------

//    const size_t row = 5;
//        const size_t col = 3;
//        std::vector<std::vector<int> > imatrix(row);
//        // ����������
//        for(size_t i = 0; i < row; ++i)
//        {
//            imatrix[i].resize(col);
//            for(size_t j = 0; j < col; ++j)
//                imatrix[i][j] = rand() % 666;
//        }
//        // ������
//        std::for_each(imatrix.begin(), imatrix.end(), [](std::vector<int>& ivec)
//        {
//            std::for_each(ivec.begin(), ivec.end(), [](int i)
//            {
//                std::cout << std::left << std::setw(5) << i;
//            });
//            std::cout << std::endl;
//        });
//        system("pause");
//        return 0;
    // ----------------------------------



//    for (int vectorCount = 0; vectorCount < n; vectorCount++) { // ���� �� ������ �������


//    printMatrix(negationTripMatrixArr, stringCount, m);
//    destroyMatrix(negationTripMatrixArr, stringCount);
}


