#include <stdio.h>
#include <unistd.h>
#include <sys/syscall.h>

// calling conventions
int returny_func(int *a, char b, short c, int d)
{
	// return value
	return b+c;
}

int main(int argc, char **argv)
{
	// 64-bit
	long long mylong = 0xbabecafef00dface;

	// 32-bit
	int myint = 0xdeadf00d;

	// string operations
	char str[] = "mystr";

	// canary value
	int i = 1337;

	// control flow
	while (i)
	{
		i--;
	}
	
	int ret = returny_func(&i, 0x42, 0x69, 0x31337);

	// syscall interface
	write(1, "done:)\n", 7);
	printf("done:)\n");

	return 32;
}
