/* dgn <number of rooms> */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROOM_TYPES 7

enum { EMPTY, UNGUARDED_TREASURE, MONSTER, MONSTER_WITH_TREASURE, SPECIAL,
       TRAP, TRAP_WITH_TREASURE };

const char *room_str[ROOM_TYPES] = {"Empty", "Unguarded Treasure", "Monster",
                                    "Monster with Treasure", "Special", "Trap",
                                    "Trap with Treasure"};

int
room_type(int roll)
{
	if (roll <= 16)
		return EMPTY;
	if (roll <= 20)
		return UNGUARDED_TREASURE;
	if (roll <= 60)
		return MONSTER;
	if (roll <= 84)
		return MONSTER_WITH_TREASURE;
	if (roll <= 88)
		return SPECIAL;
	if (roll <= 96)
		return TRAP;
	else
		return TRAP_WITH_TREASURE;
}

int
main(int argc, char *argv[])
{
	int r;

	if (argc < 2) {
		printf("Please pass room number as arg\n");
		printf("eg: dgn 6\n");
		return 1;
	}
	srand(time(NULL));
	for (r = 0; r < atoi(argv[1]); r++)
		printf("%s\n", room_str[room_type(rand() % 100 + 1)]);
	return 0;
}
