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

/**
 * 测试创建兄弟孩子树和先序遍历兄弟孩子树
 */
void testCreateAndTraverserCsTree() {
    char file[] = "/Users/blue/CLionProjects/treeAndForestExp/tData/tree11.tre";
    csNode *tree = createChildBrotherTreeFromFile(file);
    preOrderForCs(tree);
}

/**
 * 测试兄弟孩子树的后续遍历
 */
void testPostTraverserCsTree() {
    char file[] = "/Users/blue/CLionProjects/treeAndForestExp/tData/tree11.tre";
    csNode *tree = createChildBrotherTreeFromFile(file);
    postOrderForCs(tree);
}

int main() {
//    testBasicCreateTree();
//    testCreateAndTraverserCsTree();
    testPostTraverserCsTree();
    return 0;
}
