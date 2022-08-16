 #include <iostream>

int main()
{
    signed char x = 3; //char -->占8位 3在二进制 00000011
    signed char x1 = -4;//11111100
    signed char y = 5;//000000101 

    //除去反外，其他运算符均为左结合的 
    std::cout << "取反： " << ~x << std::endl; //按位置取反，---> 11111100, 为-4  为右运算
    std::cout << "罗辑与：" <<  (x && y) << std::endl;
    std::cout << "罗辑或：" <<  (x || y) << std::endl;
    std::cout << "位：" << (x | y) << std::endl;
    std::cout << "按位异或运算符：" << (x ^ y) << std::endl;

    //|,按位异或运算符与逻辑异，或的区别就是不会有上面的逻辑短路操作
    /*先对x求职判断是否能转化为bool类型true， 
      如果是ture则对y求职，如果是false则不对y求值，直接返回false */
    x && y;

    /*先对x求职，是否转化为bool类型为true，
    如果为true则不对y求值，返回true*/
    x || y;


    //位移操(<<, >> )作在一定情况下等价于乘(除)2的幂，但速度更快
    /*
    x >> 1 右移  --> 就是*2 = 8， 
    x << 1 左移  --> 就是/2 = 4,  左移3为：-4 * 2^3 以此类推
    */
    std::cout << "Bitwise left_shit :" << (x << 1) << std::endl;//由00000011 --> 00000110
    std::cout << "Bitwise right_shit:" << (x >> 1) << std::endl;//由00000011 --> 00000001
    std::cout << "Bitwise left_shit_x1:" << (x1 << 1) << std::endl;//由11111100 --> 11111000
    std::cout << "Bitwise rigfht_shit_x1:" << (x1 >>  1 ) << std::endl;//由11111100 --> 11111110,最前面的1补的是一个符号 


    //constexpr int xxx 等于 （x << 1） 左移的操作
    int x2 = 3;
    constexpr int y2 = 2; //constexpr 表明是在编译期运行, 编译器的常量 
    std::cout << "constexpr_1: " << (x2 << 1) << std::endl;
    std::cout << "constexpr_2: " << (x2 * y2) << std::endl;

    //注意整数的符号与位操作符的相关影响
    unsigned char x3 = 0xff;// 11111111二进制的表示
    auto y3 = ~x3;//取反这里会有intergral promotion(类型提升)
    std::cout << "~x3:" << y3 << std::endl;

    signed char x4 = 0xff;
    /*0xff十六进制 ，intergral promotion 为int 变为4x8= 32，第一个1会看作符号位
      11111111 -> 1111111111111111111111111111111111（int用这个值来表示负）
    -> 00000000000000000000000000000000(按位求反，所有1变0)*/
    auto y4 = ~x4;//先进行类型提升，在按位取反
    std::cout << "~x4:" << y4 << std::endl;

    // 右移保持符号，单左移不能保证
    int x5 = 0x80000000;//10....0
    std::cout << "x5: " << x5 << std::endl;
    std::cout << "x5_Bitwise_shift_right: " << (x5 >> 1) << std::endl;//整体向右移动一位在内存中，最前面加符号位 1 ：10....0 --> 110....0;
    std::cout << "x5_Bitwise_shift_left: " << (x5 << 1) << std::endl;// Result --> 代表溢出了. 舍弃最高位后面补0 ：10....0 --> 0.....00;

    int x6 = -1; //11....11
    std::cout << "x6: " << x6 << std::endl;
    std::cout << "x6_Bitwise_shift_right: " << (x6 >> 1) << std::endl;//Attention：右移保持符号，单左移不能保证. 11....11;
    std::cout << "x6_Bitwise_shift_left: " << (x6 << 1)      << std::endl;//Attention：右移保持符号，单左移不能保证. 1....10;

    /*unsigned 这种类型，Bitwise_shift_right，会再前面插入0，因为最前面的位不是符号类，即右移是保持符号的， 10....0 --> 010....0，
                       Bitwise_shift_left, 再后面插0                                             10....0 --> 0....00， 左移会去掉最高位
                       
     signed 会插入符号类 */
}
 