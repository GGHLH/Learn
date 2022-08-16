// #include <iostream>
// #include <type_traits>

// int main()
// {
//     int a[3] = {1, 2, 3};
//     /*数组a[0]到指针*a进行了一个隐式转换，然后再进行处理*/
//     std::cout << a[0] << std::endl;

//     decltype(a); // 返回int[3], 这里没有产生数组到指针的隐式转换
//     auto b = a; //这里a也进行一个隐式转换，进行了退化，变成了一个相对简单的类型指针。 专门的文章名词叫decay

// }

//隐式转换会丢失一部分信息
// #include <iostream>
// #include <type_traits>

// int main()
// {
//     int a[3] = {1, 2, 3};     // --> int[3]
//     std::cout << a[0] << std::endl;

//     auto b = a;              // b--> int* b就无法计算对象包含元素的个数
//     //21和 24 可以看我么丢失了3这个信息
// }


//针对隐式转换会丢失一部分信息， 我们采用声明来防止这部分信息的丢失
// #include <iostream>
// #include <type_traits>

// int main()
// {
//     int a[3] = {1, 2, 3};     // --> int[3]
//     std::cout << a[0] << std::endl;

//     auto& b = a;  //1.这样就防止隐式转换的信息丢失。另一层理解2.这样就防止了退化为指针
//                   // 从概念上说&b是a的别名了，加上引用   ， 就会继承a类型的属性  
//                   // b的结果--> int(&)[3]    

// }


// #include <iostream>
// #include <type_traits>
// #include "source.cpp" 


// extern int array[]; //声明，要链接到别的单元，声明
// int main()索引


//为了解决数组元素被限制的情况：int array[4] = {1, 2, 3, 4};  int array[] = {1, 2, 3, 4};
//使用指针数组
// #include <iostream>
// #include <type_traits>
// #include "source.cpp" 


// // extern int* array;//不能使用extern指针来声明数组 ，所以这里是错误的       
// int main()
// {
//     std::cout << array[1] << std::endl;

// }

// #include <iostream>
// #include <type_traits>
// #include "source.cpp"


// void fun();

// extern int array[];
//  /*
// 声明，要链接到别的单元，声明. 注意这里不是定义，声明可以不给出值
// 将array[]当作一个数组看待.
// 在C++里这个叫做 Unknow Bounded Array 声明
// */
// int main()
// {
//     fun();
//     std::cout << array << std::endl;
//     std::cout << array[1] << std::endl; //array[1] = *(array + 1)
//     std::cout << *(array + 1) << std::endl; //array[1] = *(array + 1)

// }
//###################1.获得指针指向数组开头与结尾的指针#######################################
// #include <iostream>
// #include <type_traits>
// #include "source.cpp"


// void fun();

// int main()
// {
//     int a[3]= {1, 2, 3};
//     //(&a[0]);指向元素的的第一个指针，开头指针
//    /*1. a + 3 错后指向3后面的 \n
//      2.(&a[3]) 指向这个元素结尾的指针
//    */
//     std::cout << a + 3 << " " << (&a[3]) << std::endl; //代表指向这个元素结尾的指针地址
// }



// //std::(c)begin , std::(c)end
// #include <iostream>
// #include <type_traits>
// #include "source.cpp"


// void fun();

// int main()
// {
//     int a[3]= {1, 2, 3};
//     //(&a[0]);指向元素的的第一个指针，开头指针
//    /*1. a + 3 错后指向3后面的 \n
//      2.(&a[3]) 指向这个元素结尾的指针
//    */
//     std::cout << a << "\n" << "address: " << &(a[0]) << "\nStrat address: " << std::cbegin(a) << std::endl;
//     std::cout << a << &(a[3]) << " " << std::cend(a) << std::endl;  
//     // std::cout << a + 3 << " " << (&a[3]) << std::endl; //代表指向这个元素结尾的指针地址
// }


// #include <iostream>
// #include <type_traits>
// #include "source.cpp"


// void fun();

// int main()算术#
// {
//     int a[3]= {1, 2, 3};
//     //(&a[0]);指向元素的的第一个指针，开头指针
//    /*1. a + 3 错后指向3后面的 \n
//      2.(&a[3]) 指向这个元素结尾的指针
//    */
//     std::cout << a << "\n" << "address: " << &(a[0]) << "\nStrat address: " << std::cbegin(a) << std::endl;
//     std::cout << a << &(a[3]) << " " << std::cend(a) << std::endl;  
//     // std::cout << a + 3 << " " << (&a[3]) << std::endl; //代表指向这个元素结尾的指针地址
// }




// #include <iostream>
// #include <type_traits>
// #include "source.cpp"


// void fun();

// int main()
// {
//     int a[3]= {1, 2, 3};
//     //(&a[0]);指向元素的的第一个指针，开头指针
//    /*1. a + 3 错后指向3后面的 \n
//      2.(&a[3]) 指向这个元素结尾的指针
//    */
//     std::cout << a << "\n" << "address: " << &(a[0]) << "\nStrat address: " << std::cbegin(a) << std::endl;
//     std::cout << a << &(a[3]) << " " << std::cend(a) << std::endl;  
//     // std::cout << a + 3 << " " << (&a[3]) << std::endl; //代表指向这个元素结尾的指针地址

//     auto& b = a; //引用后，表示b是a的别名m 可以使用std::cbegin   and  std::bend
//     std::cout << std::begin(b) << std::endl;
//     std::cout << std::end(b) << std::endl;  //const int*
// }


//############################3###2.指针相关的算术##########################################
// // + and -
// #include <iostream>
// #include <type_traits>
// #include "source.cpp"



// extern int array[4];
// int main()
// {
//     int a[3]= {1, 2, 3};
//     auto ptr = a; // ptr --> ptr*
//     // ptr = ptr + 1; //指针指向后一个位置  +1 这里要成于int的长度 1 * int；
//     // ptr = ptr - 1; //指针指向前一个位置  -1 这里要成于int的长度 1 * int；
// }

// // 比较
// #include <iostream>
// #include <type_traits>
// #include "source.cpp"



// extern int array[4];
// int main()
// {
//     int a[3]= {1, 2, 3};
//     auto ptr = a; // ptr --> ptr*
//     auto ptr2 = a + 3;

//     std::cout << (ptr == ptr2) << std::endl; //比较他俩 相等
//     std::cout << (ptr != ptr2) << std::endl; //比较他俩
//     std::cout << (ptr >= ptr2) << std::endl; //比较他俩  注意，这里只能时指向同一个数组的位置，才可以比较大小
//     std::cout << (ptr <= ptr2) << std::endl; //比较他俩  注意，这里只能时指向同一个数组的位置，才可以比较大小
//     std::cout << (ptr > ptr2) << std::endl; //比较他俩   注意，这里只能时指向同一个数组的位置，才可以比较大小
//     std::cout << (ptr < ptr2) << std::endl; //比较他俩   注意，这里只能时指向同一个数组的位置，才可以比较大小


// }


// ptr之间求距离
#include <iostream>
#include <type_traits>
#include "source.cpp"



extern int array[4];
int main()
{
    int a[3]= {1, 2, 3};
    auto ptr = a; // ptr --> ptr*
    auto ptr2 = a + 3;

    std::cout << (ptr2 -ptr) << std::endl; //求距离  64 - - - - 79 后面有个\n 结束符号 ，变为80 ，结果就是 80 -64 然后在除以4 就是int的length
    //俩个指针相减去，返回的时俩个指针之间包含的元素个数
    std::cout << *ptr << std::endl;


}