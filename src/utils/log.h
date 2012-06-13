/**
 *	This file defines a simple logger used to log message to a file.
 *	I've decided to implement it using macros which let me completely
 *	remove all code related to the logger simply by defining empty
 *	macros.
 */

#ifndef LOG_H_
#define LOG_H_

#include <stdarg.h>
#include <stdio.h>

/**
 *	--------------------------------------------------------
 *	=>	LOGGER STRUCT
 *	--------------------------------------------------------
 */

typedef struct logger
{
	FILE*	file;	/*!< file handle */
} logger_t;

/**
 *	--------------------------------------------------------
 *	=>	MACROS (we should be able to deactivate the logger)
 *	--------------------------------------------------------
 */

#define LOG_DECLARE()		logger_t g_log;
#define LOG_INIT(log_name)	g_log.file = fopen(log_name, "w");
#define LOG_CLEAN()			fclose(g_log.file);
#define LOG(format, ...)	log_msg(&g_log, format, __VA_ARGS__);

/**
 *	--------------------------------------------------------
 *	=>	LOGGER FUNCTIONS
 *	--------------------------------------------------------
 */

/**
 *	\brief		Log a message to a file handled by the log
 *	\param		log 	:	logger struct which contain output handle
 *	\param		format 	:	format of the string to write
 */
void log_msg(logger_t* log, const char* format, ...);

#endif