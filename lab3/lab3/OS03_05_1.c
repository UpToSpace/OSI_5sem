#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
pid_t pid = getpid();
for(int i = 0; i < 7; i++)
{
sleep(1);
printf("pid: %d, %d\n", pid, i);
}
exit(0);
}
