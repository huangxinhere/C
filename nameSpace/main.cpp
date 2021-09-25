#include <iostream>

using namespace std;
int i;

namespace Ns
{
    int j;//Ns命名空间中的变量
}

int add()
{
    static int k = 5;
    for(;k<=10;k++) {}
    return k++;
}

int main()
{
    i = 5;
    {                           //子块1（为什么会有子块这种东西？）
        using namespace Ns;     //使得在当前语句块中可以直接引用Ns的变量
        int i = 6;
        cout << i << endl;
        Ns : j = 7;
        cout << j << endl;
    }
    cout << i << endl;
    add();
    i = add();
    cout << i << endl;
    return 0;
}



// namespace 命名空间名{
//      命名空间内的各种声明（函数、类等等）
// }
// 为什么出现这个？？和类有什么区别？包装在一块？
