#include <iostream>
#include <cmath>
#include <string>

// 常量的定义
#define INT_MAX 59964

// 通过限定符来定义常量
const int MONTHS = 12;

// 无符号类型的定义
//      一般整型不能存储负数值的无符号变体，其优点是可以增大变量能够存储的最大值，例如short表示范围为-32768到+32767
//      则无符号版本的表示范围为0-65535，当然，仅当数值不会为负时才应使用无符号类型，如入口，微粒
unsigned int rovert;

using namespace std;

double test(double i){
    double x = sqrt(i);
    return x;
}

void forcedTypeConversion(int i){
    // 强制类型转换
    char y = (char) i;
    char x = char(i);
}

void useString(string i){
    cout << i.append("str") << endl;
}

// 结构的使用
struct person{
    string name;
    int age;
};

// 定义结构体时创建结构体变量以及赋值
struct student{
    string name;
} ky = {"ky"};

// 定义没有名称的结构体同时定义变量
struct {
    string name;
} brid;

// 定义结构体变量时可以省略结构体关键字struct
struct person p = {"str", 18};
person person1;

// 结构体中的位字段
//  C++也允许指定占用特定位数的结构成员，这使得创建与某个硬件设备上的寄存器对应的数据结构非常方便。
//  字段的类型应为整型或枚举，接下来是冒号，冒号后面是一个数字，它指定了使用的位数。可以使用没有名称的字段来提供间距
//  每个成员都被称为位字段（bit field）
// 位字段通常用在低级编程中
struct torgle_register{
    unsigned int SN : 4;
    unsigned int : 4;
    bool goodIn: 1;
    bool goodTorgle: 1;
};

// 共用体union
//      共用体是一种数据格式，它能够存储不同的数据类型，但只能同时存储其中的一种类型。
//          结构体可以同时存储int、long和double
//          共用体只能存储int、long或double,条件是在不同的时间进行
//      用于共用体每次只能存储一个值，因此它必须有足够的空间来存储最大的成员，所以，共用体的长度为其最大成员的长度
//  共用体的用途:当数据项使用两种或更多格式（但不会同时使用）时，可节省空间。
//          例如，假设管理一个小商品目录，其中有一些商品的ID为整数，而另一些ID为字符串，这种情况下可以使用共用体
union one4all{
    int int_val;
    int long long_val;
    double double_val;
};

//  匿名共用体anonymous union没有名称
//  其成员位于相同地址处的变量。每次只有一个成员是当前的成员
struct widget{
    char brand[20];
    int type;
    union {
        long id_num;
        char id_char[20];
    };
};

int main() {
    // 命名空间的使用
    std::cout << "Hello, World!" << std::endl;
    cout << "Hello, My Girls" << endl;
    double x = sqrt(9);
    cout << x << endl;
    cout << p.name << endl;
    cout << ky.name << endl;
    return 0;
}
