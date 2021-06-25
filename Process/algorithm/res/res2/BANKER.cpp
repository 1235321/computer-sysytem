#include "../../head/init/init2.h"
#include "../../head/res/res2/BANKER.h"
#include <iostream>
using namespace std;
Init2 bank;
int Safe_Algorithm(int Available[],int Need[][REC_NUM],int Allocation[][REC_NUM])
{
    int i=0,j=0,m=0,n=0;
    int Work[bank.REC_NUM],Finish[bank.PROGRESS] = {0,0,0,0,0};
    for(int r = 0; r < bank.REC_NUM; r++) //��������Դ��Ŀ������������Work
        Work[r] = Available[r];
    while(i < bank.PROGRESS)
    {
        if(Finish[i] == 0)
        {
            //���������ͷ���Դ������ͷ��ʼɨ����̼���
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
                bank.sign[m]=i;  //���氲ȫ����
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
            n++;   //��¼'true'����
    }
    return n;     //����'true'����
}

int Banker_Algorithm (int i,int Request[][REC_NUM])
{
    for(int m = 0; m < bank.REC_NUM; m++)
    {
        if(Request[i][m] > bank.Need[i][m])
        {
            cout<<"������Դ�����������������ֵ!"<<endl;
            return 0;
        }
        else if(Request[i][m] > bank.Available[m])
        {
            cout<<"���㹻��Դ��p["<<i<<"]��ȴ�!"<<endl;
            return 0;
        }
    }

    //����Ϊ���̷�����Դ
    for(int j = 0; j < bank.REC_NUM; j++)
    {
        bank.Available[j] = bank.Available[j] - Request[i][j];
        bank.Allocation[i][j] = bank.Allocation[i][j] + Request[i][j];
        bank.Need[i][j] = bank.Need[i][j] - Request[i][j];
    }

    //ִ�а�ȫ���㷨
    int n = Safe_Algorithm(bank.Available,bank.Need,bank.Allocation);
    cout<<endl;

    if(n == bank.PROGRESS)  //��5��'true'����1����ʾ��ʱ�̰�ȫ
    {
        cout<<"��ʱ���ǰ�ȫ״̬�����Է�����Դ��"<<"P["<<i<<"]!"<<endl;
    }
    else
    {
//�Ѹ�����P[i]���������Դ����ϵͳ
        for(int j = 0; j < bank.REC_NUM; j++)
        {
            bank.Available[j] = bank.Available[j] + Request[i][j];
            bank.Allocation[i][j] = bank.Allocation[i][j] - Request[i][j];
            bank.Need[i][j] = bank.Need[i][j] + Request[i][j];
        }
        cout<<"��ʱ�̲��ǰ�ȫ״̬�����ܽ���Դ�����"<<"P["<<i<<"]!"<<endl;
    }
    return n;
}


int BANKER()
{
//��ȡ�ļ����ݲ���ӡ,Ȼ�����ݴ��뵽��Ӧ������
    const char* inputfile = "./data/file2.txt";
    const char* outfile = "./result/result2/BANKER.txt";
    bank.Read_file(inputfile);
    //����ʼ
    int i=0;    // 'N'��ʾ������Դ����
    int Request[bank.PROGRESS][bank.REC_NUM];  //�����������Requset
    cout<<endl<<"������������ԴRequest[���̱��i][��Դ����j]:"<<endl;
    cout<<"����i=��";
    cin>>i;
    cout<<"������Դ����(A B C)=:  ";
    for(int m = 0; m < bank.REC_NUM; m++)
        cin>>Request[i][m];
    cout<<endl;
    //ִ�����м��㷨
    int result = Banker_Algorithm(i,Request);
    //���ÿ���жϲ�����ִ������
    if(bank.Print_Run_Order(outfile,result))
        return 1;
    else
        return 0;
}

