#include "../utils/ArrUtils.h"
#include "../utils/Print.h"

using namespace std;

int removeDuplicates(vector<int> &nums);

int main(int argc, char const *argv[])
{

    // vector<int> vector = {1, 1, 2};
    vector<int> vector = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    printArr(vector);

    auto res = removeDuplicates(vector);
    cout << "removeDuplicates res:" << res << endl;
    printArr(vector);

    return 0;
}

/**
 * 删除有序数组中的重复元素
 * 1、审题： 输入一个升序数组，需要将重复的元素处理成只保留一个，并返回新处理后想保留的元素长度
 * 2、解题：双指针解法
 * - 左指针，右指针不断往右边while遍历，找到与左指针元素值不同的元素，继续遍历，直到右指针遍历到数组尾部
 * 3、删除前后位置值相等的元素，使每个元素值值保留一个
 */
int removeDuplicates(vector<int> &nums)
{
    int left = 0;
    int right = 0;
    int size = nums.size();

    while (right < size)
    {
        while (right < size && nums[left] == nums[right])
        {
            right++;
        }
        if (right == size)
        {
            break;
        }
        printArr(nums);
        cout << "while left:" << left
             << ", right:" << right
             << endl;

        if (nums[left] != nums[right])
        {
            left++;
            swapArr(nums, left, right);
            right++;
        }
    }
    cout << "left:" << left << endl;
    return left + 1;
}