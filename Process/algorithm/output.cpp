#include "head/output.h"
#include <iostream>
#include "head/init/init.h"
#include "head/init/init2.h"
#include "head/init/init3.h"
#include "head/init/init4.h"
#include "head/res/res1/FCFS.h"
#include "head/res/res1/SJF.h"
#include "head/res/res1/HRRN.h"
#include "head/res/res1/SRT.h"
#include "head/res/res1/RR.h"
#include "head/res/res2/BANKER.h"
#include "head/res/res3/EDF.h"
#include "head/res/res3/LLF.h"
#include "head/res/res4/PSAt.h"
#include "head/res/res4/PSAf.h"
using namespace std;

Output::Output()
{
    this->num = 0;
}
Output::Output(int num)
{
    this->num = num;
}
int Output::printOut()
{
    AL psat1,psaf1;
    switch(this->num)
    {
    case exit:
        cout << "exit successfully!" << endl;
        break;
    case fcfs:
        if(FCFS())
            cout << "Succeed in doing FCFS!" << endl;
        else
            cout << "Fail to do FCFS" << endl;
        break;
    case sjf:
        if(SJF())
            cout << "Succeed in doing SJF!" << endl;
        else
            cout << "Fail to do SJF" << endl;
        break;
    case hrrn:
        if(HRRN())
            cout << "Succeed in doing HRRN!" << endl;
        else
            cout << "Fail to do HRRN" << endl;
        break;
    case srt:
        if(SRT())
            cout << "Succeed in doing SRT!" << endl;
        else
            cout << "Fail to do SRT" << endl;
        break;
    case rr:
        if(RR())
            cout << "Succeed in doing RR!" << endl;
        else
            cout << "Fail to do RR" << endl;
        break;
    case banker:
        if(BANKER())
            cout << "Succeed in doing BANKER!" << endl;
        else
            cout << "Fail to do BANKER" << endl;
        break;
    case edf:
        if(EDF())
            cout << "Succeed in doing EDF!" << endl;
        else
            cout << "Fail to do EDF" << endl;
        break;
    case llf:
        if(LLF())
            cout << "Succeed in doing LLF!" << endl;
        else
            cout << "Fail to do LLF" << endl;
        break;
    case psat:
        if(psat1.PSAt())
            cout << "Succeed in doing PSAt!" << endl;
        else
            cout << "Fail to do PSAt" << endl;
        break;
    case psaf:
        if(psaf1.PSAf())
            cout << "Succeed in doing PSAf!" << endl;
        else
            cout << "Fail to do PSAf" << endl;
        break;
    }
    if(this->num <= 10 && this->num >= 0)
    {
        return this->num;
    }
    else
    {
        cout << "terrible input : is not(0-10),will exit quickly" << endl;
        return 0;
    }
}
