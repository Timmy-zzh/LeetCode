#include <iostream>
#include <vector>
#include <string>

using namespace std;

/**
 * 1、审题：
 * - 输入一个无重复的升序数组，将该数组元素按照区分分割的反思返回对应的字符串数组
 * 2、解题
 * - 遍历该数字数组，既然是求一个区间，那就有区间范围的判断[left,right],
 * - 在遍历数组的过程中，判断后继元素与当前元素之差是否等于1，是的话则他们在一个连续区间内，如果中断则当前区间范围为一个结果值
 * 3、总结
 * - C++中字符串与int类型的数值相加，需要先将数字转换成字符串才行，使用to_string方法转换
 * - int类型数值范围越界问题，如果数字类型的值为-int_min，则--会出现越界情况，换一种方式相加可以解决
 * -- 例如： [-2147483648,-2147483647,2147483647]
 */
vector<string> summaryRanges(vector<int> &nums)
{
    vector<string> res;
    if (nums.size() == 0)
    {
        return res;
    }

    int left = nums[0];
    for (int i = 0; i < nums.size(); i++)
    {
        if (i == nums.size() - 1)
        {
            if (left == nums[i])
            {
                res.push_back(to_string(nums[i]));
            }
            else
            {
                string str = to_string(left) + "->" + to_string(nums[i]);
                res.push_back(str);
            }
            break;
        }

        if (nums[i] + 1 == nums[i + 1]) // 相差1，继续遍历
        {
            continue;
        }

        // 中断
        if (left == nums[i])
        {
            res.push_back(to_string(nums[i]));
        }
        else
        {
            // res.push_back(left + "->" + to_string(nums[i]));
            string str = to_string(left) + "->" + to_string(nums[i]);
            res.push_back(str);
        }
        left = nums[i + 1];
    }

    return res;
}

/**
 * 给定一个  无重复元素 的 有序 整数数组 nums 。
返回 恰好覆盖数组中所有数字 的 最小有序 区间范围列表 。也就是说，nums 的每个元素都恰好被某个区间范围所覆盖，并且不存在属于某个范围但不属于 nums 的数字 x 。
列表中的每个区间范围 [a,b] 应该按如下格式输出：

"a->b" ，如果 a != b
"a" ，如果 a == b

示例 1：
输入：nums = [0,1,2,4,5,7]
输出：["0->2","4->5","7"]
解释：区间范围是：
[0,2] --> "0->2"
[4,5] --> "4->5"
[7,7] --> "7"

示例 2：
输入：nums = [0,2,3,4,6,8,9]
输出：["0","2->4","6","8->9"]
解释：区间范围是：
[0,0] --> "0"
[2,4] --> "2->4"
[6,6] --> "6"
[8,9] --> "8->9"
 */
int main(int argc, char const *argv[])
{
    vector<int> nums = {0, 1, 2, 4, 5, 7};
    vector<string> res = summaryRanges(nums);
    for (string &num : res)
    {
        cout << num << " ,";
    }

    return 0;
}
