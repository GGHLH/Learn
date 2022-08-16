// //size of的方法
// #include <iostream>
// #include <type_traits>

// int main()
// {
//     int a[3];
//     std::cout << sizeof(a) << std::endl;
//     std::cout << sizeof(int) << std::endl;
//     std::cout << sizeof(a) / sizeof(int) << std::endl;//获得array的元素个数   数组元素总的大小 / 元素的类型 = 数组元素的个数

// }


// //std::size方法
// #include <iostream>
// #include <type_traits>


// int main()
// {
//     int a[4] = {2, 3, 5, 7};
//     std::cout << std::begin(a) << std::endl;  //int*
//     std::cout << std::cbegin(a) << std::endl; //const *
//     std::cout << "-: "<< std::cend(a) - std::cbegin(a) << std::endl; //cbegin(a)只能读，不能写 

// }

//基于元素个数遍历
// #include <iostream>
// #include <type_traits>


// int main()
// {
//     int a[4] = {2, 3, 5, 7};

//     size_t index = 0;//当前位置从0开始
//     // 当check index 小于元素个数时，打出index代表所有元素
//     while(index < std::cend(a) - std::cbegin(a)) // 当index小于元素个数，满足条件我们开始循环/这里我用std::cend(a) - std::cbegin(a)替代了std::size(a)
//     {
//         std::cout << a[index] << std::endl;
//         index = index + 1;
//     }
// }


// //基于std::cend(a) - std::cbegin(a)
// #include <iostream>
// #include <type_traits>


// int main()
// {
//     int a[4] = {2, 3, 5, 7};
    
//     auto ptr = std::cbegin(a);

//     size_t index = 0;//当前位置从0开始
//     // 当check index 小于元素个数时，打出index代表所有元素
//     while(ptr != std::cend(a)) // 当index小于元素个数，满足条件我们开始循环
//     {
//         std::cout << *ptr << std::endl;
//         ptr = ptr + 1;
//     }
// }


//基于基于range-based for 循环 方法
#include <iostream>
#include <type_traits>


int main()
{
    int a[4] = {2, 3, 5, 7};
    
    for (int x : a)// 语法糖， 这种写法和上面的while的写法一样，没什么区别。都是通过一个指针，寻找地址给出数组元素
    {
        std::cout <<  x  << std::endl;
    }


}