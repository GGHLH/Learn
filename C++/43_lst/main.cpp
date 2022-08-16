#include <iostream>


int main()
{
    int x = 3;//记住，这是初始化操作，不是赋值操作
    //左操作数为可修改左值；右操作数为右值，可以转换为左操作数的类型；
    //x = 5; 不看；x=5为赋值操作


    //赋值操作符是右结合的； 这里很重要
    int x1;
    int y1;
    x1 = y1 = 3;//赋值操作符是右结合的,所以从右往左算
    
    int x2;
    (x2 = 5) = 2;//先x=5赋予指向的内存，返回x。拿到x再=2,再把2赋给内存 ，return x
    ((x2 =5) = 2) =1;
    std::cout << "x2: " << x2 << std::endl;


    //可以引入大括号(初始化列表)以防止收缩转换（narrowing conversion）
    
    short x3;         //short -->占2个字节
    x3 = 0x80000000; //int -->4个字节  这里发生narrowing conversion
    /*这里类型转化丢掉前面2个字节0x8000
     -->Result 0000 x3 = 0
               0003 x3 = 3*/
    std::cout <<"x3: " << x3 << std::endl;


    short x4;  //一般short默认是带符号的表示65536      
    x4 = {3}; //这里发生narrowing conversion ，有一些int类型，可以保存在short里面
    std::cout <<"x4: " << x4 << std::endl; 

    constexpr int y5 = 3; // 运行编译期的常量
    short x5;
    x = {y5};//{}防止收缩转换
    std::cout << "x5： " << y5 << std::endl;

    //小心区分 =与== 

    //复合赋值云算符
    int x6 = 2;
    x6 = x6 + 2;//+法的运算级别，优于 =
    std::cout << "x6: " << x6 << std::endl;
    x6 += 2;
    std::cout << "x6_+=: " << x6 << std::endl;
    x6 *= 2;
    std::cout << "x6_*=: " << x6 << std::endl;
    x6 /= 2;
    std::cout << "x6_/=: " << x6 << std::endl;
    x6 %= 2;
    std::cout << "x6_%=: " << x6 << std::endl;//取余
    x6 &= 2;
    std::cout << "x6_&=: " << x6 << std::endl;//按位与   1  1 = 1
    x6 |= 2;
    std::cout << "x6_|=: " << x6 << std::endl;//按位或   1  0 = 1
    x6 ^= 2;
    std::cout << "x6_^=: " << x6 << std::endl;//按位异或,同是1为0，都为0为0，有单个1为1）
    x6 << 2;
    std::cout << "x6_<<: " << x6 << std::endl;//Bitwise_shit_left
    x6 >> 2;
    std::cout << "x6_>>: " << x6 << std::endl;//Bitwise_shit_right

    int x7 = 2;
    int y7 = 3;

    x7^=y7^=x7^=y7;//对x和y进行了交换，好处是节省了一块内存；
    /*
    1.x7^ = y7 --> x7 = 2^3, y7 = 3.    return x
      y7^ = x7 --> x7 = 2^3, y7 = 3^2^3 -->3^3^2--> 0^2 --> 2. return y7
      x7^ = y7  --> x7 = 2^3^2-->3^2^2 =3, y7 = 2
    2.
    7^=y7^=x7^=y7； 等于以下操作
    int tmp = x7;
    tmp = x7;
    x7 = y7;
    y7 =tmp;

    */
    std::cout << "x7: " << x7 << "\n";
    std::cout << "y7: " << y7 << "\n";
    
 
    
}