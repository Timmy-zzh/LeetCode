#include <iostream>
#include <vector>
#include "../utils/TreeNode.h"

/**
 *  将到达前一个结点的数字和当前数字进行相加，相加规则为 原有的num乘以10 再加上当前结点值，
 * - 然后再继续往下遍历，当遍历到结点为null时，说明已经是叶子结点了，则将累加值添加到集合中
 * - 往下遍历的结点，一定是不为空的结点
 */
void sumNumbersDfs(TreeNode *node, int num, std::vector<int> &array)
{
    num = num * 10 + node->val;
    if (node->left == nullptr && node->right == nullptr)
    {
        array.push_back(num);
        return;
    }

    if (node->left != nullptr)
    {
        sumNumbersDfs(node->left, num, array);
    }
    if (node->right != nullptr)
    {
        sumNumbersDfs(node->right, num, array);
    }
}

/**
 * 1、审题：
 * - 输入一个二叉树，树中每个节点值为0到9的数字，规定从根节点到叶子结点所有的数字组合成具体的数字
 * - 遍历从根节点到所有叶子结点的所有数字，当遍历到叶子结点时，返回节点数字组合
 * 2、解题：
 * - 分两条线，遍历左右子树，拿到遍历后的数字，然后和当前结点合并， -- 这思路不对
 * - 还是使用深度优先算法，把所有根节点到叶子结点的数字，保存到集合中，当所有的链路都遍历完了，再相加返回
 * 3、深度优先遍历 dfs
 * - 一直遍历，直到遍历到叶子结点，
 * 4、总结：
 * - 参数传递，传递指针（引用），不要值传递，值传递会是一个新的数据，调用的是拷贝构造函数
 * - 递归算法，从根节点开始计算，构造一个虚拟的结点
 * - 递归过程中，遇到叶子结点，就进行操作，继续往下遍历的结点，必须是不为空的结点
 */
int sumNumbers(TreeNode *root)
{
    std::vector<int> array;

    sumNumbersDfs(root, 0, array);

    int sumRes = 0;
    for (auto num : array)
    {
        sumRes += num;
    }
    return sumRes;
}

/**
 * 给你一个二叉树的根节点 root ，树中每个节点都存放有一个 0 到 9 之间的数字。
每条从根节点到叶节点的路径都代表一个数字：

例如，从根节点到叶节点的路径 1 -> 2 -> 3 表示数字 123 。
计算从根节点到叶节点生成的 所有数字之和 。
叶节点 是指没有子节点的节点。

示例 1：
输入：root = [1,2,3]
输出：25
解释：
从根到叶子节点路径 1->2 代表数字 12
从根到叶子节点路径 1->3 代表数字 13
因此，数字总和 = 12 + 13 = 25

示例 2：
输入：root = [4,9,0,5,1]
输出：1026
解释：
从根到叶子节点路径 4->9->5 代表数字 495
从根到叶子节点路径 4->9->1 代表数字 491
从根到叶子节点路径 4->0 代表数字 40
因此，数字总和 = 495 + 491 + 40 = 1026

提示：
树中节点的数目在范围 [1, 1000] 内
0 <= Node.val <= 9
树的深度不超过 10
 */
int main(int argc, char const *argv[])
{

    return 0;
}
