// #include <iostream>
// #include <type_traits>

// int main()
// {
//     int x1[3];

//     /*如何看待这个array:
//     int x2[3][4] -->x2[3] --x2是个数组，这个数组包含了三个元素；
//                  -->x2[3][4] 这个三个元素时 int [4]的类型
//                  -->x2是一个数组，其中x2的任意一个元素又是数组。不要理解为x2是一个数组，包含了四个元素，每个元素是int[3]
//     */
//     int x2[3][4]; //many dim arry ，total 12  int element；
//     int x3[3][4][5];// x3[3]的类型 -->int[4][5]型 <-- int[4][5],一个二维数组包含了4个元素，类型是int[5].
// }

// //数值左值时的表达
// #include <iostream>
// #include <type_traits>

// int main()
// {
//     int x1[3];

//     int x2[3][4];
// // x2[0];// int[4]
// std::cout << sizeof(int) << std::endl;
// std::cout << sizeof(x2[0]) << std::endl;
// std::cout << std::is_same<decltype(x2[0]), int(&)[4]>::value << std::endl;//注意x2[0]为一个表达式。 如果表达式是一个左值，比较改为地址.x2[0]的类型是int&[4]地址的引用

// }


// //int x2[3][4]在内存中的布局
// #include <iostream>
// #include <type_traits>

// int main()
// {
//     int x1[3];

//     int x2[3][4];
//     x2[0];//int[4]
//     /*int[4]在内存中的布局 --> int int int int;
//                     x2[1]-->* int int int int;
//                     x2[2]-->* int int int int;
//                     x2[3]-->* int int int int;
//     数组的含义，表示这些元素连续且有序趋近的放在一起。这样看的化：
//     int int int int int int int int int int int int
//     将他们每4个看成一堆：
//     (int int int int) (int int int int) (int int int int)  <-- row:行优先
//     */

//    int x3[4][3];
//    /*
//     在内存里的布局：
//     三个看成一堆
//     (int int int) (int int int) (int int int) (int int int)

//     */
// }

// //多维数组的聚合初始化{}, {}
// #include <iostream>
// #include <type_traits>

// int main()
// {
//     int x1[3][4]= {1, 2, 3, 4};
//     //(int int int int) (int int int int) (int int int int) 

//     int x2[4][4]= {1, 2, 3, 4, 5};
//     //(int int int int) (int int int) int (int int int int) (int int int int) (0 , 0 , 0, 0)
    
//     int x3[3][4]={
//         {1, 2, 3, 4},
//         {5, 6, 7, 8},
//     };

// }


// //多维数组的聚合初始化的变形{}, {{}}
// #include <iostream>
// #include <type_traits>

// int main()
// {
//     int x2[3][4]= {1, 2, 3, 4};
//     //下面为聚合初始化{{}}能更好的说明为那个元素初始化；
//     int x3[3][4]={
//         {1, 2, 3, 4},
//         {5, 6, 7}, //缺少，系统会自动补充为0
//     };

//     std::cout << x3[1][3] << std::endl;

//     // int a[][] = {1, 2, 3, 4};报错无法编译
//     int a[][3] = {1, 2, 3, 4};
//     /*{{1, 2, 3},
//        {4, 0, 0}
//     */ //type --> int[2][3]

//     std::cout << sizeof(a) <<std::endl;
//     std::cout <<std::is_same<decltype(a), int[2][3]>::value << std::endl;

// }


// //多维数组的聚合初始化的变形{}, {{}} 情况2 建议写法
// #include <iostream>
// #include <type_traits>

// int main()
// {
//     int x2[3][4]= {1, 2, 3, 4};
//     //下面为聚合初始化{{}}能更好的说明为那个元素初始化；
//     int x3[][4]={{1, 2, 3, 4},{5, 6, 7}, };
//     /*
//     {{1, 2, 3, 4},
//      {5, 6 ,7, 0}
//     }
//     */

//     std::cout <<std::is_same<decltype(x3), int[2][4]>::value << std::endl;
// }
//##############2.多维数组的索引与遍历############################################
#include <iostream>
#include <type_traits>  

int main()
{
    int x2[3][4];   
    /*{
    {1, 2 ,3, 4},
    {0, 0, 0, 0}
    {0, 0, 0, 0}
    }*/
    //use range-based for
    for (auto& p: x2 ) //p是x2中任意一个元素的遍历,p是每个元素的一个数组
    {
        for(auto q : p)//遍历p中的每个元素,q就是一个数据
        {
            std::cout <<  q << std::endl;
        }

    }
}


//针对多维数组 for 循环
// #include <iostream>
// #include <type_traits>  

// int main()
// {
//     int x2[3][4][5] = {1, 2, 3, 4, 5};
//     /*{{
//     {1, 2 ,3, 4, 5},
//     {0, 0, 0, 0, 0},
//     {0, 0, 0, 0, 0},
//     {0, 0, 0, 0, 0}
//     }}*/
//     //use range-based for
//     for (auto& p: x2 ) //p是x2中任意一个元素的遍历,p是每个元素的一个数组
//     {
//         for(auto& q: p)
//         {
//             for(auto z : q)
//             {
//                 std::cout << "z: " << z << std::endl;
//             }
//         }

//     }
 
// }


// //针对多维数组 while 循环 1
// #include <iostream>
// #include <type_traits>  

// int main()
// {
//     int x2[3][4] = {1, 2, 3, 4, 5};
//     /*{
//     {1, 2 ,3, 4},
//     {5, 0, 0, 0},
//     {0, 0, 0, 0,
//     {0, 0, 0, 0}
//     }*/
//     //use while
//     size_t index0 = 0; //定义一个行索引,从零开始
//     while (index0 < 3) // clow
//     {
//         size_t index1 = 0;//定义一个列索引,从零开始
//         while(index1 < 4) //row
//         {
//             std::cout << x2[index0][index1] << std::endl;
//             index1 = index1 + 1;
//         }
//         index0 = index0 + 1;

//     }
// }



// //针对多维数组 while 循环 1_1
// #include <iostream>
// #include <type_traits>  

// int main()
// {
//     int x2[3][4] = {1, 2, 3, 4, 5};
//     /*{
//     {1, 2 ,3, 4},
//     {5, 0, 0, 0},
//     {0, 0, 0, 0,
//     {0, 0, 0, 0}
//     }*/
//     //use while
//     size_t index0 = 0; //定义一个行索引,从零开始
//     while (index0 < std::cend(x2)- std::cbegin(x2)) // clow
//     {
//         size_t index1 = 0;//定义一个列索引,从零开始
//         while(index1 < 4) //row
//         {
//             std::cout << x2[index0][index1] << std::endl;
//             index1 = index1 + 1;
//         }
//         index0 = index0 + 1;

//     }
// }



// //针对多维数组 while 循环 1_2
// #include <iostream>
// #include <type_traits>  

// int main()
// {
//     int x2[3][4] = {1, 2, 3, 4, 5};
//     /*{
//     {1, 2 ,3, 4},
//     {5, 0, 0, 0},
//     {0, 0, 0, 0,
//     {0, 0, 0, 0}
//     }*/
//     size_t index1 = 0;
//     //use while
//     while (index1 < 4) // clow
//     {
//         size_t index0 =0;
//         index0 = 0;//在每一次外部循环的时候,把index1置0

//         while(index0 < 3) //row
//         {
//             std::cout << x2[index0][index1] << std::endl;
//             index0 = index0 + 1;
//         }
//         index1 = index1 + 1;

//     }
// }
// //int x2[3][4] = {1, 2, 3, 4, 5};
//                 /*00          10
//                      01       11 
//                         02    12 
//                            03 13
//                 */
// //#遍历方式成了4行3列,先低位,后高为
// //             先返回00 --> 01;
// //                  01 --> 11;
// //                  02 --> 12;
// //                  03 --> 13;

// // Result --> {
// //             {1, 5, 0, 2},  x[0][0~4] 先行 后列
// //             {0, 0, 3, 0},  x[1][0~4]
// //             {0, 4, 0, 0},  x[2][0~4]
// //            }
// // Result --> 不要这种做法 低为 高位置 就是本次的方法会占大量内存到cash的东西
// //                            x[0~2][0] 先行后列   
// //                            x[0~2][1]
// //                            x[0~2][2]
// //                            x[0~2][3]



//################################3.指针与多维数组###################################
//多维数组可以隐式的转换为指针, 只会发生在最高维,其他维度的信息被保留;
// #include <iostream>
// #include <type_traits>

// int main()
// {
//     int x2[3][4] = {1, 2, 3, 4, 5};
//     auto ptr = x2;// int (*ptr)[4] = x2; 把最高纬度x2[3][4]中的[3]给丢掉了,保留了其他维度的信息 int (*ptr)[4] 保存了[4]
//     //x2[1]-->*(x2 + 1)将x2]转化为指针,接着解引用.x移动一个位置,绝对不是一个int型length而是x移动一个int型包含4个元素的数组
//     std::cout << *(x2 + 1) << std::endl;
// }

// //使用类型别名来简化多维数组指针的声明;
// #include <iostream>
// #include <type_traits>

// int main()
// {
//     int x2[3][4] = {1, 2, 3, 4, 5};
//     auto ptr = x2;

// }


//  //使用指针来遍历多维数组
// #include <iostream>
// #include <type_traits>



// int main()
// {
//     int x2[3][4]={} ;
// 	auto ptr = std::begin(x2);
// 	while(ptr != std::end(x2))
//           {
//       		auto ptr2 = std::begin(*ptr);
//       		while(ptr2 != std::end(*ptr))
//             {
//               std::cout << *ptr2 << std::endl;
//               ptr2 = ptr2 + 1;
//             }
      	
//             ptr = ptr + 1;
//           }

// }