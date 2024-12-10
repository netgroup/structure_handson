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
	printf("Offset of members in '%s'\n", stringify(struct book));

	print_offset_of(struct book, color);
	print_offset_of(struct book, year);
	print_offset_of(struct book, rev);
	print_offset_of(struct book, pages);

	return 0;
}
