#include <iostream>
#include <cstring>

int main()
{
    char cstr1[] = "C-style string1";

    char cstr2[] = { 'C', '-', 's','t','y','l','e',' ','s','t','r','i','n','g','2','\0' };
    char cstr3[] = { '\67', '\45', '\115','t','y','l','e',' ','s','t','r','i','n','g','3','\0' };
    std::cout << cstr1;

    std::cout << "\nlength\t" << strlen(cstr1);
    std::cout << "\nCompare \"astf\",\"assss\" \t" << strcmp("astf", "assss");

    strcpy_s(cstr1, cstr2);
    std::cout << "\nCopy\t" << cstr1;


    std::cout << "\nFind\t" << strlen(cstr1) - strlen(strstr(cstr1, "sty"));


}