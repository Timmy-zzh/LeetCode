#include <iostream>
#include <vector>
#include <algorithm>
#include "../utils/Print.h"

using namespace std;

/**
 * 1、审题：输入一个数组，数组中存在三个元素的和等于0，找出所有的组合返回
 * 2、解题：双指针解法
 * - 因为输入的数组是无序的，而使用双指针解法，需要先排序
 * - 先进行排序，然后遍历数组，以遍历元素作为锚点，后面的区间使用双指针遍历，找到三个元素和为0的元素
 * - 如果后面区间的元素和小于0，做指针右移，如果大于0，则右指针左移
 * - 注意：需要去重，命中到目标值后，需要继续遍历当前区间的其他元素和
 * 3、总结：
 * - 先排序
 * - 接着遍历数组，以遍历元素作为锚点，后面的区间使用双指针解法，从前后两端往中间移动
 * - 注意移动的时候去重，去重需要注意边界条件
 * - 遍历的时候，如果遇到元素值大于0的，直接返回结果，因为是排序后的数组，后面的元素肯定都大于0
 * - 
 */
vector<vector<int>> threeSum(vector<int> &nums)
{
    vector<vector<int>> res;
    // 小于三个元素的输入数组，直接返回空结果
    if (nums.size() < 3)
    {
        return res;
    }

    // 先排序，sort方法是algorithm库中的方法
    sort(nums.begin(), nums.end());
    printArr(nums);

    /**
     * 遍历数组，以遍历到的元素作为锚点，后面的区间使用双指针解法，去查找剩下的两个元素，使得三个元素和为0
     * - 那什么时候两个元素移动呢？ 从结果入手，如果sun和大于0，则右指针左移，反之结果小于0，则左指针右移
     * - 如果遇到相等的元素值，需要跳过，避免重复
     */
    int size = nums.size();
    int i = 0;
    while (i < size)
    {
        // 如果锚点已经大于0了，那么后面元素肯定都大于0，直接返回res
        if (nums[i] > 0)
        {
            return res;
        }
        while (i > 0 && i < size &&  nums[i] == nums[i - 1])
        {
            i++;
        }

        int left = i + 1;
        int right = size - 1;
        if (left >= right)
        {
            break;
        }
        while (left < right)
        {
            int sum = nums[i] + nums[left] + nums[right];
            if (sum == 0)
            {
                res.push_back({nums[i], nums[left], nums[right]});
                left++;
                while (left < size && nums[left] == nums[left - 1])
                {
                    left++;
                }
                right--;
                while (right >= 0 && nums[right] == nums[right + 1])
                {
                    right--;
                }
            }
            else if (sum > 0)
            {
                right--;
                while (right >= 0 && nums[right] == nums[right + 1])
                {
                    right--;
                }
            }
            else
            {
                left++;
                while (left < size && nums[left] == nums[left - 1])
                {
                    left++;
                }
            }
        }
        i++;
    }
    return res;
}

int main(int argc, char const *argv[])
{
    // vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<int> nums = {0, 0, 0};
    vector<vector<int>> res = threeSum(nums);
    cout << "res size: " << res.size() << endl;
    for (auto &vec : res)
    {
        for (auto &num : vec)
        {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
