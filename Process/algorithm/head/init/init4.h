#ifndef _INIT4_H_
#define _INIT4_H_
#include<iostream>
#include<string>
using namespace std;
const int D = 50;

const int TASK_NUM = 2;

struct PCB
{
    string pn;//process name进程名字
    int at;//arrival time到达时间
    int st;//service time服务时间
    int bt;//begin time开始时间
    int ct;//completion time完成时间
    int sc;//yes or no completion是否完成
    int zt;//周转时间
    double dt;// 带权周转时间
    int st1;//剩余服务时间
    double xyb;//响应比
    int rr;//用于判断

    int priority;
    int dead_time;
    int perNum = 1;  //周期
    int period;  //周期长度
};

class AL
{
public:
    AL();
    virtual ~AL();
    PCB process[D];

    int read(char a[]);
    void write(char a[],int n);//传入地址和进程数
    void print_process_information(int n);//传递进程信息
    void print_choose();
    void choose();
    int PSAf();  //非抢占式优先级调度算法
    int PSAt();  //抢占式优先级调度算法

private:
};

#endif // _INIT4_H_
