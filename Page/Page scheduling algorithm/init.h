#ifndef _CHANGE_
#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <windows.h>
#include <fstream>

class PageInformation
{
protected:
    int pid;			  //ҳ��
    int count;		      //ͳ��פ����������еĴ�����ʱ�䣩,��ʼΪ0
public:
    PageInformation()
    {
        count=0;   //Ĭ�Ϲ��캯����פ����ҳ���ʱ���ʼ��Ϊ0
    }
    PageInformation(PageInformation &p)
    {
        p.pid=pid;
        p.count=count;
    }
    virtual ~PageInformation() {}
    void setpid(PageInformation *headptrblock,int pid);//�޸��������������Աpid ������
    void setpidrand(PageInformation *headptr,int pid);//�޸�ҳ����������Աpid ҳ���
    void display();
    int setpid();//ѡ��Ӽ�������ʱ���ö��������Աpid
    void counter();
    void resetcount();
    int getpid();
    int getcount();
    void setpid2(int pid);
    void Directloading(PageInformation *&headptr,PageInformation *&headptrblock,int pagenum,std::ofstream& OutFile);
    void FIFO(PageInformation *headptr,PageInformation *headptrblock,int pagenum,int pagenumber,int &pagecounter);
    void OPT(PageInformation *headptr,PageInformation *headptrblock,int pagenum,int pagenumber,int &pagecounter);
    void LRU(PageInformation *headptr,PageInformation *headptrblock,int pagenum,int pagenumber,int &pagecounter);
};//PageInformation
#endif
