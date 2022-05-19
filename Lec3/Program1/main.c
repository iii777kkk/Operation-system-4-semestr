#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/types.h>

int main() {

 int pid = fork();
 //создание процесса-потомка
 
 switch(pid) {
 case -1: //процесс не был создан
 
 perror("fork");
 //вывод ошибки
 return -1;
 
 case 0: //Процесс был создан
 
 printf("my pid = %i, returned pid = %i\n", getpid(), pid);
 break;
 
 default:
 printf("my pid = %i, returned pid = %i\n", getpid(), pid); break;
 
 }
 
return 0;
} 
