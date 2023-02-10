/* hp <number of hit die> <number of entities> [<bonus>] [<hd size>] */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "common.h"

#define DEFAULT_HD_SIZE 8

void print_hp(int);

void
print_hp(int hp)
{
	int i;

	for (i = 0; i < hp; i++) {
		putchar('o');
		if ((i+1) % 5 == 0)
			putchar(' ');
	}
	putchar('\n');
}

int
main(int argc, char *argv[])
{
	int i;

	if (argc < 3) {
		printf("Please pass HD and number appearing as args\n");
		printf("eg: hp 2 6\n");
		return 1;
	}
	srand(time(NULL));
	for (i = 0; i < atoi(argv[2]); i++)
		print_hp(roll(atoi(argv[1]), DEFAULT_HD_SIZE));
	return 0;
}

