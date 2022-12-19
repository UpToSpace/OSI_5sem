#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/syscall.h>

int main() {
	pid_t pid = getpid();
	nice(0);

	for(int i = 0; i < 1000000; i++) {
		printf("os05_05: PID = %d\n", pid);
		sleep(1);
	}
	
	exit(0);
}
