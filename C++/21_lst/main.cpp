// #include <iostream>

// int main()
// {
//     int x = 42;
//     int y = 56;
//     int* p = &x; //定义一个响应的指针类型, 相当于指向了x的地址
//     p = &y;      //p指向了y；可以通过一个指针，间接的应用不同的对象
//     std::cout << p << std::endl;
// }


// #include <iostream>

// int main()
// {
//     int x = 42;
//     char y = 'c';
//     std::cout << "--------------------------------" << std::endl;
//     std::cout << "变量地址" << std::endl;
//     std::cout << (&x) << std::endl;
//     std::cout << (&y) << std::endl;
//     std::cout << "--------------------------------" << std::endl;
//     std::cout << "变量大小" << std::endl;
//     std::cout << sizeof(int) << std::endl;
//     std::cout << sizeof(char) << std::endl;
   
//     int* p1  = &x;
//     char* p2 = &y;
//     std::cout << "--------------------------------" << std::endl;
//     std::cout << "指针对象地址"<< std::endl;
//     std::cout << (&p1) << std::endl;//这个地址是指针取了变量的地址，然后在指针对象开辟内存中，存储了这个变量的地址后，指针在这个内存序列的地址。
//     std::cout << (&p2) << std::endl;
//     std::cout << sizeof(p1) << std::endl; //指针尺寸具有相同的大小
//     std::cout << sizeof(p2) << std::endl; //1byte = 8bit 则8个字节需要64个bit 64/8 =8 字节
//     std::cout << "--------------------------------" << std::endl;

//     std::cout << "*解引用" << std::endl; //能说明每个类型不同的含义，解出来
//     std::cout << *p1 << std::endl;
//     std::cout << *p2 << std::endl;
// }


// #include <iostream>

// int *p1; //全局。缺省值为0；

// int main()
// {
//     int x =42;#include <iostream>

// int main()
// {
//     int x = 42;
//     char y = 'c';
//     std::cout << "--------------------------------" << std::endl;
//     std::cout << "变量地址" << std::endl;
//     std::cout << (&x) << std::endl;
//     std::cout << (&y) << std::endl;
//     std::cout << "--------------------------------" << std::endl;
//     std::cout << "变量大小" << std::endl;
//     std::cout << sizeof(int) << std::endl;
//     std::cout << sizeof(char) << std::endl;
   
//     int* p1  = &x;
//     char* p2 = &y;
//     std::cout << "--------------------------------" << std::endl;
//     std::cout << "指针对象地址"<< std::endl;
//     std::cout << (&p1) << std::endl;//这个地址是指针取了变量的地址，然后在指针对象开辟内存中，存储了这个变量的地址后，指针在这个内存序列的地址。
//     std::cout << (&p2) << std::endl;
//     std::cout << sizeof(p1) << std::endl; //指针尺寸具有相同的大小
//     std::cout << sizeof(p2) << std::endl; //1byte = 8bit 则8个字节需要64个bit 64/8 =8 字节
//     std::cout << "--------------------------------" << std::endl;

//     std::cout << "*解引用" << std::endl; //能说明每个类型不同的含义，解出来
//     std::cout << *p1 << std::endl;
//     std::cout << *p2 << std::endl;
// }
//     // int *p(&x);//直接初始化 。通常来说直接初始化和拷贝初始化，对内建数据类型『int，float...』没有什么区别
//     int *p;   //缺省初始化； p中的内容是随机。在函数内部是随机的，在全局缺省则是0；
//     std::cout << *p << std::endl; // 函数内缺省初始化解引用也不行，因为在过程中要么是0，要么地址是随机的，每次都不一样 ，0<---会导致程序崩溃。 随机值<---导致不可控
//                                  // 所以要申明一个指针时，一定要给其赋值
//     // std::cout << *p1 << std::endl;//如果对全局的p1进行解引用，p1指向的是0地址『这是一个非常特殊的地址，不能对他进行引用』 <---会导致系统报错
// }


// #include <iostream>

// int *p;
// int main()
// {
//     int x =42;
//     //拷贝初始化0，0是一个字面值， 而int* 是一个对象-->会涉及类型转换，这种是非常危险的 <-- 函数重载
//     int *p = 0; //参考C++全局的做法『int *p = 0 or int *p = NULL(NULL=0)的』 
//     /*
//     这种做法，是非法的，但报错是稳定的不会出现随机的。是一种更加安全的处理方式
//     如果 int *p； 在自己开发的电脑上没问题。但是在用户机器上用户使用时，由于程序的
//     行为是不确定的，就会出现问题
//     */
//     std::cout << *p <<std::endl;
// }

// //##########################什么是程序行为不一致，引入c++11 nullptr ###############################                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             ####################################################
// #include <iostream>

// void fun(int)
// {
//     std::cout << "1\n";
// };

// void fun(int*)
// {
//     std::cout << "2\n";                                                                                                                                                                                                                                                                                                                                                                                                                                                                             
// };

// int main()
// {一致性
//     fun(0);
//     int *p = 0;
//     // fun(p);
//     /*为了接来进行一些程序的优化，调整。认为p没有什么,将fun(p)改为了fun(0)。直接用0调用他
//      导致程序的行为发生了转变*/
//     fun(0);
// } //result 1,2 --->1,1 程序的行为发生了改变
// //###########################################################################################



//##########################引入c++11 nullptr，程序行为变的一致 ###################################   
// #include <iostream>

// void fun(int)
// {
//     std::cout << "1\n";
// };

// void fun(int*)
// {
//     std::cout << "2\n"; 
// };

// int main()
// { 
//     fun(0); //系统会调用 第一个fun（） 因为0是int
//     int *p = 0;
//     // int *p = nullptr;//nullptr是一个指针，其次可以隐式的转换成任意的指针，因此可以转换成int类型的指针
//     fun(nullptr);
//     /*为了接来进行一些程序的优化，调整。将fun(p)改为了fun(0),认为p没有什么。直接用0调用他
//     导致程序的行为发生了转变，因此C++11引入 nullptr 【是一种特殊对象指针】
//     nullptr可以转变任意类型的指针，但是nullptr不能转化为整数。
//     总结：
//         总的来说nullptr不会改变函数重载中程序的行为，使程序行为变的稳定。因此引入 C++11 nullpt                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            特性r的特性*/

// }
// // int main()
// // {
// //     int* p = nullptr;// p则隐式的转为了 指针类型为int的对象
// //     fun(p); //这里调用了p的指针方法
// // }
//result 1, 2 --> 1, 2 程序行为一致



//##########################指针与布尔类型的隐式转换######################
// #include  <iostream>

// int main()
// {

//     int *p = nullptr;


//     // int *p = ture
//     if(p)
//     {

//     }
//     //int *p= false
//     else{

//     };

// }
//##########################指针解引用和加减#####################################
// #include <iostream>

// int main()
// {
//     int x = 42;
//     int* p = &x;

//     std::cout << p << std::endl;
//     p = p + 1 ; //并不是指针地址中对对象树据的增加或减少。是在字节上对尺寸增加或减少。代表对存储在指针内部的地址，在尺寸上加1，即移动到后面4个字节 -1即移动到当前，前面四个字节
//     std::cout << p << std::endl;
//     p = p - 2;
//     std::cout << p << std::endl;

//     // std::cout << *p << std::endl;
// }

//#############################指针判断相等#####################################
// #include <iostream>

// int main()
// {
//     int x = 42;
//     int *p = &x;
//     int *q = &x;
//     std::cout << "1:true, 0:false" << "\n";
//     std::cout << (p == q) << "\n"; //输出为bool类型，实际就在判断他俩在内存中的地址是否相等

//     std::cout << "---check address---" << "\n" << std::endl;
//     std::cout << (&*p) << "\n"; 
//     std::cout << (&*q) << "\n";

//     int y;
//     int *r = &y;

//     std::cout << (r == q) << "\n";
//     std::cout << (&*q) << "\n";
//     std::cout << (&*r) << "\n"; //总结：判断俩个指针相等，其实就是在判断这俩个指针开辟的序列空间存储的地址是否一致

//     //如果在栈内，则先申明某个变量， 在申明某个变量。则会满足一定的关系，保证程序稳定性 如先申明intx  在申明y
//     std::cout << (r < q) <<std::endl;
// }******************************************

//##########################void*指针###########################################
// #include <iostream>



// void fun(void* param) //传如一个指针并不关注他的具体类型
// {

// }
// int main()
// {
//     int x = 42;

//     int* r = nullptr; //int* 在64为的系统上大小为8个字节******************************************
//     char* k = nullptr;   //char* 在64也为8个字节
//     fun(r);
//     fun(k);
// }
// /*

//     int* , char*, void* 的尺寸（指在内存序列存长度）是一样的， int 和 char的尺寸是不一样的
//     但是由于他们都变成了指针，所以指针的长度是一样的！！！！！ 所以可以进行转换了。
//     注意：void是没有尺寸信息的，这个时候trick一些事情
// */

//void* 指针第2部分#
// #include <iostream>

// void fun(void* param)
// {
//     param = param + 1; //这是一个非法操作，移动了param之后，到底指向了什么？？？
//     std::cout << (param + 1) << std::endl;   //非法操作
// };

// int main()
// { 
//     int x = 42;
    
//     int* r = &x;
//     std::cout << r << std::endl; //r指x的原始地址
//     std::cout << &*r << std::endl;// 地址是一样的，是原始r的地址
//     std::cout << &r << std::endl;// &r取的是，指针开辟内存存入地址后，是开辟内存序列的地址。而不是原始地址
//     fun(r);
// }

///############指针的指针############################################
// #include <iostream>

// int main()
// {
//     int x = 42;
//     int* A = &x;
//     int** p = &A;


//     std::cout << "数据原始的内存地址: " << &x << std::endl; 
//     std::cout << "指针开辟的内存地址: " << &A << std::endl;
//     std::cout << "指针的指针内存地址: " << &p << "\n" << std::endl;

//     std::cout << "指针存储的原始地址: " << &*A << std::endl;
//     std::cout << "指针的指针原始地址: " << &**p << std::endl;

//     std::cout << "指针的指针指向内存空间: " << &p << "-->" << &A << "-->" << &x << "\n" << std::endl;
//     std::cout << "指针的解引用" << **p << " " << *A << " " << x << "\n";
// }

//#################直接引用和指针间接引用################################
// #include <iostream>

// int mai()
// {
//     int x = 42;
//     x; //对 x直接引用

//     int* r = &x;
//     r; //指针对象的间接引用。好处，能减少传输所付出的成本。 
// }
//################################   这里重点关注：#################################
// #include <iostream>

// void fun(int param)
// {
//     param = param + 1;
// };

// int main()
// {
//     int x = 3; //c语言的传值，调用这个函数，但是不会改变我这个输入参数的值。故称“传值”
//     fun(x);   这里重点关注：
//     std::cout << x <<"\n";
// } //result 3

//如果要改变这个传入的值，这里就变成传址
// #include <iostream>

// void fun(int* param)
// {
//     *param = *param +1; //*param解引用加入 内存地址的实际值
// };

// int main()
// {
//     int x = 3;
//     int* p = &x;
//     fun(p);
//     std::cout << x << std::endl;
// }

// #include <iostream>

// void fun(int* param)
// {
//     param = param + 1;
// };

// int main()
// {
//     int x = 3;
//     int* p = &x;

//     int* p1 = nullptr; //非法操作
//     fun(p1); //这个时候行为是不可控的
// }

//引用解决指针为空的问题
// #include <iostream>

// int main()
// {
//     int x = 3;
//     // int* p = 3;//3是是一个字面值，指针是没有字面值的，因为字面值没有地址。 引用也是一样的
//     // int& ref = 3; //因为3是字面值，无法绑定到3，因为没有地址
//     int& ref = x; //&这个符号，，有不同的含义 *p:解引用， int* p:p这个指针。引用只能有一层含义：改变绑定对象地址的内容


//     int* ptr = &x;

//     int y = 0;
//     *ptr = y; //解引用x的值，然后将y的值赋给x 改变了ptr地址内存中所指向地址的内容
//     ptr = &y;//ptr原来的地址是和x绑定的，这里强行将ptr的地址与y的地址进行了绑定， 这里改变了ptr的原地址所指向的内存位置，换成了y的地址内容

//     std::cout << ref << "\n";//ref是3的别名，相当于我要输出x的值是什么！
//     ref = ref + 1;          //把ref的值+1赋值给新的ref。ref是x的别名。 相当于把x的值拿出来给x的值+1，赋予新的x
//     std::cout << x << "\n"; //结果是4
// }

// #include <iostream>

// int main()
// {
//     int x = 3;
//     //int& ref; 这样取是错误的只有在构造时，才能绑定对象！如下才是正确的。 不能绑定字面值，int& ref 是和地址相关的
//     int& ref = x;

//     int y = 0;
//     ref = y;

//     int* ptr;
// }

//非法引用
// #include <iostream>



// int& fun()
// {
//     int x; 
//     return x; //通过引用的方式返回的,在生命周期被销毁了,x就不存在了！
// };//{}为x的生命周期

// int main()
// {
//     int& res = fun(); //res引用指向的是一个被销毁的对象x，所以这里是非法引用！！！ 会报错

// #include <iostream>

// viod fun(int* ptr)// int* ptr这里有可能会指向非法指针。因为指针存在的缺点就是会有空指针或是指向的地址对象是非法的
// {

// };

// void fun(int& ptr) //ptr大概率会指向一个合法的对象。 因为引用必定是有地址和对象的的，不存在空引用，但存在非法引用
// {

// };

// int main()
// {
//     int& res =fun();
// }

//#############类型信息从左向右解析#######################################################
// #include <iostream>

// int main()
// {
//     int x = 3;
//     int* ptr = &x;

//     int*& ref = ptr; 
//     //我们构造指针ptr的引用 ，这里就是引用 哈！就是指针到引用
//     /*按照从右到左去解析这个申明，
//     int*& 和ref 俩部分--> int*&: 一个int指针的申明。ref：ref绑定到了int*这个地址上
//     类型信息从左向右解析*/
// }

// #include <iostream>

// int main()
// {
//     int x = 3;
//     int& ref = x;

//     int& & ref2 =ref; //引用的引用，这种是错误的。更具c++语法，把指针作为对象，但未对引用作为一个对象
//     int&& ref2 = ref; //&&表示右之引用，但是不能有引用来作为对象表示
// }
