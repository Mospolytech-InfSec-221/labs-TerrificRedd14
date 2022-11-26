#include <iostream>
#include "Matrix.h"

using std::cin;
using std::cout;

Matrix input() {
    int i, j;
    cout << "Enter the number of rows and columns: ";
    cin >> i >> j;
    cout << "Enter the matrix: ";
    Matrix matr(i, j);
    return matr;
}
int main()
{
    int choise;
    int a = 0;
    int k, i, j;
    Matrix matr1;
    Matrix matr2;
    Matrix matr3;
    while (a == 0) {
        std::cout << "What do you want to do?" "\n" << "1. Input" "\n" << "2. Output" "\n" << "3. Sum of two matrices" "\n" << "4. Product of two matricies" "\n" << "5. Matrix trace" "\n" << "6. Multiplying matrix by a constant" "\n" << "7.  Number of columns" "\n" << "8. Number of rows" "\n" << "9. Print the (i,j) element " "\n" << "10. Exit" "\n";
        cin >> choise;
        switch (choise)
        {
        case 1:
            //matr1(2);
            cout << "Enter the nuber of rows and columns ";
            cin >> i >> j;
            cout << "Enter the matrix: ";
            matr1.make(i, j);
            //matr1 = input();
            break;
        case 2:
            matr1.output();
            break;
        case 3:
            cout << "Enter the nuber of rows and columns ";
            cin >> i >> j;
            cout << '\n' << "Enter the matrix: ";
            matr2.make(i, j);
            matr1.sum_matrix(matr2);
            matr1.output();
            break;
        case 4:
            cout << "Enter the nuber of rows and columns ";
            cin >> i >> j;
            cout << "Enter the matrix: ";
            matr2.make(i, j);
            matr1.mult_matrix(matr2);
            break;
        case 5:
            matr1.trace();
            break;
        case 6:
            cout << "Enter the multipler: ";
            cin >> k;
            matr1.mult_number(k);
            break;
        case 7:
            cout << matr1.get_col() << '\n';
            break;
        case 8:
            cout << matr1.get_row() << '\n';
            break;
        case 9:
            cout << "Enter i and j ";
            cin >> i >> j;
            cout << matr1.get_elem(i, j) << '\n';
            break;
        case 10:
            cout << "Goodbye";
            a++;
        default:
            break;
        }
    }
}


