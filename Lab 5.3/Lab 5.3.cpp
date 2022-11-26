#include <iostream>
#include "D3Matrix.h"

using std::cout;
using std::cin;

int main()
{
    int choise;
    int a = 0;
    while (a == 0)
    {
        std::cout << "What do you want to do?" "\n" << "1. Trase" "\n" << "2. Input and output of the matrix " "\n" << "3. Sum of matricies" "\n" << "4. Multiplying matrix by a constant" "\n" << "5. Difference of the matricies" "\n" "6. Sign swap" "\n" "7. Exit" "\n";
        cin >> choise;
        if (choise == 1) {
            D3Matrix m1;
            cin >> m1;
            cout << m1.trase() << '\n';
        }
        else if (choise == 2) {
            D3Matrix m1;
            cin >> m1;
            cout << m1 << '\n';
        }
        else if (choise == 3) {
            D3Matrix m1, m2;
            cin >> m1;
            cin >> m2;
            m1 + m2;
            cout << '\n';
        }
        else if (choise == 4) {
            D3Matrix m1;
            int k;
            cin >> m1 >> k;
            m1* k;
            cout << m1;
        }
        else if (choise == 5) {
            D3Matrix m1, m2;
            cin >> m1;
            cin >> m2;
            m1 - m2;
            cout << '\n';
        }
        else if (choise == 6) {
            D3Matrix m1;
            cin >> m1;
            -m1;
            cout << '\n';
        }
        else a++;
    }
}
