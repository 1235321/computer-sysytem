#include "../../head/res/res3/LLF.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include "../../head/init/init3.h"
#define PROGRESS 7
using namespace std;

bool cmpllf(Init3 a,Init3 b)
{
    return a.Slackness<b.Slackness;
}
bool comparearrivalTime_LLF(Init3 a,Init3 b){
    return a.arrivalTime < b.arrivalTime;
}
int LLF()
{
    Init3 init3;
    vector<Init3> records;
    vector<Init3> duilie;

    //获取数据
    string infile = "./data/file3.txt";
    string outfile = "./result/result3/LLF.txt";
    ifstream inFile(infile.c_str());
    init3.read(infile,records);
    ofstream outFile(outfile.c_str());
    outFile.precision(3);

    inFile.close();
       //算法实现
    unsigned int sum=0;
    int time=0;
    unsigned int bos=0;
    sort(records.begin(),records.end(),comparearrivalTime_LLF);
    while(sum<records.size()){

        int bos2=0;

        while(bos<records.size()&&records[bos].arrivalTime<=time)
        {
            duilie.push_back(records[bos]);
            bos++;
        }
        for(unsigned int i=0;i<records.size();i++){
            duilie[i].Slackness = duilie[i].limittime - duilie[i].serviceTime - (time);
            if(duilie[i].Slackness==0){
                bos2 = 1;
                continue;
            }
        }
        if(bos2==1)
        {
            sort(duilie. begin(),duilie.end(),cmpllf);
        }
        duilie[0].serviceTime--;

        duilie[0].achieveTime++;
        outFile<<"第"<<time+1<<"秒执行"<<duilie[0].job<<endl;
        if(duilie[0].serviceTime==0)
        {
           sum++;
           duilie.erase(duilie.begin());
           sort(duilie.begin(),duilie.end(),cmpllf);
        }
        time++;
    }
    outFile.close();
    return 1;
}
