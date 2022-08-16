#include <iostream>


namespace NameSpace1
{
    void fun()
    {}
}

namespace NameSpace2
{
    void fun()
    {}
}


int main(){

    // NameSpace1::fun(); 使用域解析符调用

    // using namespace NameSpace1;
    // fun();  使用using语句的方法

    
    namespace ns1 = NameSpace1;
    ns1::fun();
}
