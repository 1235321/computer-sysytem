#include "init.h"
using namespace std;
void PageInformation::OPT(PageInformation *headptr,PageInformation *headptrblock,int pagenum,int pagenumber,int &pagecounter)
{
    ofstream OutFile("OPT.txt");
	pagecounter=0;//��0
	PageInformation pi;
	pi.Directloading(headptr,headptrblock,pagenum,OutFile);
	int aid;
	int status=1;
	int counter[3];
	aid=3;
	int temp=0;
	for(int i = pagenum;i<pagenumber;i++)//�����ȱҳ���������ͽ����������ʱ����õ�һ��ҳ��ȡ����װ���µ�ҳ��
	{
		for(int j =0;j < pagenum;j++)
		{
			(headptrblock+j)->counter();//��Ӧ�����פ��ʱ��++

		}
		for(int j = 0;j < pagenum;j++)//��ȱҳ����ѭ��������һҳ���жϣ�ȱҳѰ��δ�����δʹ�õ�ҳ���û�֮
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
			(headptrblock+temp)->setpid((headptrblock+temp),(headptr+i)->getpid());//����ҳ��װ��������û���tempҳ��
			(headptrblock+temp)->resetcount();
		}

		cout<<"��"<<setw(2)<<i+1<<"��ҳ������ʱ�������ҳ��Ϊ��";
		OutFile<<"��"<<setw(2)<<i+1<<"��ҳ������ʱ�������ҳ��Ϊ��";
		for(int j = 0;j < pagenum;j++)
		{
			(headptrblock+j)->display();
			OutFile<<(headptrblock+j)->getpid()<<" ";
		}
		if(status)
		{
			cout<<"������ȱҳ��";
			OutFile<<"������ȱҳ��";
		}
		cout<<endl;
		OutFile<<endl;
		//����ʱ�ݴ��������
		temp=0;
		aid=3;
		status=1;
	}
	int pagecounterrate=((17-pagecounter+3)*100/20);
	cout<<"ʹ��OPT�㷨��ȱҳ��Ϊ��"<<17-pagecounter+3<<" ȱҳ��Ϊ��"<<pagecounterrate<<"\%"<<endl;
    OutFile<<"ʹ��OPT�㷨��ȱҳ��Ϊ��"<<17-pagecounter+3<<" ȱҳ��Ϊ��"<<pagecounterrate<<"\%"<<endl;
}//opt
