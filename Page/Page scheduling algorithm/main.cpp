#include "over.h"
using namespace std;
//������������
int main()
{
    cout<<"����1��ʾѡ�������������ݣ�����2��ʾ���������ı�����"<<endl;
    cout<<"������Ĭ��ʹ�÷�������������Լ�ѡ���ʮ��ҳ�棩"<<endl;
    int n;
    cin>>n;
    if(n!=1&&n!=2) {
        cout<<"����ʹ��"<<endl;
        return 0;
    }
    test(n);
}
