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

int main() {
    // 命名空间的使用
    std::cout << "Hello, World!" << std::endl;
    cout << "Hello, My Girls" << endl;
    double x = sqrt(9);
    cout << x;
    return 0;
}

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