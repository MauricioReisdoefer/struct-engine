#ifndef MODULE_H
#define MODULE_H

#include <stdlib.h>

typedef enum
{
    MODULE_TRANSFORM,
    MODULE_RIGIDBODY,
    MODULE_SPRITE,
    MODULE_COLLIDER
} ModuleType;

// Forward Declaration
struct GameObject;

typedef struct
{
    struct GameObject *owner;
    ModuleType type;
} Module;

Module *Module_Create(struct GameObject *owner, ModuleType type);
void Module_Destroy(Module *component);

#endif