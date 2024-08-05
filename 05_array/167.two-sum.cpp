#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<int> twoSum(vector<int> &numbers, int target)
{
    int size = numbers.size();
    int left = 0;
    int right = size - 1;
    vector<int> res;
    while (left < right)
    {
        int sum = numbers[left] + numbers[right];
        if (sum == target)
        {
            return {left + 1, right + 1};
        }
        else if (sum < target)
        {
            left++;
        }
        else
        {
            right--;
        }
    }
    return res;
}

/**
 * 1、审题：
 * - 输入一个数组和一个目标值，数组中的元素是非递减的，其中有两个元素的和等于目标值，找出来并返回
 * - 注意：数组的下标从1开始到size
 * 2、解题：双指针解法
 * - 定义左右指针，左指针left从0开始，右指针从left+1开始，右指针元素值判断是否是目标值减去做指针的元素值
 * - 是的话返回结果，不是的话，分两种情况
 * - 元素值小于目标值减去的差值，则右指针右移动， 否则左指针右移一位，右指针从左指针的下一位开始
 * 3、时间复杂度分析： 需要遍历两层为O(n^2),不行
 * - 优化成遍历一次的算法，左右指针分别从头和未开始，不断往中间移动，直到找到目标值
 */
vector<int> twoSum1(vector<int> &numbers, int target)
{
    int left = 0;
    int right = 1;
    int size = numbers.size();
    vector<int> res;

    for (int i = 0; i < size; i++)
    {
        left = i;
        right = left + 1;
        cout << "i:" << i << ",left:" << left << ",right:" << right << endl;
        while (right < size)
        {
            int diff = target - numbers[left];
            cout << "diff:" << diff << ",numbers[right]:" << numbers[right] << endl;
            if (numbers[right] == diff)
            {
                res.push_back(left + 1);
                res.push_back(right + 1);
                cout << "left:" << left + 1 << endl;
                cout << "right:" << right + 1 << endl;
                return res;
            }
            else if (numbers[right] < diff)
            { // 小于
                right++;
                cout << "right++:" << right << endl;
            }
            else // 大于
            {
                break;
            }
        }
    }
    res.push_back(0);
    res.push_back(1);
    return res;
}

int main(int argc, char const *argv[])
{
    vector<int> nums = {-10, -8, -2, 1, 2, 5, 6};
    vector<int> res = twoSum(nums, 0);
    for (size_t i = 0; i < res.size(); i++)
    {
        cout << "res:" << res[i] << endl;
    }

    return 0;
}
