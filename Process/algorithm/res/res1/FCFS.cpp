#include "../../head/res/res1/FCFS.h"
#include "../../head/init/init.h"
#include <iostream>
using namespace std;

int FCFS(){
    const char* inputfile = "./data/file.txt";
    const char* outfile = "./result/result1/FCFS.txt";
    Init init;
    vector<Init> records;
    init.read(inputfile,records);

    //FSFC算法实现
    vector<Init> results(records.size());
    vector<char> execOrder;
    int totalTime = 0;
    for(int i=0; i< records.size();i++){

        execOrder.push_back(records[i].getJob());
        if(totalTime>records[i].getArrivalTime())
            results[i].setStartTime(totalTime);
        else
            results[i].setStartTime(records[i].getArrivalTime());
        totalTime = results[i].getStartTime()+records[i].getServiceTime();
        results[i].setFinishTime(totalTime);
        results[i].setTurnTime(results[i].getFinishTime() - records[i].getArrivalTime());
        results[i].setWeightTurnTime(results[i].getTurnTime()/(records[i].getServiceTime()*1.0));

    }

    //输出数据
    init.write(outfile,records,results,execOrder);
    return 1;
}
