#include "init.h"
using namespace std;
void PageInformation::OPT(PageInformation *headptr,PageInformation *headptrblock,int pagenum,int pagenumber,int &pagecounter)
{
    ofstream OutFile("OPT.txt");
	pagecounter=0;//置0
	PageInformation pi;
	pi.Directloading(headptr,headptrblock,pagenum,OutFile);
	int aid;
	int status=1;
	int counter[3];
	aid=3;
	int temp=0;
	for(int i = pagenum;i<pagenumber;i++)//如果有缺页现象发生，就将存入物理块时间最久的一个页面取出，装入新的页面
	{
		for(int j =0;j < pagenum;j++)
		{
			(headptrblock+j)->counter();//对应物理块驻留时间++

		}
		for(int j = 0;j < pagenum;j++)//无缺页跳出循环进行下一页面判断，缺页寻找未来最久未使用的页面置换之
		{
			if((headptrblock+j)->getpid()==(headptr+i)->getpid())
			{
				status=0;
				pagecounter++;
			}
		}
		for(int j = 0;j < pagenum;j++)
		{
			for(int k = i;k < pagenumber;k++)
			{
				if((headptrblock+j)->getpid() == (headptr+k)->getpid())
				{
					counter[j]=k;
					break;
				}
				else
					counter[j]=21;
			}
		}
		for(int j = 0;j < pagenum;j++)
		{
			if(counter[j] > aid)
			{
				aid=counter[j];
				temp=j;
			}
		}
		if(status)
		{
			(headptrblock+temp)->setpid((headptrblock+temp),(headptr+i)->getpid());//将新页面装入物理块置换掉temp页面
			(headptrblock+temp)->resetcount();
		}

		cout<<"第"<<setw(2)<<i+1<<"新页面载入时各物理块页号为：";
		OutFile<<"第"<<setw(2)<<i+1<<"新页面载入时各物理块页号为：";
		for(int j = 0;j < pagenum;j++)
		{
			(headptrblock+j)->display();
			OutFile<<(headptrblock+j)->getpid()<<" ";
		}
		if(status)
		{
			cout<<"！发生缺页！";
			OutFile<<"！发生缺页！";
		}
		cout<<endl;
		OutFile<<endl;
		//将临时暂存变量更新
		temp=0;
		aid=3;
		status=1;
	}
	int pagecounterrate=((17-pagecounter+3)*100/20);
	cout<<"使用OPT算法的缺页数为："<<17-pagecounter+3<<" 缺页率为："<<pagecounterrate<<"\%"<<endl;
    OutFile<<"使用OPT算法的缺页数为："<<17-pagecounter+3<<" 缺页率为："<<pagecounterrate<<"\%"<<endl;
}//opt
