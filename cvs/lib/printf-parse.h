/*  Parse printf format string.
    Copyright (C) 1999, 2002-2003 Free Software Foundation, Inc.

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2, or (at your option)
    any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with this program; if not, write to the Free Software Foundation,
    Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */

#ifndef _PRINTF_PARSE_H
#define _PRINTF_PARSE_H

#include "printf-args.h"


/* Flags */
#define FLAG_GROUP	 1	/* ' flag */
#define FLAG_LEFT	 2	/* - flag */
#define FLAG_SHOWSIGN	 4	/* + flag */
#define FLAG_SPACE	 8	/* space flag */
#define FLAG_ALT	16	/* # flag */
#define FLAG_ZERO	32

/* arg_index value indicating that no argument is consumed.  */
#define ARG_NONE	(~(size_t)0)

/* A parsed directive.  */
typedef struct {
	const char* dir_start;
	const char* dir_end;
	int flags;
	const char* width_start;
	const char* width_end;
	size_t width_arg_index;
	const char* precision_start;
	const char* precision_end;
	size_t precision_arg_index;
	char conversion; /* d i o u x X f e E g G c s p n U % but not C S */
	size_t arg_index;
}
char_directive;

/* A parsed format string.  */
typedef struct {
	size_t count;
	char_directive *dir;
	size_t max_width_length;
	size_t max_precision_length;
}
char_directives;


/*  Parses the format string.  Fills in the number N of directives, and fills
    in directives[0], ..., directives[N-1], and sets directives[N].dir_start
    to the end of the format string.  Also fills in the arg_type fields of the
    arguments and the needed count of arguments.  */
#ifdef STATIC
STATIC
#else
extern
#endif
int printf_parse (const char *format, char_directives *d, arguments *a);

#endif /* _PRINTF_PARSE_H */
