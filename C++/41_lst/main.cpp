#include <iostream>
#include <cmath>

int main()
{
    //关系操作符 接受算术或指针类型操作数
    std::cout << (5 < 3) << std::endl;
    std::cout << (4 > 2) << std::endl;

    int a[3]; 
    auto ptr1 = std::begin(a); 
    auto ptr2 = std::end(a);
    ptr1 != ptr2;


    //逻辑操作符接受可转换为bool值的操作数
    int x = 3;
    3 && x; //left是个字面值, 右边是个对象.都可以转换为bool value.

    //除逻辑非外,其他操作符都是左结合的

    /*
    a && b &&c   <--- 逻辑 与 左给值
    !(...) 非操作符后面包含了一系列表达式,包含了一些复杂的效果,即先对这个表达式内部求值,然后再和非结合
                 <--- 逻辑 非
    */

    //逻辑与,逻辑或具有短路特性;
    int* ptr3 = nullptr;  
    if(ptr3 && (*ptr3 == 3))
    /*判断ptr是否指向空,若为空ptr3 会转化为False 
    若果ptr3为空指针，为空，则会不对(*ptr3 == 3)进行处理，系统直接跳出if
    如果ptr3指向的是非空的内存的话，则进行处理(*ptr3 == 3)
    短路逻辑：
            先执行第一个，如不满足执行第二个，直接返回，保证程序是可控制的*/
    {

    }
      
    //逻辑操作符的左结合特性；
    /* 
    a && b && c; <-- 符合左结合特性,先a与b,在与上c
    */ 
       
   //逻辑与的优先级高于逻辑或
   /*
   a && b || c; <-- 先计算逻辑与&&，再计算逻辑或
   a || b && c; <-- 先计算逻辑与&&，再计算逻辑或
   */
 
  //不能将多个关系操作符串联
  int a1= 3;
  int b = 4;
  int c = 5;
  std::cout << "operation>: " <<(c > b > a1) << std::endl;//这样的代码错误,不建议这样写
  std::cout << "operation==: " << (a1 == b == c) << std::endl; //这样的代码错误,不建议这样写
  /*
  c > b > a1 --> true a1;
  true > a1 --> 这里发现a1 是 int，即有true自动转化为int变为1
  1 > a1 ,则返回的结果false
  a1 == b == c  --> true == c --> 1 == 5 Result: 0  
  */

 std::cout << "correct: " << ((c > b) && (b > a1)) << std::endl;

  int a11 = 3;
  int b1 = 3;
  int c1 = 3;
  std::cout << "corrcet: " << ((a11 == b1) && (b1 == c1)) << std::endl;


  // 不要写出 val==true 这样的代码
  int a12 = 3;
  //if (a == true)
  int a13 = 5;
  int b13 = 6;
  if (a12) //a12为表达式，如果这个表达式为真，即a不等于0，则执行这个逻辑
  {
     
  }

  // C++ 20关系操作符<=>
  /*下面这种操作会导致程序的性能变慢，所以我们用spaceship方法<=>
    返回的是-1， 0， 1。不是布尔值，而是俩个对象的关系
  auto res = (a13 <=> b13);
  if (res > 0)
  {v 
 
  }
  else if (res < 0)
  {   
  }
  else if(res == 0)
  {

  }*/

  //根号
  std::cout << "sqrt: " << sqrt(-1) << std::endl;
}  