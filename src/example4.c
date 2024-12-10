/* Copyright (C) 2024 andrea.mayer@uniroma2.it
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 *      but WITHOUT ANY WARRANTY; without even the implied warranty of
 *      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *      GNU General Public License for more details.
 *
 *      You should have received a copy of the GNU General Public License
 *      along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <assert.h>

#include "common.h"

struct temp {
	unsigned char valid;
	unsigned int mvalue;
};

static void print_temp(const struct temp *const t)
{
	printf("Temperature valid '%u', mvalue=%u\n", t->valid, t->mvalue);
#ifdef ENABLE_DUMP_HEX
	dump_hex(t, sizeof(*t));
#endif
}

#define TEMP_IS_VALID	0x01
#define TEMP_MVALUE	25

int main()
{
	struct temp t = { .valid = TEMP_IS_VALID, .mvalue = TEMP_MVALUE, };
	struct temp *p = &t;
	int *v;

	print_temp((const struct temp *const)p);

	v = (int *)&p->valid;
	*v = 0xcafec000 | TEMP_IS_VALID;

	printf("After update:\n");
	print_temp((const struct temp *const)p);

	assert(p->valid == TEMP_IS_VALID && p->mvalue == TEMP_MVALUE);

	return 0;
}
