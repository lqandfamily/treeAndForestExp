#include "TreeForest.h"

//#include "createTree.h"

/**
 * 测试老师代码的功能
 * 创建双亲树和遍历双亲树
 */
void testBasicCreateTree() {
    pTree tree;
    csNode *csTree;
    char file[] = "/Users/blue/CLionProjects/treeAndForestExp/tData/tree11.tre";
    CreateTreeFromFile(file, tree);

    preTraverse(tree);
}

void testCreateAndTraverserCsTree() {
    char file[] = "/Users/blue/CLionProjects/treeAndForestExp/tData/tree11.tre";
    csNode *tree = createChildBrotherTreeFromFile(file);
    preOrderForCs(tree);
}


int main() {
//    testBasicCreateTree();
    testCreateAndTraverserCsTree();
    return 0;
}
