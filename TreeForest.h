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
 * 获取兄弟孩子树的叶子节点总数
 * @param root
 * @return
 */
int getLeavesCount(csNode *root) {
    if (root == NULL) {
        return 0;
    } else {
        int childSubTreeLeavesCount = getLeavesCount(root->firstChild);
        int brotherSubTreeLeavesCount = getLeavesCount(root->nextSibling);
        /**
         * 这里只需要firstChild是NULL既是叶子节点
         */
        if (root->firstChild == NULL) {
            return childSubTreeLeavesCount + brotherSubTreeLeavesCount + 1;
        } else {
            return childSubTreeLeavesCount + brotherSubTreeLeavesCount;
        }
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

/**
 * 求孩子兄弟树的高度
 * @param root
 * @return
 */
int getHeight(csNode *root) {
    if (root == NULL) {
        return 0;
    } else {
        int childSubTreeHeight = getHeight(root->firstChild) + 1;
        int brotherSubTreeHeight = getHeight(root->nextSibling);
        return childSubTreeHeight > brotherSubTreeHeight ? childSubTreeHeight : brotherSubTreeHeight;
    }
}


#endif