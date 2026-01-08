# Copyright (C) 2024 andrea.mayer@uniroma2.it
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
#      but WITHOUT ANY WARRANTY; without even the implied warranty of
#      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#      GNU General Public License for more details.
#
#      You should have received a copy of the GNU General Public License
#      along with this program.  If not, see <http://www.gnu.org/licenses/>.

CC = gcc
CFLAGS = -Wall -Werror -g

SRCDIR = src
BUILDDIR = build

SOURCES = $(wildcard $(SRCDIR)/*.c)
HEADERS = $(wildcard $(SRCDIR)/*.h)
EXECUTABLES = $(patsubst $(SRCDIR)/%.c, $(BUILDDIR)/%, $(SOURCES))

# If the user defined CONFIG_HEAP_RANDOM_GARBAGE on the command line,
# add the corresponding -D option to CFLAGS.
ifdef CONFIG_HEAP_RANDOM_GARBAGE
CFLAGS += -DCONFIG_HEAP_RANDOM_GARBAGE=1
endif

.PHONY: all clean

all: $(EXECUTABLES)

clean:
	rm -rf $(BUILDDIR)

$(BUILDDIR):
	mkdir -p $(BUILDDIR)

$(BUILDDIR)/%: $(SRCDIR)/%.c $(HEADERS) | $(BUILDDIR)
	$(CC) $(CFLAGS) $< -o $@
