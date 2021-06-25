#ifndef _OUTPUT_H_
#define _OUTPUT_H_
class Output
{
private:
    //算法标记
    int num;
public:
    //成员变量
    enum Funcs{exit,fcfs,sjf,hrrn,srt,rr,banker,edf,llf,psat,psaf};

    //构造方法
    Output();
    Output(int num);


    //成员方法
    int printOut();
};
#endif // _OUTPUT_H_
