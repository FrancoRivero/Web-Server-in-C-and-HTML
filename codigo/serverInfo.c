
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

void cpu_info();
void kernel();
void up_time();
void meminfo();
void horayfecha();
char* formato_hora(int);
void find(char*, char*, char*);

int main(int argc, char const *argv[])
{
	cpu_info();
	up_time();
	meminfo();
	horayfecha();
	kernel();
	return 0;
}
void find(char* filename, char* line, char* coincidence)
{
    	char buffer[512];
 	char* found = NULL;
 	FILE* fd;
 	fd = fopen(filename,"r");

 	while(feof(fd) == 0)
 	{
 		fgets(buffer, 512, fd);
 		found = strstr(buffer, coincidence);
 		if(found != NULL) break;
 	}

 	fclose(fd);
 	strcpy(line,found);
 }
void cpu_info()
{
	char line[50];
    char a[] = "/proc/cpuinfo"; // enmascaro string
//    char b[] = "vendor_id";
    char c[] = "model name";
//	find(a, line, b); // busco tipo de cpu
//	sscanf(line, "vendor_id : %[^\n]c", line);
//	printf("Tipo: %s \n", line); 

	find(a, line, c); //busco modelo
	sscanf(line, "model name : %[^\n]c", line);
	printf("Modelo: %s \n", line);
}

void kernel()
{
	char line[1024];
	FILE *file;
	file = fopen("/proc/version", "r"); //busco info de version del kernel
	fscanf(file, "%[^\n]c", line);
	printf("Kernel: %s \n", line);
	fclose(file);
}

void up_time()
{
	char* line;
	FILE *file;
	int tiempo;
	file = fopen("/proc/uptime", "r");
	fscanf(file, "%i", &tiempo);
	line = formato_hora(tiempo); //convierto tiempo en segundos a dias:hs:min:ss
	printf("upTime: %s \n",  line);
	fclose(file);
}
char* formato_hora(int tiempo)
{
	int dias, horas, minutos;
	float segundos;
	static char c[32];

	dias = tiempo/86400;
	tiempo = tiempo%86400;
	horas = tiempo/3600;
	tiempo = tiempo%3600;
	minutos = tiempo/60;
	tiempo = tiempo%60;
	segundos = tiempo;

	if (dias > 0){
		sprintf(c, "%2u %02u:%02u:%02.2f", dias, horas, minutos, segundos);
	}
	else {			
		sprintf(c, "%02u:%02u:%02.2f", horas, minutos, segundos);
	}
	return c;
}
void meminfo()
{
    char line[256];
	int total,Disponible;
	char a[] = "/proc/meminfo"; // enmascaro string
	char b[] = "MemTotal";
	char c[] = "MemAvailable";
	find(a,line,b);
	sscanf(line,"MemTotal: %i", &total);
	printf("Memoria total: %i MB \n", total /1000);

	find(a,line,c);
	sscanf(line,"MemAvailable: %i", &Disponible);
	printf("Memoria Disponible: %i MB \n", Disponible /1000);
}
void horayfecha()
{
	time_t t;
  struct tm *tm;
  const char *meses[12]={"Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio", "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre"};

  t=time(NULL);
  tm=localtime(&t);
  printf ("Hoy es: %02d/%s/%d %02d:%02d:%02d \n", tm->tm_mday, meses[tm->tm_mon], 1900+tm->tm_year,tm->tm_hour,tm->tm_min,tm->tm_sec);

}
