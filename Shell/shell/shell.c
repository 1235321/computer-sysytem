#include<stdio.h>
#include<string.h>
#include<signal.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
#include<fcntl.h>
#include<sys/utsname.h>
#include<sys/stat.h>
#include<sys/wait.h>
#include<sys/ptrace.h>
#include<sys/types.h>
#include<pwd.h>
#define MAX 1024
#define MAX_COMM 100

char cwd[MAX];  //保存当前路径

void print_prompt()
{
    // 调用uname获取系统信息
    struct utsname uname_ptr;
	struct passwd *pid_to_name;
    uname(&uname_ptr);
	pid_to_name = getpwuid(getuid());
    //调用 getcwd 获取当前路径名，并存储在 cwd 指向的字符串
    getcwd(cwd, sizeof(cwd));
    //setbuf(stdout, NULL);       //禁用 buffer， 直接将 printf 要输出的内容输出
    printf("$%s@%s:%s$> ",pid_to_name->pw_name,uname_ptr.sysname, cwd); 
    fflush(stdin);
}
int main(){
	while(1){
	print_prompt();
        int size = 1024;
        int argc = 0;
        char* buff = (char*)malloc(size);
        char *str = fgets(buff,size,stdin);
        buff[strlen(buff)-1] = '\0';
        char *s = " ";
        char *p;
        char* argv[size];
		memset(argv,0,sizeof(argv));
	if(strlen(str)!=0)
		p = strtok(str,s);	
	else
		continue;	
        while(p != NULL){
            argv[argc] = p;
            argc++;
            p = strtok(NULL,s);
        }
		if(strcmp(argv[0],"exit")==0)
		{
			printf("%s\n","exit success");
			break;
		}
		else
		{
			int pid = fork();
			if (pid == 0)
			{
				if (strcmp(argv[0],"help")==0)
					execv("./tool/help",argv);                             
				else if (strcmp(argv[0],"touch")==0)
					execv("./tool/touch",argv);
				else if (strcmp(argv[0],"pwd")==0)
					execv("./tool/pwd",argv);
				else if (strcmp(argv[0],"wc")==0)
					execv("./tool/wc",argv);
				else if (strcmp(argv[0],"cat")==0)
					execv("./tool/cat",argv);
               	else if (strcmp(argv[0],"cp")==0)
					execv("./tool/cp",argv);
				else if (strcmp(argv[0],"clear")==0)
					execv("./tool/clear",argv);
				else if (strcmp(argv[0],"echo")==0)
					execv("./tool/echo",argv);
				else if (strcmp(argv[0],"ls")==0)
					execv("./tool/ls",argv);
				else if (strcmp(argv[0],"mkdir")==0)
					execv("./tool/mkdir",argv);
				else if (strcmp(argv[0],"mv")==0)
					execv("./tool/mv",argv);
				else if (strcmp(argv[0],"rm")==0)
					execv("./tool/rm",argv);
				else
					execv("./tool/command",argv);
			}
			else if (pid == -1)
				printf("create fill\n");
			else 
				wait(NULL);
		}
    }
	return 0;
}