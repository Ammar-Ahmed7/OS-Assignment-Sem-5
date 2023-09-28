#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "simple.h"
#include "util.c"

int loop=0;

int main(int argc,char *argv[]) {
char *smlload=argv[1];
load(smlload);
    do {
    
        system("clear");
        printf("\n\n");       
        store();
        display();
        execute();
        loop++;
        getchar();
    } while (loop != 99);
    return 0;
}

