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

/**
 *  测试获取孩子兄弟数的总节点数
 */
void testGetNodeCount() {
    char file[] = "/Users/blue/CLionProjects/treeAndForestExp/tData/tree11.tre";
    csNode *tree = createChildBrotherTreeFromFile(file);
    int nodeCount = getNodeCount(tree);
    cout << "树的节点总数为:" << nodeCount << endl;
}

/**
 *  测试获取树的高度
 */
void testGetHeight() {
    char file[] = "/Users/blue/CLionProjects/treeAndForestExp/tData/tree11.tre";
    csNode *tree = createChildBrotherTreeFromFile(file);
    int nodeCount = getHeight(tree);
    cout << "树的高度为:" << nodeCount << endl;
}

/**
 *  测试获取兄弟孩子树的叶子节点总数
 */
void testGetLeavesCount() {
    char file[] = "/Users/blue/CLionProjects/treeAndForestExp/tData/tree11.tre";
    csNode *tree = createChildBrotherTreeFromFile(file);
    int nodeCount = getLeavesCount(tree);
    cout << "树的叶子节点总数为:" << nodeCount << endl;
}

/**
 * 测试兄弟孩子树的层次遍历
 */
void testLevelTraverserForCs() {
    char file[] = "/Users/blue/CLionProjects/treeAndForestExp/tData/tree11.tre";
    csNode *tree = createChildBrotherTreeFromFile(file);
    levelTraverserForCs(tree);
}

int main() {
//    testBasicCreateTree();
//    testCreateAndTraverserCsTree();
//    testPostTraverserCsTree();
//    testGetNodeCount();
//    testGetHeight();
//    testGetLeavesCount();
    testLevelTraverserForCs();
    return 0;
}
