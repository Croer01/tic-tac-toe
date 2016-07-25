//
// Created by Adria on 25/07/2016.
//

#include <SDL_rwops.h>
#include <SDL_log.h>
#include <cstdio>
#include <iostream>
#include "Logger.h"
#include <boost/format.hpp>
#include <boost/date_time.hpp>

Logger::Logger(SDL_LogPriority level) {
    SDL_LogSetAllPriority(level);
}

void output(void* userdata,int category, SDL_LogPriority priority, const char *message) {
    ((Logger*)userdata)->writeLog(category,priority,message);
}

bool Logger::isOpen(){
    return logOutput != NULL;
}

void Logger::open(const char* fileName) {
    logOutput = SDL_RWFromFile(fileName, "w");
    if(isOpen()) {
        SDL_LogSetOutputFunction(output,this);
    }
}

void Logger::writeLog(int category, SDL_LogPriority priority, const char *message) {
    if(isOpen()) {
        std::string timeStamp = boost::posix_time::to_iso_extended_string(boost::posix_time::second_clock::universal_time());
        std::string line = (boost::format("%1% | LEVEL %2% | %3%\n") % timeStamp % priority % message).str();
        printf(line.c_str());
        SDL_RWwrite(logOutput, line.c_str(), 1, line.length());
    }
}

void Logger::close() {
    if(isOpen()) {
        SDL_RWclose(logOutput);
    }
}







