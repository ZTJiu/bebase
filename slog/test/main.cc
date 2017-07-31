/******************************************
* File  : main.cc
* Date  : 2017-06-12
* Author: Zhang Tianjiu
* Email : zhangtianjiu@vip.qq.com
*******************************************/

#include "slog/slog.h"


int main(int argc, char ** argv) {
    Slog::SetLogProperties("./logger.properties");
    LOG_DEBUG("Hello world");
    return 0;
}
