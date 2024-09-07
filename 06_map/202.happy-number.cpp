#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * 1、审题：输入一个整数，判断这个数字，是否是快乐数
 * - 快乐数的定义是，这个数中的所有位置的数字进行求平方的和，如果最后结果是1，就是快乐数，如果不是那就判断不是快乐数
 * 2、解题：
 * - 求某个数字中，所有数字的平方和，这个好算，使用迭代就可以
 * - 问题是如何判断这个数不是快乐数，只有一种情况，那就是出现了循环，使用vector保存已经计算好了的快乐数结果，然后进行判断
 */

vector<int> arr;
bool isHappy(int n)
{
    cout << "isHappy n:" << n << endl;
    if (find(arr.begin(), arr.end(), n) != arr.end()) // 找到了，说明快乐数存在循环情况
    {
        return false;
    }
    arr.push_back(n);

    // 计算数字中所有数字的平方和
    int sum = 0;
    while (n != 0)
    {
        // 不断取最地位
        int num = n % 10;
        sum += num * num;
        n = n / 10; // 高位继续循环
    }
    cout << "sum:" << sum << endl;

    if (sum == 1)
    {
        return true;
    }

    return isHappy(sum);
}

/**
 * 编写一个算法来判断一个数 n 是不是快乐数。

「快乐数」 定义为：
对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和。
然后重复这个过程直到这个数变为 1，也可能是 无限循环 但始终变不到 1。
如果这个过程 结果为 1，那么这个数就是快乐数。
如果 n 是 快乐数 就返回 true ；不是，则返回 false 。

示例 1：
输入：n = 19
输出：true
解释：
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1

示例 2：
输入：n = 2
输出：false
 */
int main(int argc, char const *argv[])
{
    auto res = isHappy(2);
    cout << "res:" << res << endl;
    return 0;
}
