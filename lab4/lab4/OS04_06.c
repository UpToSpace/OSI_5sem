#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>

int main() {
pid_t tid = gettid();
for(int i = 1; i < 1000; i++) {
sleep(2);
printf("OS04_06_T1 PID - %d, TID - %d, i - #%d\n",getpid(), tid, i);		
}
exit(0);
}
