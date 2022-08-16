// #include <iostream>
// #include <type_traits>
// #include <typeinfo>

// namespace MyNS
// {
//     int x = 3;
//     void fun()
//     {
        
//     }             //定义了在namesapce中的函数的域
//     using MyInt = int;//域内定义
// }

// // int x = 3;    //global scope

// using MyInt = float;//全局定义
// void fun()      //全局的域
// {
//     int x = 3; //block scope
// }

// int main()
// {
//     int x = 3;
// }
#include <iostream>
#include <type_traits>
#include <typeinfo>

int x = 4;

int main()
{
    int x = 3;//局部域x隐藏了外部域的x
    {
        int x = 5;//域嵌套在域内 <--block scope. 隐藏了局部域中x定义
        std::cout << x << "\n";
    }
    std::cout << x << "\n";
}
