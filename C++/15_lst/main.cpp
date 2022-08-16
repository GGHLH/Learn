#include <iostream>

int main()
{
    int x = 42;
    int y = 0;
    while (x != y) //引入循环结构
    {
        std::cout << "please input number: \n";
        std::cin >> y;
    }
}