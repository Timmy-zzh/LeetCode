#include <iostream>
#include <vector>

using namespace std;

/**
 * 1、审题：
 * - 输入两个集合，一个是区间集合，并且是升序无重叠的区间集合，在这个区间集合基础上要新插入一个区间，
 * - 插入的区间可以和原有区间集合合并，如果没有可合并的区间，则加入一个区间。
 * 2、解题：
 * - 插入区间，一共分几种情况：
 * -- 插入区间与原有区间没有重叠部分，则新插入
 * -- 插入区间在单个区间范围内，则被合并
 * -- 插入区间与原有区间存在重叠情况（包括部分重叠），则合并重叠的部分
 */
vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
{
    vector<vector<int>> res;
    int size = intervals.size();
    if (size == 0)
    {
        res.push_back(newInterval);
        return res;
    }

    // 去除头尾的情况
    if (newInterval[1] < intervals[0][0])
    {
        res.push_back(newInterval);
        res.insert(res.end(), intervals.begin(), intervals.end());
        return res;
    }

    if (intervals[size - 1][1] < newInterval[0])
    {
        res.insert(res.end(), intervals.begin(), intervals.end());
        res.push_back(newInterval);
        return res;
    }

    // 在区间内，先判断插入区间的开始元素大小
    int start = newInterval[0];
    int end = newInterval[1];
    for (int i = 0; i < size; i++)
    {
        vector<int> itemArr = intervals[i];
        cout << "for-- " << itemArr[0] << "-" << itemArr[1] << endl;

        // 插入区间的开始位置，在当前区间内
        if (itemArr[1] < start) // 开始位置都大于区间，将当前区间添加
        {
            cout << "333 push_back start:" << itemArr[0] << " ,end:" << itemArr[1] << endl;
            res.push_back(itemArr);
        }
        if (itemArr[0] <= start && start <= itemArr[1])
        {
            start = min(itemArr[0], start);
        }
        else // 开始位置小于当前区间，过滤
        {
        }

        /**
         * 插入区间的结束位置，与当前区间比较，存在三种情况：
         * - 结束位置，在当前区间的前面，插入
         * - 在区间中间，合并
         * - 在区间后面，继续遍历
         */
        if (end < itemArr[0])
        {
            cout << "111 push_back start:" << start << " ,end:" << end << endl;
            if (end > intervals[i - 1][1])
            {
                res.push_back({start, end});
            }
            res.push_back(itemArr);
        }
        else if (itemArr[0] <= end && end <= itemArr[1])
        {
            end = max(itemArr[1], end);
            cout << "222 push_back start:" << start << " ,end:" << end << endl;
            res.push_back({start, end});
        }
        else
        {
            // 这个区间被覆盖了
            if (i == size - 1)
            {
                res.push_back({start, end});
            }
        }
    }

    return res;
}

/**
 * 给你一个 无重叠的 ，按照区间起始端点排序的区间列表 intervals，其中 intervals[i] = [starti, endi] 表示第 i 个区间的开始和结束，
 * 并且 intervals 按照 starti 升序排列。同样给定一个区间 newInterval = [start, end] 表示另一个区间的开始和结束。
在 intervals 中插入区间 newInterval，使得 intervals 依然按照 starti 升序排列，且区间之间不重叠（如果有必要的话，可以合并区间）。
返回插入之后的 intervals。

注意 你不需要原地修改 intervals。你可以创建一个新数组然后返回它。

示例 1：
输入：intervals = [[1,3],[6,9]], newInterval = [2,5]
输出：[[1,5],[6,9]]

示例 2：
输入：intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
输出：[[1,2],[3,10],[12,16]]
解释：这是因为新的区间 [4,8] 与 [3,5],[6,7],[8,10] 重叠。
 */
int main(int argc, char const *argv[])
{
    vector<vector<int>> intervals;
    // intervals.push_back({1, 3});
    // intervals.push_back({6, 9});
    // vector<int> newInterval = {2, 5};

    // intervals.push_back({1, 2});
    // intervals.push_back({3, 5});
    // intervals.push_back({6, 7});
    // intervals.push_back({8, 10});
    // intervals.push_back({12, 16});
    // vector<int> newInterval = {4, 8};

    intervals.push_back({1, 5});
    vector<int> newInterval = {2, 7};

    vector<vector<int>> res = insert(intervals, newInterval);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i][0] << "-" << res[i][1] << ",";
    }
    cout << endl;

    return 0;
}
