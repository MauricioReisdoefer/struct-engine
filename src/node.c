#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "node.h"
#include "feature.h"

Node *Node_Create()
{
    Node *node = (Node *)malloc(sizeof(Node));

    if (node == NULL)
    {
        printf("Node_Create: Node was not initialized!");
        return NULL;
    }

    node->active = 1;
    node->componentCount = 0;
    snprintf(node->tag, sizeof(node->tag), "Default");

    return node;
}
void Node_Destroy(Node *node)
{
    if (!node)
        return;
    if (node->componentCount > 0)
    {
        for (int i = 0; i < node->componentCount; i++)
        {
            Feature_Destroy(node->components[i]);
            node->components[i] = NULL;
        }
        node->componentCount = 0;
    }
    if (node->childrenCount > 0)
    {
        for (int i = 0; i < node->childrenCount; i++)
        {
            Node_Destroy(node->children[i]);
            node->children[i] = NULL;
        }
        node->childrenCount = 0;
    }
    free(node);
}

void Node_Add_Feature(Node *self, Feature *feature)
{
    if (!self || !feature)
    {
        printf("Node_Add_Feature: self or feature is NULL\n");
        return;
    }

    if (self->componentCount >= MAX_COMPONENTS)
    {
        printf("Node_Add_Feature: maximum components reached\n");
        return;
    }

    self->components[self->componentCount] = feature;
    self->componentCount++;
}