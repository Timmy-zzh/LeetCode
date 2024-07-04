#include "../utils/ArrUtils.h"
#include "../utils/Print.h"

void rotate(vector<int> &nums, int k);
void rotateRange(vector<int> &nums, int start, int end);

int main(int argc, char const *argv[])
{
    {
        // vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
        // rotate(nums, 3);
        vector<int> nums = {-1, -100, 3, 99};
        printArr(nums);
        rotate(nums, 2);
        printArr(nums);
        return 0;
    }
}

/**
 * 1、审题： 轮转数组，输入数组nums，和需要翻转的数组元素个数k
 * - 将数组中的元素翻转k个
 * 2、解题：
 * - 遍历k次，每次数组轮转一次（可以使用while循环，也可以使用递归函数）
 * - 方式二： 先全部翻转，再局部翻转
 * - [0,n]所有元素进行翻转
 * - [0,k-1]元素翻转
 * - [k,n-1] 元素翻转
 */
void rotate(vector<int> &nums, int k)
{
    k = k%nums.size();
    rotateRange(nums, 0, nums.size() - 1);
    printArr(nums);
    rotateRange(nums, 0, k - 1);
    printArr(nums);
    rotateRange(nums, k, nums.size() - 1);
    printArr(nums);
}

void rotateRange(vector<int> &nums, int start, int end)
{
    cout << "start:" << start << " ,end:" << end << endl;
    while (start < end)
    {
        int temp = nums[end];
        nums[end] = nums[start];
        nums[start] = temp;
        start++;
        end--;
    }
}
