#include <vector>
#include <iostream>

using namespace std;

/**
 * 1、审题： 输入一个数组和一个目标值，找到数组中一个子数组，要求子数组的和大于等于目标值，返回子数组的最小长度
 * 2、解题：
 * - 区间解法，其实也就是双指针解法，不过左右指针是动态变化的
 * - 定义两个指针，确定区间范围，求这个区间的和，如果和大于等于目标值，记录区间长度，存储起来，左指针右移动，不断缩小区间范围
 * - 如果打小于目标值，则右指针右移动，扩大区间范围，
 * - 使用for循环，确定区间的右指针，左指针根据和的大小来移动
 */
int minSubArrayLen(int target, vector<int> &nums)
{
    int count = nums.size();
    int left = 0;
    int sum = 0;
    int res = INT_MAX;
    for (int right = 0; right < count; right++)
    {
        sum += nums[right];
        while (sum >= target && left <= right) // 大于目标值，才需要移动左指针，如果小于的话，右指针继续移动
        {
            if (left == right)
            {
                return 1;
            }
            int len = right - left + 1;
            res = res > len ? len : res;
            cout << "left:" << left << ",right:" << right << ",len:" << len << ",sum:" << sum << endl;
            sum -= nums[left];
            left++;
        }
    }
    return res == INT_MAX ? 0 : res;
}

int main(int argc, char const *argv[])
{
    // vector<int> nums = {7, 3, 1, 2, 4, 3};
    // auto res = minSubArrayLen(7, nums);
    vector<int> nums = {2, 3, 1, 2, 4, 3};
    auto res = minSubArrayLen(7, nums);
    // vector<int> nums = {1, 2, 3, 4, 5};
    // auto res = minSubArrayLen(15, nums);
    cout << "res:" << res << endl;
    return 0;
}
