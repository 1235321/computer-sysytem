#include "../../head/res/res1/HRRN.h"
#include "../../head/init/init.h"

using namespace std;

int HRRN(){
    const char* inputfile = "./data/file.txt";
    const char* outfile = "./result/result1/HRRN.txt";
    Init init;
    vector<Init> records;

    init.read(inputfile,records);

    //HRRN算法实现
    vector<Init> results(records.size());
    vector<char> execOrder;
    int size = records.size();
    int totalTime = 0;
    vector<int> jobList(size);
    vector<double> priorityList(size);
    for(int i=0; i<size; i++){
        priorityList[i] = 0.;
        jobList[i] = 0;
    }

    int finish =0;
    while(finish < size ){

        for(int i = 0; i<size;i++){
            if(jobList[i] != -1 && records[i].getArrivalTime() <= totalTime){
                jobList[i] = 1;
                priorityList[i] = (totalTime - records[i].getArrivalTime() + records[i].getServiceTime())/(records[i].getServiceTime()*1.0);

            }
        }

        int maxIndex = -1;
        int maxValue = -1;
        for(int i=0; i<size; i++){
            if(jobList[i]==1 && maxValue < priorityList[i]){
                maxIndex = i;
                maxValue = priorityList[i];
            }
        }
        execOrder.push_back(records[maxIndex].getJob());
        if(totalTime>records[maxIndex].getArrivalTime())
            results[maxIndex].setStartTime(totalTime);
        else
            results[maxIndex].setStartTime(records[maxIndex].getArrivalTime());
        totalTime = results[maxIndex].getStartTime()+records[maxIndex].getServiceTime();
        results[maxIndex].setFinishTime(totalTime);
        results[maxIndex].setTurnTime(results[maxIndex].getFinishTime() - records[maxIndex].getArrivalTime());
        results[maxIndex].setWeightTurnTime(results[maxIndex].getTurnTime()/(1.0*records[maxIndex].getServiceTime()));

        jobList[maxIndex] = -1;

        finish++;
    }

    //输出数据
    init.write(outfile,records,results,execOrder);
    return 1;
}
