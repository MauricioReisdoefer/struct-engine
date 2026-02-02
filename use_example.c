#include <stdio.h>

#include "node.h"
#include "feature.h"

int main()
{
    Node *firstNode = Node_Create();
    Feature *emptyFeature = Feature_Create(firstNode, FEATURE_UNDEFINED);

    Node_Add_Feature(firstNode, emptyFeature);
    Node_Destroy(firstNode);

    if (firstNode)
    {
        printf("firstNode was Destroyed");
    }

    if (emptyFeature)
    {
        printf("emptyFeature was Destroyed");
    }
    return 0;
}