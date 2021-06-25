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
    int pid;			  //页号
    int count;		      //统计驻留在物理块中的次数（时间）,初始为0
public:
    PageInformation()
    {
        count=0;   //默认构造函数，驻留在页面的时间初始化为0
    }
    PageInformation(PageInformation &p)
    {
        p.pid=pid;
        p.count=count;
    }
    virtual ~PageInformation() {}
    void setpid(PageInformation *headptrblock,int pid);//修改物理块对象数组成员pid 物理块号
    void setpidrand(PageInformation *headptr,int pid);//修改页面对象数组成员pid 页面号
    void display();
    int setpid();//选择从键盘输入时设置对象数组成员pid
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
