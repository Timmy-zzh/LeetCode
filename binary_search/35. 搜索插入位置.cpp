#include <iostream>
#include <vector>

/**
 * 1、审题：
 * - 输入一个有序数组和一个目标值target，求目标值在有序数组中的位置
 * - 有序数组中的元素不存在重复元素，如果数组有相同的元素，则返回该元素位置
 * - 如果数组中没有目标值的位置，则返回该目标值应该插入的位置
 * 2、解题：
 * - 有序数组的查找，二分查找法
 * - 创建左右指针和中间指针，判断目标值与中间值的大小
 * - 如果中间值和目标值相等，则直接返回
 * - 如果不相等，根据大小，判断目标值在中间值的左侧，还是右侧？进行左右指针的移动
 */
int searchInsert(vector<int> &nums, int target)
{
    int left = 0;
    int right = nums.size() - 1;
    int mid = 0;

    while (left <= right)
    {
        mid = left + (right - left) / 2;
        std::cout << left << " - " << right << "mid:" << mid << std::endl;
        if (target == nums[mid])
        {
            return mid;
        }
        else if (target < nums[mid])
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    return right + 1;
}

/**
 * 给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
请必须使用时间复杂度为 O(log n) 的算法。

示例 1:
输入: nums = [1,3,5,6], target = 5
输出: 2

示例 2:
输入: nums = [1,3,5,6], target = 2
输出: 1

示例 3:
输入: nums = [1,3,5,6], target = 7
输出: 4

提示:
1 <= nums.length <= 104
-104 <= nums[i] <= 104
nums 为 无重复元素 的 升序 排列数组
-104 <= target <= 104
 */
int main(int argc, char const *argv[])
{

    return 0;
}