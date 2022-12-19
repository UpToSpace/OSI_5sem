#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <pthread.h>
#include <sys/syscall.h>
#include <sched.h>

int main(){
    pid_t pid = getpid();
    printf("OS06_07 PID %d\n", pid);

    void* memr = malloc(1024*1024 * 256);
    printf("memr(1024*1024*256) = %p\n", memr);

    int* arr = (int*) memr;
    for(int i = 0; i < 256; i++)
    {
        arr[i] = i;
    }

    sleep(2000000);
    exit(0);
}
