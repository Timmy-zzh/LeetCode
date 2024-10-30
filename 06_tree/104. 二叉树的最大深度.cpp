#include <string>
#include <vector>
#include "../utils/TreeNode.h"

/**
 * 1、审题：给定一个二叉树，求最大深度
 * 2、解题：
 * - 递归算法，不断遍历树结构的左右子树，直到叶子结点，最后的叶子结点深度为1，空节点直接返回0
 * - 上层结点，取左右子树比较后的最大深度，再加上1，并返回
 */
int maxDepth(TreeNode *root)
{
    if (root == nullptr)
    {
        return 0;
    }

    int leftDep = maxDepth(root->left);
    int rightDep = maxDepth(root->right);
    return std::max(leftDep, rightDep) + 1;
}

/**
 * 给定一个二叉树 root ，返回其最大深度。
二叉树的 最大深度 是指从根节点到最远叶子节点的最长路径上的节点数。

示例 1：
输入：root = [3,9,20,null,null,15,7]
输出：3

示例 2：
输入：root = [1,null,2]
输出：2
 */
int main(int argc, char const *argv[])
{
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    TreeNode *right = new TreeNode(20);
    root->right = right;
    right->left = new TreeNode(15);
    right->right = new TreeNode(7);

    auto res = maxDepth(root);
    std::cout << "res:" << res << std::endl;

    return 0;
}