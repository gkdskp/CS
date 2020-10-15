/* Implement the producer-consumer problem using semaphores */
/* Code from https://github.com/ceadoor/System-Software-lab */

#include <stdio.h>
#include <stdlib.h>

int mutex = 1;
int full = 0, empty = 3, x = 0;

int wait(int);
int signal(int);
void producer();
void consumer();

int wait(int s)
{
	return --s;
}

int signal(int s)
{
	return ++s;
}

void producer()
{
	mutex = wait(mutex);
	full = signal(full);
	empty = wait(empty);
	++x;
	printf("\nItem%d produced", x);
	mutex = signal(mutex);
}

void consumer()
{
	mutex = wait(mutex);
	full = wait(full);
	empty = signal(empty);
	printf("\nItem%d consumed", x);
	--x;
	mutex = signal(mutex);
}

int main()
{
	int n;
	do {
		printf("\n1. Producer\n2. Consumer\n");
		scanf("%d", &n);
		switch(n)
		{
			case 1:
				if(mutex == 1 && empty) producer();
				else printf("\nBuffer overflow");
				break;

			case 2:
				if(mutex == 1 && full) consumer();
				else printf("\nBuffer empty");
				break;
			
			default:
				printf("\nUnknown command");
				exit(0);
		} 
	} while(1);

	return 0;
}