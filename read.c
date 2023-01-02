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
while(printing){
printing = print_notes(fd,userid,searchstring);
}
printf("----------- [end of note data] ------------ \n");
close(fd);
}

int print_notes(int fd,int uid,char *searchstring) {
int note_length;
char byte = 0,note_buffer[100];
note_length = find_user_notes(fd,uid);
if(note_length == -1) // if end of file reached
    return 0;
read(fd,note_buffer,note_length); //Read note data
note_buffer[note_length] = 0;
if(search_note(note_buffer,searchstring)){
printf(note_buffer);
}
return 1;
}

