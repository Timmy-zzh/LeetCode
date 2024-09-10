#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * 1、审题：
 * - 输入一个区间的集合，集合中的区间会存在重叠情况，要求将重叠的区间进行合并，并返回一个没有重叠的区间集合回去
 * 2、解题：
 * - 先将区间集合进行排序，按照的开始位置排序
 * - 遍历升序排序好了的集合，如果第二个区间开始位置在前一个区间范围内，则该区间需要扩展
 * - 如果不在，则将上一个区间范围添加到结果集中，
 */
vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    vector<vector<int>> res;

    if (intervals.size() == 1)
    {
        res.push_back(intervals[0]);
        return res;
    }

    // 1、先排序
    sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b)
         { return a[0] < b[0]; });

    // 2、遍历排序好了的区间集合
    int left = 0, right = 0;
    for (int i = 0; i < intervals.size(); i++)
    {
        if (i == 0)
        {
            left = intervals[i][0];
            right = intervals[i][1];
            continue;
        }

        vector<int> item = intervals[i];
        cout << "left:" << left << ",right:" << right << endl;
        cout << " item[0]:" << item[0] << ",item[1]:" << item[1] << endl;

        if (item[0] > right) // 出现中断了
        {
            vector<int> resItem;
            resItem.push_back(left);
            resItem.push_back(right);
            res.push_back(resItem);

            left = item[0];
            right = item[1];
            cout << "if---- item[0]:" << item[0] << ",item[1]:" << item[1] << endl;
        }
        else
        { // 合并，right数值扩展
            right = max(right, item[1]);
        }

        if (i == intervals.size() - 1) // 最后一个
        {
            vector<int> resItem;
            resItem.push_back(left);
            resItem.push_back(right);
            res.push_back(resItem);
        }
    }
    return res;
}

/**
 * 以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti, endi] 。
 * 请你合并所有重叠的区间，并返回 一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间 。

示例 1：
输入：intervals = [[1,3],[2,6],[8,10],[15,18]]
输出：[[1,6],[8,10],[15,18]]
解释：区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].

示例 2：
输入：intervals = [[1,4],[4,5]]
输出：[[1,5]]
解释：区间 [1,4] 和 [4,5] 可被视为重叠区间。

提示：
1 <= intervals.length <= 104
intervals[i].length == 2
0 <= starti <= endi <= 104
 */
int main(int argc, char const *argv[])
{
    vector<vector<int>> intervals;
    intervals.push_back({1, 3});
    intervals.push_back({2, 6});
    intervals.push_back({8, 10});
    intervals.push_back({15, 18});

    auto res = merge(intervals);
    return 0;
}
