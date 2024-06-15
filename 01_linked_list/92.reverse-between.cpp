#include <iostream>
// #include "../bean/ListNode.h"
#include "../bean/Print.h"

// 先声明
ListNode *reverseList(ListNode *head);

int main(int argc, char const *argv[])
{
    std::cout << "链表翻转" << std::endl;

    ListNode node1 = ListNode(1);
    ListNode node2 = ListNode(2);
    ListNode node3 = ListNode(3);

    node1.next = &node2;
    node2.next = &node3;

    printLinkedList(&node1);

   auto res =  reverseList(&node1);

    printLinkedList(res);

    return 0;
}

/**
 * 1、审题：
 * - 翻转链表，只不过是翻转链表中间的一个部分
 * 2、解题：
 * - 先做一遍链表翻转操作，全部翻转处理
 */
ListNode *reverseBetween(ListNode *head, int left, int right)
{
    return nullptr;
}

/**
 * 反转链表：
 * - 不断遍历链表中的结点
 * - 使用一个变量prev结点，表示翻转后的链表的头结点
 * - 遍历过程中，新遍历位置的链表插入到头结点的前面去，成为新的头结点，并且prev结点新赋值为新插入头结点
 * - 知道原始链表遍历完成
 */
ListNode *reverseList(ListNode *head)
{
    ListNode *prve = nullptr;
    ListNode *temp = nullptr;

    while (head != nullptr)
    {
        temp = head->next; // 临时存储下一个节点

        head->next = prve; // 遍历到的结点插入到头部位置
        prve = head;

        head = temp; // 移动到下一个节点位置
    }

    return prve;
}