#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/syscall.h>

int main() 
{
	pid_t tid = gettid();
	pid_t pid = getpid();
	int cnice = nice(0);
	printf("OS05_04 PID, TID: %d, %d\n", pid, tid);
	printf("nice %d\n", cnice);
	cpu_set_t set;
	CPU_ZERO(&set);
	if(sched_getaffinity(0, sizeof(cpu_set_t), &set) == 0) {
		int is = 0;
		for(int i = 0; i < CPU_SETSIZE; i++) {
			is = CPU_ISSET(i, &set);
			if(is) printf("CPU = %i is %s\n", i, "set");
		}
	}
	else printf("sched_getaffinity error");	
	
	exit(0);
}
