#include <stdio.h>
#include <stdlib.h>

#include "gameobject.h"
#include "module.h"

const char *_module_type_to_string(ModuleType type)
{
    switch (type)
    {
    case MODULE_TRANSFORM:
        return "MODULE_TRANSFORM";
    case MODULE_RIGIDBODY:
        return "MODULE_RIGIDBODY";
    case MODULE_SPRITE:
        return "MODULE_SPRITE";
    case MODULE_COLLIDER:
        return "MODULE_COLLIDER";
    default:
        return "UNKNOWN_MODULE";
    }
}

Module *Module_Create(GameObject *owner, ModuleType type)
{
    Module *module = (Module *)malloc(sizeof(Module));
    if (module == NULL)
    {
        printf("Module of type %s was not initialized!\n", _module_type_to_string(type));
        return NULL;
    }

    module->owner = owner;
    module->type = type;
}

void Module_Destroy(Module *module)
{
    free(module);
}
