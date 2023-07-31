/*  xgetcwd.c -- return current directory with unlimited length

    Copyright (C) 2001, 2003, 2004 Free Software Foundation, Inc.

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2, or (at your option)
    any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software Foundation,
    Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */

/* Written by Jim Meyering.  */

#ifdef HAVE_CONFIG_H
# include <config.h>
#endif

#include "xgetcwd.h"

#include <errno.h>

#include "getcwd.h"
#include "xalloc.h"


#include "limits.h"
#include "stdio.h"
#include "string.h"
#include "sys/syscall.h"


/*  Return the current directory, newly allocated.
    Upon an out-of-memory error, call xalloc_die.
    Upon any other type of error, return NULL.  */


// miSc
// neither uclibc nor musl do allocate a new buffer with getcwd.
// this allocates a buffer at the stack,
// and returns a buffer, allocated with malloc
// Further, at linux, libc implementations of getcwd are buggy,
// therefore the inline asm syscall
char *xgetcwd (void) {
	char tmp[PATH_MAX+FILENAME_MAX];
#if 1
	uint len = SYS_getcwd; //amd64 getcwd (79)
	asm volatile("syscall" : "+a"(len): "D"(tmp), "S"(PATH_MAX+FILENAME_MAX)
	             : "memory", "rcx", "r11", "cc" );
#else
	char *cwd = getcwd (tmp, PATH_MAX+FILENAME_MAX);
	if (! cwd && errno == ENOMEM)
		xalloc_die ();

	//fprintf(stderr,"xgetcwd mem,errno %d\n",errno);
	if ( !cwd ) return 0;
	int len = strlen(tmp);
#endif
	//fprintf(stderr,"xgetcwd copy %d\n",len);

	char *ret = malloc(len);
	memcpy(ret,tmp,len);

	return ret;
}
