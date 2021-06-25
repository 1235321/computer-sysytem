#include "head/input.h"
#include <iostream>

using namespace std;

Input::Input()
{

}
int Input::printMenu()
{
    cout << "please input your choice(0-10):" << endl;
    cout << "0: exit" << endl;
    cout << "1: FCFS" << endl;
    cout << "2: SJF" << endl;
    cout << "3: HRRN" << endl;
    cout << "4: SRT" << endl;
    cout << "5: RR" << endl;
    cout << "6: BANKER" << endl;
    cout << "7: EDF" << endl;
    cout << "8: LLF" << endl;
    cout << "9: SPAt" << endl;
    cout << "10: SPAf" << endl;
    int menu = 0;
    cin >> menu ;
    return menu;
}
