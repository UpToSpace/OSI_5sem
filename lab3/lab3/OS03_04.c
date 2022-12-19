#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
pid_t pid = getpid();
for (int i = 1; i < 1000; i++)
{
sleep(1);
printf("%d-%d\n", pid, i);
}
exit(0);
}
