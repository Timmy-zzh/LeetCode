#include <iostream>
#include <vector>
using namespace std;

// swap1(nums,left,right);
void swapArr(vector<int> &nums, int left, int right)
{
    int temp = nums[left];
    nums[left] = nums[right];
    nums[right] = temp;
}
