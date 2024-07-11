#include <iostream>
#include <vector>
#include <map>
#include "../utils/Print.h"
#include <algorithm>

/**
 * 给你一个整数数组 citations ，其中 citations[i] 表示研究者的第 i 篇论文被引用的次数。计算并返回该研究者的 h 指数。
根据维基百科上 h 指数的定义：h 代表“高引用次数” ，一名科研人员的 h 指数 是指他（她）至少发表了 h 篇论文，
并且 至少 有 h 篇论文被引用次数大于等于 h 。如果 h 有多种可能的值，h 指数 是其中最大的那个。

示例 1：
输入：citations = [3,0,6,1,5]
输出：3
解释：给定数组表示研究者总共有 5 篇论文，每篇论文相应的被引用了 3, 0, 6, 1, 5 次。
     由于研究者有 3 篇论文每篇 至少 被引用了 3 次，其余两篇论文每篇被引用 不多于 3 次，所以她的 h 指数是 3。

示例 2：
输入：citations = [1,3,1]
输出：1
 */

/**
 * 1、审题：
 * - 输入一个数组，数组长度标识作者发表了多少篇论文，数组内的元素表示论文被引用次数，
 * - 求h引用书，规则定义如下：有h篇论文，被引用次数大于等于h，求h的最大值
 * 2、解题：
 * - h这个数字肯定是小于等于数组长度size的，动态规划，求出每篇论文被应用的次数，可以先升序排序，然后使用map保存
 * - map的key值为引用次数，value为该引用次数的计数（两个概念，不要被绕进去）
 * - 接着遍历数组，从后往前遍历，找到最大值h
 * - value为论文被应用次数，求论文被应用次数value的元素有多少个count， 要求count大于等于value，该值为所求的h值
 */
int hIndex(std::vector<int> &citations)
{
    int size = citations.size();
    if (size == 1)
    {
        if (citations[0] == 0)
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }

    std::map<int, int> countMap = std::map<int, int>();
    // 排序
    std::sort(citations.begin(), citations.end());

    int res = 0;
    int i = size - 1;
    for (; i >= 0; i--)
    {
        int count = citations[i];
        std::cout << std::endl;
        std::cout << count << " ,i:" << i << " ";
        if (count == 0)
        {
            std::cout << "continue" << std::endl;
            break;
        }

        auto it = countMap.find(count);
        if (it == countMap.end())
        {
            std::cout << " 不包含" << std::endl;
            if (i == size - 1)
            {
                countMap.insert(std::make_pair(count, 1));
            }
            else
            {
                int numValue = countMap[citations[i + 1]];
                countMap.insert(std::make_pair(count, numValue + 1));
            }
        }
        else
        {
            std::cout << " 包含" << std::endl;
            // 包含
            int numValue = countMap[count];
            countMap[count] = numValue + 1;
        }

        int numValue = countMap[count];
        res = std::max(res, std::min(count, numValue));
    }

    return res;
}

int main(int argc, char const *argv[])
{
    // std::vector<int> nums = {3, 0, 6, 1, 5};
    // std::vector<int> nums = {1, 3, 1};
    std::vector<int> nums = {1, 7, 9, 4};
    printArr(nums);
    auto res = hIndex(nums);
    std::cout << "res:" << res << std::endl;

    return 0;
}
