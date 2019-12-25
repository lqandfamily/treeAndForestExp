# 算法问题
- 求树的高度时：只有在访问firstChild时高度才会加一，同时返回的应该是孩子子树和兄弟子树的高度最大值

- 求树的叶子节点总数时：只需要firstChild为空即为叶子节点

## 代码封装问题
- 对于代码，应该封装内部细节，使得呈现给用户的是最简洁最容易解释的API
```c
csNode *createChildBrotherTreeFromFile(char *fileFullName) {
    pTree tree;
    csNode *csTree;
    CreateTreeFromFile(fileFullName, tree);
    createCsTree(csTree, tree);
    return csTree;
}
```