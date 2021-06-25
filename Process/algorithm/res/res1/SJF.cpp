#include "../../head/res/res1/SJF.h"
#include "../../head/init/init.h"

using namespace std;

int SJF(){
    const char* inputfile = "./data/file.txt";
    const char* outfile = "./result/result1/SJF.txt";
    Init init;
    vector<Init> records;

    init.read(inputfile,records);

    int size = records.size();
    vector<Init> results(records.size());
    vector<char> execOrder;
    vector<int> jobList(size);
    int totalTime = 0;

    for(int i=0; i<size; i++){
        jobList[i] = 0;
    }

    int finsh = 0;
    int count = 0;
    while(finsh < size){
        for(int i = count;i<size;i++){
            if(records[i].getArrivalTime() <= totalTime){
                jobList[i] = 1;
                count++;
            }
        }

        int minIndex = -1;
        int minValue = 9999;
        for(int i=0; i<size; i++){
            if(jobList[i] && minValue > records[i].getServiceTime()){
                minIndex = i;
                minValue = records[i].getServiceTime();
            }
        }

        execOrder.push_back(records[minIndex].getJob());
        if(totalTime>records[minIndex].getArrivalTime())
            results[minIndex].setStartTime(totalTime);
        else
            results[minIndex].setStartTime(records[minIndex].getArrivalTime());
        totalTime = results[minIndex].getStartTime()+records[minIndex].getServiceTime();
        results[minIndex].setFinishTime(totalTime);
        results[minIndex].setTurnTime(results[minIndex].getFinishTime() - records[minIndex].getArrivalTime());
        results[minIndex].setWeightTurnTime(results[minIndex].getTurnTime()/(1.0*records[minIndex].getServiceTime()));
        jobList[minIndex] = 0;
        finsh++;
    }

    //Êä³öÊý¾Ý
    init.write(outfile,records,results,execOrder);
    return 1;
}
