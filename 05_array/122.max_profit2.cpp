#include <iostream>
#include <vector>

using namespace std;

/**
 * 买卖股票的最大利润
 * 1、审题：输入一个数组标识某只股票的价格，现在修改规则为每天可以操作股票两次，
 * - 可以分别买入和卖出一次
 * 2、解题：
 * - 遍历数组，判断当前股票价格和前一天价格，如果升高了，则买入
 */
int maxProfit(vector<int> &prices)
{
    int res = 0;
    for (size_t i = 1; i < prices.size(); i++)
    {
        if (prices[i] > prices[i - 1])
        {
            res += prices[i] - prices[i - 1];
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
