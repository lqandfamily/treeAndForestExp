#include "TreeForest.h"

//#include "createTree.h"

/**
 * 测试老师代码的功能
 */
void testBasicCreateTree() {
    pTree tree;
    char file[] = "/Users/blue/CLionProjects/treeAndForestExp/tData/tree11.tre";
    CreateTreeFromFile(file, tree);
    preTraverse(tree);
}

int main() {
    testBasicCreateTree();
    preOrderTraverse(NULL);
    return 0;
}
