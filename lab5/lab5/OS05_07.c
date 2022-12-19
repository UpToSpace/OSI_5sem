#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <sys/syscall.h>

void forkedthread() {
	pid_t pid = getpid();
	
	for(int i = 0; i < 1000000; i++) {
		if(i == 10) {
			setpriority(PRIO_PROCESS, 0, -10);
		}
		printf("child thread: PID = %d\n", pid);
		sleep(1);
	}
}

void mainthread() {
	pid_t pid = getpid();
	for(int i = 0; i < 1000000; i++) {
		printf("os05_07 main thread: PID = %d\n", pid);
		sleep(1);
	}
}

int main() {
	pid_t pid;
	switch(pid = fork()) {
		case -1: 
			perror("fork error");
			exit(-1);
		case 0:
			forkedthread();
		default:
			mainthread();
			wait(NULL);	
	}
}
