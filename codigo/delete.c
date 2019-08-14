#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(void)
{
	char *data;
	char module[20];
	data = getenv("QUERY_STRING");
	sscanf(data,"module=%s",module);
	char command[200]="sudo rmmod ";
	strcat(command,module);
	fflush(0);
	system(command);
	printf("Modulo: %s Eliminado correctamente",module);
	return 0;
}
