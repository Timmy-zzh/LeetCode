#include <iostream>
#include <vector>
#include "../utils/TreeNode.h"

typedef struct
{
    int min;
    int max;
    bool isBst;
} BstTree;

/**
 * 迭代法，中序遍历
 * - 使用stack栈保存中序遍历到的结点，判断当前结点是否比前一个结点的值大
 * - 大的话，继续遍历，知道所有结点
 * - 小的话，说明不是二叉搜索树，直接返回false
 */
bool isValidBST(TreeNode *root)
{
    std::stack<TreeNode *> myStack;
    long preNum = LONG_MIN + 1;

    while (root != nullptr || !myStack.empty())
    {
        while (root != nullptr) // 不断将左子节点添加到栈中
        {
            myStack.push(root);
            root = root->left;
        }

        // 遇到左侧叶子结点，则出栈
        TreeNode *node = myStack.top();
        myStack.pop();

        // 判断当前结点值和前继值大小，并重新赋值前继值
        if (node->val <= preNum)
        {
            return false;
        }
        preNum = node->val;

        // 当前结点遍历完了，继续遍历右侧的结点，如果有的话，没有的话，那就会从栈中取节点
        root = node->right;
    }

    return true;
}

bool helper(TreeNode *node, long min, long max)
{
    if (node == nullptr)
    {
        return true;
    }
    
    // 使用当前结点值，与区间返回比较，在区间外，则说明不是二叉搜索树
    if (node->val <= min || node->val >= max)
    {
        return false;
    }

    return helper(node->left, min, node->val) && helper(node->right, node->val, max);
}

/**
 * 递归：利用二叉搜索树的特性
 * - 左子树所有的节点值，都比当前结点节点值小，右子树所有结点值，都比当前结点值大
 * - 且左右子树都是二叉搜索树
 *
 */
bool isValidBST(TreeNode *root)
{
    return helper(root, LONG_MIN, LONG_MAX);
}

/**
 * 给你一个二叉树的根节点 root ，判断其是否是一个有效的二叉搜索树。
有效 二叉搜索树定义如下：

节点的左
子树
只包含 小于 当前节点的数。
节点的右子树只包含 大于 当前节点的数。
所有左子树和右子树自身必须也是二叉搜索树。

示例 1：
输入：root = [2,1,3]
输出：true

示例 2：
输入：root = [5,1,4,null,null,3,6]
输出：false
解释：根节点的值是 5 ，但是右子节点的值是 4 。

提示：
树中节点数目范围在[1, 104] 内
-231 <= Node.val <= 231 - 1
 */
int main(int argc, char const *argv[])
{
    return 0;
}
