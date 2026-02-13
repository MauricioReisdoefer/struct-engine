#pragma once

#include "vector2.h"

typedef struct Transform
{
    Vector2 position;
    Vector2 scale;
    Vector2 rotation;
} Transform;

Transform Transform_Create();