#include <iostream>
#include <vector>

#include "../utils/Node.h"

/**
 * 1、审题：
 * - 输入一个二叉树，二叉树的属性结构中，除了有左右指针，还有一个next指针，指向右侧节点，右侧没有节点，则指向null
 * - 初始情况下，所有结点的next都指向null，现在要求将有右侧节点的next指针，添加上指向，并最终返回当前二叉树
 * 2、解题：
 * - 层序遍历，遍历二叉树，将遍历到的二叉树节点保存到队列中，队列以先进先出的方式存储
 */
Node *connect(Node *root)
{
  if (root == nullptr)
  {
    return nullptr;
  }

  std::vector<Node *> queue;
  queue.push_back(root);
  queue.push_back(nullptr);

  while (!queue.empty() && queue.size() > 1)
  {
    // 从队列头中取出元素
    Node *pop = queue.front();
    // 再删除
    queue.erase(queue.begin());
    if (pop != nullptr)
    {
      if (pop->left != nullptr)
      {
        queue.push_back(pop->left);
      }
      if (pop->right != nullptr)
      {
        queue.push_back(pop->right);
      }

      // next指针，指向队列的后一个
      pop->next = queue.front();
    }
    else
    {
      // 为空了，在队列末尾，插入一个空
      queue.push_back(nullptr);
    }
  }

  return root;
}

/**
 * 给定一个二叉树：

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 NULL 。
初始状态下，所有 next 指针都被设置为 NULL 。

示例 1：
输入：root = [1,2,3,4,5,null,7]
输出：[1,#,2,3,#,4,5,7,#]
解释：给定二叉树如图 A 所示，你的函数应该填充它的每个 next 指针，以指向其下一个右侧节点，
如图 B 所示。序列化输出按层序遍历顺序（由 next 指针连接），'#' 表示每层的末尾。

示例 2：
输入：root = []
输出：[]

提示：
树中的节点数在范围 [0, 6000] 内
-100 <= Node.val <= 100

进阶：
你只能使用常量级额外空间。
使用递归解题也符合要求，本题中递归程序的隐式栈空间不计入额外空间复杂度。
 */
int main(int argc, char const *argv[])
{

  return 0;
}
