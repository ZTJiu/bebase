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

#define LOG_DEBUG(logEvent) LOG4CPLUS_DEBUG(Slog::Instance(), logEvent)

class Slog {
public:
    static log4cplus::Logger & Instance() {
        static Slog slogger;
        return slogger.Logger();
    }

private:
    Slog() {
        log4cplus::BasicConfigurator config;
        config.configure();
        log4cplus::PropertyConfigurator::doConfigure("./logger.properties");
        logger_ = log4cplus::Logger::getInstance(LOG4CPLUS_TEXT("main"));
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


