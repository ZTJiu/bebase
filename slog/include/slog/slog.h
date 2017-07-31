/******************************************
* File  : slog.h
* Date  : 2017-06-05
* Author: Zhang Tianjiu
* Email : zhangtianjiu@vip.qq.com
*******************************************/

#pragma once

#include <log4cplus/logger.h>
#include <log4cplus/loggingmacros.h>
#include <log4cplus/configurator.h>
#include <log4cplus/initializer.h>
#include <log4cplus/configurator.h>

#define MAX_LOG_LEN 2048

void log_format(char * buf, const char * format, ...);

#define LOG_TRACE(format, ...) do {\
		if (format != nullptr && Slog::Instance().isEnabledFor(log4cplus::TRACE_LOG_LEVEL)) { \
			char buf[MAX_LOG_LEN];\
			log_format(buf, format, ##__VA_ARGS__);\
			LOG4CPLUS_TRACE(Slog::Instance(), buf);\
		}\
	} while(0)

#define LOG_DEBUG(format, ...) do {\
		if (format != nullptr && Slog::Instance().isEnabledFor(log4cplus::DEBUG_LOG_LEVEL)) { \
			char buf[MAX_LOG_LEN];\
			log_format(buf, format, ##__VA_ARGS__);\
			LOG4CPLUS_DEBUG(Slog::Instance(), buf);\
		}\
	} while(0)

#define LOG_INFO(format, ...) do {\
		if (format != nullptr && Slog::Instance().isEnabledFor(log4cplus::INFO_LOG_LEVEL)) { \
			char buf[MAX_LOG_LEN];\
			log_format(buf, format, ##__VA_ARGS__);\
			LOG4CPLUS_INFO(Slog::Instance(), buf);\
		}\
	} while(0)

#define LOG_WARN(format, ...) do {\
		if (format != nullptr && Slog::Instance().isEnabledFor(log4cplus::WARN_LOG_LEVEL)) { \
			char buf[MAX_LOG_LEN];\
			log_format(buf, format, ##__VA_ARGS__);\
			LOG4CPLUS_WARN(Slog::Instance(), buf);\
		}\
	} while(0)

#define LOG_ERROR(format, ...) do {\
		if (format != nullptr && Slog::Instance().isEnabledFor(log4cplus::ERROR_LOG_LEVEL)) { \
			char buf[MAX_LOG_LEN];\
			log_format(buf, format, ##__VA_ARGS__);\
			LOG4CPLUS_ERROR(Slog::Instance(), buf);\
		}\
	} while(0)


class Slog {
public:
    static log4cplus::Logger & Instance() {
        static Slog slogger;
        return slogger.Logger();
    }

	static SetLogProperties(const std::string & properties_conf_path) {
		log4cplus::PropertyConfigurator::doConfigure(properties_conf_path);
	}

private:
    Slog() {
        log4cplus::BasicConfigurator config;
        config.configure();
        //log4cplus::PropertyConfigurator::doConfigure("./logger.properties");
        logger_ = log4cplus::Logger::getInstance(LOG4CPLUS_TEXT("global"));
    }
    ~Slog() {
        log4cplus::Logger::shutdown();
    }
    log4cplus::Logger & Logger() {
        return logger_;
    }

private:
    log4cplus::Logger logger_;
    log4cplus::Initializer initializer_;

};


