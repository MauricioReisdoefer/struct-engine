#ifndef NODE_H
#define NODE_H

#define MAX_COMPONENTS 32
#define MAX_TAG_SIZE 64
#define MAX_CHILDREN_NODES 32

#include "feature.h"

// Forward Declaration
typedef struct Node Node;

typedef struct Node
{
    Feature *features[MAX_COMPONENTS];
    Node *children[MAX_CHILDREN_NODES];
    int active;

    int featureCount;
    int childrenCount;
    char tag[MAX_TAG_SIZE];
} Node;

Node *Node_Create();
void Node_Destroy(Node *node);
void Node_Add_Feature(Node *self, Feature *feature);

#endif