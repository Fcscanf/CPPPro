#include <iostream>
#include <cmath>

int main() {
    // 命名空间的使用
    using namespace std;
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