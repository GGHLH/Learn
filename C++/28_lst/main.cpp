// #include <iostream>
// #include <type_traits>

// int main()
// {
//     int x; //int
//     std::cout << "please input number:" << "\n";
//     std::cin >> x;
//     int b[10]; // b的类型不再是int， 在c++里面要区分int类型和元素的类型。 b的类型就是int[10]
//     std::cout << std::is_same<decltype(b), int[10]>::value << std::endl;
// }
//###################################2#################################################
// #include <iostream>
// #include <type_traits>

// int main()
// {
//     int a;    //int
//     int b[1]; // int[1]
//     std::cout << std::is_same<decltype(b), int[1]>::value << std::endl;
//     std::cout << std::is_same<decltype(b), int>::value << std::endl;
// }
//###################################3#################################################
// #include <iostream>
// #include <type_traits>

// int main()
// {
//     constexpr short x = 3;
//     int b[x];
//     std::cout << std::is_same<decltype(b), int[1]>::value << std::endl;
//     std::cout << std::is_same<decltype(b), int>::value << std::endl;
// }
//######################4数组的初始化方式#################################################
// #include <iostream>
// #include <type_traits>

// int b[3]; //在这里会初始化为0

// int main()
// {
//     int b[3]; //在这里定义是三个随机的数
// }
//######################5数组的聚合初始化方式##############################################

// #include <iostream>
// #include <type_traits>


// int main()
// {
//     int b[3] = {1, 2, 3};//聚合初始化
// }

//聚合初始化的变种
// #include <iostream>
// #include <type_traits>


// int main()
// {
//     int b[3] = {1, 2};//系统自动将前俩个元素1，2初始化，最后一个用0来初始化
//     std::cout << b[3] << std::endl;
//     std::cout << std::is_same<decltype(b), int[3]>::value << "\n";
// }

// #include <iostream>
// #include <type_traits>


// int main()
// {
//     int b[] = {1, 2, 3};//b的类型，就是int3；，有几个元素就是int[x]的类型x为总元素
//     std::cout << b[3] << std::endl;
//     std::cout << std::is_same<decltype(b), int[3]>::value << "\n";
// }
//######################6数组类型的注意项目###################################################
// #include <iostream>
// #include <type_traits>
// #include <typeinfo>

// int main()
// {
//     auto b = {1, 3, 4};
//     std::cout << typeid(b).name() << std::endl;   //命令行输入 ./main | c++filt -t 可以看到他的类型  --->
//     std::cout << std::is_same<decltype(b), std::initializer_list<int>>::value << std::endl;
//     std::cout << std::is_same<decltype(b), int[3]>::value << std::endl;
// }
//######################6数组类型的注意项目###################################################

// #include <iostream>
// #include <type_traits>
// #include <typeinfo>

// int main()
// {
//     int b[] = {1, 3, 4};
//     auto a = b; //类型的自动推导，作为右值会退化。 这里b作为右值退化为相应的指针； 这种方式比数组的赋值方式更快的，可以用指针的形式访问数组
//     std::cout << std::is_same<decltype(a), int*>::value << std::endl;//这里发现a是个指针
//     // a = b; //这也是错误的，也会报错『一个数组复制给另一个数组也是不支持的』
//     // int a[3] = b; //error， 数组是不支持赋值的！
//     // int a[3] = b;//这里赋值错误，我们初始化要使用大括号去初始化
// }

//c++ 内建数组，更多关心的是性能
// #include <iostream>
// #include <type_traits>
// #include <typeinfo>

// int main()
// {
//     int b[] = {1, 3, 4};
//     auto& a = b; 
//     std::cout << std::is_same<decltype(a), int(&)[3]>::value << std::endl;//这里发现a是个指针
// }

//字符串数组的特殊性
#include <iostream>
#include <type_traits>
#include <typeinfo>

int main()
{
    char str[] = "Hello"; //正确的
    // char str[] = {'H', 'e', 'l', 'l','o'};// 上面是简写的方式 char[5]
    std::cout << typeid(str).name() << std::endl;
    std::cout << std::is_same<decltype(str), char[5]>::value << std::endl;
    
}