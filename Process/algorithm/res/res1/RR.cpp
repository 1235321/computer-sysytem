#include "../../head/res/res1/RR.h"
#include "../../head/init/init.h"

using namespace std;

int RR(){
    const char* inputfile = "./data/file.txt";
    const char* outfile = "./result/result1/RR.txt";
    Init init;
    vector<Init> records;

    init.read(inputfile,records);

    //RR算法
    int size = records.size();
    vector<Init> results(records.size());
    vector<char> execOrder;
    vector<int> jobList(size,0);
    vector<int> serviceList(size,0);
    queue<int> queue;

    int totalTime = 0;

    int slice = 1;

    for(int i=0;i<size;i++){
        serviceList[i]=records[i].getServiceTime();
    }

    int count =0;
    queue.push(count);
    serviceList[count] -=slice;
    count++;
    int tmp;
    while(!queue.empty()){
        tmp = queue.front();
        execOrder.push_back(records[tmp].getJob());
        queue.pop();
        if(jobList[tmp] == 0){
            results[tmp].setStartTime(totalTime);
            jobList[tmp] = 1;
        }
        totalTime += slice;



        if((count < size) && (jobList[count]==0)&&records[count].getArrivalTime() <= totalTime ){

            queue.push(count);
            serviceList[count] -=slice;
            if(serviceList[count] == 0){
                jobList[count] = -1;
            }
            count++;
        }

        if(serviceList[tmp] == 0){
            jobList[tmp] = -1;
            results[tmp].setFinishTime(totalTime);
            results[tmp].setTurnTime(results[tmp].getFinishTime() - records[tmp].getArrivalTime());
            results[tmp].setWeightTurnTime(results[tmp].getTurnTime()/(1.0*records[tmp].getServiceTime()));
        }

        if(jobList[tmp] != -1){
            queue.push(tmp);
            serviceList[tmp] -=slice;
            if(serviceList[tmp] == 0){
                jobList[tmp] = -1;
            }
        }
    }
    //输出数据
    init.write(outfile,records,results,execOrder);
    return 1;
}
