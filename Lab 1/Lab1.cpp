#include <iostream> 
#include <bitset> 

int main()
{
    std::cout << "1.\n" << "Shchebelev Andrey Dmitrievich, 221-351\n";
    std::cout << "2.\n";
    std::cout << "min_int = " << std::numeric_limits<int>::min() << ", max_int = "
        << std::numeric_limits<int>::max() << ", Size of int = " << sizeof(int) << "\n";
    std::cout << "min unsigned int = " << std::numeric_limits<unsigned>::min() << ", max unsigned int = "
        << std::numeric_limits<unsigned>::max()
        << ", size of unsigned int = " << sizeof(unsigned) << "\n";
    std::cout << "min short = " << std::numeric_limits<short>::min() << ", max short = "
        << std::numeric_limits<short>::max()
        << ", size of short = " << sizeof(short) << "\n";
    std::cout << "min unsigned short = " << std::numeric_limits<unsigned short>::min() << ", max unsigned short = "
        << std::numeric_limits<unsigned short>::max()
        << ", size of unsigned short = " << sizeof(unsigned short) << "\n";
    std::cout << "min long = " << std::numeric_limits<long>::min() << ", max long = "
        << std::numeric_limits<long>::max() << ", size of long = " << sizeof(long) << "\n";
    std::cout << "min long long = " << std::numeric_limits<long long>::min() << ", max long long = "
        << std::numeric_limits<long long>::max() << ", size of long long = "
        << sizeof(long long) << "\n";
    std::cout << "min double = " << std::numeric_limits<double>::min() << ", max double = "
        << std::numeric_limits<double>::max() << ", size of double = "
        << sizeof(double) << "\n";
    std::cout << "min char = " << std::numeric_limits<char>::min() << ", max char = "
        << std::numeric_limits<char>::max() << ", size of char = "
        << sizeof(char) << "\n";
    std::cout << "min bool = " << std::numeric_limits<bool>::min() << ", max bool = "
        << std::numeric_limits<bool>::max() << ", size of bool = "
        << sizeof(bool) << "\n";
    std::cout << "3.\n";
    std::cout << "Enter your number: ";
    int ch;
    std::cin >> ch;
    std::cout << "Binary number ";
    std::cout << std::bitset<32>(ch) << "\n";
    std::cout << "hex number " << std::hex << ch << "\n" << std::dec;
    std::cout << "bool " << bool(ch) << "\n";
    std::cout << "double " << double(ch) << "\n";
    std::cout << "char " << char(ch) << "\n";
    std::cout << "4.\n";
    double x;
    int a, b;
    std::cout << "Enter a*x = b coefficients: " << "\n";
    std::cin >> a;
    std::cin >> b;
    std::cout << a << " * x = " << b << "\n";
    std::cout << "x = " << b << "/" << a << "\n";
    x = (double) b / a;
    std::cout << "x = " << x << "\n";
    std::cout << "5.\n";
    int x1, x2;
    double mp;
    std::cout << "Enter the ends of the segment: " << "\n";
    std::cin >> x1;
    std::cin >> x2;
    mp = (x1 + x2) / 2.;
    std::cout << "The center of the segment with left end " << x1 << " and right end " << x2 << " is: " << mp << std::endl;
 }
