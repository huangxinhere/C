#include <iostream>

using namespace std;

/*---����Ա����---*/

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
    //b��const�������������Զ�ѡ��const����
    const P b(3,4);//Ȼ��const�������Ե��ã��ǣ���������
    b.print();

    return 0;
}
