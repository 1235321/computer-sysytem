#include "../head/init/init.h"
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
Init::Init() {}

void Init::setJob(char job)
{
    this->job = job;
}
char Init::getJob()
{
    return this->job;
}

void Init::setArrivalTime(int arrivalTime)
{
    this->arrivalTime = arrivalTime;
}
int Init::getArrivalTime()
{
    return this->arrivalTime;
}

void Init::setServiceTime(int serviceTime)
{
    this->serviceTime = serviceTime;
}
int Init::getServiceTime()
{
    return this->serviceTime;
}

void Init::setStartTime(int startTime)
{
    this->startTime = startTime;
}
int Init::getStartTime()
{
    return this->startTime;
}

void Init::setFinishTime(int finishTime)
{
    this->finishTime = finishTime;
}
int Init::getFinishTime()
{
    return this->finishTime;
}

void Init::setTurnTime(int turnTime)
{
    this->turnTime = turnTime;
}
int Init::getTurnTime()
{
    return this->turnTime;
}

void Init::setWeightTurnTime(int weightTurnTime)
{
    this->weightTurnTime = weightTurnTime;
}
double Init::getWeightTurnTime()
{
    return this->weightTurnTime;
}

void Init::read(const char* file,vector<Init>& records)
{
    ifstream infile(file,ios::in);
    for(int i = 0 ; i < this->PROGRESS ; i++)
    {
        Init record;
        char job;
        int arrivalTime;
        int serviceTime;
        infile >> job;
        infile >> arrivalTime;
        infile >> serviceTime;
        record.setJob(job);
        record.setArrivalTime(arrivalTime);
        record.setServiceTime(serviceTime);
        records.push_back(record);
    }
    infile.close();
}

void Init::write(const char* file,vector<Init>& records,vector<Init>& results,vector<char>& execOrder)
{
    ofstream outfile(file,ios::out);
    outfile.precision(3);
    outfile << "��ҵ\t����ʱ��\t����ʱ��\t��ʼʱ��\t����ʱ��\t��תʱ��\t��Ȩ��תʱ��\n";
    double avgTurnTime = 0;
    double avgWeightTurnTime = 0;
    double size = records.size();
    for(int i=0; i<size; i++)
    {
        outfile << records[i].getJob() << "\t"
                << records[i].getArrivalTime() << "\t"
                << records[i].getServiceTime() << "\t"
                << results[i].getStartTime() << "\t"
                << results[i].getFinishTime() << "\t"
                << results[i].getTurnTime() << "\t"
                << results[i].getWeightTurnTime() << "\n";

        avgTurnTime += results[i].getTurnTime();
        avgWeightTurnTime += results[i].getWeightTurnTime();
    }
    outfile << "ƽ����תʱ�䣺" << avgTurnTime/size << "\n";
    outfile << "ƽ����Ȩ��תʱ�䣺" << avgWeightTurnTime/size << "\n";
    outfile << "ִ��˳�� ";
    for(int i=0; i<execOrder.size(); i++)
    {
        if(i!= execOrder.size()-1)
        {
            outfile << execOrder[i] << "->";
        }
        else
        {
            outfile << execOrder[i] << "\n";
        }
    }
    outfile.close();
}
