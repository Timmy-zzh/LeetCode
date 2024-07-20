#include <iostream>
#include <vector>
#include "../utils/Print.h"

using namespace std;

/**
 * 1、审题：
 * - 输入一个数组，数组元素是每个孩子的评分，给孩子分糖果，要求每个孩子最少分到一个糖果，相邻两个孩子评分高的孩子要分到更多的糖果
 * - 求最少需要准备多少糖果
 * 2、解题：
 * - 使用一个数组表示每个孩子的糖果树，所有元素的初始值为1
 * - 不断从做到右遍历，每个孩子的分数和糖果数，如果当前孩子的分数比前一个孩子的分数高，当前孩子的糖果数需要增加，否则不变
 * - 再判断当前孩子的分数和后一个孩子的分数，如果也高的话，且糖果数也需要比后一个孩子的糖果数要多，否则增加谈过数，知道遍历结束
 * - 使用一个标记位，判断此次遍历过程中是否有有糖果数增加，如果有，则继续遍历，否则退出while循环
 * - 最后计算所有孩子的糖果数之和，并返回
 * 3、数据量多的时候，会超时
 */
int candy1(vector<int> &ratings)
{
    int count = ratings.size();
    vector<int> candy(count, 1);
    bool flag = false; // 表示是否需要继续分配糖果

    while (1)
    {
        flag = false;
        for (size_t i = 0; i < count; i++)
        {
            cout << "for i:" << i << endl;
            printArr(candy);

            // 当前孩子的分数与左边孩子的分数和糖果比较
            if (i > 0 && ratings[i] > ratings[i - 1] && candy[i] <= candy[i - 1])
            {
                candy[i] = candy[i - 1] + 1;
                flag = true;
            }
            // 与右边孩子的分数和糖果的比较
            if (i < count - 1 && ratings[i] > ratings[i + 1] && candy[i] <= candy[i + 1])
            {
                candy[i] = candy[i + 1] + 1;
                flag = true;
            }
        }
        if (!flag)
        {
            break;
        }
    }

    int sum = 0;
    for (size_t i = 0; i < count; i++)
    {
        sum += candy[i];
    }
    return sum;
}

/**
 * 优化：两次遍历，
 * - 从左到右遍历，如果当前孩子的分数比前一个高，则糖果数在他的基础上加1，否则为1
 * - 再从右到左遍历，一样的处理逻辑
 */
int candy(vector<int> &ratings)
{
    int count = ratings.size();
    vector<int> candy(count, 0);
    bool flag = false; // 表示是否需要继续分配糖果

    for (size_t i = 0; i < count; i++)
    {
        if (i > 0 && ratings[i] > ratings[i - 1])
        {
            candy[i] = candy[i - 1] + 1;
        }
        else
        {
            candy[i] = 1;
        }
    }
    printArr(candy);

    for (int i = count - 1; i >= 0; i--)
    {
        if (i < count - 1 && ratings[i] > ratings[i + 1])
        {
            candy[i] = max(candy[i], candy[i + 1] + 1);
        }
    }
    printArr(candy);

    int sum = 0;
    for (size_t i = 0; i < count; i++)
    {
        sum += candy[i];
    }
    return sum;
}

/**
 * n 个孩子站成一排。给你一个整数数组 ratings 表示每个孩子的评分。
你需要按照以下要求，给这些孩子分发糖果：
每个孩子至少分配到 1 个糖果。
相邻两个孩子评分更高的孩子会获得更多的糖果。
请你给每个孩子分发糖果，计算并返回需要准备的 最少糖果数目 。

示例 1：
输入：ratings = [1,0,2]
输出：5
解释：你可以分别给第一个、第二个、第三个孩子分发 2、1、2 颗糖果。

示例 2：
输入：ratings = [1,2,2]
输出：4
解释：你可以分别给第一个、第二个、第三个孩子分发 1、2、1 颗糖果。
     第三个孩子只得到 1 颗糖果，这满足题面中的两个条件。
 */
int main(int argc, char const *argv[])
{
    vector<int> ratings = {1, 0, 2};
    int res = candy(ratings);
    cout << res << endl;
    return 0;
}