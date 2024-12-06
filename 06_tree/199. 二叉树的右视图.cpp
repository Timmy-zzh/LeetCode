#include <iostream>
#include <vector>
#include "../utils/TreeNode.h"

/**
 * 1、审题：
 * - 输入一个二叉树，将二叉树右侧看到的结点保存到一个集合中返回
 * 2、解题：
 * - 层序遍历，在遍历到一层最左侧的结点时，将该结点值保存到集合中
 * - 没遍历完一层的结点后，插入一个空节点到集合中，遍历到这个空节点，意味着上一个节点就是二叉树右侧视角的结点
 * - 使用一个变量保存前一个结点的值
 * 3、总结：
 * - 层序遍历
 * - 在遍历到一层结束时，插入标记位
 * - 递归终止结束
 */
std::vector<int> rightSideView(TreeNode *root)
{
    std::vector<TreeNode *> queue;
    std::vector<int> res;

    if (root == nullptr)
    {
        return res;
    }

    queue.push_back(root);
    queue.push_back(nullptr);
    int preVal = 0;

    while (!queue.empty())
    {
        TreeNode *node = queue.front();
        queue.erase(queue.begin());

        if (node != nullptr)
        {
            if (node->left != nullptr)
            {
                queue.push_back(node->left);
            }
            if (node->right != nullptr)
            {
                queue.push_back(node->right);
            }
            preVal = node->val;
        }
        else
        {
            // 等于空，则
            res.push_back(preVal);
            if (!queue.empty())
            {
                queue.push_back(nullptr);
            }
        }
    }

    return res;
}

/**
 * 给定一个二叉树的 根节点 root，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。

示例 1：
输入：root = [1,2,3,null,5,null,4]
输出：[1,3,4]
解释：

示例 2：
输入：root = [1,2,3,4,null,null,null,5]
输出：[1,3,4,5]
解释：

示例 3：
输入：root = [1,null,3]
输出：[1,3]

示例 4：
输入：root = []
输出：[]

提示:
二叉树的节点个数的范围是 [0,100]
-100 <= Node.val <= 100
 */
int main(int argc, char const *argv[])
{
    return 0;
}
