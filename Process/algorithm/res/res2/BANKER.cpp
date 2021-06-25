#include "../../head/init/init2.h"
#include "../../head/res/res2/BANKER.h"
#include <iostream>
using namespace std;
Init2 bank;
int Safe_Algorithm(int Available[],int Need[][REC_NUM],int Allocation[][REC_NUM])
{
    int i=0,j=0,m=0,n=0;
    int Work[bank.REC_NUM],Finish[bank.PROGRESS] = {0,0,0,0,0};
    for(int r = 0; r < bank.REC_NUM; r++) //将可用资源数目赋给工作向量Work
        Work[r] = Available[r];
    while(i < bank.PROGRESS)
    {
        if(Finish[i] == 0)
        {
            //满足条件释放资源，并从头开始扫描进程集合
            while(j < bank.REC_NUM && Need[i][j] <= Work[j] )
                j++;
            if(j == bank.REC_NUM)
            {
                for(int k = 0; k < bank.REC_NUM; k++)
                {
                    bank.work[i][k] = Work[k];
                    Work[k] = Work[k]+Allocation[i][k];
                    bank.workAll[i][k] = Work[k];
                }
                Finish[i]=1;
                bank.sign[m]=i;  //保存安全序列
                i=-1;
                m++;
            }
        }
        j=0;
        i++;
    }
    for(int p = 0; p < bank.PROGRESS; p++)
    {
        if(Finish[p] == 1)
            n++;   //记录'true'个数
    }
    return n;     //返回'true'个数
}

int Banker_Algorithm (int i,int Request[][REC_NUM])
{
    for(int m = 0; m < bank.REC_NUM; m++)
    {
        if(Request[i][m] > bank.Need[i][m])
        {
            cout<<"所需资源数超出其宣布的最大值!"<<endl;
            return 0;
        }
        else if(Request[i][m] > bank.Available[m])
        {
            cout<<"无足够资源，p["<<i<<"]需等待!"<<endl;
            return 0;
        }
    }

    //尝试为进程分配资源
    for(int j = 0; j < bank.REC_NUM; j++)
    {
        bank.Available[j] = bank.Available[j] - Request[i][j];
        bank.Allocation[i][j] = bank.Allocation[i][j] + Request[i][j];
        bank.Need[i][j] = bank.Need[i][j] - Request[i][j];
    }

    //执行安全性算法
    int n = Safe_Algorithm(bank.Available,bank.Need,bank.Allocation);
    cout<<endl;

    if(n == bank.PROGRESS)  //有5个'true'返回1，表示此时刻安全
    {
        cout<<"此时刻是安全状态，可以分配资源给"<<"P["<<i<<"]!"<<endl;
    }
    else
    {
//把给进程P[i]分配过的资源还给系统
        for(int j = 0; j < bank.REC_NUM; j++)
        {
            bank.Available[j] = bank.Available[j] + Request[i][j];
            bank.Allocation[i][j] = bank.Allocation[i][j] - Request[i][j];
            bank.Need[i][j] = bank.Need[i][j] + Request[i][j];
        }
        cout<<"此时刻不是安全状态，不能将资源分配给"<<"P["<<i<<"]!"<<endl;
    }
    return n;
}


int BANKER()
{
//读取文件数据并打印,然后将数据存入到相应矩阵中
    const char* inputfile = "./data/file2.txt";
    const char* outfile = "./result/result2/BANKER.txt";
    bank.Read_file(inputfile);
    //任务开始
    int i=0;    // 'N'表示请求资源次数
    int Request[bank.PROGRESS][bank.REC_NUM];  //定义请求矩阵Requset
    cout<<endl<<"请输入请求资源Request[进程标号i][资源类型j]:"<<endl;
    cout<<"进程i=：";
    cin>>i;
    cout<<"各类资源数量(A B C)=:  ";
    for(int m = 0; m < bank.REC_NUM; m++)
        cin>>Request[i][m];
    cout<<endl;
    //执行银行家算法
    int result = Banker_Algorithm(i,Request);
    //输出每次判断产生的执行序列
    if(bank.Print_Run_Order(outfile,result))
        return 1;
    else
        return 0;
}

