//
// Created by Adria on 30/07/2016.
//

#include "Serializer.h"

struct serialtizationException : public std::exception {
    const char *what() const throw() {
        return "class not has serialize function";
    }
};


