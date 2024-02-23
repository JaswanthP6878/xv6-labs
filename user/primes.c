#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main(int argc, char *argv[]) {
    int p[2];
    pipe(p);
    int pid = fork();
    if (pid > 0) {
        for(int i = 2; i <= 35; i++) {
             write(p[1], i, sizeof(i));
        }
        wait((int *) 0);
    } else { // child processes, these should spawn the left and righ parts
        int buf[1];
        int n = read(p[0], buf, sizeof(buf));
        if(n == 0) {
            exit(0);
        }
        int val = buf[0]; // val from left side
        for(;;) {
            int buf[1];
            int n = read(p[0], buf, sizeof(buf));
            if (n == 0) {
                break;
            }
            int new_val = buf[0];
            if (new_val % val != 0) {
            }
        }
    }

}