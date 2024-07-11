#include <iostream>
#include "../utils/ListNode.h"
#include "../utils/Print.h"

// 先声明
ListNode *reverseList(ListNode *head);
ListNode *reverseBetween(ListNode *head, int left, int right);

int main(int argc, char const *argv[])
{
    std::cout << "链表翻转" << std::endl;

    ListNode node1 = ListNode(1);
    ListNode node2 = ListNode(2);
    ListNode node3 = ListNode(3);
    ListNode node4 = ListNode(4);
    ListNode node5 = ListNode(5);

    node1.next = &node2;
    node2.next = &node3;
    // node3.next = &node4;
    // node4.next = &node5;

    printLinkedList(&node1);

    // auto res = reverseList(&node1);
    // auto res = reverseBetween(&node1, 2, 4);
    auto res = reverseBetween(&node1, 2, 3);

    printLinkedList(res);

    return 0;
}

/**
 * 翻转连接：一次循环，遍历的过程中插入，中间控制前继节点
 * - 遍历过程中，找到翻转部分的前继节点，和后继节点
 * - 在区间范围内，进行单个节点的插入，插入到前继节点的后面
 * - 并且原始链表正常往后遍历，节点插入后，整个链表还是连续的，不能出现中断
 * 总结： 
 * - 此题时间复杂度100%，这花的时间都是值得的，而且发现这个是有规律的，
 * -- 我的花时间进行规律提取，这个是深入思考的过程
 * -- 遍历过程中将节点进行插入操作： 保持遍历结点的后继节点后面需要连接起来，
 * --- 插入节点的时候，先连接后面的结点，再使用前继节点连接遍历结点，
 * --- 这到题目，还需要保持链表整体性的连接，这也就是last指针的作用
 * - 不断刷题，
 */
ListNode *reverseBetween(ListNode *head, int left, int right)
{
    if (head == nullptr)
    {
        return nullptr;
    }

    ListNode *empty = new ListNode(-1);
    empty->next = head;
    ListNode *prev = empty;
    ListNode *temp = nullptr;
    ListNode *last = nullptr;
    int n = 1;

    while (head != nullptr)
    {
        if (n < left)
        {
            prev = head;
            head = head->next;
            n++;
            continue;
        }
        else if (n == left)
        {
            last = head;
        }
        else if (n == right + 1)
        {
            break;
        }

        temp = head->next;

        // 插入
        head->next = prev->next;
        prev->next = head;

        // 谁指向中间链表部分的最后位置呢，中间的位置是断开的
        if (last != nullptr)
        {
            last->next = temp;
        }

        head = temp;
        n++;
    }

    return empty->next;
}

/**
 * 1、审题：
 * - 翻转链表，只不过是翻转链表中间的一个部分
 * 2、解题：
 * - 先做一遍链表翻转操作，全部翻转处理
 * - 翻转中间的一部分，那先找到这部分的前缀节点，和后继节点，翻转后再合并起来
 */
ListNode *reverseBetween2(ListNode *head, int left, int right)
{
    if (head == nullptr)
    {
        return nullptr;
    }

    ListNode *empty = new ListNode(-1);
    empty->next = head;

    ListNode *prev = empty;
    ListNode *last = nullptr;
    int n = 1;

    while (head != nullptr)
    {
        if (n == left - 1)
        {
            prev = head;
        }
        else if (n == right)
        {
            last = head;
        }

        n++;
        head = head->next;
    }

    // 记录中间部分的前一个结点
    ListNode *prev1 = prev->next;
    prev->next = nullptr; // 截断

    ListNode *last1 = last->next;
    last->next = nullptr;

    printLinkedList(prev1);
    ListNode *reverseNode = reverseList(prev1);
    printLinkedList(reverseNode);

    // 最后连接起来
    prev->next = reverseNode;
    prev1->next = last1;
    printLinkedList(reverseNode);

    return empty->next;
}

/**
 * 反转链表：
 * - 不断遍历链表中的结点
 * - 使用一个变量prev结点，表示翻转后的链表的头结点
 * - 遍历过程中，新遍历位置的链表插入到头结点的前面去，成为新的头结点，并且prev结点新赋值为新插入头结点
 * - 知道原始链表遍历完成
 * 复盘：
 * -  ListNode *prve; 创建局域变量时的指针指向了head
 * - 需要改为 ListNode *prve = nullptr; 才是一个空指针
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