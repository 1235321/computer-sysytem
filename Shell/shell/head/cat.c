#include <stdio.h>  
void file_copy(FILE * file1,FILE * file2);
int main(int argc,char *argv[])  
{  
    FILE * fp;  
    if(argc == 1)  
        file_copy(stdin,stdout);  
    else  
        while(--argc > 0)   //循环遍历，取出相应文件名进行进行相应的文件读取操作
        {  
            if((fp = fopen(*++argv,"r")) == NULL)  
            {  
                printf("no such file %s\n",*argv);  
                return 1;  
            }  
            else  
            {  
                file_copy(fp,stdout);  
                fclose(fp);  
            }  
        }  
    return 0;  
} 
void file_copy(FILE * file1,FILE * file2)  
{  
    int c;  

    while((c = getc(file1)) != EOF)  
    {  
        putc(c,file2);  
    }  
}