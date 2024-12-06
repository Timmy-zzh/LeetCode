#include <iostream>
#include <vector>
#include "../utils/TreeNode.h"

/**
 * 1、审题：
 * - 输入一棵二叉树，求二叉树每层结点的平均值
 * 2、解题：
 * - 层序遍历，将每层结点添加到集合中，然后求取平均值，最后返回
 * - 还是在每层结束的位置插入标记位null
 */
std::vector<double> averageOfLevels1(TreeNode *root)
{
    std::vector<double> resArr;
    std::vector<int> levelArr;
    std::vector<TreeNode *> queue;

    if (root == nullptr)
    {
        return resArr;
    }

    queue.push_back(root);
    queue.push_back(nullptr);

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
            levelArr.push_back(node->val);
        }
        else
        {
            // 为空，添加结束标记，求上一层集合的平均值，清空集合
            if (!queue.empty())
            {
                queue.push_back(nullptr);
            }
            int size = levelArr.size();
            double sum = 0;
            for (auto num : levelArr)
            {
                sum += num;
            }
            std::cout << "sum:" << sum << ",size:" << size << std::endl;
            double average = sum * 1.0 / size;

            resArr.push_back(average);
            levelArr.clear();
        }
    }

    return resArr;
}

// 优化，不用层级集合，直接使用sum和size尽心计数
std::vector<double> averageOfLevels(TreeNode *root)
{
    std::vector<double> resArr;

    if (root == nullptr)
    {
        return resArr;
    }

    double sum = 0;
    int size = 0;
    std::vector<TreeNode *> queue;

    queue.push_back(root);
    queue.push_back(nullptr);

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

            sum += node->val;
            size++;
        }
        else
        {
            // 为空，添加结束标记，求上一层集合的平均值，清空集合
            if (!queue.empty())
            {
                queue.push_back(nullptr);
            }
            std::cout << "sum:" << sum << ",size:" << size << std::endl;
            double average = sum * 1.0 / size;

            resArr.push_back(average);
            sum = 0;
            size = 0;
        }
    }

    return resArr;
}

/**
 * 给定一个非空二叉树的根节点 root , 以数组的形式返回每一层节点的平均值。与实际答案相差 10-5 以内的答案可以被接受。

示例 1：
输入：root = [3,9,20,null,null,15,7]
输出：[3.00000,14.50000,11.00000]
解释：第 0 层的平均值为 3,第 1 层的平均值为 14.5,第 2 层的平均值为 11 。
因此返回 [3, 14.5, 11] 。

示例 2:
输入：root = [3,9,20,15,7]
输出：[3.00000,14.50000,11.00000]

提示：
树中节点数量在 [1, 104] 范围内
-231 <= Node.val <= 231 - 1
 */
int main(int argc, char const *argv[])
{
    return 0;
}
