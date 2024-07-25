#include <iostream>
#include <vector>

using namespace std;

/**
 * 1、审题：
 * - 输入一个数组，数组元素是每个柱子的高度，求這些柱子能存储多少水
 * 2、解题：
 * 双指针解法：
 * - 从左往右遍历，左边位置元素作为起始值，需要找到右边比当前值大于等于的元素，然后计算两个元素之间的差值的和
 * - 如果找不到比当前元素大的值，则左侧指针往右移动，继续寻找，双指针处理的区域不断往后移动，就是解题的关键
 * 3、问题：
 * - 当数据为单调递减的时候，就不行了，
 * - 先从左往右移动，遇到右边比左边大的值，计算范围，并整体往后移动
 * - 当右边一直比左指针小的情况时，那就反过来从右往左移动，一样的逻辑
 */
int trap1(vector<int> &height)
{
    int count = height.size();
    if (count < 3)
    {
        return 0;
    }

    // 过滤开头是0的情况
    int x = 0;
    while (height[x] == 0)
    {
        x++;
    }

    int left = x;
    int right = left + 2;
    int sum = 0;

    while (left < count)
    {
        cout << "while left:" << left << ",right:" << right << endl;
        // 不断往右查找，大于左指针的值
        if (right >= count)
        {
            // 右指针到尾部了，左指针移动
            left++;
            right = left + 2;
            continue;
        }

        if (height[left] <= height[right]) // 找到右指针比左指针大的值，计算这个区间范围的总和，左指针移动到右指针位置，右指针++
        {
            cout << "for left:" << left << ",right:" << right << endl;
            int min = std::min(height[left], height[right]);
            for (size_t i = left + 1; i < right; i++)
            {
                int diff = min - height[i];
                sum += diff;
            }
            left = right;
            right++;
            cout << "sum:" << sum << endl;
        }
        else
        { // 右指针没找到比左指针大的值，右指针后移++
            right++;
        }
    }
    return sum;
}

/**
 * 双指针解法：
 * - 从左往右遍历，遇到右边指针比左边大的值，计算区间范围的差值和，接着左右指针整体往右移动
 * - 当遇到右边指针都比左指针小的情况时，右指针已经到数组尾部了，就反过来从右往左遍历求区间返回的差值和
 */
int trap2(vector<int> &height)
{
    int count = height.size();
    if (count < 3)
    {
        return 0;
    }
    int left = 0;
    int right = 1;
    int sum = 0;

    while (left < count)
    {
        // 找到右边比左边大的值，小于的话，右指针后移，右指针后移到尾部了，反过来从右往左遍历
        if (right >= count)
        {
            cout << "end if left:" << left << ",right:" << right << endl;
            // 反过来遍历
            int tempI = right - 2;
            right = right - 1;
            while (tempI >= left)
            {
                if (height[tempI] >= height[right])
                {
                    cout << "end for left:" << left << ",tempI:" << tempI << ",right:" << right << endl;
                    int minNum = std::min(height[tempI], height[right]);
                    for (size_t i = tempI + 1; i < right; i++)
                    {
                        int diff = minNum - height[i];
                        sum += diff;
                    }
                    right = tempI;
                    tempI = right - 1;
                    cout << "end sum:" << sum << ",tempI:" << tempI << ",right:" << right << endl;
                }
                else
                {
                    tempI--;
                }
            }
            break;
        }

        if (height[left] <= height[right]) // 找到右指针比左指针大的值，计算这个区间范围的总和，左指针移动到右指针位置，右指针++
        {
            cout << "for left:" << left << ",right:" << right << endl;
            int min = std::min(height[left], height[right]);
            for (size_t i = left + 1; i < right; i++)
            {
                int diff = min - height[i];
                sum += diff;
            }
            left = right;
            right++;
            cout << "sum:" << sum << endl;
        }
        else
        { // 右指针没找到比左指针大的值，右指针后移++
            right++;
        }
    }
    return sum;
}

/**
 * 动态规划解法：
 * - 题目要求的是每个柱子能接到的雨水，而每个柱子能接到多少水，取决于左右两边最高的柱子中，较低的哪个柱子，再减去当前柱子的高度
 * - 问题拆分为两个子问题，分别是求当前柱子左右两边的最高柱子的高度，可以使用两个数组来保存，且数据之间存在关联
 * -- 动态规划的状态转移方程式： leftMax[i]表示柱子i左侧的最高柱子的高度 = max(leftMax[i-1],heiht[i])
 * - 右侧的最高柱子高度也是一样的
 * - 最后根据这两个数组，计算每个柱子能够接到的水量， = min(leftMax[i],rightMax[i]) - height[i]
 */
int trap(vector<int> &height)
{
    int count = height.size();
    vector<int> leftMax(count, 0);
    vector<int> rightMax(count, 0);

    leftMax[0] = height[0];
    rightMax[count - 1] = height[count - 1];

    for (int i = 1; i < count; i++)
    {
        leftMax[i] = std::max(leftMax[i - 1], height[i]);
    }

    for (int i = count - 2; i >= 0; i--)
    {
        rightMax[i] = std::max(rightMax[i + 1], height[i]);
    }

    int sum = 0;
    for (int i = 1; i < count - 1; i++)
    {
        sum += std::min(leftMax[i], rightMax[i]) - height[i];
    }
    return sum;
}

int main(int argc, char const *argv[])
{
    std::vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int res = trap(height);
    cout << "res:" << res << endl;

    return 0;
}
