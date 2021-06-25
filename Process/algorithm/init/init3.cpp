#include "../head/init/init3.h"
#include <vector>
#include <fstream>
#include <string>
#include <iostream>
using namespace std;
void Init3::read(string infile,vector<Init3>& records)
{
    const int PROGRESS = 7;
    ifstream inFile(infile.c_str());

    if(!inFile.is_open())
    {
        cout<<"File open error."<<endl;
    }
    else
    {
        for (int i = 0 ; i < PROGRESS ; i++)
        {
            Init3 record;
            inFile >> record.job;
            inFile >> record.arrivalTime;
            inFile >> record.serviceTime;
            inFile >> record.limittime;
            record.achieveTime = record.arrivalTime;
            record.actionTime = 0;
            records.push_back(record);
        }
        inFile.close();
    }
}
Init3::Init3(){}
