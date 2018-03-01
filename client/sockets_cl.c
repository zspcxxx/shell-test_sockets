#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <sys/un.h>
#include <sys/socket.h>
#include "error_handing.h"
#include "get_num.h"

#define SV_SOCK_PATH "/tmp/us_xfr"
#define BUF_SIZE 100

int 
main(int argc, char *argv[])
{
	struct sockaddr_un addr;
	int sfd;
	ssize_t numRead;
	char buf[BUF_SIZE];
	printf("00000000000000");
	sfd = socket(AF_UNIX, SOCK_STREAM, 0);   /* Create client socket */
	if (sfd == -1)
		usageErr("socket");
	
	printf("111111111111111");
		
	/* Construct server address, and make the connection */
	memset(&addr, 0, sizeof(struct sockaddr_un));
	addr.sun_family = AF_UNIX;
	strncpy(addr.sun_path, SV_SOCK_PATH, sizeof(addr.sun_path) - 1);
	
	printf("222222222222222");
	
	if (connect(sfd, (struct sockaddr *) &addr, sizeof(struct sockaddr_un)) == -1)
		usageErr("connect");
	
	printf("333333333333333333");
	/* Copy stdin to socket */
	while ((numRead = read(STDOUT_FILENO, buf, BUF_SIZE)) > 0)
		if (write(sfd, buf, numRead) != numRead)
			usageErr("partial/failed write");	
	printf("4444444444444444444");		
	if (numRead == -1)
		usageErr("read");
		
	exit(EXIT_SUCCESS);
}


