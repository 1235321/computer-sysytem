#ifndef _OUTPUT_H_
#define _OUTPUT_H_
class Output
{
private:
    //�㷨���
    int num;
public:
    //��Ա����
    enum Funcs{exit,fcfs,sjf,hrrn,srt,rr,banker,edf,llf,psat,psaf};

    //���췽��
    Output();
    Output(int num);


    //��Ա����
    int printOut();
};
#endif // _OUTPUT_H_
