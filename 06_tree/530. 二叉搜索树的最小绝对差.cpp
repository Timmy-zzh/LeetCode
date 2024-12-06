#include <iostream>
#include <vector>
#include "../utils/TreeNode.h"

/**
 * 1、审题：
 * - 输入一棵二叉树，求树中相邻节点之间的差值的最小值，并返回
 * 2、解题：
 * - 递归解法
 * - 遍历到的结点与左右子节点（存在），求他们之间的差值，并与已存在的最小差值进行取最小值
 * - 然后继续遍历左右子节点
 * 3、审题错误： 题目要求返回二叉树中任意两个节点之间的的差值，不只是相邻节点的差值
 * - 忘记考虑二叉搜索树的特性，中序遍历是升序的，中序遍历：左根右
 * - 在中序遍历的过程中，判断前一个结点和当前结点的差值，使用当前结点的值减去上一个节点的值，和最终的最小结果值进行比较
 * - 默认第一个节点的前置节点值为-1
 * 4、总结：
 * - int& pre，在遍历的过程中，不断修改pre的引用值
 * 5、其他解法：
 * - 中序遍历过程中，使用集合保存遍历到的节点值，然后对集合中的元素，进行前后数据的差值求取
 */
int minRes = INT_MAX;

void getMinDiff(TreeNode *node, int &pre)
{
    if (node == nullptr)
    {
        return;
    }

    getMinDiff(node->left, pre);

    std::cout << "num:" << node->val << " ,pre:" << pre << std::endl;
    if (pre != -1)
    {
        int diffNum = node->val - pre;
        minRes = std::min(minRes, diffNum);
    }

    pre = node->val;
    getMinDiff(node->right, pre);
}

int getMinimumDifference(TreeNode *root)
{
    int pre = -1;
    getMinDiff(root, pre);
    return minRes;
}

/**
 * 给你一个二叉搜索树的根节点 root ，返回 树中任意两不同节点值之间的最小差值 。
差值是一个正数，其数值等于两值之差的绝对值。

示例 1：
输入：root = [4,2,6,1,3]
输出：1

示例 2：
输入：root = [1,0,48,null,null,12,49]
输出：1

提示：
树中节点的数目范围是 [2, 104]
0 <= Node.val <= 105
 */
int main(int argc, char const *argv[])
{
    return 0;
}
