#include "../../head/res/res1/SRT.h"
#include "../../head/init/init.h"

using namespace std;

int SRT(){
    const char* inputfile = "./data/file.txt";
    const char* outfile = "./result/result1/SRT.txt";
    Init init;
    vector<Init> records;

    init.read(inputfile,records);

    int size = records.size();
    vector<Init> results(records.size());
    vector<char> execOrder;
    vector<int> jobList(size,0);
    vector<int> serviceList(size,0);

    for(int i=0;i<size;i++){
        serviceList[i] = records[i].getServiceTime();
    }

    int totalTime = 0;
    int pretotalTime = 0;
    int finish = 0;
    int current = 0;


    for(int i= 0; i<size; i++){

        pretotalTime = totalTime;
        totalTime = records[i].getArrivalTime();


        serviceList[current] -= (totalTime - pretotalTime);
        execOrder.push_back(records[current].getJob());
        if(current!= 0 && jobList[current] !=0 && results[current].getStartTime() ==0  ){
            results[current].setStartTime(pretotalTime);
            jobList[current] =1;
        }


        jobList[i] = 1;

        if(serviceList[current] <= 0){
            pretotalTime = totalTime;
            totalTime +=serviceList[current];
            serviceList[current]=0;
            jobList[current] = -1;
            results[current].setFinishTime(totalTime);
            results[current].setTurnTime(results[current].getFinishTime()- results[current].getStartTime());
            results[current].setWeightTurnTime(results[current].getTurnTime()/(1.0*records[current].getServiceTime()));

            finish++;

        }

        if(pretotalTime > totalTime){

            jobList[i] = 0;
            i--;
        }

        int minIndex=-1;
        int minValue=9999;

        for(int k=0;k<size; k++){
            if((jobList[k] == 1) && minValue > serviceList[k]){
                minValue = serviceList[k];
                minIndex = k;
            }
        }
        current = minIndex;
    }

    while(finish < size){

        int minIndex = -1;
        int minValue = 9999;

        for(int k=0; k<size; k++){
            if((jobList[k]==1) && minValue > serviceList[k]){
                minIndex = k;
                minValue = serviceList[k];
            }
        }

        execOrder.push_back(records[minIndex].getJob());
        if(results[minIndex].getStartTime() == 0){
            results[minIndex].setStartTime(totalTime);
        }
        if(totalTime>records[minIndex].getArrivalTime())
            results[minIndex].setStartTime(totalTime);
        else
            results[minIndex].setStartTime(records[minIndex].getArrivalTime());
        totalTime = results[minIndex].getStartTime()+records[minIndex].getServiceTime();
        results[minIndex].setFinishTime(totalTime);
        results[minIndex].setTurnTime(results[minIndex].getFinishTime() - records[minIndex].getArrivalTime());
        results[minIndex].setWeightTurnTime(results[minIndex].getTurnTime()/(1.0*records[minIndex].getServiceTime()));
        jobList[minIndex] = -1;
        finish++;

    }

    //Êä³öÊý¾Ý
    init.write(outfile,records,results,execOrder);
    return 1;
}
