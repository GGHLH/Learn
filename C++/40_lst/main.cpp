#include <iostream>

int main()
{
    int x = 3;
    int y = 5;
    +x;//一个操作符+ 一个操作数x.即一个一元表达
    
    //通常来说,操作数与结果均为算术类型的右值;但+, -法与一元 + 可接受指针
    int a[3] = {1, 2, 3};
    int* ptr = a;
    ptr = ptr + 1; 
    ptr = ptr - 1;

    std::cout << std::cend(a) - std::cbegin(a) << std::endl;
    //const auto& x = +a; ---> int *const & x = +a; 
    //const auto& x = a; ---> int *const(&x)[3]= a; 

    //一元 + 操作符会产生integral promotion
    short x1 = 3;
    auto y1 = +x; //+x是一个exprssion x是一个数组,当有了+号+x时,会变为类型的提升integral promotion Result-->
    auto y2 = -x; // -会改变值

    //整数相除会产生整数,向0取整数
    int x4 = 4;
    int x5 = 3;
    std::cout << (x4/x5) <<std::endl;

    //求余只能接受整数类型操作数,结果符号与第一个操作数相同

    std::cout << "% :" << (3 % 4) << std::endl;
    std::cout << "/ :" << (4 / 3) << std::endl;
    
    //满足(m/n) + m%n == m
    std::cout << "m: "<< (4/3)*3 + (4 % 3) <<std::endl;
    std::cout << "m: "<< (4/3)*3  <<std::endl;
}  