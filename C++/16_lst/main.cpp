#include <iostream>

// struct Point
// {
//     int x;
//     int y;
// };

// Point fun(Point p) //  1.as function input parameters
// {
//     p.x = p.x + 1;
//     return p;  //      2.as function return value
// }

// int main()
// {
//     Point p; //访问结构体里的消息
//     p.x = 3;
//     p.y = 5;
//     p = fun(p);
//     std::cout << p.x << " " << p.y << "\n";

// }

struct Point
{
    int x;
    int y;
    void IncX()  //       3.把函数放入结构体内部，表示这个函数和结体息息相关，体现更好的结构性
    {
        x = x + 1;
    }
};



int main()
{
    Point p; //访问结构体里的消息
    p.x = 3;
    p.y = 5;
    p.IncX();
    std::cout << p.x << " " << p.y << "\n";

}