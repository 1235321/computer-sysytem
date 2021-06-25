#include <iostream>
#include "head/input.h"
#include "head/output.h"
using namespace std;
int main()
{
    int fun = 1;
    while(fun)
    {
        Input in;
        Output out(in.printMenu());
        fun = out.printOut();
    }
    return 0;
}
