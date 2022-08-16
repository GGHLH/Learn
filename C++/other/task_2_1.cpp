#include<iostream>
#include<memory>
#include<assert.h>
#include<stdlib.h>
#include<string.h>
using namespace std;

class Matrix{
    public:
        Matrix(int row, int col);   //构造函数
        Matrix(int row, int col, int num);//构造函数重载
        ~Matrix();                  //析构函数
        Matrix(const Matrix & other); //赋值函数
        Matrix operator*(const Matrix& other);      //矩阵相乘
        Matrix operator+(const Matrix& other);      //矩阵相加
        Matrix operator-(const Matrix& other);      //矩阵相减
        int **a = nullptr;          //初始化一共空指针
        int row, col;
        void shape();               //打印矩阵形状
        void Ma_pri();              //打印矩阵
};

int main(){
    std::cout << " Creat Matrix a:"  << std::endl;
    Matrix a(2,1);      //构造一个（2,1）矩阵
    Matrix b(1,2);      //构造一个（1，2）矩阵`
    a.a[0][0] = 4;      //初始化矩阵
    a.a[1][0] = 2;
    b.a[0][0] = 3;
    b.a[0][1] = 5;
    a.shape();          //矩阵形状打印
    b.shape();
    Matrix c = a*b;     //矩阵相乘
    c.shape();
    c.Ma_pri();         //矩阵打印
    Matrix d(3,3,1);
    d.Ma_pri();
    system("pause");
    return 0;
}


Matrix::Matrix(int row, int col){
    this->row = row;
    this->col = col;
    this->a = new int*[row];
    for(int i=0;i<this->row;i++){
        a[i] = new int[this->col];
    }
}


Matrix::Matrix(int row, int col, int num){
    this->row = row;
    this->col = col;
    this->a = new int*[row];
    for(int i=0;i<this->row;i++){
        a[i] = new int[this->col];
    }
    for(int i = 0; i < this->row; i++){
        for(int j =0; j <this->row; j++){
            this->a[i][j] = num;
        }
    }
}



Matrix::~Matrix(){
    for(int i=0;i<this->row;i++){
        if(a[i] != nullptr){
            delete[] a[i];
            a[i] = nullptr;
        }
    }
    if(a != nullptr){
        delete[] a;
        a = nullptr;
    }
}

Matrix::Matrix(const Matrix& other){
    row = other.row;
    col = other.col;
    a = new int*[row];
    for(int i=0;i<row;i++){
        a[i] = new int[col];
        memcpy(a[i], other.a[i],sizeof(int)*col);
    }
}

/*矩阵相乘*/
Matrix Matrix::operator*(const Matrix& other){
    if(this->col != other.row){
        cout<<"shape error"<<endl;
        exit(0);
    }
    Matrix m(this->row,other.col);
    for(int i=0; i<this->row; i++){
        for(int j=0;j<other.col;j++){
            int sum = 0;
            for(int k=0;k<this->col;k++){
                sum += this->a[i][k] * other.a[k][j];
            }
            m.a[i][j] = sum;
        }
    }
    return m;
}
/*矩阵相加*/
Matrix Matrix::operator+(const Matrix& other){
    if(this->col != other.col or this->row != other.row){
        cout<<"shape error"<<endl;
        exit(0);
    }
    Matrix m(this->row,this->col);
    for(int i = 0;i < this->row; i++){
        for(int j = 0; j < this-> col; j++){
            m.a[i][j] = this->a[i][j] + other.a[i][j];
        }
    }
    return m;
}
/*矩阵相减*/
Matrix Matrix::operator-(const Matrix& other){
    if(this->col != other.col or this->row != other.row){
        cout<<"shape error"<<endl;
        exit(0);
    }
    Matrix m(this->row,this->col);
    for(int i = 0;i < this->row; i++){
        for(int j = 0; j < this-> col; j++){
            m.a[i][j] = this->a[i][j] - other.a[i][j];
        }
    }
    return m;
}
/*打印矩阵行列*/
void Matrix::shape(){
    cout<<"显示矩阵行列shape: "<< a << "\n" << "("<<this->row<<","<<this->col<<")"<<endl;
}

void Matrix::Ma_pri(){
    for(int i = 0; i < this->row; i++){
        for(int j =0; j <this->row; j++){
            cout<<this->a[i][j]<<" ";
        }
        cout<<"++"<<endl;
    }
}
