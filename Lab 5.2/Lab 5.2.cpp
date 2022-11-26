#include <iostream>
#include "Matrix.h"

using std::cout;
using std::cin;

int main()
 {
    int choise;
    int a = 0;
    Matrix m1;
    while (a == 0)
    {
        std::cout << "Что вы хотите выполнить?" "\n" << "1. Ввод нулевой матрицы" "\n" << "2. Ввод матрицы пользователем" "\n" << "3. Сумма матриц" "\n" << "4. Сумма матриц" "\n" << "5. Умножение матриц" "\n" "6. Умножение матриц" "\n" "7. Выход" "\n";
        cin >> choise;
        if (choise == 1) {
            int i, j;
            cout << "Введите число строк и столбцов ";
            cin >> i >> j;
            m1.input(i, j); 
        }
        else if(choise == 2){
            int i, j;
            cout << "Введите число строк и столбцов ";
            cin >> i >> j; 
            double* arr = new double[i*j];
            cout << "Введите матрицу ";
            for (int k = 0; k < i * j; k++) {
                cin >> arr[k];
            }
            m1.input(i, j, arr);
            delete[]arr;
        }
        else if (choise == 3) {
            int i, j;
            cout << "Введите число строк и столбцов ";
            cin >> i >> j;
            double* arr = new double[i * j];
            cout << "Введите матрицу ";
            for (int k = 0; k < i * j; k++) {
                cin >> arr[k];
            }
            Matrix m2(i, j, arr);
            m1.sum_matrix(m2);
            m1.output();
            delete[]arr;
        }
        else if (choise == 4) {
            int i, j;
            i = m1.get_col();
            j = m1.get_row();
            double* arr = new double[i * j];
            cout << "Введите матрицу с таким же количеством столбцов и строк ";
            for (int k = 0; k < i * j; k++) {
                cin >> arr[k];
            }
            Matrix m2(m1.sum_matrix(arr));
            m2.output();
            delete[]arr;
        }
        else if (choise == 5) {
            int i, j;
            cout << "Введите число строк и столбцов ";
            cin >> i >> j;
            double* arr = new double[i * j];
            cout << "Введите матрицу ";
            for (int k = 0; k < i * j; k++) {
                cin >> arr[k];
            }
            Matrix m2(i,j,arr);
            m1.mult_matrix(m2);
            delete[]arr;
        }
        else if (choise == 6) {
            int i, j;
            i = m1.get_col();
            j = m1.get_row();
            double* arr = new double[i * j];
            cout << "Введите матрицу с таким же количеством столбцов и строк ";
            for (int k = 0; k < i * j; k++) {
                cin >> arr[k];
            }
            Matrix m2(m1.mult_matrix(arr));
            m2.output();
            delete[]arr;
        }
        else if (choise == 7) {
            a++;
        }
    }
    return 0;
}