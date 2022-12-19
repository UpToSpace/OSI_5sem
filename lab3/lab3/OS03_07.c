#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
char *argv [] = {NULL};
execv("OS03_05_1",argv);
for(int i=0;i<100;i++)
{
printf("pid: %d, i: %d \n",getpid(), i);
sleep(1);
}
return 0;
}
