//std::string
#include <iostream>
#include <string> //类模板
int main()
{
  //初始化
  std::string x = " hellor world"; //string是一个数据结构， 定义于std的名词空间中 
  std::string y = x;
  y = y + " !"; //将赋值的语句后面加了空格和叹号

  //其他方法
  //判断
  std::string x1("have a good time");
  std::string x2("The word");
  std::cout << (x1 == x2) << std::endl;
  std::cout << (x1 < x2) << std::endl;
  std::cout << (x1 > x2) << std::endl;

  //赋值
  y = "New String";

  //拼接
  y = y + x;
  std::cout << y << "\n";//在运行期，改变强变形元素

  y = std::string("fish") + y + "Test";//构建临时变量，进行拼接
  std::cout << y << "\n";

  //index
  std::string x3 = "xxx11";
  std::cout << x3[2] << std::endl;

  //转为C字符串
  auto ptr = y.c_str();//y是sting这样一个抽象的字符串, c_str()代表C类型所支持的字符串 返回的是一个const char* T的指针
  std::cout << ptr << std::endl;
} 
