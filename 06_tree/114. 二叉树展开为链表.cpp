#include <vector>
#include "../utils/TreeNode.h"

/**
 * 1、审题：
 * - 输入一棵二叉树，要求将这棵树展开成只有右节点的单叉树，要求单叉的结构和二叉树的前序遍历顺序相同
 * 2、解题:
 * - 前序遍历这棵二叉树，在遍历的过程中构建单叉树
 * -
 */

TreeNode *node;
void flatten(TreeNode *root)
{
    if (root == nullptr)
    {
        return;
    }

    TreeNode *left = root->left;
    TreeNode *right = root->right;

    node = root;
    if (left != nullptr)
    {
        node->left = nullptr;
        node->right = left;
        node = node->right;
        flatten(node);
    }

    if (right != nullptr)
    {
        node->right = right;
        node = node->right;
        flatten(node);
    }
}

/**
 * 给你二叉树的根结点 root ，请你将它展开为一个单链表：
展开后的单链表应该同样使用 TreeNode ，其中 right 子指针指向链表中下一个结点，而左子指针始终为 null 。
展开后的单链表应该与二叉树 先序遍历 顺序相同。

示例 1：
输入：root = [1,2,5,3,4,null,6]
输出：[1,null,2,null,3,null,4,null,5,null,6]

示例 2：
输入：root = []
输出：[]

示例 3：
输入：root = [0]
输出：[0]

提示：
树中结点数在范围 [0, 2000] 内
-100 <= Node.val <= 100

进阶：你可以使用原地算法（O(1) 额外空间）展开这棵树吗？
 */
int main(int argc, char const *argv[])
{

    return 0;
}
