#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#define MAX_COMPONENTS 16
// Adicionar component.h

#include "component.h"

typedef struct GameObject
{
    Component *components[MAX_COMPONENTS];
    int active;
    int componentCount;
} GameObject;

#endif