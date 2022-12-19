#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
system("./OS03_05_1");
for(int i = 0; i < 100; i++){
printf("%d \n", getpid());
sleep(1);
}
return 0;
} 
