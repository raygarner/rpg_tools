/* rl <times> <sides> */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "common.h"

int
main(int argc, char *argv[])
{
	if (argc < 3) {
		printf("Please pass sides and count as args\n");
		printf("eg: rl 1 6 (for 1d6)\n");
		return 1;
	}
	srand(time(NULL));
	printf("%d\n", roll(atoi(argv[1]), atoi(argv[2])));
	return 0;
}
