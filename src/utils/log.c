#include "log.h"

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