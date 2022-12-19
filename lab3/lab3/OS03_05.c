#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void cycle(int n, char* s)
{
for(int i = 0; i < n; i++)
{
sleep(1);
printf("%s: %d pid: %d\n", s, i, getpid());
}
};
int main()
{
pid_t pid;
switch(pid = fork())
{
case -1: perror("fork error"); exit(-1);
case 0: cycle(50, "child: os03_05_1");
default: cycle(100, "parent: os03_05");
}
exit(0);
}
