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

#include "common.h"
#include "data.h"

int main()
{
	const size_t off_member = offsetof(struct book, pages);
	struct book b1 = { .year = 2001,
			   .pages = 170,
			   .color = 'B',
			   .rev = 1,
	};
	const struct book *p1 = &b1;
	unsigned short *pages;

	pages = (unsigned short *)((unsigned char *)p1 + off_member);

	printf("pages@%p of b1 accessed using offset=%hu\n",
	       (void *)pages, *pages);
	printf("pages@%p of b1 accessed using member name offset=%hu\n",
	       (void *)&p1->pages, p1->pages);

	return 0;
}
