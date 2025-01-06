#include <iostream>
#include <vector>
#include "../utils/TreeNode.h"
#include <stack>

/**
 * 1、递归遍历，中序遍历
 * - 遍历过程中，遍历到空节点，返回-1
 * - 先遍历左子树，再遍历当前结点，那i值就减少了--，知道i=0则为目标值
 * - 遇到了空节点，返回-1，
 * - 目标节点值，存在三种情况： 在左子树，在当前结点，在右子树中
 * 2、其他解法：
 * - 迭代解法，使用栈保存中序遍历的结点值
 * - 记录结点个数的思路
 */
int kthSmallestbck(TreeNode *node, int &i)
{
    std::cout << "val:" << node->val << ",i:" << i << std::endl;
    if (node == nullptr)
    {
        return -1;
    }

    int res = kthSmallestbck(node->left, i);
    if (res != -1)
    {
        return res; //   目标值在左子树中
    }

    if (--i == 0) // 目标值为当前结点
    {
        return node->val;
    }

    return kthSmallestbck(node->right, i); // 看是否在右子树中，根据返回值判断，没在最终会返回-1
}
/**
 * 1、审题：
 * - 输入一棵二叉搜索树，求这棵树中第k小的元素
 * 2、解题
 * - 二叉搜索树，表示根据树的中序遍历的集合结果，是升序排列的
 * - 使用递归遍历解法
 * - 思路没毛病，主要是实现，需要传递引用，因为最小元素为最左边的叶子结点，需要不断往下传递i值
 */
int kthSmallest1(TreeNode *root, int k)
{
    int i = k;
    return kthSmallestbck(root, i);
}

/**
 * 迭代解法：
 * 1、使用栈保存迭代遍历的节点
 * 2、逻辑操作要符合二叉树的中序遍历
 * 3、在遍历的过程中，计算第k个数据，也就是目标值
 * - 迭代算法，使用栈保存遍历到的结点，并且不断查询他的左子节点，保存到栈中
 * - 知道叶子结点，然后就是从栈中取出栈顶元素，
 * -- 原始版本，变换一下
 */
int kthSmallest2old(TreeNode *root, int k)
{
    std::stack<TreeNode *> nodeStack;
    nodeStack.push(root);

    while (!nodeStack.empty())
    {
        TreeNode *node = nodeStack.top();
        while (node != nullptr)
        {
            nodeStack.push(node);
            node = node->left;
        }

        node = nodeStack.top();
        nodeStack.pop();
        if (k == 0)
        {
            return node->val;
        }
        k--;

        if (node->right != nullptr)
        {
            nodeStack.push(node->right);
        }
    }
    return -1;
}

/**
 * 1、不断遍历二叉树的左子树节点，保存到栈中，遍历到叶子结点时，出栈
 * 2、然后遍历他的右子树节点，不管他是否是空节点，
 * - 如果这个时候的右子节点不为空，则从这个节点开始不断遍历他的左子节点树
 * 3、如果右子节点为空，则从栈中集合中取数据，出栈操作。
 */
int kthSmallest(TreeNode *node, int k)
{
    std::stack<TreeNode *> nodeStack;

    while (node != nullptr || !nodeStack.empty())
    {
        while (node != nullptr)
        {
            nodeStack.push(node);
            node = node->left;
        }

        node = nodeStack.top();
        nodeStack.pop();
        if (k == 1)
        {
            return node->val;
        }
        k--;

        node = node->right;
    }
    return -1;
}

/*
 * 前序遍历的迭代解法
 */
std::vector<int> preOrder(TreeNode *root)
{
    std::vector<int> resList;
    if (root == nullptr)
    {
        return resList;
    }

    std::stack<TreeNode *> nodeStack;
    nodeStack.push(root);

    while (!nodeStack.empty())
    {
        TreeNode *currNode = nodeStack.top();
        nodeStack.pop();

        if (currNode->left != nullptr)
        {
            nodeStack.push(currNode->left);
        }
        if (currNode->right != nullptr)
        {
            nodeStack.push(currNode->right);
        }
    }
    return resList;
}

/**
 * 给定一个二叉搜索树的根节点 root ，和一个整数 k ，请你设计一个算法查找其中第 k 小的元素（从 1 开始计数）。

示例 1：
输入：root = [3,1,4,null,2], k = 1
输出：1

示例 2：
输入：root = [5,3,6,2,4,null,null,1], k = 3
输出：3

提示：
树中的节点数为 n 。
1 <= k <= n <= 104
0 <= Node.val <= 104
进阶：如果二叉搜索树经常被修改（插入/删除操作）并且你需要频繁地查找第 k 小的值，你将如何优化算法？
 */
int main(int argc, char const *argv[])
{

    return 0;
}
