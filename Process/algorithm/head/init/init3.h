#ifndef _INIT3_H_
#define _INIT3_H_
#include <string>
#include <vector>
using namespace std;
class Init3
{
public:
   string job;
   int arrivalTime;
   int actionTime;
   int achieveTime;
   int serviceTime;
   int limittime; //
   int Slackness; //

   Init3();
   void read(string infile,vector<Init3>& records);
};
#endif // _INTI3_H_
