#include "client.h"
#define ERR -1
#define MAXBITS 8

void usage(char*);

void setkill(pid_t pid, int signum)
{
	if (kill(pid, signum) == ERR)
	{
		perror("kill error");
		exit(1);
	}
}

void    send_char(pid_t pid, char c)
{
	int             bit;
	int             i;

	i = 0;
	while (i < MAXBITS)
	{
		usleep(5000);
		bit = (c >> i) & 0x01;
		if (bit == 0)
			setkill(pid, SIGUSR1);
		else if (bit == 1)
			setkill(pid, SIGUSR2);
		i++;
	}
}

int main(int argc, char *argv[])
{
	pid_t serv_pid;
	int i;

	if (argc <= 2)
		usage(argv[0]);
	
	serv_pid = ft_atoi(argv[1]);
	i = 0;
	while (argv[2][i] != '\0')
		send_char(serv_pid, argv[2][i++]); 
	usleep(5000);
	return(0);
}

void usage(char* command_name)
{
	fprintf(stderr, "Usage: %s \n", command_name);
	exit(1);
}
