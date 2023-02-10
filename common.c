#include <stdlib.h>

#include "common.h" 

int
roll(int count, int sides)
{
        int i, total = 0;

        for (i = 0; i < count; i++)
                total += (rand() % (sides)) + 1;
        return total;
}
