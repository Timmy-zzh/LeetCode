#include <iostream>
#include "../utils/TreeNode.h"
#include <vector>
#include <algorithm>
#include "../utils/Print.h"

using namespace std;

void printArr(std::vector<int> &vector)
{
    std::cout << "print vector: ";
    int size = vector.size();
    for (size_t i = 0; i < size; i++)
    {
        std::cout << vector[i] << ",";
    }
    std::cout << std::endl;
}

/**
 * 1、审题：
 * - 输入一个二叉树，的前序遍历序列和中序遍历序列，根据这两个序列构造二叉树
 * 2、解题：
 * - 前序遍历的二叉树，是从根节点开始遍历，遍历顺序是： 根 -》左 -》 右
 * - 中序遍历的二叉树，是从左子树节点开始遍历，顺序是： 左 -》 根 -》右
 * -- 根据前序遍历的第一个节点，就是根节点，在中序遍历中找到根节点的位置，那么中序序列的左边就是左子树，右边就是右子树
 * - 再继续遍历，需要在遍历的过程中，构建二叉树
 * 3、解题思路：递归解法，不断的将大问题分解为小问题来处理
 * - 从前序序列中取出第一个节点，就是根节点，返回
 * - 拿着这个根节点，在中序序列中找到根节点的位置，左边的就是做子树，右边的就是右子树
 * - 那根节点的左子节点，就从左子树中返回，右子节点就从右子树中返回
 * - 递归调用buildTree方法，
 * 4、总结
 * - 递归思想
 * - 熟悉二叉树的前序遍历和中序遍历的规则，前序遍历是根节点先访问，再然后是左子树-》右子树
 * -- 中序遍历，根节点是在中间位置访问
 * - 在递归遍历的过程中，前序序列的首个元素就是根节点，取出根节点，在中序序列中查找，确定左右子树的序列个数
 * - 前序序列和中序序列，通过根节点进行分割成左右子树的序列，再根据前序和中序子序列进行查找左右子节点
 * - 在遍历的过程中组建二叉树的结点位置
 */
TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    if (preorder.size() == 0)
    {
        return nullptr;
    }
    if (preorder.size() == 1)
    {
        return new TreeNode(preorder[0]);
    }

    int nodeVal = preorder[0];
    TreeNode *node = new TreeNode(nodeVal);

    /**
     * nodeVal 为前序遍历的根节点值
     * 根据nodeVal的值，在中序序列中找出该元素位置，以该位置为标记，进行分割，得到中序遍历的左子树，和右子树
     * 再根据分割后的中序序列的左子树个数，从前序序列中截取出中序遍历的左子树，（要先过滤第一个位置）， 前序序列的右子树也是一样
     */
    // 1、找到根节点元素在中序遍历的位置 index
    auto it = std::find(inorder.begin(), inorder.end(), nodeVal);
    int index = it - inorder.begin();
    std::cout << "nodeVal:" << nodeVal << ",index:" << index << std::endl;
    // 2、对中序遍历进行分割，成两个数组
    std::vector<int> inLeft(inorder.begin(), it);
    std::vector<int> inRight(it + 1, inorder.end());
    printArr(inLeft);
    printArr(inRight);

    // 3、对前序序列，进行遍历分割，成两个数组
    std::vector<int> preLeft(preorder.begin() + 1, preorder.begin() + 1 + index);
    std::vector<int> preRight(preorder.begin() + 1 + index, preorder.end());
    printArr(preLeft);
    printArr(preRight);

    node->left = buildTree(preLeft, inLeft);
    node->right = buildTree(preRight, inRight);

    return node;
}

/**
 * 给定两个整数数组 preorder 和 inorder ，其中 preorder 是二叉树的先序遍历，
 *  inorder 是同一棵树的中序遍历，请构造二叉树并返回其根节点。
 *
 * 示例 1:
 * 输入: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
 * 输出: [3,9,20,null,null,15,7]
 *
 * 示例 2:
 * 输入: preorder = [-1], inorder = [-1]
 * 输出: [-1]
 */
int main(int argc, char const *argv[])
{
    std::vector<int> preorder = {3, 9, 20, 15, 7};
    std::vector<int> inorder = {9, 3, 15, 20, 7};
    TreeNode *root = buildTree(preorder, inorder);

    return 0;
}
