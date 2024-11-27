#pragma once

#include <iostream>
#include "ListNode.h"
#include <vector>
#include <map>

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

void printMap(std::map<int, int> &map)
{
    std::cout << "print map: " << std::endl;
    // 使用迭代器遍历
    for (std::map<int, int>::iterator it = map.begin(); it != map.end(); it++)
    {
        std::cout << it->first << "-" << it->second << std::endl;
    }

    // int size = map.size();
    // for (const auto &pair : map)
    // {
    //     std::cout << pair.first << "-" << pair.second << std::endl;
    // }
    // std::cout << std::endl;
}