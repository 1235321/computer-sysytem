#include "../head/init/init2.h"
#include <iostream>
#include <fstream>
using namespace std;

Init2::Init2(){}
void Init2::Read_file(const char* inputfile){
    //��ȡֻ�����ֵ��ļ������������
    ifstream inFile(inputfile,ios::in);
    if(!inFile)
          cerr<<"File open error."<<endl;
    else{
        int data;
       //��ȡ���ֲ��������
        for(int j = 0;j < PROGRESS;j++) {
            for(int i = 0;i < REC_NUM;i++) {
                inFile>>data;
                this->Max[j][i]=data;
            }
            for(int i = 0;i < REC_NUM;i++) {
                inFile>>data;
                this->Allocation[j][i]=data;
            }
            for(int i = 0;i < REC_NUM;i++) {
                inFile>>data;
                this->Need[j][i]=data;
            }
            if(j==0) {
                for(int i = 0;i < REC_NUM;i++) {
                  inFile>>data;
                  this->Available[i]=data;
                }
            }
        }
        inFile.close();
    }
}

//��ӡ��ȫ�Լ���ִ������
int Init2::Print_Run_Order(const char* outfile,int result) {


    ofstream outFile(outfile,ios::out);
    outFile.precision(3);
    if(result == PROGRESS) {
        outFile <<" ����\\��Դ���"<<" Work(A B C)"<<" Need(A B C)"
            <<" Allocation(A B C)"<<" Work+Available(A B C)"<<" Finish\n";
        for(int i = 0;i < PROGRESS;i++) {
            outFile<<"    "<<"P["<<this->sign[i]<<"]  "<<'\t';
            for(int j = 0;j < REC_NUM;j++)
                outFile<<this->work[this->sign[i]][j]<<" ";
            outFile<<'\t'<<'\t';
            for(int j = 0;j < REC_NUM;j++)
                outFile<<this->Need[this->sign[i]][j]<<" ";
            outFile<<'\t'<<'\t';
            for(int j = 0;j < REC_NUM;j++)
                outFile<<this->Allocation[this->sign[i]][j]<<" ";
            outFile<<'\t'<<'\t';
            for(int j = 0;j < REC_NUM;j++)
                outFile<<this->workAll[this->sign[i]][j]<<" ";
            outFile<<'\t'<<'\t';
            outFile<<"true\n";
        }
        outFile<<"\n�ҵ���ȫ���У�P["<<this->sign[0]<<"]";
        for(int m = 1;m < PROGRESS;m++){
            outFile<<", P["<<this->sign[m]<<"]";
        }
        outFile<<"}\n";
        outFile.close();
        return 1;
    } else {
        outFile<<"   ����\\��Դ��� "<<"  Allocation(A B C)"<<"   Need(A B C)"<<"   Available(A B C)\n";
        for(int k = 0;k < 5;k++){
            outFile<<'\t'<<"P["<<k<<"]"<<'\t'<<'\t';
            for(int j = 0;j < 3;j++)
                outFile<<this->Allocation[k][j]<<" ";
            outFile<<'\t'<<'\t';
            for(int j = 0;j < 3;j++)
                outFile<<this->Need[k][j]<<" ";
            outFile<<'\t'<<'\t';
            if(k == 0) {
                for(int j = 0;j < 3;j++)
                outFile<<this->Available[j]<<" ";
            }
            outFile<<"\n";
        }
        outFile.close();
        return 0;
    }
}
