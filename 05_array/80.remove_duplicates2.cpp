#include "../utils/ArrUtils.h"
#include "../utils/Print.h"

int removeDuplicates(vector<int> &nums);

int main(int argc, char const *argv[])
{
    vector<int> nums = {0, 1, 2, 2, 2, 2, 2, 3, 4, 4, 4};
    // vector<int> nums = {1, 1, 1, 2, 2, 3};
    // vector<int> nums = {0, 0, 1, 1, 1, 1, 2, 3, 3};
    printArr(nums);
    auto res = removeDuplicates(nums);
    cout << "res:" << res << endl;
    printArr(nums);

    return 0;
}

int removeDuplicates(vector<int> &nums)
{
    int size = nums.size();
    if (size < 2)
    {
        return size;
    }

    int left = 2;
    int right = 2;
    while (right < size)
    {
        cout << "left:" << left << ",right:" << right << endl;
        if (nums[left - 2] != nums[right])
        {
            nums[left] = nums[right];
            left++;
        }
        right++;
    }

    return left;
}

/**
 * 1、审题：
 * - 输入一个升序数组，存在重复元素，要求删除元素重复超过两个的数据，使得每个元素值的个数不超过2个
 * 2、解题：双指针解法
 * - 定义三个标记，左右指针和每个元素当前的个数，右指针不断遍历，并与左指针判断是否相同
 * - 如果相同，判断元素个数
 * -- 个数小于2，左指针右移，
 * -- 个数大于2了，左指针不动了
 * - 如果不相等，左指针先右移，再交换，
 * - 右指针不断移动，直到数组末尾
 * 3、不相等的时候，也需要记录当前左指针前一个位置的元素与右指针是否相等，相等的话，count需要增加，
 * 4、优化解法： 也是快慢指针，通过慢指针减去前面2个位置的元素，与当前慢指针元素是否相等，决定慢指针是否需要重新赋值
 */
int removeDuplicates2(vector<int> &nums)
{
    int left = 0;
    int right = 0;
    int count = 0;
    int size = nums.size();

    while (right < size)
    {
        if (nums[left] == nums[right])
        {
            cout << "left:" << left << ",right:" << right << ",count:" << count << endl;
            if (left > 0 && nums[left] != nums[left - 1]) // 是否是一个新的元素开始项
            {
                left++;
                count = 1;
            }
            else if (count < 2)
            {
                left++;
                count++;
            }
        }
        else
        {
            cout << "swapArr left:" << left << ",right:" << right << endl;
            // swapArr(nums, left, right); // 交换
            // 不交换，直接将right的值赋值给left元素
            if (left > 0 && nums[left - 1] == nums[right]) // 注意左侧的相同元素的数量
            {
                if (count < 2)
                {
                    nums[left] = nums[right];
                    left++;
                }
                count++;
            }
            else
            {
                nums[left] = nums[right];
                left++;
                count = 1;
            }
        }
        right++;
    }
    cout << "res left:" << left << endl;

    return left;
}