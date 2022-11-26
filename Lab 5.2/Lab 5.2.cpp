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
        std::cout << "What do you want to do?" "\n" << "1. Enter the null matrix" "\n" << "2. Output of the matrix by the user" "\n" << "3. Sum of matricies" "\n" << "4. Sum of matricies" "\n" << "5. Productt of matricies" "\n" "6. Productt of matricies" "\n" "7. Exit" "\n";
        cin >> choise;
        if (choise == 1) {
            int i, j;
            cout << "Enter the number of rows and columns ";
            cin >> i >> j;
            m1.input(i, j); 
        }
        else if(choise == 2){
            int i, j;
            cout << "Enter the number of rows and columns ";
            cin >> i >> j; 
            double* arr = new double[i*j];
            cout << "Enter the matrix ";
            for (int k = 0; k < i * j; k++) {
                cin >> arr[k];
            }
            m1.input(i, j, arr);
            delete[]arr;
        }
        else if (choise == 3) {
            int i, j;
            cout << "Enter the number of rows and columns ";
            cin >> i >> j;
            double* arr = new double[i * j];
            cout << "Enter the matrix ";
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
            cout << "Enter the matrix with same number of columns and rows ";
            for (int k = 0; k < i * j; k++) {
                cin >> arr[k];
            }
            Matrix m2(m1.sum_matrix(arr));
            m2.output();
            delete[]arr;
        }
        else if (choise == 5) {
            int i, j;
            cout << "Enter the number of rows and columns ";
            cin >> i >> j;
            double* arr = new double[i * j];
            cout << "Enter the matrix ";
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
            cout << "Enter the matrix with same number of columns and rows ";
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