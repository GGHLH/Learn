// #include <iostream>
// #include <vector> //类模板



// //vector更加侧重于易用性;
// int main()
// {   
//     // int a[3];
//     // int b[3] = a; // 数组不支持复制.但是Vector支持
//     std::vector<int> x;//vector<int>是x的类型
//     std::vector<int> y;
//     y = x;
// }



// #include <iostream>
// #include <vector> //类模板
// int main()
// {   
//     int a[3];//缺省初始化为随机值
//     std::vector<int> x; //缺省初始化，变为0个元素

// }

// #include <iostream>
// #include <vector> //类模板
// //vector聚合初始化;
// int main()
// {   
//     int a[3]= {1, 2, 3};
//     std::vector<int> x = {1, 2, 3 }; 

// }


// #include <iostream>
// #include <vector> //类模板

// int main()
// {   
//     int a[3]= {1, 2, 3};
//     std::vector<int> x1(3,1);//vector中包含了三个元素，每个元素都是1 
//     std::vector<int> x2 = {1, 1, 1};//vector中包含了三个元素，每个元素都是1 
// }


// //C++设计没有考虑到的一个问题

// #include <iostream>
// #include <vector> //类模板

// int main()
// {   

//     std::vector<int> x1{3,1}; //大括号表示我有2个元素 第一个是3 ，第二个是1
//     std::vector<int> x1(3,1);//vector中包含了三个元素，每个元素都是1 
//     std::vector<int> x2 = {1, 1, 1}; 

// }

//##########################2.获取元素个数,判断是否为空##################################
// #include <iostream>
// #include <vector> //类模板

// int main()
// {   

//     std::vector<int> x1{3,1}; //大括号表示我有2个元素 第一个是3 ，第二个是1
//     std::cout << "x1_elements: " <<x1.size() << std::endl; // 调用x1.size()的方法，会返回 x1元素的个数
//     /*
//     .表示这个size位于x1这个类模板中定义的函数；

      
//      */
//     std::vector<int> x2(3,1);//vector中包含了三个元素，每个元素都是1 
//     std::cout << "x2_elements: " << x2.size() << std::endl;

//     std::vector<int> x3 = {1, 1, 1}; 
//     std::cout << "x3_elements: " << x3.size() << std::endl;

//     //判断对象是否为空
//     std::cout << "x1_empty: " <<x1.empty() << std::endl;//return bool value， if false ——> elemets  , true --> no elemets

//     //添加元素，动态改变元素个数
//     std::vector<int> x4;
//     x4.push_back(2);//push_back添加元素，在运行期间执行。 表示最后结尾插入一个元素
//     std::cout << "x4_elements: "<<x4.size() << std::endl;
//     std::cout << "x4_empty: " << x4.empty() << std::endl;

//     //删除元素，动态改变元素个数
//     std::vector<int> x5= {1, 2, 3, 4, 6};
//     x5.pop_back();//pop指弹出这个元素，back表示把数组最后一个元素弹出来
//     std::cout << "x5_elements: "<<x5.size() << std::endl;
//     std::cout << "x5_empty: " << x5.empty() << std::endl;

//     //vector的比较
//     /*
//         vector是按照字典去进行比较的，比较vector中俩个的第一个元素，相同，比较下一个
//     */
//     std::vector<int> x6= {1, 2, 3, 4, 6};
//     std::vector<int> x7= {1, 6, 8, 9, 11};
//     std::cout << "++++++++++++++++++++++++" << std::endl;
//     std::cout << "x6x7_equal: "<< (x6 == x7) << std::endl;
//     std::cout << "x6x7_Result <: " << (x6 < x7) << std::endl;
//     std::cout << "x6x7_Result >: " << (x6 > x7 ) << std::endl;


//##########################3.vector中元素的索引和遍历  ##################################
// //index 1
// //vector用来模拟数组
// #include <iostream>
// #include <vector>

// int main()
// {
//     int a[3] = {1, 2, 3};
//     std::vector<int> x1 = {1, 2, 3};
//     std::cout << "x1[2]_value function: "<< x1[2] << std::endl;
//     //是用.at()防止越界
//     std::cout << "x1.at(2)_value function: " <<x1.at(2) << std::endl;


//     //获取指针 begin 和 end的函数 用法
//     std::begin(a);//指向a中的第一个元素
//     std::end(a);//获取a中的最后一个元素
//     std::begin(x1); //使用来获取一个‘东西’，来指向x1中的第一个元素  <-- 注意这里的东西
//     auto b = std::begin(x1);
//     auto c = std::end(x1);//指向x1末尾的下一个元素


//     //获取指针 begin 和 end的method 用法
//     auto b  = x1.begin();
//     auto b  = x1.end();iterator
// }


// //index 2
// //vector循环遍历 使用 begin() and end() method
// #include <iostream>
// #include <vector>

// int main()
// {    //是用.at()防止越界
//     int a[3] = {1, 2, 3};
//     std::vector<int> x1 = {1, 2, 3};
//     std::cout << "x1[2]_value function: "<< x1[2] << std::endl;
//     std::cout << "x1.at(2)_value function: " <<x1.at(2) << std::endl;
//     //use range-based for
//     for(auto val : a)
//     {
//         std::cout << "range-based for x1_value: " << val << std::endl; 
//     }

//     //获取指针 begin 和 end的函数 用法
//     std::begin(a);//指向a中的第一个元素
//     std::end(a);//获取a中的最后一个元素
//     std::begin(x1); //使用来获取一个‘东西’，来指向x1中的第一个元素  <-- 注意这里的东西


//     //获取指针 begin 和 end的method 用法
//     auto b  = x1.begin();
//    //use while
//     while( b != x1.end())
//     {
//         std::cout << "use while -*b value: " << *b << std::endl;
//         b = b + 1;
//     }
// }


//解引用，获取元素值与下标志访问
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> x1 = {1, 2, 3};
    auto b = std::begin(x1);
    auto e = x1.end();
    std::cout << "push_back befor: "<< *b << "\n";
    std::cout << "push_back befor: "<< *e << "\n";
    std::cout << "(*b ): " << (*b ) << std::endl;
    std::cout << "(*b +1 ): " <<(*b + 1) << std::endl;
    std::cout << "b[1] similar equal (*b + 1): " << b[1] << std::endl;

    //移动
    b = b + 1;

    //2个迭代器相减求距离
    std::cout << "elements: " << std::end(x1) - std::begin(x1) << std::endl; //求有几个元素
    std::cout << "iter_1 -iter_2: " << e -b << std::endl;//俩个迭代器相减少。动态数组，只有地址，无长度

    //迭待器进行比较 注意：比较发生在同一个数组
    std::cout << "=?: " << (e == b) << "\n";
    std::cout << "<?: " << (e < b) << "\n";
    std::cout << ">?: " << (e > b) << "\n";

    //添加元素使得迭代器失效
    x1.push_back(4); //b 和 e可能就无效了
    std::cout << "push_back after: "<< *b << "\n";
    std::cout << "push_back after: "<< *e << "\n";

    //多维vector
    //这种方法构造多维的Vector比较复杂，推荐下一个聚合化的方式初始化
    int x2[3][4]= {};
    std::vector<std::vector<int>> x; //构造了一个二维vector
    x.push_back(std::vector<int>()); //构造一个vector的对象， push进去
    x[0].push_back(1);//x是一个二维vector，x[0]是一个维的vector。所以这里添加了一个元素1
    std::cout << x[0][0] << "\n";


    //聚合初始化多维数组
    //这种灵活性的代价就是导致程序的性能拖慢
    std::vector<std::vector<int>> x3{{1, 2, 3}, {4, 5, 6}};
    std::cout << "x3_value: " << x3.size() << " vector elements" << "\n";
    std::cout << "find elements: " << x3[0][1] << "\n";

    // 从. 到-> 操作符；
    std::vector<int> x4 = {1, 2, 3, 4};
    std::cout << "x4.size: " << x4.size() << "\n";
    std::vector<int>* ptr = &x4;//x4是一个对象。所以我们可以构造的他的指针,接下来，就可以用ptr指针访问x4地址内存
    std::cout << "*ptr: " << (*ptr).size() << "\n";//对ptr解引用，访问地址，，size()返回数组元素个数.

    //使用指针调用对象的方法 (*ptr).size() 这样会不友好 请看下面更好的方法
    //语法糖 ->
    //特点箭头左边一定是指针
    std::cout << "->: " << ptr->size() << "\n"; //之间诶调用对象x4的方法；
}