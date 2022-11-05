#include <iostream>
#include <cstring>
#include <string> 
#include <fstream> 
#include <bitset>

using std::string;
using std::cout;
using std::cin;

string file_format(const string file_path_full) {   
    int num;
    string abc;
    num = file_path_full.find_first_of('.');
    abc = file_path_full.substr(num, file_path_full.size() - num);
    return abc;
}

string file_name(const string file_path_full) { 
    int num, num1;
    string abc;
    num = file_path_full.find_last_of('.');
    num1 = file_path_full.find_last_of("\\");
    int a = file_path_full.size() - num1 - 1 - (file_path_full.size() - num);
    abc = file_path_full.substr(num1 + 1, a);
    return abc;
}

string file_path(const string file_path_full) { 
    int num;
    string abc;
    num = file_path_full.find_last_of("\\");
    abc = file_path_full.substr(0, num);
    return abc;
}

char file_disk(const string file_path_full) {   
    return file_path_full.at(0);
}

string file_rename(string file_path_full) { 
    string new_name;
    cin >> new_name;
    file_path_full = file_path_full.substr(0, file_path_full.find_last_of("\\") + 1) + new_name + ".cpp";
    return file_path_full;
}

bool file_copy(const string file_path_full) {
    int num;
    std::fstream fs;
    std::fstream out;
    string temp;
    num = file_path_full.find_first_of('.');
    fs.open(file_path_full, std::fstream::in);
    out.open(file_path_full.substr(0, num) + "_copy" + file_path_full.substr(num, file_path_full.size() - num), std::fstream::out);
    while (!fs.eof()) {
        fs >> temp;
        out << temp << '\n';
    }
    return 1;
}

int main()
{
    string file_path_name;
    int a = 0;
    int choise;
    while (a == 0) {
        std::cout << "What do you want to do?" "\n" << "1. Enter" "\n" << "2. Task 1" "\n" << "3. Task 2" "\n" << "4. Task 3" "\n" << "5. Task 4" "\n" "6. Task 5" "\n" "7. Task 6"  "\n" "8. Exit" "\n";
        cin >> choise;
        switch (choise)
        {
        case 1:
            cout << "Enter file path without spaces: "; cin >> file_path_name;
            break;
        case 2:
            cout << file_format(file_path_name) << '\n';
            break;
        case 3:
            cout << file_name(file_path_name) << "\n";
            break;
        case 4:
            cout << file_path(file_path_name) << "\n";
            break;
        case 5:
            cout << file_disk(file_path_name) << "\n";
            break;
        case 6:
            cout << file_rename(file_path_name) << "\n";
            break;
        case 7:
            file_copy(file_path_name);
            break;
        case 8:
            cout << "Goodbye!";
            a++;
        default:
            break;
        }


    }
}