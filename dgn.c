/* dgn <number of rooms> */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DEFAULT_ROOMS 8
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
	int rooms, r;

	rooms = argc < 2 ? DEFAULT_ROOMS : atoi(argv[1]);
	srand(time(NULL));
	for (r = 0; r < rooms; r++)
		printf("%s\n", room_str[room_type(rand() % 100 + 1)]);
	return 0;
}
