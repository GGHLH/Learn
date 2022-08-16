// #include <iostream>

// typedef int MyInt; //为int引入了一个别名，叫MyInt

// int mian()
// {
//     MyInt x = 3;
// }
//#############################################2#####################
// #include <iostream>

// using  IntPtr = int*;//表示了一个int型的指针

// int main()
// {
//     int x = 3;
//     const IntPtr ptr = &x; //是一个顶层的const等价于int* const ptr = &x; ，
//     /*这个const是修是整个 IntPtr的 
//       不是修饰using IntPtr = int*中的 int.如果只是做简单的替换
//       如下：
//          const int* ptr = &x;则const是修饰这个int的，而不是修
//          饰这个int*的 
//       所以说，如果我们定义一个类型别名，在这个类型别名上引入const，引入指针也好
//       我们要注意const int* ptr = &x中const，或是指针他是修饰IntPtr整个类型别名，而不能拆开
//     */
   

// }
//#############################################3#####################
// #include <iostream>
// #include <type_traits>

// using RefInt = int&;  //定义了引用
// using RefRefInt = RefInt&; //定义了引用的引用

// // template <typename T>

// int main()
// {

//     std::cout < std::is_same_v<int&, RefRefInt> << std::endl;//比较RefInt, RefRefInt是否相同 is_same_v在C++17里开启
// } 这是错误的 、引用的引用
//#############################################4#####################
//自动推导对象类型
// # include <iostream>

// int main()

// {   

//     //初始化一定要指定类型,
//     // int x = 3 + 15l;//IDE知道double 和 int 的类型，自动法国推导对象的类型，如下所是
//     auto x = 3.5 + 15l;
//     std::cout << x << " \n";
// }

// //使用auto 自动推导对象的类型   1
// #include <iostream>

// int main()
// {
//     auto x = 6.5;
// }

// //使用auto 产生类型退化        2
// #include <iostream>

// int main()
// {
//     int x;
//     x = 3; //左值

//     int y = x; //right value
// }
// //使用auto 产生类型退化        3
// #include <iostream>

// int main()
// {
//     int x1 = 3;
//     int& ref = x1; //left_value

//     ref =3;// 3 type is int  ref是int型的引用。所以将一个int的值赋给一个int的引用没有问题的
// }


// //典型的类型退化，int的引用退化为int类型 4
// #include <iostream>

// int main()
// {
//     int x1 = 3;
    
//     int& ref = x1; //left_value
    
//     int y = ref; 
//     /*ref为右值使用，这时ref不看作int& ref的引用。看作int就可以了
//     实际上int的引用不能赋予y，要赋予的是int的引用所包含的那个值
//     所以说ref那个到=右边使用，他的类型 就从int& ref 变成了int
//     int& ref ---> int ref
//     const int& --->int
//     */ 
 
// }

// //证明典型的类型退化，int的引用退化为int类型 5
// #include <iostream>
// #include <type_traits>


// using namespace std;

// int main()
// {
//     int x1 = 3;
//     int& ref = x1;

//     auto ref2 = ref;

//     std::cout << std::is_same<decltype(ref2), int>::value << std::endl;
//     std::cout << std::is_same<decltype(ref2), int&>::value << std::endl;
// }

// // const auto/constexpr auto；推导出的是常量/常量表达式的 6
// #include <iostream>
// #include <type_traits>

// int main()
// {
//     // const auto x = 3;
//     // constexpr auto x = 3;
//     const int x = 3;
//     const auto y = x;// const int这个东西（x），放在右边会产生退化
//     auto z = y;
//     std::cout << std::is_same<decltype(x), const int>::value  << std::endl;
//     std::cout << std::is_same<decltype(x), const int&>::value << std::endl;
//     std::cout << std::is_same<decltype(y), const int>::value  << std::endl;
//     std::cout << std::is_same<decltype(z), int>::value << std::endl;
// }
//#############################################5#####################
//auto&：推导出引用类型，避免类型退化
// #include <iostream>
// #include <type_traits>

// int main()
// {
//     const int& x = 3;
//     auto& y = x;// 无论auto替换成什么，y都是是引用类型。 看到这样的语句IDE不会对x进行退化处理 x在右边会被视作const int
//     std::cout << std::is_same<decltype(y), const int&>::value << std::endl;
//     std::cout << std::is_same<decltype(y), int >::value << std::endl;

// }

//#############################################6#####################
// decltype(exp):返回exp表达式的类型（左值加引用）
// #include <iostream>
// #include <type_traits>

// int main()
// {
//     // decltype(3.5 + 15l) x = 3.5 + 15l; //不会产类型退化
//     int x = 3;
//     const int y1 = x;

//     auto y2 = y1;//会产生类型退化
//     std::cout << std::is_same<decltype(y2), int>::value << std::endl;

//     decltype(y1) y3 = y1;
//     std::cout << std::is_same<decltype(y3),  const int>::value << std::endl;//decltyp(exp) 避免类型退化
//     std::cout << std::is_same<decltype(y2), int>::value << std::endl;
// }

// //左值加引用
// #include <iostream>
// #include <type_traits>

// int main()
// {
//     int x = 3;
//     int* ptr = &x;
//     /*
//       ptr--> int*;
//      *ptr--> int&;
//      */
//     // decltype(*ptr);//*ptr解引用， *ptr是个左值
//     (x) = 5;

//     const int y1 = 3;
//     const int& y2 = y1;
//     //常量
//     std::cout << std::is_same<decltype(y1), const int>::value << std::endl;
//     std::cout << std::is_same<decltype(y2), const int&>::value << std::endl;
//     //字面值
//     std::cout << std::is_same<decltype(3.5 + 15l), double>::value << std::endl;
//     //变量
//     std::cout << std::is_same<decltype(ptr), int*>::value << std::endl;
//     std::cout << std::is_same<decltype(*ptr), int&>::value << std::endl;
//     std::cout << std::is_same<decltype(x), int>::value << std::endl;
//     std::cout << std::is_same<decltype((x)), int&>::value << std::endl;//左值加引用
//     //表达式
//     std::cout << std::is_same<decltype((y1)), const int&>::value << std::endl;//左值加引用
//     std::cout << std::is_same<decltype((y2)), const int&>::value << std::endl;//没有引用的引用，所以推导完了还是const int&
// }
//#############################################7#####################
//decltype(auto):从c++14开始，简化decltype的使用

// #include <iostream>
// #include <type_traits>

// int main()
// {
//     decltype(auto) x = 3.5 +15l;//decltype（exp）：返回exp表达式的类型。不会产生退化。auto = 3.5 +15l


// }

//#############################################8#####################
// //concept auto: 从C++20开始支持，表示一系列类型（std::integral auto x =3;）
// --std = c++ 11 请注意这里
// #include <iostream>
// #include <type_traits>
// #include <typeinfo>
// #include <concepts>

// int main()
// {
//     std::integral auto y =3;
//     std::cout << std::is_same<decltype(y), int>::value << std::endl;
// }