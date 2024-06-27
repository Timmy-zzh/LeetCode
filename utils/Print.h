#include <iostream>
#include "..\bean\ListNode.h"
#include <vector>

using namespace std;

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

void printArr(vector<int> vector)
{
    cout << "print vector: ";
    int size = vector.size();
    for (size_t i = 0; i < size; i++)
    {
        cout << vector[i] << ",";
    }
    cout << endl;
}