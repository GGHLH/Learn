// #include <iostream>

// int main()
// {
//      const int x = 4; //加了const只能读，不能写！

//     std::cout << x << "\n";
//     x = 6; //所以有着一行，会报错！
// }


//const 防止非法操作
// #include <iostream>

// int main()
// {
//     const int x = 4; //将一个对象由变量变为了常量，来防止写操作

//     if (x = 3)
//     {

//     }
// }

//const 优化程序逻辑
// #include <iostream>

// int main()
// {
//     const int x = 4;


//     // ....即设是引入的大量逻辑
//     int y = x + 1; //这里是优化
// }

//const 限制指针不能修改开辟内存中存入的地址
// #include <iostream>

// int main()
// {
//     int x = 4;
//     int* const ptr = &x;  // 代表ptr的指针内存存储的地址不能被修改，只能指向x  但是可以修改原始对象内容
//     // const int* ptr = &x;  // 代表ptr指向x, x的值不能被修改面，即ptr不能改变x的值。

//     int y = 3;           
//     ptr = &y;           //报错！ 因为ptr上一步，被设为常量指针。其内部存储地址是不会发生变化的，只能指向原来的对象。这就是const的防止写入操作

// }
//反过来看

// #include <iostream> 

// int main()
// {
//     int x = 4;
//     const int* ptr = &x;// 指向的是x， 不能修改x。常量ptr中的地址可以发生改变
//     // int* const ptr = &x; //指向的是ptr，常量指针，即指针不能被修改，可以改变指针开辟空间内存中存储地址指向的对象；


// }

// #include <iostream>

// int main()
// {
//     int x = 4;
//     const int* ptr = &x; //这样不能修改x的值

//     *ptr; // const int
//     std::cout << &x << "\n";
//     std::cout << &ptr << "\n";
// }
// #include <iostream>

// int main()
// {
//     int x = 4;
//     int* const ptr = &x; //这样不能修改ptr的值

//     *ptr; // int
//     std::cout << &x << "\n";
//     std::cout << &ptr << "\n";
// }

//######常量指针，指向变量
// #include <iostream>

// int main()
// {
//     int x = 4;
//     &x; //int*
//     const int* ptr = &x;//是ptr的一个构造，通过拷贝一个构造函数来完成的 =为拷贝构造函数
//     /*隐式的类型转化怎么进行：
//                 int*  --> const int* 
//                 然后将这个值赋给ptr*/
 

// }
//ptr ---> int*         int* const ptr 是直接对指针禁止修改
//&x  ---> const int*   之间对的原始对象，禁止修改

/*
const int* ptr --> int* const ptr // 是不被编译器接受的
         &x ------------>ptr 

int* const ptr --> const int* ptr  
         ptr -----------> &x
*/


/*
const int* ptr --> int* const ptr // 是不被编译器接受的
         &x ------------>ptr 

int* const ptr --> const int* ptr  
         ptr -----------> &x
*/


// #include <iostream>

// int main()
// {
//     const int x = 3;

//     int* ptr = &x;// 根据const int x = 3; 这种写法是不合理的    
// }


// #include <iostream>

// int main()
// {
//     const int x = 3;
//     const int* ptr = &x;// 这里const int* ptr = const int* 这里不涉及隐式转换，完全没问题
// }

//#######################常量引用############################################
// #include <iostream>

// struct Str //结构体比如独占文件。不支持被复制。因此引入常量引用
// {
//     //...很多很多的数据
// };

// void fun(const Str& param)//内建函数类型比较小，意味着数据数据拷贝，不需要消耗更多的资源
// {
 
// }

// int main()
// {
//     Str x;
//     // const int& ref = x;// ref只能指向x,主要用途函数的型参
//     fun(x);//x时要拷贝，拷贝，拷贝，拷贝，拷贝，拷贝，拷贝，拷贝，拷贝，拷贝给void fun()中的param

// }
//常量引用 用来绑定字面值

// #include <iostream>


// void fun(const int& param) //常量引用（const int& ref = 3；[还绑定了字面值3]）被当作函数的型参的型参
// {

// };

// int main()
// {
//     int x = 3;
//     // int& ref = 3;//3是字面值，字面值没有地址。只能绑定到一个对象上。 所以这个代码是非法的
//     fun(x);
//     fun(3);//这里调用了，在fun()里param都会被替换成3，因为有这样的关系。所以我们必须保证常量引用能够关联到3 ---》所以常量引用可以绑定到字面值
//     const int& ref = 3;
// }   



// #include <iostream>

// int main()
// {
//     int x;
//     std::cin >> x;

//     const int y1 = x;

//     const int y2 = 3;

//     if (y1 == 3) // 在运行期确定；
//     {

//     }
//     if (y2 == 3) // 在编译期确定，编译期的常量； 因为前面规定了 const int y2 =3； 所以完全没有避免引入这个if
//     {

//     }
// }

// #include <iostream>

// int main()
// {
//     int x;
//     std::cin >> x;
//     const int y1 = x;
//     const int y2 = 3;

//     constexpr int y2 = 3;

//     if (y1 == 3)
//     {

//     }
// }

// #include <iostream>
// int main()
// {
//     constexpr int y2 = 3; //限定符号， y2还是一个const int类型

//     /* ptr类型是： const int* const:
//         1.表示指针本身不能被修改（const）
//         2.表示指针指向的东西不能被修改 
//        如下所示：constexpr只是修是了ptr,并不是类型申明的一部分，ptr的类型是--> const int* const*/
//     constexpr const int* ptr = nullptr; //常量表达式指针 ,constexpr 表示ptr是个常量。 第二，这个值在编译期间就被确定了
    

//     constexpr const char* ptr2 = "123"; 
// }


// #include <iostream>
// #include <type_traits>//用来判断俩类型是否相等
