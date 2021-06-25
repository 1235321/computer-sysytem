#include "over.h"
using namespace std;
void test(int n){
    int pagenum=3;				//页框数-物理块数
    int pagenumber=20;		    //页面数量
    int pagecounter=0;
	time_t Time;
	time(&Time);
	int control;
	PageInformation *headptr = new PageInformation[pagenumber];    //生成页面序列
	PageInformation *headptrblock = new PageInformation[pagenum];  //生成页框
    PageInformation *headptr1 = new PageInformation[pagenumber];    //生成页面序列
	PageInformation *headptrblock1 = new PageInformation[pagenum];  //生成页框
    PageInformation *headptr2 = new PageInformation[pagenumber];    //生成页面序列
	PageInformation *headptrblock2 = new PageInformation[pagenum];  //生成页框
	PageInformation pi;

	if(n == 1)//是否向main函数传入参数
	{
		cout <<  "当前系统时间是:" << ctime(&Time) ;
		cout<<"选择从键盘读入数据扣1，默认选择随机生成数据"<<endl;
		int status;
		cout<<"请输入你的选择：";
		cin>>status;
		if(status == 1)
		{
			cout<<"（从键盘中读入数据）"<<endl;
			cout<<"（请输入来访的二十个页面）"<<endl;

			for(int i = 0;i < pagenumber;i++)
			{
				int m = (headptr+i)->setpid();
				(headptr1+i)->setpid2(m);
				(headptr2+i)->setpid2(m);
			}
		}
		else
		{
			cout<<"(随机生成数据)"<<endl;
			srand((unsigned) time (&Time));//srand((unsigned) time (NULL));也可以传入空指针
			cout<<"随机生成页面序列为：";
			for(int i = 0;i < pagenumber;i++)
			{
			    int m = (int)rand()%10;
				(headptr+i)->setpidrand((headptr+i),m);
				(headptr1+i)->setpidrand((headptr1+i),m);
                (headptr2+i)->setpidrand((headptr2+i),m);
                cout<<m<<" ";
			}
			cout<<endl;
		}
	}
	else//从文件中读入数据
	{
	    cout<<"(默认从test.txt进行文本的读取)"<<endl;
		cout<<"(文件读入数据)"<<endl;
		ifstream in("test.txt");
		if(in.is_open())
		{
			cout << "文件打开成功！"<<endl;
		}
		else
		{
			cout << "文件打开失败！";
			exit(0);
		}
		cout<<"所读取的页面序列为：";
		int j=0;
		for(int p; in>>p; )
		{
			(headptr+j)->setpidrand((headptr+j),p);//将文件数据读入
			(headptr1+j)->setpidrand((headptr1+j),p);//将文件数据读入
			(headptr2+j)->setpidrand((headptr2+j),p);//将文件数据读入
			cout<<p<<" ";
			j++;
		}
		in.close();
		cout<<endl;
	}
	do
	{
		cout <<  "当前系统时间是:" << ctime(&Time) <<endl;
		cout<<"|============================页面置换算法=======================|"<<endl
			<<"|                        *1.OPT最佳置换算法	                       |"<<endl
			<<"|                        *2.FIFO先进先出置换算法                    |"<<endl
			<<"|                        *3.LRU最近最久未使用置换算法               |"<<endl
			<<"|                        *0.退出                                    |"<<endl
			<<endl;
		cout<<"请输入你的指令：";
		enum set_number {exit,opt,fifo,lru};
		cin>>control;
		switch(control)
		{
		case opt:
				system("cls");
				cout<<"（OPT最佳置换算法）"<<endl;
				pi.OPT(headptr,headptrblock,pagenum,pagenumber,pagecounter);
				break;
		case fifo:
				system("cls");
				cout<<"（FIFO先进先出置换算法）"<<endl;
				pi.FIFO(headptr1,headptrblock1,pagenum,pagenumber,pagecounter);
				break;
		case lru:
				system("cls");
				cout<<"（LRU最近最久未使用置换算法）"<<endl;
				pi.LRU(headptr2,headptrblock2,pagenum,pagenumber,pagecounter);
				break;
		case exit:
				cout<<"                         1秒后程序结束"<<endl;
				Sleep(1000);
				break;
		default:
				cout<<"                         输入错误！请重新输入：";
				Sleep(1000);
				system("cls");
		}
	}
	while(control!=0);
	delete[] headptr;
	delete[] headptr1;
	delete[] headptr2;

}
