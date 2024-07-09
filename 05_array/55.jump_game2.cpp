#include <iostream>
#include <vector>
#include <map>
#include "../utils/Print.h"

using namespace std;

/**
 * 1、审题：跳跃游戏
 * - 输入一个数组，每个数组的元素值，表示当前元素可以跳跃的最大长度，判断跳跃到数组最后位置，需要的最小次数
 * - 提供的数据都可能达到最后位置
 * 2、解题：
 * - 回溯算法，从第一步开始，根据当前遍历到的元素往后继续遍历，并记录走过的步数
 * 3、超出时间限制： 裁剪，将到达该位置所需要的步数，使用map保存起来，后面遇到相同的，且更大的则直接中断了
 * - 使用map进行了裁剪，还是不行
 * - 需要使用动态规划才行了
 */
int res55 = INT_MAX;
map<int, int> myMap;

void canJumpBack(vector<int> &nums, int size, int index, int count)
{
    cout << "index:" << index << ",count:" << count << endl;
    if (index == size - 1)
    {
        if (count < res55)
        {
            res55 = count;
        }
        return;
    }
    if (index >= size)
    {
        return;
    }

    /**
     * 判断map中是否包含该位置下标的跳跃次数？
     * - count表示该key值的个数 int keyCount= myMap.count(index);
     * - 要使用find查找
     */
    auto it = myMap.find(index);
    if (it != myMap.end() && myMap[index] <= count)
    {
        return;
    }

    myMap[index] = count;

    int ele = nums[index];
    for (size_t i = 1; i <= ele; i++)
    {
        canJumpBack(nums, size, index + i, count + 1);
    }
}

int jump2(vector<int> &nums)
{
    int size = nums.size();
    if (size == 0)
    {
        return size;
    }

    canJumpBack(nums, size, 0, 0);

    return res55;
}

/**
 * 动态规划解法：
 * - dp[i] 标识到达位置i时，所需要走的步数，
 * - dp[0]=0
 * - 状态转移方程式： dp[i+1] = min(dp[i+1],dp[i]+1)
 * -- 要求 dp[i]的值要大于等于 i+value
 */
int jump(vector<int> &nums)
{
    printArr(nums);

    int size = nums.size();
    if (size == 0)
    {
        return size;
    }

    vector<int> dp = vector<int>(size);
    for (size_t i = 0; i < size; i++)
    {
        dp[i] = INT_MAX / 2;
    }
    printArr(dp);

    dp[0] = 0;
    for (size_t i = 0; i < size; i++)
    {
        // 判断 nums[i]是否大于0，大于0才表示可以继续走
        int value = nums[i];
        int x = 1;
        while (x + i < size && x <= value)
        {
            dp[x + i] = min(dp[x + i], dp[i] + 1);
            x++;
            if (x == size)
            {
                break;
            }
        }
        printArr(dp);
    }

    return dp[size - 1];
}

int main(int argc, char const *argv[])
{

    vector<int> nums = {2, 3, 1, 1, 4};
    // vector<int> nums = {0};
    auto res = jump(nums);
    cout << res << endl;
    return 0;
}
