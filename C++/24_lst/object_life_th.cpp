#include <iostream>
#include <type_traits>
#include <typeinfo>

int x = 4;//生命周期为整个程序的运行到结束

int main()
{
    int x = 3;//局部域x隐藏了外部域的x/生命周期9-14行
    {
        int x = 5;//域嵌套在域内 <--block scope. 隐藏了局部域中x定义
        std::cout << x << "\n";
    }
    std::cout << x << "\n";
}
