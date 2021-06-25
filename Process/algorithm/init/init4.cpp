#include "../head/init/init4.h"
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<algorithm>
using namespace std;
AL::AL()
{
    //ctor
}

AL::~AL()
{
    //dtor
}

bool cmp3(PCB a,PCB b)
{
    return a.at<b.at;
}

//从txt中读取数据返回行数(针对优先级算法，一行读取四列)
int  AL::read(char a[])
{
    int num=0;//记录进程数
    ifstream file1(a);
    if(!file1)
    {
        cout<<"打开失败\n";

    }
    else
    {
//获取第一行的文字
        string processname;
        string processarriver;
        string processservice;
        string processpriority;
        file1>>processname;
        file1>>processarriver;
        file1>>processservice;
        file1>>processpriority;
//获取信息
        int i=1;

        while(!file1.eof())
        {
            file1>>process[i].pn;
            file1>>process[i].at;
            file1>>process[i].st;
            file1>>process[i].priority;
            process[i].sc=0;
            num++;
            i++;
        }
        num--;


    }

    file1.close();
    return num;
}



void AL::write(char a[],int n)
{
    sort(&process[1],&process[1]+n,cmp3);
    ofstream file2(a);
    file2<<"运行的进程号\t到达时间\t服务时间\t开始时间\t结束时间\t周转时间\t带权周转时间\n";
    for(int i=1; i<=n; i++) //打印各进程的信息
    {
        int zhou=process[i].ct-process[i].at;
        double daiquan=(zhou*1.0)/(process[i].st*1.0);
        file2<<process[i].pn<<"\t\t"<<process[i].at<<"\t"<<process[i].st<<"\t";
        file2<<process[i].bt<<"\t"<<process[i].ct<<"\t"<<zhou<<"\t"<<daiquan<<endl;

    }



    file2.close();

}
