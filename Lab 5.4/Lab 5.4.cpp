#include <iostream>
#include "Circle.h";
#include "Position.h";
#include "Square.h";
#include "CircleInSquare.h"

using std::cout;
using std::cin;

int main()
{
    setlocale(LC_ALL, "Russian");
    int choise;
    double x, y, side, rad;
    int a = 0;
    while (a == 0)
    {
        std::cout << "What do you want to do?" "\n" << "1. Position input" "\n" << "2. User's circle input" "\n" << "3. Circle's radius input" "\n" << "4. User's square input" "\n" << "5. Square's side input" "\n" "6. Input circle in square by the radius" "\n" "7. Input circle in square by the square's side" "\n" "8. Exit" "\n";
        cin >> choise;
        if (choise == 1) {
            cout << "Enter x and y: "; cin >> x >> y;
            Position a(x, y);
            a.out();
        }
        if (choise == 2) {
            cout << "Enter centre and radius: "; cin >> x >> y >> rad;
            Circle a(x, y, rad);
            a.out();
        }
        if (choise == 3) {
            cout << "Enter radius: "; cin >> rad;
            Circle a(rad);
            a.out();
        }
        if (choise == 4) {
            cout << "Enter centre and side: "; cin >> x >> y >> side;
            Square a(x, y, side);
            a.out();
        }
        if (choise == 5) {
            cout << "Enter side: "; cin >> side;
            Square a(side);
            a.out();
        }
        if (choise == 6) {
            cout << "Enter centre and radius: "; cin >> x >> y >> rad;
            CircleInSquare a(x, y, rad);
            a.Circle::out();
            a.Square::out();
        }
        if (choise == 7) {
            cout << "Enter side: "; cin >> side;
            CircleInSquare a(side);
            a.Circle::out();
            a.Square::out();
        }
        if (choise == 8) {
            a++;
        }
    }
    return 0;
}