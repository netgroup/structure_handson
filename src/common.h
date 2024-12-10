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

#ifndef __COMMON_H
#define __COMMON_H

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <time.h>
#include <errno.h>

#define BUILD_BUG_ON(condition) \
	((void)sizeof(char[1 - 2*!!(condition)]))

#define stringify(x)	#x

#define print_offset_of(sname, field)				\
	do {							\
		printf("offset of '%s' is %lu (bytes) in '%s'\n",\
		       stringify(field),			\
		       offsetof(sname, field),			\
		       stringify(sname));			\
	} while(0)

#define struct_member_sizeof(sname, field)			\
	sizeof(((sname *)0)->field)

#define print_struct_member_sizeof(sname, field)		\
	do {							\
		printf("size of '%s' is %lu (bytes) in '%s'\n", \
		       stringify(field),			\
		       struct_member_sizeof(sname, field),	\
		       stringify(sname));			\
	} while(0)

#define print_member_info(sname, field)				\
	do {							\
		printf("%s: member %s@%lu (bytes), %lu (bytes) in size\n",\
		       stringify(sname),			\
		       stringify(field),			\
		       offsetof(sname, field),			\
		       struct_member_sizeof(sname, field));	\
	} while (0)



#define print_size(obj) \
	printf("size of '%s' is %lu bytes\n", stringify(obj), sizeof(obj))

#define __noinline __attribute__ ((noinline))

static inline void heap_alloc_init(void)
{
	srand(time(NULL));
}

static inline void *heap_alloc(size_t size)
{
	unsigned char *p = malloc(size);
	static int initialized = 0;
	int i;

	if (!(initialized++))
		heap_alloc_init();

	if (!p)
		return NULL;

	for(i = 0; i < size; ++i)
		p[i] = rand() & 0xff;

	return (void *)p;
}

static inline void heap_free(void *p)
{
	free(p);
}

static inline void dump_hex(const void *const p, size_t len)
{
	size_t i;

	for (i = 0; i < len; ++i)
		printf("%02hhXh ", ((unsigned char *)p)[i]);

	printf("\n");
}

#endif /* end of __COMMON_H */
