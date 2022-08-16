#include <iostream>

struct Str
{
    int x;
};

struct Str1
{
    int x1;
};

void fun(int x6, int x7)
{

};

namespace ABC
{
    int x8;
};

int x7;

int main()
{
    // 成员访问操作符：.与->
    // .
    Str a;
    a.x;//通过.来访问结构体中的x. a左值-->a.x返回左值

    // -->
    Str* ptr = &a;
    /*
    (*ptr).x; = ptr-> x先解引用，然后再访问x中的代码,这样那个书写不便，所以改为ptr-> x;
    */
    ptr-> x;
 

    //的左操作数是左值(或右值)，返回左值(或右值xvalue)
    Str1 a1;
    // decltype((a1.x)) y = a.x;//a.x作为表达式返回的是个左值 Result --> int& y
    // decltype((Str1().x)) y = std::move(a1.x);//.的操作数是右值的化，将返回一个将亡值
    

    // ->的左操作数指针，返回左值
    decltype((ptr->x)) y = a.x;


    //唯一的三元操作符
    //接受一个可转换为bool的表达式与2个类型相同的表达式，只有一个表达式会被求值
    std::cout << "三目运算符: " << (true ? 3 : 5) << std::endl; //ture --> 对3求值，返回3； false --> 对5求值，返回5

    int x2 = 1;
    int y2 = 2;


    int x3 = 1;
    int y3 = 2;
    false ? (++x3) : (++y3);//因为是false， 则值会对++y3求职
    std::cout << "x3: " << x3 << std::endl;
    std::cout << "y3: " << y3 << std::endl;


    //如果表达式均是左值则返回左值，否则为右值
    int x4 = 2;
    false ? 1 : x4; // 1是一个纯右值， x4是一个左值 return right_value

    int x5 = 2;
    int y5 = 3;
    false ? x5 : y5;//2个表达式均是左值，返回的是左值

    //右结合
    int score = 100;
    int res = (score > 0) ? 1 : (score == 0) ? 0 : -1; //想让人看起来费尽，不简洁。不建议这样写
    std::cout << "res: " << res << std::endl;

    // int res = ((score > 0) ? 1 : (score == 0)) ? 0 : -1;//改变运算优先级
    // std::cout << "res_add_(): " << res << std::endl;

    //逗号操作符
    std::cout << (2, 3, 4, 5);

    //函数调用
    fun(2, 3);

    //sizeof操作符
    int* ptr1 = nullptr;
    std::cout << "sizeof_type: " << sizeof(*ptr1) << std::endl;
    std::cout << "sizeof_expression: " << sizeof *ptr1 << std::endl;


    //域解析操作符
    int x7;
    int y7 = ::x7;//再去全局和局部读定义了x7，::x7代表使用全局的定义
    int x8 = ABC::x8;
}
