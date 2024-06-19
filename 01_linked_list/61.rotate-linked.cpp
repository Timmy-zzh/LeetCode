#include <iostream>
#include "../bean/Print.h"

ListNode *retateRight(ListNode *head, int k);

int main(int argc, char const *argv[])
{
    ListNode node1 = ListNode(1);
    ListNode node2 = ListNode(2);
    ListNode node3 = ListNode(3);
    ListNode node4 = ListNode(4);
    ListNode node5 = ListNode(5);

    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;

    printLinkedList(&node1);

    auto res = retateRight(&node1, 2);

    printLinkedList(res);

    return 0;
}

/**
 * 翻转链表：
 * - 先找到链表倒数k个节点的前继节点，然后将该链表的子串部分，整体插入到链表头部
 */
ListNode *rotateRight(ListNode *head, int k)
{
    if (head == nullptr)
    {
        return head;
    }

    int len = 0;
    ListNode *temp = head;
    while (temp != nullptr)
    {
        temp = temp->next;
        len++;
    }
    k = k % len;

    ListNode *empty = new ListNode(-1);
    empty->next = head;
    int i = 0;
    ListNode *prev = empty;
    ListNode *last = nullptr;

    while (head != nullptr)
    {
        if (i >= k)
        {
            prev = prev->next;
        }
        i++;
        if (head->next == nullptr)
        {
            last = head;
        }
        head = head->next;
    }

    // 插入
    last->next = empty->next;
    empty->next = prev->next;
    prev->next = nullptr;

    return empty->next;
}
