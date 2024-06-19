#include <iostream>
#include "../bean/Print.h"

ListNode *partition(ListNode *head, int x);

int main(int argc, char const *argv[])
{
    ListNode node1 = ListNode(1);
    ListNode node2 = ListNode(4);
    ListNode node3 = ListNode(3);
    ListNode node4 = ListNode(2);
    ListNode node5 = ListNode(5);
    ListNode node6 = ListNode(2);

    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;
    node5.next = &node6;

    printLinkedList(&node1);

    auto res = partition(&node1, 3);

    printLinkedList(res);

    return 0;
}

/**
 * 1、审题：
 * - 输入一个链表的头结点，和元素x，要求将小于x元素的结点，都放到前面，大于等于x的结点都在后面，且元素的相对位置不变
 * 2、解题：
 * - 双指针解法，遍历的时候要持有前继节点，因为只有持有了前继节点，才能获取到后面的节点，将后继节点插入到前面位置
 * - 并且保持链表不断裂，所以遍历的时候，以后继节点为判断条件
 * 3、问题：
 * - 新创建了一个节点，后面跟着头结点，还是不行呢
 * 4、换个思路：创建两个子链表，小于x的，和大于x的，最后将两个链表连接起来即可
 * - 赋值出错了
 */
ListNode *partition(ListNode *head, int x)
{
    ListNode *small = new ListNode(-1);
    ListNode *smallHead = small;
    ListNode *large = new ListNode(-1);
    ListNode *largeHead = large;

    while (head != nullptr)
    {
        if (head->val < x)
        {
            small->next = head;
            small = small->next;
        }
        else
        {
            large->next = head;
            large = large->next;
        }

        head = head->next;
    }
    printf("small.val:%d \n", small->val);
    printf("large.val:%d \n", large->val);

    large->next = nullptr;
    small->next = largeHead->next;

    return smallHead->next;
}

