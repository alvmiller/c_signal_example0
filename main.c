#include <signal.h>
#include <stdio.h>
#include <strings.h>
#include <unistd.h>
#include <stdlib.h>

/*
https://pvs-studio.com/en/blog/posts/cpp/0950/
https://www.codequoi.com/en/sending-and-intercepting-a-signal-in-c/
https://faculty.cs.niu.edu/~hutchins/csci480/signals.htm
https://www.geeksforgeeks.org/c/signals-c-language/
*/

void sigint_handler(int signal)
{
	if (signal == SIGINT)
		printf("\nIntercepted SIGINT!\n");
	exit(signal);
}

void set_signal_action(void)
{
	struct sigaction act;
	bzero(&act, sizeof(act));
	act.sa_handler = &sigint_handler;
	sigaction(SIGINT, &act, NULL);
}

int main(void)
{
	set_signal_action();
	for(int i = 0; i < 5; ++i) {
		printf("Hello...\n");
		sleep(1);
	}
	raise(SIGINT);
	return (0);
}
