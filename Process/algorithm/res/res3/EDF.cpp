#include <iostream>
#include "../../head/init/init3.h"
#include "../../head/res/res3/EDF.h"
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

bool cmpedf(Init3 a,Init3 b)
{
    return a.limittime<b.limittime;
}
bool comparearrivalTime_EDF(Init3 a,Init3 b){
    return a.arrivalTime < b.arrivalTime;
}
int EDF()
{
    Init3 init3;
    const int PROGRESS = 7;
    vector<Init3> records;
    vector<Init3> duilie;
    //获取数据
    string path = "./data/file3.txt";
    string out = "./result/result3/EDF.txt";
    init3.read(path,records);
    ofstream outFile(out.c_str());
    outFile.precision(3);
       //算法实现
    int sum=0;

    int time=0, bos=0;
    sort(records.begin(),records.end(),comparearrivalTime_EDF);
    while(sum<records.size()){

        int bos2=0;

        while(bos<records.size()&&records[bos].arrivalTime<=time)
        {
            duilie.push_back(records[bos]);
            bos++;
            bos2=1;
        }
        if(bos2==1)
        {
            sort(duilie.begin(),duilie.end(),cmpedf);
        }
        duilie[0].serviceTime--;

        duilie[0].achieveTime++;
        if(duilie[0].serviceTime==0)
        {
           sum++;
           duilie.erase(duilie.begin());
           sort(duilie.begin(),duilie.end(),cmpedf);
        }
        time++;
        outFile<<"第"<<time<<"秒执行"<<duilie[0].job<<endl;
    }
    outFile.close();
    return 1;
}
