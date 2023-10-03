#include <time.h>
#include <stdio.h>
#include <stdarg.h>

#include <pthread.h>
pthread_mutex_t logger_mut;

#include "logger.h"

// Logger g_logger = { .fhandler = stdout };

// int logmsg(Logger * logger, int level, const char * fmt, ...)
int logmsg(FILE * fp, int level, const char * fmt, ...)
{
    // if (!logger)
    //     return -1;

    time_t now;
    time(&now);
    struct tm * local = localtime(&now);

    pthread_mutex_lock(&logger_mut);
    // print time and log level
    fprintf(fp, "%d/%02d/%02d-%02d:%02d:%02d %2d ",
            local->tm_year + 1900, local->tm_mon + 1, local->tm_mday,
            local->tm_hour, local->tm_min, local->tm_sec,
            level);
    // print message
    va_list vl;
    va_start(vl, fmt);
    fprintf(stdout, fmt, vl);
    pthread_mutex_unlock(&logger_mut);
    return 0;
}