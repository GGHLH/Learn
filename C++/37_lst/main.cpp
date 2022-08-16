#include <iostream>

struct A 
{

};

//操作数求值顺序的不确定性
void fun(int p1, int p2)
{
    std::cout << p1 << " " << p2 << "\n";
}

int main()
{
    //表达式
    int x;
    x = 3; //return 3

    //操作数是左值还是右值 --> 结果也有左值和右值域值
    int u;
    u = 3;// u:左值, 3:右值

    //结合性
    int z;
    2+(3+5);//定义完加法,俩个A对象有什么样的行为

    //操作数求值顺序的不确定性
    int v = 0;
    fun(v = v + 1, v = v + 1);//这是一个不安全的结果,负结果! 函数调用也是表达式 里面2个表达式.
    /*
    clang
     v = v + 1 fun种的第一个
     p1 = 第一个v+1
     v = v + 1 第二个
     p2 = 第二个v+1
    Result -->  1,  2

    g++
     v = v + 1 fun种的第一个
     v = v + 1 第二个
     p1 = 第一个v+1
     p2 = 第二个v+1
    Result --> 2, 2
     */
}