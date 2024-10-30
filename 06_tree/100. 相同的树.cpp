#include <iostrem>
#include "../utils/TreeNode.h"

/**
 * 1、审题：
 * - 输入二叉树，判断这两棵树是否相同
 * - 二叉树相同，要求节点位置和节点的数值都相同
 * 2、解题：
 * - 递归解法，先判断当前结点是否相同（都为空 、 或者都不为空，且数值相同）
 * - 然后继续递归往下遍历判断左右子树是否相同
 */
bool isSameTree(TreeNode *p, TreeNode *q)
{
    if (p == nullptr && q == nullptr)
    {
        return true;
    }

    if (p != nullptr && q != nullptr && p->val == q->val) // 当前结点相同，再判断左右子树是否相同
    {
        bool leftRes = isSameTree(p->left, q->left);
        bool rightRes = isSameTree(p->right, q->right);
        return leftRes && rightRes;
    }
    return false;
}

/**
 * 给你两棵二叉树的根节点 p 和 q ，编写一个函数来检验这两棵树是否相同。
如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的。

示例 1：
输入：p = [1,2,3], q = [1,2,3]
输出：true

示例 2：
输入：p = [1,2], q = [1,null,2]
输出：false

示例 3：
输入：p = [1,2,1], q = [1,1,2]
输出：false

提示：
两棵树上的节点数目都在范围 [0, 100] 内
-104 <= Node.val <= 104
 */
int main(int argc, char const *argv[])
{
    return 0;
}
