#include "over.h"
using namespace std;
//以下是主函数
int main()
{
    cout<<"输入1表示选择引用输入数据，输入2表示引入所给文本数据"<<endl;
    cout<<"（这里默认使用分配三个物理块以及选择二十个页面）"<<endl;
    int n;
    cin>>n;
    if(n!=1&&n!=2) {
        cout<<"结束使用"<<endl;
        return 0;
    }
    test(n);
}
