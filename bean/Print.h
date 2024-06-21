#include <iostream>
#include "ListNode.h"

using namespace  std;

void printLinkedList(ListNode *head)
{
    cout << "linked list:";
    while (head != nullptr)
    {
        std::cout << head->val << ",";
        head = head->next;
    }
    std::cout << std::endl;
}