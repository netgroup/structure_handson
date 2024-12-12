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

#ifndef FORCE_STRUCT
union elem {
	char c;
	short s;
	int i;
	double d;
};
typedef union elem elem_t;
#else
struct elem {
	double d;
	int i;
	short s;
	char c;
};
typedef struct elem elem_t;
#endif /* FORCE_STRUCT */

struct node {
	/* opaque type depending on whether FORCE_STRUCT is specified or not */
	elem_t data;
	struct node *next;
};

int main()
{
	print_size(elem_t);
	print_size(struct node);

	print_member_info(struct node, data);
	print_member_info(struct node, next);

	return 0;
};
