#include "over.h"
using namespace std;
void test(int n){
    int pagenum=3;				//ҳ����-�������
    int pagenumber=20;		    //ҳ������
    int pagecounter=0;
	time_t Time;
	time(&Time);
	int control;
	PageInformation *headptr = new PageInformation[pagenumber];    //����ҳ������
	PageInformation *headptrblock = new PageInformation[pagenum];  //����ҳ��
    PageInformation *headptr1 = new PageInformation[pagenumber];    //����ҳ������
	PageInformation *headptrblock1 = new PageInformation[pagenum];  //����ҳ��
    PageInformation *headptr2 = new PageInformation[pagenumber];    //����ҳ������
	PageInformation *headptrblock2 = new PageInformation[pagenum];  //����ҳ��
	PageInformation pi;

	if(n == 1)//�Ƿ���main�����������
	{
		cout <<  "��ǰϵͳʱ����:" << ctime(&Time) ;
		cout<<"ѡ��Ӽ��̶������ݿ�1��Ĭ��ѡ�������������"<<endl;
		int status;
		cout<<"���������ѡ��";
		cin>>status;
		if(status == 1)
		{
			cout<<"���Ӽ����ж������ݣ�"<<endl;
			cout<<"�����������õĶ�ʮ��ҳ�棩"<<endl;

			for(int i = 0;i < pagenumber;i++)
			{
				int m = (headptr+i)->setpid();
				(headptr1+i)->setpid2(m);
				(headptr2+i)->setpid2(m);
			}
		}
		else
		{
			cout<<"(�����������)"<<endl;
			srand((unsigned) time (&Time));//srand((unsigned) time (NULL));Ҳ���Դ����ָ��
			cout<<"�������ҳ������Ϊ��";
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
	else//���ļ��ж�������
	{
	    cout<<"(Ĭ�ϴ�test.txt�����ı��Ķ�ȡ)"<<endl;
		cout<<"(�ļ���������)"<<endl;
		ifstream in("test.txt");
		if(in.is_open())
		{
			cout << "�ļ��򿪳ɹ���"<<endl;
		}
		else
		{
			cout << "�ļ���ʧ�ܣ�";
			exit(0);
		}
		cout<<"����ȡ��ҳ������Ϊ��";
		int j=0;
		for(int p; in>>p; )
		{
			(headptr+j)->setpidrand((headptr+j),p);//���ļ����ݶ���
			(headptr1+j)->setpidrand((headptr1+j),p);//���ļ����ݶ���
			(headptr2+j)->setpidrand((headptr2+j),p);//���ļ����ݶ���
			cout<<p<<" ";
			j++;
		}
		in.close();
		cout<<endl;
	}
	do
	{
		cout <<  "��ǰϵͳʱ����:" << ctime(&Time) <<endl;
		cout<<"|============================ҳ���û��㷨=======================|"<<endl
			<<"|                        *1.OPT����û��㷨	                       |"<<endl
			<<"|                        *2.FIFO�Ƚ��ȳ��û��㷨                    |"<<endl
			<<"|                        *3.LRU������δʹ���û��㷨               |"<<endl
			<<"|                        *0.�˳�                                    |"<<endl
			<<endl;
		cout<<"���������ָ�";
		enum set_number {exit,opt,fifo,lru};
		cin>>control;
		switch(control)
		{
		case opt:
				system("cls");
				cout<<"��OPT����û��㷨��"<<endl;
				pi.OPT(headptr,headptrblock,pagenum,pagenumber,pagecounter);
				break;
		case fifo:
				system("cls");
				cout<<"��FIFO�Ƚ��ȳ��û��㷨��"<<endl;
				pi.FIFO(headptr1,headptrblock1,pagenum,pagenumber,pagecounter);
				break;
		case lru:
				system("cls");
				cout<<"��LRU������δʹ���û��㷨��"<<endl;
				pi.LRU(headptr2,headptrblock2,pagenum,pagenumber,pagecounter);
				break;
		case exit:
				cout<<"                         1���������"<<endl;
				Sleep(1000);
				break;
		default:
				cout<<"                         ����������������룺";
				Sleep(1000);
				system("cls");
		}
	}
	while(control!=0);
	delete[] headptr;
	delete[] headptr1;
	delete[] headptr2;

}
