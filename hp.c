/* hp <number of hit die> <number of entities> [<bonus>] [<hd size>] */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "common.h"

#define DEFAULT_HD_SIZE 8
#define DEFAULT_BONUS 0
#define DEFAULT_ENTITIES 1
#define DEFAULT_HD 1

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
	int sides, bonus, entities, hd, i;

	sides = (argc < 5) ? DEFAULT_HD_SIZE : atoi(argv[4]);
	bonus = (argc < 4) ? DEFAULT_BONUS : atoi(argv[3]);
	entities = (argc < 3) ? DEFAULT_ENTITIES : atoi(argv[2]);
	hd = (argc < 2) ? DEFAULT_HD : atoi(argv[1]);
	srand(time(NULL));
	for (i = 0; i < entities; i++)
		print_hp(roll(hd, sides) + bonus);
	return 0;
}

