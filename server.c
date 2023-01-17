#include "server.h"
#define ERR -1

static char c;
static int bit;
void restore(int signum)
{
	if (signum == SIGUSR1)
		c += (0 << bit);
	else if (signum == SIGUSR2)
		c += (1 << bit);
	bit++;
}


void    receiver(void handler(int))
{
    struct sigaction    act;

    bzero(&act, sizeof(struct sigaction));
    act.sa_handler = handler;
    sigemptyset(&act.sa_mask);
    act.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR1, &act, NULL);
    sigaction(SIGUSR2, &act, NULL);
}

int main(void)
{
	int pid;

	pid = getpid();
	printf("%d\n", pid);
	receiver(restore);
	c = bit = 0;
	while(1)
	{
		pause();
		if (bit >= 8)
		{
			ft_putchar_fd(c, 1);
			c = 0;
			bit = 0;
		}
	}
	return(0);
}
