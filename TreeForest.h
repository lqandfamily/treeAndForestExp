/**
 * 树与森林头文件
 * @author lq
 * @date 2019.12.25
 */


#ifndef TREE_FOREST_H
#define TREE_FOREST_H

#include "createTree.h"

/**
 * 封装孩子兄弟树的创建
 * @param fileFullName
 * @return
 */
csNode *createChildBrotherTreeFromFile(char *fileFullName) {
    pTree tree;
    csNode *csTree;
    CreateTreeFromFile(fileFullName, tree);
    createCsTree(csTree, tree);
    return csTree;
}

/**
 * 孩子兄弟树的先序遍历
 * @param curNode
 */
void preOrderForCs(csNode *curNode) {
    if (curNode != NULL) {
        cout << curNode->data << "\t";
        preOrderForCs(curNode->firstChild);
        preOrderForCs(curNode->nextSibling);
    }
}

/**
 * 孩子兄弟树的后续遍历
 * @param curNode
 */
void postOrderForCs(csNode *curNode) {
    if (curNode != NULL) {
        postOrderForCs(curNode->firstChild);
        postOrderForCs(curNode->nextSibling);
        cout << curNode->data << "\t";
    }
}

/**
 * 获取孩子孩子兄弟树的节点总数
 * @param root
 */
int getNodeCount(csNode *root) {
    if (root == NULL) {
        return 0;
    } else {
        return getNodeCount(root->firstChild) + getNodeCount(root->nextSibling) + 1;
    }
}



#endif