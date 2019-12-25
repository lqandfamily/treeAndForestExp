/**
 * 树与森林头文件
 * @author lq
 * @date 2019.12.25
 */


#ifndef TREE_FOREST_H
#define TREE_FOREST_H

#include "createTree.h"

csNode *createChildBrotherTreeFromFile(char *fileFullName) {
    pTree tree;
    csNode *csTree;
    CreateTreeFromFile(fileFullName, tree);
    createCsTree(csTree, tree);
    return csTree;
}

/**
 * 树的先序遍历
 * @param curNode
 */
void preOrderForCs(csNode *curNode) {
    if (curNode != NULL) {
        cout << curNode->data << "\t";
        preOrderForCs(curNode->firstChild);
        preOrderForCs(curNode->nextSibling);
    }
}

#endif