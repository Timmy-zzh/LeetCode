#include <iostream>
#include <vector>
#include "../utils/TreeNode.h"

/**
 * 1、审题
 * - 输入一棵完全二叉树，求这棵树的结点个数
 * 2、解题
 * - 层序遍历，使用一个计数记录结点的个数
 * 3、优化算法
 * - 完全二叉树，特性怎么使用，找到最后一层结点的个数，
 * -- 要先知道树的层数
 * - 或者前序遍历算法
 */
int countNodes1(TreeNode *root)
{
    int count = 0;
    if (root == nullptr)
    {
        return count;
    }
    std::vector<TreeNode *> list;
    list.push_back(root);

    while (!list.empty())
    {
        // 取出来，删除，添加他的左右子节点，计数增加
        count++;
        TreeNode *node = list.front();
        list.erase(list.begin());

        if (node->left != nullptr)
            list.push_back(node->left);
        if (node->right != nullptr)
            list.push_back(node->right);
    }

    return count;
}

/**
 * 递归算法：
 * - 结点个数，等于当前结点数（1） + 左右子树的结点个数
 */
int countNodes(TreeNode *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}

/**
 * 给你一棵 完全二叉树 的根节点 root ，求出该树的节点个数。
完全二叉树 的定义如下：在完全二叉树中，除了最底层节点可能没填满外，其余每层节点数都达到最大值，并且最下面一层的节点都集中在该层最左边的若干位置。若最底层为第 h 层，则该层包含 1~ 2h 个节点。

示例 1：
输入：root = [1,2,3,4,5,6]
输出：6

示例 2：
输入：root = []
输出：0

示例 3：
输入：root = [1]
输出：1

提示：
树中节点的数目范围是[0, 5 * 104]
0 <= Node.val <= 5 * 104
题目数据保证输入的树是 完全二叉树

进阶：遍历树来统计节点是一种时间复杂度为 O(n) 的简单解决方案。你可以设计一个更快的算法吗？
 */
int main(int argc, char const *argv[])
{

    return 0;
}
