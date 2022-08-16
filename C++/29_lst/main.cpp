// #include <iostream>
// #include <type_traits>

// int main()
// {
//     int* a[3]; //<-- 代表a里面包含了三个元素，每个元素都代表了一个指针
//     int * a[3]; //<-- 代表a里面包含了三个元素，每个元素都代表了一个指针
//     int *a[3]; //<-- 代表a里面包含了三个元素，每个元素都代表了一个指针
//     //这样写都没有问题
// }

//##################1.指针数组####################################################
// #include <iostream>
// #include <type_traits>

// int main()
// {
//     int* a[3]; 
//     std::cout << std::is_same<decltype(a), int*[3]>::value << std::endl;
// }
//##################2.数组的指针####################################################
// #include <iostream>
// #include <type_traits>

// int main()
// {
//     int (*a)[3]; 
//     /*解应用这个对象：
//     指向一个包含3个元素，每个元素是int型的数组
//     */
// }

//指针的数组的初始化
// #include <iostream>
// #include <type_traits>

// int main()
// {
//     int b[3];
//     int (*a)[3];  //对指针的数组初始化
//     // int (*a)[3] = {&x1, &x2, &x3};//不能这样初始化

// }

//指针数组的类型判断是否相等
// #include <iostream>
// #include <type_traits>

// int main()
// {
//     int (*a)[3];
//     std::cout << std::is_same<decltype(a), int(*)[3]>::value << std::endl;
// }

//##################3.引用#######################################################
//声明数组的引用
// #include <iostream>
// #include <type_traits>

// int main()
// {
//     int b[3];
//     int (&a)[3]= b; //数组的引用
//     std::cout << std::is_same<decltype(a), int(&)[3]>::value << std::endl;
// }


//##################3.数组中的元素访问#############################################
// #include <iostream>
// #include <type_traits>

// int main()
// {
//     int a[3] = {1, 2, 3};
//     std::cout << a[1] << std::endl;
// }

//数组对象是一个左值
// #include <iostream>
// #include <type_traits>

// int main()
// {
//     int a[3] = {1, 2, 3};
//     //l-value :放在等号左边的值，在C++当中对其进行了修改，实际上变为了locator cvalue.在C++中一些左值没有被放到左边
//     std::cout << a[1] << std::endl;
// }

//验证左值是否是一个引用，根据cpp reference declinaction
// #include <iostream>
// #include <type_traits>

// int main()
// {
//     const int x = 3;
//     std::cout << std::is_same<decltype(x), const int>::value << std::endl;
    
//     // x作为表达式的时候一定是一个左值，decltype(())，所以他一定是一个引用，注意括号
//     std::cout << std::is_same<decltype((x)), const int&>::value << std::endl; 
// }



#include <iostream>
#include <type_traits>

int main()
{
    int a[3] = {1, 2, 3};
//     std::cout << a[100] << std::endl; // --> result: 32767
    std::cout << *(a + 100) << std::endl;//将a转化为指针，向后移动100个int。超出了我们开辟3个内存的大小，即变成内存溢出。即内存访问的越届
    std::cout << *(a -1) << std::endl; //将a转化为指针，向前移动一位，也是超出了我们开辟3个内存的大小，即越届
}