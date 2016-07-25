//
// Created by Adria on 25/07/2016.
//

#ifndef SDL_HELLO_WORLD_LOGGER_H
#define SDL_HELLO_WORLD_LOGGER_H


class Logger {
    SDL_RWops *logOutput;
    bool isOpen();

public:
    void open(const char* fileName);

    void close();

    void writeLog(int category, SDL_LogPriority priority, const char *message);

    Logger(SDL_LogPriority level);
};


#endif //SDL_HELLO_WORLD_LOGGER_H
