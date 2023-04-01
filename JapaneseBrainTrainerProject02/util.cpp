#include "util.h"

int rand_init(int max, int min) {
	if (min > max)
	{
		int t = max;
		max = min;
		min = t;
	}

	return rand() % (max - min + 1) + min;
}

bool chance_symbol() {
	return rand() % 2;
}
