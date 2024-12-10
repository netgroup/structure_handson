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

#define NUM_OF_MEMBERS 3
struct baz {
	char  a;
	double b;
	short c;
};

static const size_t baz_offsets[NUM_OF_MEMBERS] = {
	[0] = offsetof(struct baz, a),
	[1] = offsetof(struct baz, b),
	[2] = offsetof(struct baz, c),
};

static void *get_baz_member_ptr(struct baz *b, unsigned int index)
{
	size_t off;
	void *p;

	if (index >= NUM_OF_MEMBERS)
		return NULL;

	off = baz_offsets[index];
	p = (void *)((unsigned char *)b + off);

	return p;
}

int main()
{
	struct baz baz1 = { .a = 'Y', .b = 3.14, .c = 0xabba, };
	short *c;
	double *b;

	b = (double *)get_baz_member_ptr(&baz1, 1);
	c = (short *)get_baz_member_ptr(&baz1, 2);

	if (b)
		printf("value of baz.b=%f\n", *b);
	if (c)
		printf("value of baz.c=0x%hx\n", *c);

	return 0;
}
