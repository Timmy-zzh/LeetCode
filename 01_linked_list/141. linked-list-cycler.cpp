#include <iostream>
#include "../bean/ListNode.h"
#include <set>

// namespace std;

/**
 * 总结：
 * 1、第一个C++程序
 * 2、创建cpp类，ListNode类型
 * 3、set集合使用，导入包<set>,添加的是指针类型，要放弃之前的java思想，C++中大部分用的是指针
 * 4、快慢指针解法，快指针在第二个元素位置
 * -- 可以优化，快指针在第一个元素位置，while循环判断快指针是否到链表尾部了
 */
int main(){

    printf("LeetCode");
    
    return 0;
}


/**
 * 解法1：哈希表解法
 * - 遍历链表，将遍历过的结点保存到set集合中
 * - 在后面的遍历中，如果该界面已经在集合中存在，则说明存在环，否则没有
 */
bool hasCycle1(ListNode *head) {
    std::set<ListNode*> setVal;
    while (head!=nullptr)
    {
        if (setVal.find(head) != setVal.end())
        {
            return true;
        }
        setVal.insert(head);
        head = head->next;
        
    }
    return false;
}

/**
 * 1、审题:输入一个链表，判断该链表是否存在环
 * 2、解题：快慢双指针，
 * - 如果不存在环，则两个指针都会运行到链表尾部，最后的结果都是null
 * - 如果存在环，则两个指针一定会相遇，
 * -- 如何证明会相遇呢？
 * - 定义两个指针，slow，fast，快指针从链表第二个位置开始
 * -- 存在环的情况：两个指针相等
 * -- 不存在环的情况：快指针遍历到尾部
 */
bool hasCycle2(ListNode *head) {
    if (head==nullptr || head->next == nullptr)
    {
        return false;
    }
    ListNode* slow = head;
    ListNode* fast = head->next;
    while (slow != fast)
    {
        if (fast==nullptr || fast->next == nullptr)
        {
            return false;
        }
        slow = slow->next;
        fast = fast->next->next;
    }
    return true;
}

bool hasCycle(ListNode *head) {

    ListNode* slow = head;
    ListNode* fast = head;

    while(fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (fast==slow)
        {
            return true;
        }
    }
    return false;
}