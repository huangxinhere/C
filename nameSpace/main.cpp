#include <iostream>

using namespace std;
int i;

namespace Ns
{
    int j;//Ns�����ռ��еı���
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
    {                           //�ӿ�1��Ϊʲô�����ӿ����ֶ�������
        using namespace Ns;     //ʹ���ڵ�ǰ�����п���ֱ������Ns�ı���
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



// namespace �����ռ���{
//      �����ռ��ڵĸ�����������������ȵȣ�
// }
// Ϊʲô�����������������ʲô���𣿰�װ��һ�飿
