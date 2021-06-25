#ifndef _INIT2_H_
#define _INIT2_H_

class Init2
{
public:
    static const int PROGRESS = 5;     //进程数量
    static const int REC_NUM = 3;     //资源种类数量
    int Available[PROGRESS];      //定义可用资源向量Available
    int sign[PROGRESS],work[PROGRESS][REC_NUM],workAll[PROGRESS][REC_NUM];
            //记录成功的安全序列,并定义工作矩阵和可用资源矩阵
    int Max[PROGRESS][REC_NUM],Allocation[PROGRESS][REC_NUM],Need[PROGRESS][REC_NUM];
            //定义最大需求矩阵Max，分配矩阵Allocation，需求矩阵Need
    Init2();
    void Read_file(const char* inputfile);     //读取文件
    int Print_Run_Order(const char* outfile,int result);         //打印判断执行序列
};
#endif // _INIT2_H_

