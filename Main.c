#include <stdio.h>
#include <stdlib.h>
#include "cTree.h"



int main() {
    
    TreeNode* node = CreateTreeNode(4);
    Insert(node, 5);
    Insert(node, 1);
    Insert(node, 2);
    Insert(node, 6);
    Insert(node, 4.5);
    
    TreeNode* found = Find(node, 5);
    PrintPtr(found, Left);
   
    FreeTree(node);
    
    return 0;
}