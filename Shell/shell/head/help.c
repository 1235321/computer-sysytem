#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

void help_help(){
	printf("help \n");
	printf("\thelp : 显示所有命令的使用格式以及作用\n");
	printf("\thelp order : 显示该命令的使用格式以及该命令的作用 \n");
}
void help_touch(){
	printf("touch \n");
	printf("\ttouch : touch filename(path/filename) 在当前目录创建一个文件/在指定路径创建\n");
	printf("\ttouch filename1(包括路径) filename2 filename3 : 在当前目录创建多个文件/在指定路径创建多个文件，同时更新文件的时间戳\n");
	printf("\t\t-a : touch -a filename,改变 filename 的读取时间记录\n");
	printf("\t\t-c : touch -c filename,如果 filename 不存在，不创建文件\n");
	printf("\t\t-m : touch -m filename,改变 filename 的修改时间记录\n");
}
void help_pwd(){
	printf("pwd \n");
	printf("\t\t-L : pwd –L,显示当前的路径，有连接文件时，直接显示连接文件的路径，(不加参数时默认此方式) \n");
	printf("\t\t-P : pwd –p,显示当前的路径，有连接文件时，不使用连接路径，直接显示连接文件所指向的文件，当包含多层连接文件时，显示连接文件最终指向的文件\n");
}
void help_wc(){
	printf("wc \n");
	printf("\t\t-c : wc -c filename,显示文件的字节数 \n");
	printf("\t\t-m : wc -m filename,显示文件的字符数 \n");
	printf("\t\t-l : wc -l filename,显示文件的行数 \n");
	printf("\t\t-L : wc -L filename,显示文件的最大行长度 \n");
	printf("\t\t-w : wc -w filename	,显示文件的单词数 \n");
}
void help_cat(){
	printf("cat \n");
	printf("\tcat file :（可打开当前路径下文件的内容）打开文件内容\n");
    printf("\tcat file1 file2 :（可打开当前路径下文件的内容）顺序打开文件file1和file2的内容\n");
}
void help_clear(){
	printf("clear \n");
	printf("\tclear : 实现Clear清屏操作\n");
}
void help_echo(){
	printf("echo \n");
	printf("\techo : 本身输出字符串\n");
	printf("\t\t-n : echo -n,不换行实现字符串 \n");
}
void help_ls(){
	printf("ls \n");
	printf("\tls : 列出当前目录下的文件\n");
}
void help_mkdir(){
	printf("mkdir \n");
	printf("\tmkdir direction : 在工作目录下，建立一个名为direction的子目录 \n");

}
void help_mv(){
	printf("mv \n");
	printf("\tmv test.log test1.txt : 将文件test.log重命名为test1.txt\n");
	printf("\tmv llog1.txt log2.txt log3.txt /test3 : 将文件log1.txt,log2.txt,log3.txt移动到根的test3目录中 \n");
}
void help_rm(){
	printf("rm \n");
	printf("\trm filename : 删除指定文件 \n");
}
void help_cp(){
	printf("cp \n");
	printf("\tcp file1 file2 : 复制文件file1为file2 \n");
    printf("\tcp file1 folder : 复制文件file1到folder \n");
    printf("\tcp folder1 folder2 : 复制文件夹folder1为folder2 \n");
}

int main(int argc,char* argv[]){
	if(argc == 1){	
		help_help();
		help_touch();
		help_pwd();
		help_wc();
		help_cat();
		help_clear(); 
		help_echo();
		help_ls();
		help_mkdir();
		help_mv();
		help_rm();
        help_cp();
	}
	else if(argc == 2){
		if (strcmp(argv[1],"help")==0)
        {
            help_help();
        }
        else if (strcmp(argv[1],"touch")==0)
        {
            help_touch();
        }
		else if (strcmp(argv[1],"pwd")==0)
        {
            help_pwd();
        }
		else if (strcmp(argv[1],"wc")==0)
        {
            help_wc();
        }
		else if (strcmp(argv[1],"cat")==0)
        {
            help_cat();
        }
        else if (strcmp(argv[1],"cp")==0)
        {
            help_cp();
        }
		else if (strcmp(argv[1],"clear")==0)
        {
            help_clear();
        }
		else if (strcmp(argv[1],"echo")==0)
        {
			help_echo();
        }
		else if (strcmp(argv[1],"ls")==0)
        {
            help_ls();
        }
		else if (strcmp(argv[1],"mkdir")==0)
        {
            help_mkdir();
        }
		else if (strcmp(argv[1],"mv")==0)
        {
            help_mv();
        }
		else if (strcmp(argv[1],"rm")==0)
        {
            help_rm();
        }
		else
		{
            printf("help command not found\n");
        }
	}
	else{
		printf("input invaild");
	}
}
