#include "log.h"
#include "time.h"

/**
 *	--------------------------------------------------------
 *	=>	LOGGER FUNCTIONS
 *	--------------------------------------------------------
 */

void log_msg(logger_t* log, const char* format, ...)
{
	if(log->file != NULL)
	{
		// Create the va_list
		va_list p_args;
		va_start(p_args, format);
		// Print to the file
		vfprintf(log->file, format, p_args);
		// Close the va_list
		va_end(p_args);
	}
}
// -----------------------------------------------------------------
void vlog_msg(logger_t* log, const char* format, va_list args)
{
	if(log->file != NULL)
	{
		vfprintf(log->file, format, args);
	}
}
// -----------------------------------------------------------------
void log_msg_with_time(logger_t* log, const char* format, ...)
{
	if(log->file != NULL)
	{
		va_list		p_args;
		char 		buf[50];
		time_t 		ltime;
		struct tm*	itime;

		va_start(p_args, format);
		time(&ltime);
		itime = localtime(&ltime);
		strftime(buf, 50, "%x - %X", itime);
		fprintf(log->file, "%s | ", buf);
		vlog_msg(log, format, p_args);
		va_end(p_args);
	}
}