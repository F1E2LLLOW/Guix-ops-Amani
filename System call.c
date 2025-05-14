#define _GNU_SOURCE 
#include <sched.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
intchildFunc(void *arg) { 
printf("Hello from child process\n"); 
 return 0; 
} 
int main() { 
constint STACK_SIZE = 1024*1024; 
 char *stack = malloc(STACK_SIZE); 
 if (!stack) { 
perror("malloc"); 
 exit(1); 
 } 
intpid = clone(childFunc, stack + STACK_SIZE, SIGCHLD,  
NULL); 
 if (pid == -1) { 
perror("clone"); 
 exit(1); 
 } 
printf("Hello from parent process\n"); 
 wait(NULL); 
 return 0; 
}
