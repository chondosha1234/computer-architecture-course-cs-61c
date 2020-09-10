#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "lfsr.h"

void lfsr_calculate(uint16_t *reg) {
	uint16_t next = *reg & 1;
	next = next ^ ((*reg >> 2) & 1);
	next = next ^ ((*reg >> 3) & 1);
	next = next ^ ((*reg >> 5) & 1);
	*reg = *reg >> 1;
	*reg ^= (-next ^ *reg) & (1 << 15);
}

