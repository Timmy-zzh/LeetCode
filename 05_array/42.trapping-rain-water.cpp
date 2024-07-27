#include <iostream>
#include <vector>
#include <stack>

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
 *
 * 3、其他解法
 * - 单调栈解法
 * - 双指针解法
 */
int trap3(vector<int> &height)
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

/**
 * 单调栈解法：
 * - 使用一个栈来保存柱子的索引，栈中保存的柱子高度需要是递减的，
 * - 不断遍历数组，遇到比栈顶元素小的值，索引入栈
 * - 当遇到比栈顶元素大于等于的值，则需要计算能接到雨水的数量，出现这种情况说明栈中元素一定存在至少两个元素，
 * -- 要形成单调栈，则栈中一定要至少两个元素，如果只有一个元素，当遇到比栈顶元素大的值，说明是连续上升的情况，直接全部出栈，将最新的最大的值入栈
 * -- 如果栈中有两个元素，且出现的值比栈顶元素大，则计算能接到的雨水量
 */

/**
// 1、取出栈顶元素进行比较，
// - 比栈顶元素小的，入栈
// - 比栈顶元素大的，继续判断元素个数
// 2、判断元素个数
// - 栈中只有一个元素，来了一个比栈顶元素大的值，要保持单调递减栈，需要出栈后，将新值入栈
// - 如果栈中元素大于等于两个，计算能接到的雨水量，雨水量等于： 宽度*落差值
--  落差值为： min（栈中top-1，新的值i）-栈顶元素值top ， --》最后栈顶元素出栈
*  - 继续与栈顶元素比较，让这新值不断与新出现的栈顶元素比较最后的结果，要么入栈维持单调递减，要么全部出栈，新值入栈作为栈顶元素
*/
int trap(vector<int> &height)
{
    int count = height.size();
    stack<int> stack;
    stack.push(0);
    int sum = 0;

    for (int i = 1; i < count; i++)
    {
        int topI = stack.top();
        // 如果比栈顶元素小，直接入栈
        if (height[i] < height[stack.top()])
        {
            stack.push(i);
            continue;
        }

        // 比栈顶元素大，不断出栈了，知道栈顶元素比当前值大，然后入栈
        while (height[stack.top()] < height[i])
        {
            // 如果只有一个的话，直接出栈，新值入栈
            if (stack.size() == 1)
            {
                stack.pop();
                stack.push(i);
                break;
            }

            // 2个及以上，计算雨水量
            // 出栈
            int popI = stack.top();
            stack.pop();

            // 前一个更大高度的柱子下标
            int leftI = stack.top();

            // 计算雨水量
            int rains = (i - leftI - 1) * (min(height[i], height[leftI]) - height[popI]);
            sum += rains;

            cout << "while i:" << i << ",popI:" << popI << ",leftI:" << leftI << ",rains:" << rains << endl;
        }
        stack.push(i);
    }
    return sum;
}

int main(int argc, char const *argv[])
{
    std::vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    // std::vector<int> height = {4, 2, 0, 3, 2, 5};
    int res = trap(height);
    cout << "res:" << res << endl;

    return 0;
}
