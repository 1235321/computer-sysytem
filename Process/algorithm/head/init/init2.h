#ifndef _INIT2_H_
#define _INIT2_H_

class Init2
{
public:
    static const int PROGRESS = 5;     //��������
    static const int REC_NUM = 3;     //��Դ��������
    int Available[PROGRESS];      //���������Դ����Available
    int sign[PROGRESS],work[PROGRESS][REC_NUM],workAll[PROGRESS][REC_NUM];
            //��¼�ɹ��İ�ȫ����,�����幤������Ϳ�����Դ����
    int Max[PROGRESS][REC_NUM],Allocation[PROGRESS][REC_NUM],Need[PROGRESS][REC_NUM];
            //��������������Max���������Allocation���������Need
    Init2();
    void Read_file(const char* inputfile);     //��ȡ�ļ�
    int Print_Run_Order(const char* outfile,int result);         //��ӡ�ж�ִ������
};
#endif // _INIT2_H_

