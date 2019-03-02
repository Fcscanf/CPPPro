//
// Created by fcsca on 2019-02-16/0016.
//

#include "Mouh.h"
#include <string>

using namespace std;

// 定义命名空间
namespace Jack{
    double pail;
    int pal;
    struct Well{
        int name;
        int age;
    };
}

namespace Jill{
    double fetch;
    struct Hill{
        string name;
        int age;
    };
}

// 创建命名空间的别名
namespace J = Jill;

// 创建未命名的命名空间
namespace {
    int ice;
    int bandycoot;
}