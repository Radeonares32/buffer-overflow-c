#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#define FILENAME "./notes" //data segment

int print_notes(int,int,char *);
int find_user_notes(int,int);
int search_note(char *,char *);

void fatal(char *);

int main(int argc,char *argv[]) {
 int userid,printing=1,fd;
 char searchstring[100];
 if(argc > 1)
 strcpy(searchstring,argv[1]);
 else
    searchstring[0] = 0;
 userid = getuid();
 fd = open(FILENAME,O_RDONLY); // Open the file for read-only access
 if(fd == -1) {
 fatal("in main() while opening file for reading !");
}
