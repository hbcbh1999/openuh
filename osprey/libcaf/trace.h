/*
 Runtime library for supporting Coarray Fortran 

 Copyright (C) 2011 University of Houston.

 This program is free software; you can redistribute it and/or modify it
 under the terms of version 2 of the GNU General Public License as
 published by the Free Software Foundation.

 This program is distributed in the hope that it would be useful, but
 WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  

 Further, this software is distributed without any warranty that it is
 free of the rightful claim of any third person regarding infringement 
 or the like.  Any license provided herein, whether implied or 
 otherwise, applies only to this software file.  Patent licenses, if 
 any, provided herein do not apply to combinations of this program with 
 other software, or any other product whatsoever.  

 You should have received a copy of the GNU General Public License along
 with this program; if not, write the Free Software Foundation, Inc., 59
 Temple Place - Suite 330, Boston MA 02111-1307, USA.

 Contact information: 
 http://www.cs.uh.edu/~hpctools
*/

#ifndef _TRACE_H
#define _TRACE_H 

#ifdef ENABLE_LIBCAF_TRACES
# define LIBCAF_TRACE_INIT __libcaf_tracers_init
# define LIBCAF_TRACE __libcaf_trace
# define START_TIMER  __start_timer
# define STOP_TIMER  __stop_timer
#else
# define LIBCAF_TRACE_INIT() ((void) 1)
# define LIBCAF_TRACE(arg1, arg2, ...) ((void) 1)
# define START_TIMER() ((void) 1)
# define STOP_TIMER(arg1) ((void) 1)
#endif

typedef enum {
    LIBCAF_LOG_FATAL=0,    /* unrecoverable problem */
    LIBCAF_LOG_DEBUG,      /* debugging information */
    LIBCAF_LOG_TIME,       /* timing information */
    LIBCAF_LOG_NOTICE,     /* serious, but non-fatal */
    LIBCAF_LOG_TIME_SUMMARY,    /* print accumulated time */
    LIBCAF_LOG_INIT,       /* during LIBCAF initialization */
    LIBCAF_LOG_MEMORY,     /* symmetric memory operations */
    LIBCAF_LOG_CACHE,      /* cache flushing ops */
    LIBCAF_LOG_BARRIER,    /* barrier ops */
    LIBCAF_LOG_REDUCE,     /* reduction ops */
    LIBCAF_LOG_SYMBOLS,    /* dump global symbol table */
    NUM_TRACERS=LIBCAF_LOG_SYMBOLS
} libcaf_trace_t;

typedef enum {
    START,
    STOP,
    PRINT,
    PRINT_ROLLUP
} __timer_start_stop_t; /* time recording start or stop */

typedef enum {
    INIT,
    READ,
    WRITE,
    SYNC,
    DUMMY
} __timer_type_t; /* type of timer */

extern void __libcaf_tracers_init(void);
extern void __libcaf_trace(libcaf_trace_t msg_type, char *fmt, ...);
extern int  __trace_is_enabled(libcaf_trace_t level);
void __start_timer();
void __stop_timer(__timer_type_t type);


#endif /* _TRACE_H */