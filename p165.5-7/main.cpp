#include <iostream>

using namespace std;

/*---常成员函数---*/

class P{
public:
    P(int a,int b) : p1(a),p2(b){}
    void print()
    {
        cout << "NUM one : "<< p1 << p2<<endl;
    }
    void print() const
    {
        cout << "NUM two : "<<p1<<p2<< endl;
    }

private:
    int p1;
    const int p2;
};
int main()
{
    P a(1,2);
    a.print();
    //b是const（常量）对象，自动选择const函数
    const P b(3,4);//然后const函数可以调用（非）常量数据
    b.print();

    return 0;
}
