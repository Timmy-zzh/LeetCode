#include <iostream>
#include <vector>
#include "../utils/TreeNode.h"

/**
 * 1、审题：
 * - 输入一个二叉树，求这个二叉树中一条最大值的路径和
 * - 路径定义：
 * -- 包含最少一个节点，
 * -- 不一定要包括根节点
 * -- 每个节点只能在一条路径中
 * 2、解题:
 * - 如何找到这条路径？可把这个问题进行拆分到更小的问题
 * - 可以看做，根节点与左右子树的组合形成的路径，分为四种情况
 * -- 左右子树都不要添加到路径中，只有当前结点（如果左右子树的路径和都小于0）
 * -- 根节点和左右子树中的一个组合成新路径，这要看左右哪个值更大了（要有一个路径和大于0，一个小于0的情况）
 * -- 最后是根节点和左右子树的路径，三个部分一起形成一条新的路径
 * 3、采用递归解法
 * - 深度优先解法，dfs，在递归的过程中不断求最大路径和，并不断更新已有的值
 */
int maxSumRes = INT_MIN;

int calcMaxSum(TreeNode *root)
{
    if (root == nullptr) // 叶子结点往下了，就是0，叶子结点就返回自身值
    {
        return 0;
    }

    int leftPathSum = calcMaxSum(root->left);   // 左子树，计算后得到的最大路径和
    int rightPathSum = calcMaxSum(root->right); // 右子树
    // 当前结点求取的最大路径和
    int leftPathMax = std::max(leftPathSum, 0);
    int rightPathMax = std::max(rightPathSum, 0);

    int currPathMax = root->val + leftPathMax + rightPathMax;

    maxSumRes = std::max(maxSumRes, currPathMax);

    return root->val + std::max(leftPathMax, rightPathMax); // 返回当前结点的最大陆景和，从左右子树中选择其中一个
}

int maxPathSum(TreeNode *root)
{
    calcMaxSum(root);
    return maxSumRes;
}

/**
 * 二叉树中的 路径 被定义为一条节点序列，序列中每对相邻节点之间都存在一条边。同一个节点在一条路径序列中 至多出现一次 。
 * 该路径 至少包含一个 节点，且不一定经过根节点。路径和 是路径中各节点值的总和。
 * 给你一个二叉树的根节点 root ，返回其 最大路径和 。
 *
示例 1：
输入：root = [1,2,3]
输出：6
解释：最优路径是 2 -> 1 -> 3 ，路径和为 2 + 1 + 3 = 6

示例 2：
输入：root = [-10,9,20,null,null,15,7]
输出：42
解释：最优路径是 15 -> 20 -> 7 ，路径和为 15 + 20 + 7 = 42

提示：
树中节点数目范围是 [1, 3 * 104]
-1000 <= Node.val <= 1000
 */
int main(int argc, char const *argv[])
{
    TreeNode *root = new TreeNode(1);
    TreeNode *left = new TreeNode(2);
    TreeNode *right = new TreeNode(3);
    root->left = left;
    root->right = right;

    int res = maxPathSum(root);
    printf("res:" + res);

    return 0;
}
