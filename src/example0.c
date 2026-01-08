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

#include <string.h>

#include "common.h"
#include "data.h"

static void __noinline
init_book(struct book *book, unsigned char color, unsigned int year,
	  unsigned char rev, unsigned short pages)
{
	book->color = color;
	book->year = year;
	book->rev = rev;
	book->pages = pages;
}

int main()
{
	struct book *b1, *b2;
	int result;

	BUILD_BUG_ON_WRONG_DATA_SIZE();

	b1 = heap_alloc(sizeof(*b1));
	b2 = heap_alloc(sizeof(*b2));
	if (!b1 || !b2) {
		printf("Cannot allocate heap memory\n");
		/* a buffer has been allocated, at least */
		heap_free(b1);
		heap_free(b2);

		return 1;
	}

	init_book(b1, 'A', 2001, 1, 170);
	init_book(b2, 'A', 2001, 1, 170);

	/* ...be careful while doing this... */
	result = memcmp((const void *)b1, (const void *)b2, sizeof(*b1));
	if (!result)
		printf("b1 and b2 are equal\n");
	else
		printf("b1 and b2 are NOT equal\n");

	heap_free(b1);
	heap_free(b2);

	return !!result;
}
