#include <vector>
#include "../utils/TreeNode.h"
#include <iostream>

/**
 * 递归实现，不断遍历当前树的结点（分左右子树）
 * - 如果当前结点是空，说明上一层遍历到了叶子结点，判断当前累加的sum与目标值是否相同，并返回判断结果值
 * - 如果当前结点不为空，说明可能还存在下一层结点，则继续遍历左右节点，并传递累加值
 * - 因为是二叉树，所以要综合判断左右子树的结果值
 * - 截断，如果当前累加值大于目标值了，则没必要继续往下遍历了，直接返回false
 * 考虑： 节点值有可能等于0
 * - 不用这样判断，当目标值和累加值相等时，判断当前结点是否是叶子结点
 * - 采用判断当前节点是否是空节点，和目标值与累加值是否相同
 * 解题关键：
 * - 只关注当前结点的累加值
 */
bool hasPathSumBck(TreeNode *node, int targetSum, int sum) // sum的值，表示已经到node结点的累加值了
{
    std::cout << "hasPathSumBck  node:" << node->val << " ,sum: " << sum << std::endl;

    if (sum == targetSum) // 等于,判断当前结点是否是叶子结点
    {
        if (node->left == nullptr && node->right == nullptr)
        {
            return true;
        }
    }

    bool leftRes = false;
    if (node->left != nullptr)
    {
        leftRes = hasPathSumBck(node->left, targetSum, sum + (node->left->val));
    }
    bool rightRes = false;
    if (node->right != nullptr)
    {
        rightRes = hasPathSumBck(node->right, targetSum, sum + (node->right->val));
    }
    return leftRes || rightRes;
}

/**
 * 1、审题：
 * - 输入一棵二叉树和一个int值的目标值，判断从二叉树的根节点到叶子节点的路径上所有结点值的和，是否等于目标值，如果存在则返回true，否则返回false
 * 2、解题：
 * - 前序遍历，从根节点开始不断往左右子树下方遍历，直到叶子结点停止，
 * - 并在递归的过程中不断累加树节点的值，直到叶子结点，且累加和等于目标值的
 * - 裁剪，如果累加值已经大于等于目标值了，直接返回false，不用继续往下层遍历了
 */
bool hasPathSum2(TreeNode *root, int targetSum)
{
    if (root == nullptr)
    {
        return false;
    }
    return hasPathSumBck(root, targetSum, root->val); // 递归实现，查看到当前结点的值是否等于目标值 targetSum
}

/**
 * 递归解法，不断往下遍历左右子节点，在遍历的过程中，目标值targetSum不断减少，
 * - 知道递减的值等于当前结点值，如果相等，判断当前结点是否是叶子结点
 * - 如果不相等，则继续往下遍历，左右子节点
 * 问题：
 * - 当遇到结点值为0的情况，还是解决不了
 * -- [10,2,11,0]
 */
bool hasPathSum(TreeNode *root, int targetSum)
{
    if (root == nullptr)
    {
        return false;
    }
    // if (root->val == targetSum)
    // {
    //     return root->left == nullptr && root->right == nullptr;
    // }

    if (root->left == nullptr && root->right == nullptr) // 改变判断思路，当节点为叶子结点时，判断结点值，是否等于累加值
    {
        return root->val == targetSum;
    }

    return hasPathSum(root->left, targetSum - root->val) ||
           hasPathSum(root->right, targetSum - root->val);
}

/**
 * 给你二叉树的根节点 root 和一个表示目标和的整数 targetSum 。判断该树中是否存在 根节点到叶子节点 的路径，
 * 这条路径上所有节点值相加等于目标和 targetSum 。如果存在，返回 true ；否则，返回 false 。
叶子节点 是指没有子节点的节点。

示例 1：
输入：root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
输出：true
解释：等于目标和的根节点到叶节点路径如上图所示。

示例 2：
输入：root = [1,2,3], targetSum = 5
输出：false
解释：树中存在两条根节点到叶子节点的路径：
(1 --> 2): 和为 3
(1 --> 3): 和为 4
不存在 sum = 5 的根节点到叶子节点的路径。

示例 3：
输入：root = [], targetSum = 0
输出：false
解释：由于树是空的，所以不存在根节点到叶子节点的路径。

提示：
树中节点的数目在范围 [0, 5000] 内
-1000 <= Node.val <= 1000
-1000 <= targetSum <= 1000
 */
int main(int argc, char const *argv[])
{
    return 0;
}
