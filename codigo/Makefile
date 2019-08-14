CFLAGS = -Wall -pedantic -Werror
all: baash.cgi serverInfo.cgi delete.cgi modules.cgi upload.cgi

serverInfo.cgi: serverInfo.c
	cc -g $(CFLAGS) -o serverInfo.cgi serverInfo.c

delete.cgi: delete.c
	cc -g $(CFLAGS) -o delete.cgi delete.c

modules.cgi: modules.c
	cc -g $(CFLAGS) -o modules.cgi modules.c

upload.cgi: upload.c
	cc -g $(CFLAGS) -o upload.cgi upload.c

baash.cgi: Baash.c
	cc -g $(CFLAGS) -o baash.cgi Baash.c

clean :
	rm -f *.o *.cgi
