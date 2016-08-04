//
// Created by Adria on 01/08/2016.
//

#ifndef TIC_TAC_TOE_REGISTERTOSERIALIZE_H
#define TIC_TAC_TOE_REGISTERTOSERIALIZE_H

#define CREATE_METADATA(className)\
private:\
static Serializer::Register<className> registration;

#define INIT_METADATA(className)\
Serializer::Register<className> className::registration = Serializer::Register<className>();

#endif //TIC_TAC_TOE_REGISTERTOSERIALIZE_H
