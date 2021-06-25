#ifndef _INIT4_H_
#define _INIT4_H_
#include<iostream>
#include<string>
using namespace std;
const int D = 50;

const int TASK_NUM = 2;

struct PCB
{
    string pn;//process name��������
    int at;//arrival time����ʱ��
    int st;//service time����ʱ��
    int bt;//begin time��ʼʱ��
    int ct;//completion time���ʱ��
    int sc;//yes or no completion�Ƿ����
    int zt;//��תʱ��
    double dt;// ��Ȩ��תʱ��
    int st1;//ʣ�����ʱ��
    double xyb;//��Ӧ��
    int rr;//�����ж�

    int priority;
    int dead_time;
    int perNum = 1;  //����
    int period;  //���ڳ���
};

class AL
{
public:
    AL();
    virtual ~AL();
    PCB process[D];

    int read(char a[]);
    void write(char a[],int n);//�����ַ�ͽ�����
    void print_process_information(int n);//���ݽ�����Ϣ
    void print_choose();
    void choose();
    int PSAf();  //����ռʽ���ȼ������㷨
    int PSAt();  //��ռʽ���ȼ������㷨

private:
};

#endif // _INIT4_H_
