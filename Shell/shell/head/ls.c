#include <sys/stat.h>	
#include <fcntl.h>		
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
 
/*
在Linux系统中，dirent结构体定义如下：  
struct dirent  
{  
    ino_t          d_ino;       //inode number 
    off_t          d_off;       //offset to the next dirent   
    unsigned short d_reclen;    //length of this record 
    unsigned char  d_type;      //type of file  
    char           d_name[256]; //filename  
};
*/
 
int main(int argc,char *argv[])
{
 
	DIR *dir;    //目录流指针
	struct dirent *rent;    //dirent结构体
 
	dir=opendir(".");    //打开当前目录
 
	char str[100];
	memset(str,0,100);
	
	while((rent=readdir(dir)))
	{
		strcpy(str,rent->d_name);
		if(str[0]=='.')
			continue;
		printf("%s  ",str);
		
	}
	//换行
	//printf("\n");
	puts("");	
 
	closedir(dir);
	
	return 0;
}
