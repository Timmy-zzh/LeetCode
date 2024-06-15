#include <iostream>
#include "ListNode.h"

// namespace std

void printLinkedList(ListNode *head)
{
    std::cout << "linked list:";
    while (head != nullptr)
    {
        std::cout << head->val << ",";
        head = head->next;
    }
    std::cout << std::endl;
}