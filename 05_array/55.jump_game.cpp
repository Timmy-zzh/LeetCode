#include <iostream>
#include <vector>

using namespace std;

/**
 * 1、审题：跳跃游戏
 * - 输入一个数组，每个数组的元素值，表示当前元素可以跳跃的最大长度，判断是否可以跳跃到数组最后位置
 * 2、解题：
 * - 遍历数组，拿到当前遍历的元素值，当前下标加上元素值，就是他可以到达的最长位置
 * -- 可以新建一个bool数组，标记每个元素可以到达的最长位置，
 * -- 也可以使用一个标记位，动态改变，永远保存可以到达的最长位置
 */
bool canJump(vector<int> &nums)
{
    int size = nums.size();
    if (size == 0)
    {
        return true;
    }

    int right = nums[0];
    for (size_t i = 1; i < size - 1; i++)
    {
        cout << "for right:" << right << i << endl;
        if (right < i)
        {
            return false;
        }

        if (i + nums[i] > right)
        {
            right = i + nums[i];
        }
        if (right >= size - 1)
        {
            return true;
        }
    }
    cout << "right:" << right << endl;
    return right >= size - 1;
}

int main(int argc, char const *argv[])
{

    // vector<int> nums = {2, 3, 1, 1, 4};
    vector<int> nums = {3, 2, 1, 0, 4};
    auto res = canJump(nums);
    cout << res << endl;
    return 0;
}
