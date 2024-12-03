#include <iostream>
#include <vector>
#include "../utils/TreeNode.h"

/**
 * 1、审题
 * - 输入一个二叉树，和二叉树中的两个节点，求两个节点的最近公共祖先，节点也可以是自己的祖先
 * 2、解题：
 * - 递归解法，将这个问题拆分为三种情况
 * - 根节点， p，q节点分别是左右子树中，则当前结点为最近公共祖先，进行返回
 * - 根节点为p，q中一个节点，另一个节点在左、或者右子树中，这个时候返回节点
 * - 最后在根节点看来，就返回左右子树中不为空的结点
 * 3、一次搞定，这也行，我还以为会不成功呢
 * 总结：
 * - 不断拆分成不同情况，拆分成更小的情况
 */
TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (root == nullptr)
    {
        return nullptr;
    }
    if (root->val == p->val || root->val == q->val)
    {
        return root; // 当前结点等于其中一个目标值，返回当前值了
    }

    TreeNode *left = lowestCommonAncestor(root->left, p, q);
    TreeNode *right = lowestCommonAncestor(root->right, p, q);

    if (left != nullptr && right != nullptr)
    {
        // 左右子树都存在，则当前结点为最近公共祖先
        return root;
    }

    if (left != nullptr)
    {
        return left;
    }
    if (right != nullptr)
    {
        return right;
    }
    // if (left == nullptr && right == nullptr)
    // {
    //     return nullptr;
    // }
    return nullptr; // 左右节点都没有目标值，返回null
}

/**
 * 给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。
百度百科中最近公共祖先的定义为：“对于有根树 T 的两个节点 p、q，最近公共祖先表示为一个节点 x，
满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”

示例 1：
输入：root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
输出：3
解释：节点 5 和节点 1 的最近公共祖先是节点 3 。

示例 2：
输入：root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
输出：5
解释：节点 5 和节点 4 的最近公共祖先是节点 5 。因为根据定义最近公共祖先节点可以为节点本身。

示例 3：
输入：root = [1,2], p = 1, q = 2
输出：1

提示：
树中节点数目在范围 [2, 105] 内。
-109 <= Node.val <= 109
所有 Node.val 互不相同 。
p != q
p 和 q 均存在于给定的二叉树中。
 */
int main(int argc, char const *argv[])
{
    return 0;
}
