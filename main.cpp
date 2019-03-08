#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <cfloat>
#include "module1/Mouh.h"
#include "module2/Stock.h"
#include "module3/FcTime.h"
#include "module4/vector.h"
#include "module5/queue.h"
#include "module6_extends/tabtenn.h"
#include "module7_polymorphism/brass.h"
#include "module9_dynamic_memory_allocation_friend_inheritance/dma.h"
#include "module10_code_reuse/workermi.h"
// #include "module11_class_template/stacktp.h"
#include "module11_class_template/pointer_stack/stcktp.h"
#include "module11_class_template/arrry/arraytp.h"
#include "module11_class_template/multiple_type_parameters/pairs.h"
#include "module12_friend_class/tv.h"
#include "module13_nesting/template_nesting/queuetp.h"

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

// -----------------------------------结构体---------------------------------------

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

// ------------------------------共用体和匿名共用体-----------------------------------

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

// ------------------------------------枚举----------------------------------------

// 枚举类型
//  枚举量：默认情况下会将整数值赋值给枚举量，第一个枚举量为0，第二个枚举量为1···，通过指定的整数值覆盖默认值
enum spectrum{
    red, orange, yellow, green, blue, violet, indigo, ultraviolet
};

spectrum band;
int color = 3 + band;

// 设置枚举变量的值
// 可以使用赋值操作来显式地设置枚举量的值
enum bits{
    one = 1,
    two = 2,
    four = 4,
    eight = 8
};

// 指定的值必须是整数，也可以只显式地定义其中一些枚举量的值
// 这里first在默认情况下为0，后面没有被初始化的枚举变量的值将比其前面的枚举量大1，因此third的值为101
enum bigstep{
    first, second = 100, third
};

// 创建多个值相同的枚举量
// 其中zero和null都为0，one_c和umero_uno都为1
enum {
    zero, null = 0, one_c, numero_nuo = 1
};

// ----------------------------------指针-------------------------------------
void pointer(){
    int updates = 6;
    int * p_updates;
    p_updates = & updates;
    cout << "Value:updates = " << updates << endl;
    cout << "*p_updates = " << *p_updates << endl;
    cout << "Address:&updates = " << &updates << endl;
    cout << "p_updates = " << p_updates << endl;
    // 程序输出：
    //    Value:updates = 6
    //    *p_updates = 6
    //    Address:&updates = 0xffffcbd4
    //    p_updates = 0xffffcbd4
    // int变量updates和指针变量p_updates只不过是一枚硬币的两面。变量updates表示值，并使用&操作符来获得地址；
    // 而变量p_updates表示地址，并使用*操作符来取值，由于p_updates指向updates，因此*p_updates和updates
    // 完全等价。可以像使用int变量那样使用*p_updates。

    // 指针的定义-*号操作符两边的空格是可选的
    int *ptr;
    int* psr;
    // 每个指针变量的创建都需要一个*,下面的例子将创建一个指针p1和一个int变量p2
    int *p1, p2;

    // 使用new关键字为指针分配内存
    // 在C语言中可以使用库函数malloc()来分配内存，在C++中还有更好的方法——使用new操作符
    int *pt = new int;

    // 内存耗尽
    // 计算机可能会由于没有足够的内存而无法满足new的请求，在这种情况下，new将返回0,在C++中，值为0分指针
    // 被称为空指针null pointer，C++确保空值指针不会指向有效的数据，因此它常被用来表示操作符或函数失效，
    // 如果成功，将返回一个有用的指针。

    // 使用delete来释放内存
    //  当需要内存时，可以使用new来请求，这只是C++内存管理数据包中有魅力的一个方面。另一个方面是delete操作符，
    // 它使得在使用完内存后，能够将其归还给内存池，这是通向最有效地使用内存的关键一步。归还或释放free的内存可供
    // 程序的其他部分使用。使用delete时，后面要加上指向内存块的指针（这些内存块最初是用new分配的）
    // **注意：只能用delete来释放使用new分配的内存。不过对空指针使用DELETE是安全的。

    // 这将释放ps指向的内存，但不会删除指针ps的本身，例如，可以将ps重新指向另一个新分配的内存块，一定要配对
    // 地使用new和delete。否则程序将发生内存泄露memory leak，也就是说，被分配的内存再也无法使用了；如果
    // 内存泄露严重，则程序将由于不断寻找更多内存而终止
    int *p3 = new int;
    delete p3, pt;

    // 不要尝试释放已经释放的内存块，C++标准指出，这样做的结果将是不确定的，这意味着什么情况都可能发生。另外
    // 不能使用delete来释放声明变量所获得的内存；
    // int *p4 = new int;
    // delete p4;
    // delete p4;           //not ok now，不能重复释放已经释放的内存块
    // int jugs = 5;
    // int *p5 = &jugs;
    // delete p5;           //不能delete来释放声明变量所获得的内存；

    // **注意，使用delete的关键在于，将他用于new分配的内存，这并不意味着要使用用于new的指针，而是用于new的地址
    // 一般来说，不要创建两个指向同一个内存块的指针，因为这将增加错误地删除同一个内存块两次的可能性
    // int *p6 = new int;
    // int *p7 = p6;
    // delete = p6;

    // 使用new创建动态数组
    // 在C++中，创建动态数组很容易，只要将数组的元素类型和元素数目告诉new即可，必须在类型名后加上[]，其中包含元素数目
    int *psome = new int[10];
    // new操作符返回第一个元素的地址，在这个例子中，该地址被赋给指针psome，当程序结束后，应使用DELETE释放

    // 指针数组的使用
    psome[0] = 0;
    psome[1] = 2;
    psome[2] = 3;
    cout << "psome[0] = " << psome[0] << endl;
    cout << "psome[1] = " << psome[1] << endl;
    cout << "psome[2] = " << psome[2] << endl;
    // psome[0] = 0
    // psome[1] = 2
    // psome[2] = 3

    psome = psome + 1;
    cout << "psome[0] = " << psome[0] << endl;
    cout << "psome[1] = " << psome[1] << endl;
    // psome[0] = 2
    // psome[1] = 3

    // 指针返回到开始
    psome = psome - 1;
    // 不能修改数组名的值，但指针是变量，因此可以修改他们的值。将psome + 1的效果，表达式psome[0]现在指向的是
    // 数组的第二个值，因此将psome + 1导致它指向第二个元素而不是第一个。将它减一后，指针将指向原来的值

    // 在释放new创建的动态数组时，应使用另一种格式的delete，它能够指出所要释放的是一个数组
    // []会告诉程序，应释放整个数组，而不仅仅是指针指向的元素
    delete[] psome;

    // 使用new和delete时，应遵守以下规则：
    // 1、不要使用delete来释放不是new分配的内存
    // 2、不要使用delete释放同一个内存两次
    // 3、如果使用new []为数字分配内存，则应使用delete[]来释放
    // 4、如果使用new []为一个实体分配内存，则应使用delete来释放
    // 5、对空指针应用delete是安全的

    // 将指针变量加一后，其增加的值等于指向类型占用的字节数
    // stacks[1]可以看作是* (stacks + 1)，这意味着先计算第二个元素的地址，然后找到存储在那里的值。
    // 最后输出存储在那里的值。

    char flower[10]= "rose";
    cout << flower << endl;
    cout << &flower << endl;
}

// 动态结构
void structure(){

    struct things{
        int good;
        int bad;
    };

    things grubonse = {3, 453};
    things *pt = &grubonse;

    // 如果结构体标识符是结构名，则使用句点操作符
    // 如果标识符是指向结构的指针，则使用箭头操作符
    cout << "ps.good = " << pt->good << endl;
    cout << "ps.bad = " << pt->bad << endl;

    // 使用new创建结构体变量
    person *person2 = new person;
    person2->name = "fc";
    person2->age = 18;
    cout << "person2.name = " << person2->name << endl;
    cout << "person2.age = " << person2->age << endl;

    // 释放使用new创建的动态结构的空间
    delete person2;
}

void input(){
    string string1;
    // 将输入的字符串读入到变量中。不过该操作将忽略空格、换行和制表符
    cin >> string1;
    // 可以通过调用成员函数将返回下一个输入字符——包括空格、换行和制表符
    string1 = cin.get();

}

void fileoperation(string filename){
    // 文件写入相关操作
    ofstream outFile;
    outFile.open("info.txt");
    outFile << fixed;
    outFile << "Make and model" << endl;
    outFile << "Year" << endl;
    outFile.close();

    // 文件读取操作
    ifstream inFile;
    inFile.open(filename);
    if (!inFile.is_open()){
        cout << "Could not open the file" << filename << endl;
    }

    string value;
    inFile >> value;
    if (inFile.eof())
        cout << "End of file reached;" << endl;
    else if (inFile.fail())
        cout << "Input terminated by data mismatch." << endl;
    else
        cout << "Input terminated for unknown reason." << endl;

    inFile.close();

}

// 定义指针函数
// 指针函数声明时需要将*和函数名括起来，括号优先级比*操作符高，因此*fun (int)代表返回指针的函数，
// 而(*fun) (int)意味着fun是一个指向函数的指针
double pam(int);
double (*pf) (int);
// 指针函数的赋值,将pam函数的地址赋给pf，赋值函数和指针函数的返回值类型编写相同才能赋值
// pf = pam;
// 指针函数的调用
//double x = pam(3);
//double y = (*pf)(5);

// 内联函数
// 内联函数声明前加上关键字inline
// 内联函数占用内存大，但运行速度快
inline double square(double x){
    return x * x;
}

// 引用变量
// 使用类型标识符，int &指向int的引用,rodents和rats指向相同的值和内存单元
void referenceVariable(){
    int rats;
    //int *rodents = &rats;
    int & rodents = rats;
    rats = 10;
    cout << "rats Value is : " << rats << endl;
    cout << "rats Address is : " << &rats << endl;
    cout << "rats Value is : " << rodents << endl;
    cout << "rats Address is : " << &rodents << endl;
    // rats Value is : 10
    // rats Address is : 0xffffcbc4
    // rats Value is : 10
    // rats Address is : 0xffffcbc4
}

// 函数模板的定义
//template <class Any>
template <typename Any>
void Swap(Any &a, Any &b){
    Any temp;
    temp = a;
    a= b;
    b = temp;
}

// 重载的模板
template<class Any>
void Swap(Any *a, Any *b, int n);
void Show(int a[]);
const int Lim = 8;

template<class Any>
void Swap(Any a[], Any b[], int n){
    Any temp;
    for (int i = 0; i < n; i++) {
        temp = a[i];
        a[i] = b[i];
        b[i] = temp;
    }
}

void Show(int a[]){
    cout << a[0] << a[1] << endl;
    cout << a[2] << a[3] << endl;
    for (int i = 4; i < Lim; ++i) {
        cout << a[i];
    }
    cout << endl;
}

// 模板实例化
// 隐式实例化
template void Swap<int> (int &, int &);
// 显示实例化
//template <> void Swap<int>(int &, int &);
//template <> void Swap(int &, int &);

void useTemSwap(){
    int i = 10, j = 20;
    cout << "i, j =" << i << "," << j << endl;
    Swap(i, j);
    cout << "i, j =" << i << "," << j << endl;
    double n = 5.0;
    double m = 10.0;
    cout << "n, m =" << n << "," << m << endl;
    Swap(n, m);
    cout << "n, m =" << n << "," << m << endl;

    int d1[Lim] = {0, 7, 0, 4, 1, 7, 7, 6};
    int d2[Lim] = {0, 6, 2, 0, 2, 9, 6, 9};
    cout << "Original arrays: \n";
    Show(d1);
    Show(d2);
    Swap(d1, d2, Lim);
    cout << "Swapped arrays: \n";
    Show(d1);
    Show(d2);
}

// 判断结果格式化输出
void coutFormat(){

    // 命名空间的使用
    std::cout << "Hello, World!" << std::endl;
    cout << "Hello, My Girls" << endl;
    double x = sqrt(9);
    cout << x << endl;
    cout << p.name << endl;
    cout << ky.name << endl;
    cout << color << endl;

    cout << "The expression x = 100 has the value ";
    // ()的优先级高于<<，则会先对x赋值100
    cout << (x = 100) << endl;
    cout << "The expresion x < 3 has the value ";
    cout << (x < 3) << endl;
    // The expresion x < 3 has the value 0
    cout << "The expresion x > 3 has the value ";
    cout << (x > 3) << endl;
    // The expresion x > 3 has the value 1
    // 设置判断结果的布尔值输出
    cout.setf(ios_base::boolalpha);
    cout << "The expresion x < 3 has the value ";
    cout << (x < 3) << endl;
    // The expresion x < 3 has the value false
    cout << "The expresion x > 3 has the value ";
    cout << (x > 3) << endl;
    // The expresion x > 3 has the value true
}

// 对象数组的使用
//void ObjectArray(){
//    Stock stock = Stock{};
//
//    // 对象数组-要创建对象数组，则这个类必须有默认构造函数
//    Stock stuff[4] = {
//            Stock("NanoSmart", 12.5, 20),
//            Stock("Boffo Objects", 200, 2.0),
//            Stock("Monolithic Obelisks", 130, 3.24),
//            Stock("Fleep EnterPrices", 60, 6.5)
//    };
//    stuff[0].update(23.0);
//    stuff[3].show();
//    Stock tops = stuff[2].topval(stuff[1]);
//}

// 类的使用以及友元函数的使用
void friendFunction(){
    FcTime aida(3, 25);
    FcTime tosca(2, 48);
    FcTime temp;

    cout << "Aida and Tosca:\n";
    cout << aida << "; " << tosca << endl;
    temp = aida + tosca;
    cout << "Aida + Tosca" << endl;
    temp = aida * 1.17;
    cout << "Aida * 1.17: " << temp << endl;
    cout << "Tosca * 10: " << 10 * tosca << endl;
}

// 使用Vector类模拟随机行走
void randwalk(){
    using VECTOR::Vector;
    srand(time(0));
    double direction;
    Vector step;
    Vector result(0.0, 0.0);
    unsigned long steps = 0;
    double dstep;
    double target;
    cout << "Enter target distance(q to quit): ";
    while (cin >> target) {
        cout << "Enter step length: ";
        if (!(cin >> dstep)) {
            break;
        }
        while (result.magval() < target){
            direction = rand()%360;
            step.set(dstep, direction, 'p');
            result = result + step;
            steps++;
        }
        cout << "After " << steps << " steps, the subject has the following location: \n";
        cout << result << endl;
        result.polar_mode();
        cout << " or\n" << result << endl;
        cout << "Average outward distance per step = " << result.magval()/steps << endl;
        steps = 0;
        result.set(0.0, 0.0);
        cout << "Enter target distance (q to quit): ";
    }
    cout << "Bye!\n";
}

// 队列类
const int MIN_PER_HR = 60;
bool newcustomer(double x);
bool newcustomer(double x){ return rand()*x / RAND_MAX < 1;}

void bank(){
    cout << "Case Study:Bank of Heather Automatic Teller\n";
    cout << "Enter maximum size of queue: ";
    int qs;
    cin >> qs;
    Queue line(qs);

    cout << "Enter the number of simulation hours: ";
    int hours;
    cin >> hours;
    long cyclelimit = MIN_PER_HR * hours;

    cout << "Enter the average number of customers per hour: ";
    double perhour;
    cin >> perhour;
    double min_per_cust;
    min_per_cust = MIN_PER_HR / perhour;

    Item temp;
    long turnaways = 0;
    long customers = 0;
    long served = 0;
    long sum_line = 0;
    int wait_time = 0;
    long line_wait = 0;

    for (int cycle = 0; cycle < cyclelimit; cycle ++){
        if (newcustomer(min_per_cust)){
            if (line.isfull())
                turnaways++;
            else{
                customers++;
                temp.set(cycle);
                line.enqueue(temp);
            }
        }
        if (wait_time <= 0 && !line.isempty()){
            line.dequeue(temp);
            wait_time = temp.ptime();
            line_wait += cycle = temp.when();
            served++;
        }
        if (wait_time > 0)
            wait_time--;
        sum_line += line.queuecount();
    }
    if (customers >0){
        cout << "customers accepted: " << customers << endl;
        cout << "customers served: " << served << endl;
        cout << "turnaways: " << turnaways << endl;
        cout << "average queue size: ";
        cout.setf(ios_base::fixed, ios_base::floatfield);
        cout.setf(ios_base::showpoint);
        cout << (double)sum_line/cyclelimit << endl;
        cout << "average wait time: " << (double)line_wait/served << " minutes\n";
    } else
        cout << "No customers!\n";
    cout << "Done!\n";
}

// 派生类
void usett(){
    TableTennisPlayer player1("Chuck", "Blizzard", true);
    TableTennisPlayer player2("Tara", "Boomdea", false);
    RatedPlayer ratedPlayer(1140, "Mallory", "Duck", true);
    ratedPlayer.Name();
    if (ratedPlayer.HasTable()) {
        cout << ":has a table.\n";
    }else{
        cout << ":has't a table.\n";
    }
    player1.Name();
    if (player1.HasTable()) {
        cout << ":has a table.\n";
    } else{
        cout << ":has't a table.\n";
    }
    player2.Name();
    if (player2.HasTable()) {
        cout << ":has a table.\n";
    } else{
        cout << ":has't a table.\n";
    }
    cout << "Name: ";
    ratedPlayer.Name();
    cout << ":Rating: " << ratedPlayer.Rating() << endl;
    RatedPlayer ratedPlayer1(1221, player1);
    cout << "Name: ";
    ratedPlayer1.Name();
    cout << ":Rating :" << ratedPlayer1.Rating() << endl;
}

// 多态公有继承
void useBrass(){
    Brass Piggy("Procelot Pigg", 381299, 4000.00);
    BrassPlus Hoggy("Horatio Hogg", 382288, 3000.00);
    Piggy.ViewAcct();
    cout << endl;
    Hoggy.ViewAcct();
    cout << endl;
    cout << "Depositing $1000 into the Hogg Account: \n";
    Hoggy.Deposit(1000.00);
    cout << "New balance: $ " << Hoggy.Balance() << endl;
    cout << "Withdrawing $4200 from the Pigg Account:\n";
    Piggy.Withdraw(4200.00);
    cout << "Pigg account balance: $ " << Piggy.Balance() << endl;
    cout << "Withdrawing $4200 from the Hogg Account:\n";
    Hoggy.Withdraw(4200.00);
    Hoggy.ViewAcct();
}

// 抽象类的应用
void usedma(){
    baseDMA shirt("Portabelly", 8);
    lacksDMA balloon("red", "Blimpo", 4);
    hasDMA map("Mercator", "Buffalo Keys", 5);
    cout << shirt << endl;
    cout << balloon << endl;
    cout << map << endl;
    lacksDMA balloon2(balloon);
    hasDMA map2;
    map2 = map;
    cout << balloon2 << endl;
    cout << map2 << endl;
}

// 代码的重用，私有继承，多重继承
const int SIZE_M = 5;
void workmi(){
    Worker * lolas[SIZE_M];
    int ct;
    for (ct = 0; ct < SIZE_M; ct++) {
        char choise;
        cout << "Enter the employee category:\n"
        << "w: waiter s: singer t: singing waiter q: quit\n";
        cin >> choise;
        while (strchr("wstq", choise) == NULL) {
            cout << "Please enter a w, s, t, or q: ";
            cin >> choise;
        }
        if (choise == 'q')
            break;
        switch (choise) {
            case 'w': lolas[ct] = new Waiter;
                break;
            case 's': lolas[ct] = new Singer;
                break;
            case 't': lolas[ct] = new SingingWaiter;
                break;
        }
        cin.get();
        lolas[ct]->Set();
    }

    cout << "\nHere is your sraff:\n";
    int i;
    for (i = 0; i < ct; i++) {
        cout << endl;
        lolas[i]->Show();
    }
    for  (i = 0; i < ct; i++)
        delete lolas[i];
    cout << "Bye.\n";
}

// 使用模板类
void useTemplateClass(){
    Stack<string> st;
    char ch;
    string po;
    cout << "Please enter A to add a purchase order, \n" << "P to process a PO, or to quit.\n";
    while (cin >> ch && toupper(ch) != 'Q') {
        while (cin.get() != '\n') {
            continue;
        }
        if (!isalpha(ch)) {
            cout << '\a';
            continue;
        }
        switch (ch){
            case 'A':
            case 'a': cout << "Enter a PO number to add: ";
            cin >> po;
            if (st.isfull())
                cout << "Stack already full\n";
            else
                st.push(po);
            break;
        case 'P':
        case 'p': if (st.isempty())
            cout << "Stack already empty\n";
            else{
                st.pop(po);
                cout << "PO #" << po << " popped\n";
                break;
            }
        }
        cout << "Please enter A to add a purchase order ,\n" << "P to process a PO , or Q to quit.\n";
    }
    cout << "Bye\n";

}

// 正确使用指针堆栈
const int Num = 10;
void usePointerStack(){
    srand(time(0));
    cout << "Please enter stack size: ";
    int stacksize;
    cin >> stacksize;
    Stack<const char *> st(stacksize);
    const char * in[Num] = {
            "1:Hank Gilgamesh", "2:Kiki Ishtar", "3:Betty Rocker", "4:Ian Flagranti",
            "5:Wolfgang Kibble", "6:Portia Koop", "7:Joy Almonda", "8:Xaverie Paprika",
            "9:Juan Moore", "10:Misha Mache"
    };
    const char * out[Num];
    int processed = 0;
    int nextin = 0;
    while (processed < Num) {
        if (st.isempty()) {
            st.push(in[nextin++]);
        } else if(st.isfull())
            st.pop(out[processed++]);
        else if (rand()%2 && nextin < Num)
            st.push(in[nextin++]);
        else
            st.pop(out[processed++]);
        for (int i = 0; i < Num; i++)
            cout << out[i] << endl;
        cout << "Bye\n";
    }
}

// 数组模板的使用
void useArrayTemplate(){
    ArrayTP<int, 10> sums;
    ArrayTP<double , 10> aves;
    ArrayTP<ArrayTP<int, 5>, 10> twodee;
    int i, j;
    for (int i = 0; i < 10; i++) {
        sums[i] = 0;
        for (int i = 0; i < 5; i++) {
            twodee[i][j] = (i + 1)*(j + 1);
            sums[i] += twodee[i][j];
        }
        aves[i] = (double)sums[i] / 10;
    }
    for (int i = 0; i < 10; i++) {
        for (int i = 0; i < 5; i++) {
            cout.width(2);
            cout << twodee[i][j] << ' ';
        }
        cout << " :sum = ";
        cout.widen(3);
        cout << sums[i] << ", average = " << aves[i] << endl;
    }
    cout << "Done.\n";
}

// 多个类型参数
void useMultipleTypeParameter(){
    Pair<string, int> rating[4] = {
            Pair<string, int>("The Purple Duke", 5),
            Pair<string, int>("Jake's Frisco AI Fresco", 4),
            Pair<string, int>("Mont Souffle", 5),
            Pair<string, int>("Gertie's Eats", 3)
    };
    int joints = sizeof(rating) / sizeof(Pair<string, int>);
    cout << "Rating :\t Eatery\n";
    for (int i = 0; i < joints; i++) {
        cout << rating[i].second() << ":\t" << rating[i].first() << endl;
        cout << "Oops! Revised rating :\n";
        rating[3].first() = "Gertie's Fab Eat";
        rating[3].second() = 6;
        cout << rating[3].second() << ":\t" << rating[3].first() << endl;
    }
}

// 友元类的使用
void useFriendClass(){
    Tv s27;
    cout << "Initial setting for 27\" TV:\n";
    s27.setting();
    s27.onoff();
    s27.chanup();
    cout << "\nAdjusted setting for 27\" TV:\n";
    s27.setting();

    Remote grey;
    grey.set_chan(s27, 10);
    grey.volup(s27);
    grey.volup(s27);
    cout << "\n27\" settings after using remote:\n";
    s27.setting();

    Tv s32(Tv::On);
    s32.set_mode();
    grey.set_chan(s32, 28);
    cout << "\n32\" setting:\n";
    s32.setting();
}

// 嵌套类的使用
void useNestClass(){
    QueueTP<string> cs(5);
    string temp;

    while (!cs.isfull()) {
        cout << "Please enter your name. You will be served in the order of arrival.\n name: ";
        getline(cin, temp);
        cs.enqueue(temp);
    }
    cout << "The queue is full. Processing bedins!\n";

    while (!cs.isempty()) {
        cs.dequeue(temp);
        cout << "Now processing " << temp << "...\n";
    }
}

// 调用abort处理异常
double hmean(double a, double b){
    if (a == -b) {
        cout << "untenable argument to hmean()\n";
        abort();
    }
    return 2.0 * a * b / (a + b);
}

void errorOne(){
    double x, y, z;
    cout << "Enter two numbers: ";
    while (cin >> x >> y) {
        z = hmean(x, y);
        cout << "Harmonic mean of " << x << " and " << y << " is " << z << endl;
        cout << "Enter next set of numbers <q to quit>: ";
    }
    cout << "Bye!\n";
}

// 返回错误码
bool hmean(double a, double b, double *ans);

bool hmean(double a, double b, double *ans){
    if (a == -b) {
        *ans = DBL_MAX;
        return false;
    } else{
        *ans = 2.0 * a * b / (a + b);
        return true;
    }
}

void errorCode(){
    double x, y, z;
    cout << "Enter two numbers: ";
    while (cin >> x >> y) {
        if (hmean(x, y, &z))
            cout << "Harmonic mean of " << x << " and " << y << " is " << z << endl;
        else
            cout << "One value should not be the negative of the other - try again.\n";
        cout << "Enter next set of numbers <q to quit>: ";
    }
    cout << "Bye!\n";
}

int main() {

//    pointer();
//    structure();
//    fileoperation("info.txt");
//    referenceVariable();
//    useTemSwap();
//    friendFunction();
//    randwalk();
//    bank();
//    usett();
//    useBrass();
//    usedma();
//    workmi();
//    useTemplateClass();
//    usePointerStack();
//    useArrayTemplate();
//    useMultipleTypeParameter();
//    useFriendClass();
//    useNestClass();
//    errorOne();
    errorCode();


    double a = square(5.0);
    cout << "a : " << a << endl;

    return 0;
}
