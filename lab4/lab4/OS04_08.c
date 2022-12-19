#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/syscall.h>

void* OS04_08_T1(void* arg) {
pid_t tid = syscall(SYS_gettid);
pid_t pid = getpid();
for (int i = 0; i < 75; i++) {
sleep(1);
printf("OS04_08_T1 PID - %d, TID - %d, i - %d\n", getpid(), tid, i);	
if (i == 50) {
printf("\n\n--Thread OS04_08_T1 sleep--\n\n");
sleep(10);
}
}
pthread_exit(NULL);
}

int main() {
pid_t tid = syscall(SYS_gettid);
pthread_t a_thread;
void* thread_result;
printf("main: PID: %d\n", getpid());
int pthread_status = pthread_create(&a_thread, NULL, OS04_08_T1, NULL);
if (pthread_status != 0) {
printf("cannot create thread, status = %d", pthread_status);
exit(-1);
}
for(int i = 0; i < 100; i++) {
sleep(1);
printf("main PID - %d, TID - %d, i - %d\n", getpid(), tid, i);
if (i == 30) {
printf("\n\n--Thread main sleep--\n\n");
sleep(15);
}
}
int status = pthread_join(a_thread, (void**)&thread_result);
if (status != 0) {
printf("cannot create thread, status = %d", status);
exit(-1);
}
exit(0);
}
