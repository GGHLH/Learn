#include <iostream>
#include <vector>
#include <utility>
struct Str
{ 
    int x5;
};

void fun(std::vector<int>&&  par) //&& 是右值引用. fun函数接受名为:par的参数
{

};

void fun1(const int& par) //const int& 应用表明绑定了一个对象
{

};

int main()
{
    // int x  = 3; //x =3 进行了初始化,  = 不是运算符
    // x = 3;//没有封号是表达式,加了封号是语句

    // int{}; //构造一个随机对象,缺省初始化.用于操作符的操作数,初始化,认为是pvalue
    // Str{}; //构造一个随机对象,缺省初始化


    std::vector<int> x;//再运行期动态改变数组的大小,保存相应的数据 <--左值glvalue;
    fun(std::move(x));                                    //<--右值prvalue;
    /*
    1. std::move() --> c++的标准函数, 使用std::vector<int> x 构造std::move(x)的值.
    std::vector<int> x 是glvalue

    2. std::move(x) -->将std::vector<int> x 中的x转为将亡值(expiring).

    3.将亡值(expiring) 利用std::move(x)去调用fun函数,即将std::move(x)的信息传递给par,
    由于std::move(x)是一个prvalue引用(将亡值),表明后续在main中我不会再对x中包含的资源进行任何处理

    */


    //c++语言:左值和右边不一定都放在等号左边或右边;
    //1.左值
    const int x1 = 3;

    //2.右值, 右值放在等号左边
    int x2 = int();//int() aand int {} 代表一个纯右值
    Str() = Str();//等号左边Str()作为初始化的接受者,是prvalue

    //左值转为右值
    int x3 = 3;
    int y3;
    y3 = x3;//此时x作为操作符(=)的操作数

    int x4 = 3;
    int y4 = x3;
    x4 + y4; // + 接受右值(y4)作为输入, 右值作为+法的操作数进行使用. x4左值
    /**
    我们需要一个右值,但是我恶魔年传入了一个左值(✖4), x + y 进行求值后指向的是地址的内存那块区域
    我们在表达式某个地方需要的是右值,但是我们可以提供相应的左值,因为编译器会把他进行处理当作右值来处理
     */


    //临时具体化  pralue -->xvalue
    /*
    Str().x5:中
    Str()纯右值,第一个子表达式;x为第二个子表达式, .为操作符
    表示从我的表达式中对应的内存(x5)中取出特定一部分;
    原先是纯右值,有了.操作后需要关注内部的存储结构,怎么取出/这个时候将Str()视作一个将亡值,一个
    将亡值,属于泛左值.然后才可以去看.x5中的内容. 即将纯右值--->将亡值
    */
    Str().x5;


    /*
    将这个3转为了临时将亡值, 在fun1()中const int& 就可以绑定到这个将亡值上  重点<---------------------------------
    */
    fun1(3);//这里3是一个纯右值,不会被认为绑定了一个对象
    

    //再论decltype
    //根据cpp.reference中的定义decltype()作为表达式,
    //情况一: 如果表达式为纯右值 ,为T
    //情况二: 如果表达式为左值,为T&
    //情况一: 如果表达式为将亡值 ,为T&&

    decltype(3) x6;  //result --> int 3;
    
   
    int x7;         //glvalue
    decltype((x7)) y6 = x7; //result --> int& y6;

    int x8;
    decltype(std::move(x8)) y7 = std::move((x8));//result --> int&& y7 = std::move((x8));
    //y是右值引用,不能绑定到左值,即decltype(std::move(x8)) y7 = x;
  
    
   




}