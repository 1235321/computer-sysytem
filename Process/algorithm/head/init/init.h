#ifndef _INIT_H_
#define _INIT_H_
#include <vector>
using namespace std;
class Init
{
private:
    char job;
    int arrivalTime;
    int serviceTime;
    int startTime;
    int finishTime;
    int turnTime;
    double weightTurnTime;
public:
    static const int PROGRESS = 6;

    Init();

    void setJob(char job);
    char getJob();

    void setArrivalTime(int arrivalTime);
    int getArrivalTime();

    void setServiceTime(int serviceTime);
    int getServiceTime();

    void setStartTime(int startTime);
    int getStartTime();

    void setFinishTime(int finishTime);
    int getFinishTime();

    void setTurnTime(int turnTime);
    int getTurnTime();

    void setWeightTurnTime(int weightTurnTime);
    double getWeightTurnTime();

    void read(const char* file,vector<Init>& records);
    void write(const char* file,vector<Init>& records,vector<Init>& results,vector<char>& execOrder);
};
#endif // _INIT
