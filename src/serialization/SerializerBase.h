//
// Created by Adria on 01/08/2016.
//

#ifndef TIC_TAC_TOE_REGISTERTOSERIALIZE_H
#define TIC_TAC_TOE_REGISTERTOSERIALIZE_H

#define CREATE_METADATA(className)\
private:\
static Register<className> registration;

#define INIT_METADATA(className)\
Register<className> className::registration = Register<className>();

#endif //TIC_TAC_TOE_REGISTERTOSERIALIZE_H
