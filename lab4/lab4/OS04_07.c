#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/syscall.h>

void* OS04_07_T1(void* arg) {
pid_t tid = syscall(SYS_gettid);
pid_t pid = getpid();
for (int i = 0; i < 75; i++) {
sleep(1);
printf("OS04_07_T1 PID - %d, TID - %d, i - %d\n", getpid(), tid, i);	
}
pthread_exit("Child thread");
}

int main() {
pid_t tid = syscall(SYS_gettid);
pthread_t a_thread;
void* thread_result;
printf("main: PID: %d\n", getpid());
int pthread_status = pthread_create(&a_thread, NULL, OS04_07_T1, NULL);
if (pthread_status != 0) {
printf("cannot create thread, status = %d", pthread_status);
exit(-1);
}
for(int i = 0; i < 100; i++) {
sleep(1);
printf("main PID - %d, TID - %d, i - %d\n", getpid(), tid, i);
}
int status = pthread_join(a_thread, (void**)&thread_result);
if (status != 0) {
printf("cannot create thread, status = %d", status);
exit(-1);
}
exit(0);
}

