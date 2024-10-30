#include <iostream>
#include "../utils/TreeNode.h"

/**
 * 1、审题
 * - 输入一棵二叉树，将二叉树翻转，需要对二叉树的所有结点的左右节点进行翻转
 * 2、解题
 * - 还是递归算法，不断的往底层二叉树节点遍历，知道跟节点为空就直接返回
 * - 根节点不为空，则将当前结点的左右子节点进行调换，可以先调换，
 * - 在递归的时候，传入的参数为一个节点，节点如果为空，则直接返回
 * -- 不为空，则调用底下的左右子树先进行调换，会返回调换后的左右子树的结点，然后再将当前的左右子树的结点进行对调
 * -- 最后返回当前编辑的结点
 */
TreeNode *invertTree(TreeNode *root)
{
    if (root == nullptr)
    {
        return nullptr;
    }

    TreeNode *left = invertTree(root->left);
    TreeNode *right = invertTree(root->right);

    TreeNode *tmpNode = left;
    root->left = right;
    root->right = tmpNode;
    return root;
}

/**
 * 给你一棵二叉树的根节点 root ，翻转这棵二叉树，并返回其根节点。

示例 1：
输入：root = [4,2,7,1,3,6,9]
输出：[4,7,2,9,6,3,1]

示例 2：
输入：root = [2,1,3]
输出：[2,3,1]

示例 3：
输入：root = []
输出：[]

提示：
树中节点数目范围在 [0, 100] 内
-100 <= Node.val <= 100
 */
int main(int argc, char const *argv[])
{

    return 0;
}
