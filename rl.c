/* rl <times> <sides> */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "common.h"

#define DEFAULT_SIDES 6
#define DEFAULT_TIMES 1

int
main(int argc, char *argv[])
{
	int sides, times;

	times = (argc < 2) ? DEFAULT_TIMES : atoi(argv[1]);
	sides = (argc < 3) ? DEFAULT_SIDES : atoi(argv[2]);
	srand(time(NULL));
	printf("%d\n", roll(times, sides));
	return 0;
}
