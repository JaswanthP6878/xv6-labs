#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main(int argc, char *argv[]) 
{
    int p[2];
    pipe(p);
    int pid = fork();
    if (pid == 0) {  // child process
        char buf[512];
        read(p[0], buf, sizeof buf); 
        printf("%d: received ping\n", pid);
        write(p[1], "Hello", 5);
    } else { // parent process
        char buf1[512];
        write(p[1], "hello", 5);
        read(p[0], buf1, sizeof buf1);
        printf("%d: received pong\n", pid);
    }
    exit(0);
}