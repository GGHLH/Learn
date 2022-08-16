#include<iostream>


 
void fun(const char* pInfo, int /*pValue*/)  //int即无形参
{
    std::cout << pInfo << std::endl;
    return;
}


//#######################################
// int main()的2种形式                   
// int main(int argc, char* agec[])    
// {                                   
                                        
// }
//#####################################
int main()
{
    fun("H K", 0);
    fun("911", 1);
    return 0; // 0是返回给了操作系统同
}

