#include <iostream>
#include "../utils/TreeNode.h"

bool isSymmetricBak(TreeNode *p, TreeNode *q)
{
    if (p == nullptr && q == nullptr)
    {
        return true;
    }

    if (p != nullptr && q != nullptr && p->val == q->val)
    {
        // 左右子树节点
        bool leftRes = isSymmetricBak(p->left, q->right);
        bool rightRes = isSymmetricBak(p->right, q->left);
        return leftRes && rightRes;
    }
    else
    {
        return false;
    }
}

/**
 * 1、审题：
 * - 输入一个二叉树，判断这个二叉树是否轴对称
 * 2、解题：
 * - 轴对称，要求从根节点开始，左右两边的结点值要相同，
 */
bool isSymmetric(TreeNode *root)
{
    if (root == nullptr)
    {
        return true;
    }

    return isSymmetricBak(root->left, root->right);
}

/**
 * 给你一个二叉树的根节点 root ， 检查它是否轴对称。

示例 1：
输入：root = [1,2,2,3,4,4,3]
输出：true

示例 2：
输入：root = [1,2,2,null,3,null,3]
输出：false

提示：
树中节点数目在范围 [1, 1000] 内
-100 <= Node.val <= 100
进阶：你可以运用递归和迭代两种方法解决这个问题吗？
 */
int main(int argc, char const *argv[])
{

    return 0;
}
