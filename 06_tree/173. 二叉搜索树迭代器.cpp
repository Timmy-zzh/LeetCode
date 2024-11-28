#include <iostream>
#include <vector>
#include "../utils/TreeNode.h"

/**
 * 1、审题：
 * - 输入一个二叉树，构建一个二叉树的迭代器，要求实现迭代器的next和hasNext方法
 * 2、解题：
 * - 根据输入的二叉树，进行中序遍历，拿到中序遍历后的集合，
 * - 在next和hasNext方法中，遍历这个集合
 */
class BSTIterator
{
public:
    BSTIterator(TreeNode *root)
    {
        generateList(root);
        size = array.size();
        currIndex = 0;
    }

    // 中序遍历二叉树，并将获取到的节点值，添加到集合中
    void generateList(TreeNode *node)
    {
        if (node == nullptr)
        {
            return;
        }
        generateList(node->left);
        array.push_back(node->val);
        generateList(node->right);
    }

    int next()
    {
        return array[currIndex++];
    }

    bool hasNext()
    {
        return size > currIndex;
    }

private:
    std::vector<int> array;
    int size = 0;
    int currIndex = 0;
};

/**
 * 实现一个二叉搜索树迭代器类BSTIterator ，表示一个按中序遍历二叉搜索树（BST）的迭代器：
BSTIterator(TreeNode root) 初始化 BSTIterator 类的一个对象。BST 的根节点 root 会作为构造函数的一部分给出。
指针应初始化为一个不存在于 BST 中的数字，且该数字小于 BST 中的任何元素。
boolean hasNext() 如果向指针右侧遍历存在数字，则返回 true ；否则返回 false 。
int next()将指针向右移动，然后返回指针处的数字。
注意，指针初始化为一个不存在于 BST 中的数字，所以对 next() 的首次调用将返回 BST 中的最小元素。

你可以假设 next() 调用总是有效的，也就是说，当调用 next() 时，BST 的中序遍历中至少存在一个下一个数字。

示例：
输入
["BSTIterator", "next", "next", "hasNext", "next", "hasNext", "next", "hasNext", "next", "hasNext"]
[[[7, 3, 15, null, null, 9, 20]], [], [], [], [], [], [], [], [], []]
输出
[null, 3, 7, true, 9, true, 15, true, 20, false]

解释
BSTIterator bSTIterator = new BSTIterator([7, 3, 15, null, null, 9, 20]);
bSTIterator.next();    // 返回 3
bSTIterator.next();    // 返回 7
bSTIterator.hasNext(); // 返回 True
bSTIterator.next();    // 返回 9
bSTIterator.hasNext(); // 返回 True
bSTIterator.next();    // 返回 15
bSTIterator.hasNext(); // 返回 True
bSTIterator.next();    // 返回 20
bSTIterator.hasNext(); // 返回 False

提示：
树中节点的数目在范围 [1, 105] 内
0 <= Node.val <= 106
最多调用 105 次 hasNext 和 next 操作

进阶：
你可以设计一个满足下述条件的解决方案吗？next() 和 hasNext() 操作均摊时间复杂度为 O(1) ，并使用 O(h) 内存。其中 h 是树的高度。
 */
int main(int argc, char const *argv[])
{

    return 0;
}
