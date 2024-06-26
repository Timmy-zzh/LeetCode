#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{

    return 0;
}

/**
 * 删除数组中的元素
 * 1、审题：
 * - 输入一个数组，要求原地移除数值等于val的元素，数组的前k个元素需要为不等于val的数据
 * 2、解题：
 * - 双指针解法，从数组的前后两端开始遍历，左边left的指针寻找为val的元素，右边right的指针寻找不为val的元素，进行交换
 * 3、总结：
 * - 双指针解法，左边指针查找相等的val元素，右边指针查找不相等的元素，进行交换
 * - 边界问题处理，left指针大于right指针，说明left指针登录val元素，直接返回left下标，[0,left-1]一共left个数元素是有效的
 * -- 都是在while里面解决的，不会跳出while循环外返回的
 */
int removeElement(vector<int> &nums, int val)
{
    if (nums.size() == 0)
    {
        return 0;
    }

    int left = 0;
    int right = nums.size() - 1;
    while (left <= right)
    {
        while (left < nums.size() && nums[left] != val)
        {
            left++;
        }
        while (right >= 0 && nums[right] == val)
        {
            right--;
        }
        if (left >= right)
        {
            return left;
        }

        // 交换
        // swap1(nums,left,right);
        int temp = nums[left];
        nums[left] = nums[right];
        nums[right] = temp;

        left++;
        right--;
    }
    return left ;
}