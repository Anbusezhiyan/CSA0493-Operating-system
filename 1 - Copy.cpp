#include<stdio.h>
#include<unistd.h>
int main()
{
printf("process id:%d\n",getpid() );
printf("parent process id:%d\n",getpid() );
return 0;
}
