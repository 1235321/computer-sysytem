#include "init.h"
using namespace std;

void PageInformation::setpid(PageInformation *headptrblock,int pid)//�޸��������������Աpid ������
{
    headptrblock->pid=pid;
}
void PageInformation::setpidrand(PageInformation *headptr,int pid)//�޸�ҳ����������Աpid ҳ���
{
    headptr->pid=pid;
    //cout<<pid<<" ";
}
void PageInformation::display()
{

    cout<<pid<<" ";
    //cout<<pid;
}
int PageInformation::setpid()//ѡ��Ӽ�������ʱ���ö��������Աpid
{
    int pidtemp;
    cout<<"����������ҳ�ţ���Χ1-9����";
    cin>>pidtemp;
    this->pid=pidtemp;
    return this->pid;
}
void PageInformation::setpid2(int pid)
{
    this->pid = pid;
}
void PageInformation::counter()
{
    count++;
}
void PageInformation::resetcount()
{
    count=0;
}
int PageInformation::getpid()
{
    return pid;
}
int PageInformation::getcount()
{
    return count;
}
void PageInformation::Directloading(PageInformation *&headptr,PageInformation *&headptrblock,int pagenum,ofstream& OutFile)//ֱ�ӽ�ǰ����ҳ��װ��������� pagenum
{
    int temp;
    for(int i=0; i < pagenum; i++) //ֱ�ӽ��������������С��ҳ��װ���������
    {
        (headptrblock+i)->setpid((headptrblock+i),(headptr+i)->getpid());
        temp=i+1;
        for(int j=0; j < temp; j++)
        {
            (headptrblock+j)->counter();//��Ӧ�����פ��ʱ��++
        }
        cout<<"�� "<<i+1<<"��ҳ������ʱ�������ҳ��Ϊ��";
        OutFile<<"�� "<<i+1<<"��ҳ������ʱ�������ҳ��Ϊ��";
        for(int mm=0; mm<=i; mm++)
        {
            (headptrblock+mm)->display();
            OutFile<<(headptrblock+mm)->getpid()<<" ";
        }
        cout<<"! ����ȱҳ!"<<endl;
        OutFile<<"! ����ȱҳ!"<<endl;
    }
    cout<<"ԭʼ�������ҳ��Ϊ��"<<"\t\t";
    OutFile<<"ԭʼ�������ҳ��Ϊ��"<<"\t\t";
    for(int i = 0; i < pagenum; i++)
    {
        (headptrblock+i)->display();
        OutFile<<(headptrblock+i)->getpid()<<" ";
    }
    cout<<endl;
    OutFile<<endl;
}//Directloading
