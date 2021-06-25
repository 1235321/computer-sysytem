#include <iostream>
#include <algorithm>
#include "../../head/res/res4/PSAt.h"
#include"../../head/init/init4.h"

bool cmpPP(PCB a, PCB b)
{
    return a.at < b.at;
}

int AL::PSAt()
{
    int n = this->read("./data/file4.txt");
    for(int i=1; i<=n; i++)
        process[i].st1 = process[i].st;

//Ëã·¨
    sort(&process[1], &process[1]+n, cmpPP);
    int t = 0;
    int num=0;

    while(num != n)
    {
        int tmp=10000;
        int tmpI=0;
        for(int i=1; i<=n; i++)
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
            if(process[tmpI].st1 == process[tmpI].st)
                process[tmpI].bt = t;
            process[tmpI].st1 -= 1;
            t++;

            if(process[tmpI].st1 == 0)
            {
                process[tmpI].ct = t;
                process[tmpI].sc = 1;
                num++;
            }
        }
    }

    this->write("./result/result4/PSAt.txt", n);
    return 1;
}
