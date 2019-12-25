#include "TreeForest.h"

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

/**
 * 测试先序遍历以及打印层次号
 */
void testPreOrderAndShowLevelForCs() {
    char file[] = "/Users/blue/CLionProjects/treeAndForestExp/tData/tree11.tre";
    csNode *tree = createChildBrotherTreeFromFile(file);
    preOrderAndShowLevelForCs(tree);
}

/**
 * 测试输出广义表表示的树
 */
void testOutGList() {
    char file[] = "/Users/blue/CLionProjects/treeAndForestExp/tData/tree11.tre";
    csNode *tree = createChildBrotherTreeFromFile(file);
    outGList(tree);
}

int main() {
//    testBasicCreateTree();
//    testCreateAndTraverserCsTree();
//    testPostTraverserCsTree();
//    testGetNodeCount();
//    testGetHeight();
//    testGetLeavesCount();
//    testLevelTraverserForCs();
//    testPreOrderAndShowLevelForCs();
    testOutGList();
    return 0;
}
