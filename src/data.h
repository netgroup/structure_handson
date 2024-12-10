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

#ifndef __DATA_H
#define __DATA_H

#include <limits.h>

/* for sizes of main types considered in our experiments see below */
#ifndef REORDERED
struct book {
	char color;		/* 1 byte */
	unsigned int year;	/* 4 bytes */
	unsigned char rev;	/* 1 byte */
	unsigned short pages;	/* 2 bytes */

};
#else
struct book {
	unsigned int year;	/* 4 bytes */
	unsigned short pages;	/* 2 bytes */
	unsigned char rev;	/* 1 byte */
	char color;		/* 1 byte */
};
#endif

/* e.g., size of 'int' is compiler dependent, so let's check the size of the
 * different data types. Standard defines only minimum size (bits).
 */
static inline void BUILD_BUG_ON_WRONG_DATA_SIZE(void)
{
	/* if your build stops here, check your machine type sizes */
	BUILD_BUG_ON(sizeof(char) * CHAR_BIT != 8);
	BUILD_BUG_ON(sizeof(short) * CHAR_BIT != 16);
	BUILD_BUG_ON(sizeof(int) * CHAR_BIT != 32);
	BUILD_BUG_ON(sizeof(float) * CHAR_BIT != 32);
	BUILD_BUG_ON(sizeof(long) * CHAR_BIT != 64);
	BUILD_BUG_ON(sizeof(double) * CHAR_BIT != 64);
	BUILD_BUG_ON(sizeof(void *) * CHAR_BIT != 64);
}

#endif /* end of __DATA_H */
