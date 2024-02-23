#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main(int argc , char *argv[]) 
{
    char *time;
    if (argc <= 1) {
        fprintf(2, "usage: sleep pattern [time to sleep]\n");
        exit(1);
    }
    time = argv[1];
    int time_int = atoi(time);
    int val = sleep(time_int);
    if (val < 0) {
        fprintf(2, "Sleep call failed");
        exit(1);
    }
    exit(0);
}