#ifndef __COMMON_LOGGER_H__
#define __COMMON_LOGGER_H__

#include <stdio.h>

/* 
typedef struct _tLogger {
    FILE * fhandler;
} Logger;

extern Logger g_logger;

int logmsg(Logger * logger, int level, const char * fmt, ...);
*/

int logmsg(FILE * fp, int level, const char * fmt, ...);

#define CLOG(lvl, ...) do { logmsg(stdout, lvl, __VA_ARGS__); } while (0)
#define ELOG(lvl, ...) do { logmsg(stderr, lvl, __VA_ARGS__); } while (0)

#endif