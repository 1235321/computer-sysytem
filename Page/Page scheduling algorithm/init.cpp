#include "init.h"
using namespace std;

void PageInformation::setpid(PageInformation *headptrblock,int pid)//修改物理块对象数组成员pid 物理块号
{
    headptrblock->pid=pid;
}
void PageInformation::setpidrand(PageInformation *headptr,int pid)//修改页面对象数组成员pid 页面号
{
    headptr->pid=pid;
    //cout<<pid<<" ";
}
void PageInformation::display()
{

    cout<<pid<<" ";
    //cout<<pid;
}
int PageInformation::setpid()//选择从键盘输入时设置对象数组成员pid
{
    int pidtemp;
    cout<<"请输入您的页号（范围1-9）：";
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
void PageInformation::Directloading(PageInformation *&headptr,PageInformation *&headptrblock,int pagenum,ofstream& OutFile)//直接将前三个页面装入物理块中 pagenum
{
    int temp;
    for(int i=0; i < pagenum; i++) //直接将符合物理块数大小的页面装入物理块中
    {
        (headptrblock+i)->setpid((headptrblock+i),(headptr+i)->getpid());
        temp=i+1;
        for(int j=0; j < temp; j++)
        {
            (headptrblock+j)->counter();//对应物理块驻留时间++
        }
        cout<<"第 "<<i+1<<"新页面载入时各物理块页号为：";
        OutFile<<"第 "<<i+1<<"新页面载入时各物理块页号为：";
        for(int mm=0; mm<=i; mm++)
        {
            (headptrblock+mm)->display();
            OutFile<<(headptrblock+mm)->getpid()<<" ";
        }
        cout<<"! 发生缺页!"<<endl;
        OutFile<<"! 发生缺页!"<<endl;
    }
    cout<<"原始各物理块页号为："<<"\t\t";
    OutFile<<"原始各物理块页号为："<<"\t\t";
    for(int i = 0; i < pagenum; i++)
    {
        (headptrblock+i)->display();
        OutFile<<(headptrblock+i)->getpid()<<" ";
    }
    cout<<endl;
    OutFile<<endl;
}//Directloading
