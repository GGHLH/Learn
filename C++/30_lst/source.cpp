#include  <iostream>
int array[4] = {1, 2, 3, 4};
/*为什么会产生隐式转换
一个数组和一个指针，通常情况下是混用的，但是数组里通常会包含元素的长度，
纵观这个信息（4）是最不重要的*/

void  fun()
{
    std::cout << array << std::endl;
}