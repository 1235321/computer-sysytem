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

//��txt�ж�ȡ���ݷ�������(������ȼ��㷨��һ�ж�ȡ����)
int  AL::read(char a[])
{
    int num=0;//��¼������
    ifstream file1(a);
    if(!file1)
    {
        cout<<"��ʧ��\n";

    }
    else
    {
//��ȡ��һ�е�����
        string processname;
        string processarriver;
        string processservice;
        string processpriority;
        file1>>processname;
        file1>>processarriver;
        file1>>processservice;
        file1>>processpriority;
//��ȡ��Ϣ
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
    file2<<"���еĽ��̺�\t����ʱ��\t����ʱ��\t��ʼʱ��\t����ʱ��\t��תʱ��\t��Ȩ��תʱ��\n";
    for(int i=1; i<=n; i++) //��ӡ�����̵���Ϣ
    {
        int zhou=process[i].ct-process[i].at;
        double daiquan=(zhou*1.0)/(process[i].st*1.0);
        file2<<process[i].pn<<"\t\t"<<process[i].at<<"\t"<<process[i].st<<"\t";
        file2<<process[i].bt<<"\t"<<process[i].ct<<"\t"<<zhou<<"\t"<<daiquan<<endl;

    }



    file2.close();

}
