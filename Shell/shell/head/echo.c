#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc,char* argv[]){
    int m; //count
    int i;
    if(strcmp(argv[1],"-n")==0){
      for(m=2;m<argc;m++){         
         if(m<argc-1){
            printf("%s ",argv[m]);
            break;
         }else{
            printf("%s",argv[m]);
         }
      }
    }else{
      for(i=1;i<argc;i++){      
         if(i==argc-1){
            printf("%s%s",argv[i],"\n");
            break;
         }else{
            printf("%s ",argv[i]);
         }
      }
    }
    return 0;
}
