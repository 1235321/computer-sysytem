#include <iostream>
#include "../../head/init/init4.h"
#include "../../head/res/res4/PSAf.h"
#include <algorithm>

bool cmpNPP(PCB a, PCB b)
{
    return a.at < b.at;
}

int AL::PSAf()
{
    int n = this->read("./data/file4.txt");

//�㷨
    sort(&process[1], &process[1]+n, cmpNPP);
    int t = process[1].at;
    int num = 0;  //��¼ִ�еĽ�����
    while(num != n)
    {
        int tmp=10000;  //��¼������
        int tmpI=0;  //��¼ִ�еĽ���
        for(int i=1; i<=n; i++)  //Ѱ���ѵ��������������С
        {
            if(process[i].at <= t && process[i].sc == 0)
            {
                if(process[i].priority < tmp)
                {
                    tmp = process[i].priority;
                    tmpI = i;
                }
            }
        }

        if(tmpI == 0)
            t++;
        else
        {
            process[tmpI].bt = t;
            process[tmpI].ct = process[tmpI].bt + process[tmpI].st;
            process[tmpI].sc = 1;
            t = process[tmpI].ct;
            num++;
        }

    }

    this->write("./result/result4/PSAf.txt", n);
    return 1;
}
