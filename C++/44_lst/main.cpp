#include <iostream>

int main()
{
    int x = 3;
    //x += 1; = ++x; = x + 1；
    int y;

    //分前缀与后缀俩种情况；
    y = x++;//后缀  return right； 返回一个临时变量，纯右值3
    /*y = 3, 是因为我们使用了后缀运算符，为右值，将返回x的原始值3
                                        后缀返回x运算之后前的值*/
    std::cout << "x:" << x << "\n";
    std::cout << "y:" << y << "\n";

    int x1 = 3;
    int y1;
    y1 = ++x1;//前缀 renturn left；
    std::cout << "x1:" << x1 << "\n";// 前缀返回x变化之后的值
    std::cout << "y1:" << y1 << "\n";

    //建议使用前缀形式；
    int x2 = 3;
    x++;//返回原始右值，需要构造一个临时变量的成本，c拷贝的成本
    ++x;//返回改变后左值 。前缀则不需要
}