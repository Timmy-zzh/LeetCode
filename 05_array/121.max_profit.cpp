#include <iostream>
#include <vector>

using namespace std;

/**
 * 买卖股票的最佳时机
 * 1、审题：输入一个数组，数组中的元素表示这只股票的价格，求最大利润
 * - 题目要求只能在某天买入，在随后的某天卖出，所以买入卖出的动作分别最多最优一次，也可能没有
 * 2、解题：
 * - 遍历数组，找到这只股票的最低价格，
 * - 然后在随后的某天，找到一个价格最高的点，存在的话则卖出即可
 * 3、问题： 如果最小值在后面，但是前面存在购买赚钱的情况，这个算法就不适用了，
 * -
 */
int maxProfit(vector<int> &prices)
{
    int minPos = 0;
    cout << "minPos:" << minPos << endl;
    int res = 0;
    for (size_t i = minPos + 1; i < prices.size(); i++)
    {
        if (prices[i] > prices[minPos])
        {
            res = max(res, prices[i] - prices[minPos]);
        }
        else if (prices[i] < prices[minPos])
        {
            minPos = i;
        }
    }
    return res;
}

int main(int argc, char const *argv[])
{
    vector<int> nums = {7, 1, 5, 3, 6, 4};
    auto res = maxProfit(nums);
    cout << "res:" << res << endl;
    return 0;
}
