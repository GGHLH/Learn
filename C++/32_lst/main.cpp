// #include <iostream>

// int main()
// {
//     /*char str[] = "Hello"; / chart_type = char[6] .
//      第6个：就是null -terminated string < -- 以0结尾的字符串起。这是从c语言来的，c语言关注的时运行期间*/
//     char str[] = "Hello";  
//     auto ptr = str;//遍历时直到\0结束,会被隐式的增加,会有char[6], 如果指针没有\0就比较困难 

// }
//strlen来求数组的长度
#include <iostream>
#include <cstring>

int main()
{

    char str[] = {'H','e','l', 'l', 'o', '\0'}; //str_type char[5]
    // char str[] = "Hello"; // str_type char[6] 以\0结尾
    auto ptr = str;
    std::cout << strlen(str) << std::endl;
    std::cout << strlen(ptr) << std::endl;
    std::cout << *ptr << std::endl;

}