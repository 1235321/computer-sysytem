#include "init.h"
using namespace std;
void PageInformation::FIFO(PageInformation *headptr,PageInformation *headptrblock,int pagenum,int pagenumber,int &pagecounter)
{
    ofstream OutFile("FIFO.txt");
    PageInformation pi;
    pi.Directloading(headptr,headptrblock,pagenum,OutFile);
	pagecounter=0;//��0
	int status=1;
	int temp=0;
	for(int i = pagenum;i < pagenumber;i++)//�����ȱҳ���������ͽ����������ʱ����õ�һ��ҳ��ȡ����װ���µ�ҳ��
	{
		for(int j =0;j < pagenum;j++)
		{
			(headptrblock+j)->counter();//��Ӧ�����פ��ʱ��++

		}
		for(int j = 0;j < pagenum;j++)//��ȱҳ����ѭ��������һҳ���жϣ�ȱҳѰ��פ��ʱ�����ҳ���û�֮
		{
			if((headptrblock+j)->getpid()==(headptr+i)->getpid())
			{
				status=0;
				pagecounter++;
			}
		}
		for(int j = 0;j < pagenum;j++)
		{
			if((headptrblock+j)->getcount() > (headptrblock+temp)->getcount())
				temp=j;
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
		status=1;
	}
	int pagecounterrate=((17-pagecounter+3)*100/20);
	cout<<"ʹ��FIFO�㷨��ȱҳ��Ϊ��"<<17-pagecounter+3<<" ȱҳ��Ϊ��"<<pagecounterrate<<"\%"<<endl;
	OutFile<<"ʹ��FIFO�㷨��ȱҳ��Ϊ��"<<17-pagecounter+3<<" ȱҳ��Ϊ��"<<pagecounterrate<<"\%"<<endl;

}//fifo
