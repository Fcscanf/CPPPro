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