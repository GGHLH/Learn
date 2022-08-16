// #include <iostream>

// int main()
// {
//     int x = 10; // 4 byte --> 4 *8 = 32 bit -> 2**32数据存储
//     char y = 'a';
//     // 1 byte -> 8位--> a bit ->258种数据
//     std::cout << sizeof(x) << '\n';
// }


// #include <iostream>
// #include <limits>

// int  main()
// {
//     int x = 10;
//     char y = 'a';
//     std::cout << std::numeric_limits<int>::min() << std::endl;
//     std::cout << std::numeric_limits<int>::max() << std::endl;
//     std::cout << std::numeric_limits<unsigned int>::min() << std::endl;
//     std::cout << std::numeric_limits<unsigned int>::max() << std::endl;
//     std::cout << sizeof(x) << '\n';
// }

//###############################################################################

// #include <iostream>
// #include <limits>

// int main()
// {
//     //8000-8003
//     //7999-8002


//     //从内存中读取到cash len种。要读取俩次：
//     //7999-8002 要读取这个的分为以下2个步骤
//     //8000-64 - 7999  1.8000减去66
//     //8000-8064       2.先读8000-8064的，然后在去读1
//     int x = 10;
// }

//###############################################################################

#include <iostream>
#include <limits>
struct str
{   //8000
    char b;
    //8004-8007
    int x;
};
//所以8000-8007 一共用了8个字节 来保存 ，所对齐对整个系统结构体大小的影响
int main()
{

    int x = 10;
    std::cout << sizeof(str) << std::endl;
}