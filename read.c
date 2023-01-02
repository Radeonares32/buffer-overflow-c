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
int find_user_note(int fd,int user_uid) {
int note_uid = 1;
unsigned char byte;
int length;
while(note_uid != user_uid) {
if(read(fd,&note_uid,4) != 4)
    return -1;
if(read(fd,&byte,1) !=1)
    return -1;
byte = length = 0;
while(byte != '\n')  {
    if(read(fd,&byte,1) != 1) {
        return -1;
    }
    length++;
}
}
lseek(fd,length * -1,SEEK_CUR);
printf("[DEBUG] found a %d byte note for user id %d\n",length,note_uid);
return length;
}

