/******************************************
* File  : slog.cc
* Date  : 2017-06-05
* Author: Zhang Tianjiu
* Email : zhangtianjiu@vip.qq.com
*******************************************/

#include "slog/slog.h"
/*#include <log4cplus/logger.h>
#include <log4cplus/loggingmacros.h>
#include <log4cplus/configurator.h>
#include <log4cplus/initializer.h>
#include <log4cplus/configurator.h>*/

void log_format(char * buf, const char * format, ...) {
	if (format == nullptr) {
		return;
	}

	va_list args;
	va_start(args, format);
	vsnprintf(buf, MAX_LOG_LEN, format, args);
	va_end(args);
}
