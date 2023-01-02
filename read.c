#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>

void usage(char *prog_name,char *filename) {
    printf("Usage %s <data to add to %s>\n",prog_name,filename);
    exit(0);
}
void fatal(char *);
