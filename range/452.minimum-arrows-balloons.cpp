#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

/**
 * 1、审题： 使用最少的箭将区间范围的气球射穿
 * 2、解题：区间交集解法
 * - 先对区间集合进行排序，根据单个区间开始位置进行升序排序
 * - 使用一个新的区间集合res保存处理后的区间交集数据，默认保存原始区间的第一个区间范围
 * - 然后遍历区间集合，判断当前区间和res区间集合最后面一个区间是否存在交集，如果存在，则将res区间的最后一个数据出栈
 * - 并与当前区间取交集范围数据，插入到res集合中
 * - 如果没有交集，则直接插入到res集合中
 */
int findMinArrowShots(vector<vector<int>> &points)
{
    vector<vector<int>> res;
    int size = points.size();
    if (size == 0)
    {
        return res.size();
    }

    // 先排序
    sort(points.begin(), points.end(), [](vector<int> &arr1, vector<int> &arr2)
         { return arr1[0] < arr2[0]; });

    res.push_back(points[0]);
    for (int i = 1; i < size; i++)
    {
        vector<int> itemArr = points[i];
        if (res[res.size() - 1][1] >= itemArr[0])
        {
            vector<int> preArr = res[res.size() - 1];
            // 存在交集
            res.pop_back();
            res.push_back({max(preArr[0], itemArr[0]), min(preArr[1], itemArr[1])});
        }
        else
        {
            res.push_back(itemArr);
        }
    }
    return res.size();
}

/**
 * 1、审题：
 * - 输入一个区间集合，区间范围内表示的是一串气球，现在要射出一支箭只要区间范围内，就可以全部引爆，
 * - 两个区间可能存在重叠，存在重叠的部分使用一支箭就可以同时引爆两个区间，求要讲所有区间内的球引爆，最少需要几支箭？
 * 2、解题：
 * - 不是区间合并这么简单的，现在是要寻找存在重叠的区间，且存在相同的交集，重叠的两个区间肯定存在交集，
 * - 如果存在重叠的是三个区间，他们之间也必须存在共同的交集，才可以使用一支箭引爆。
 * -- 我们的问题变成寻找存在共同交集的区间集合，存在共同交集的两个集合，则都进行抵消并插入一个新的交集集合，
 * - 使用一个新集合保存，查找交集抵消的区间，每次处理一个，直到原先集合中的区间都处理过
 * 3、就感觉这样写不行，集合中的元素又是vector集合，先保存到新集合，再取出来遍历，删除同样区间元素的原始集合，感觉有问题呢
 */
int findMinArrowShots1(vector<vector<int>> &points)
{
    vector<vector<int>> res;
    while (!points.empty())
    {
        vector<int> baseRange = points[0]; // 基准区间
        // 保存存在交集的集合，需要从原始集合中减去的
        vector<vector<int>> removeArr;
        // 与集合中的其他区间进行比较，求出最后的交集部分
        for (int i = 1; i < points.size(); i++)
        {
            vector<int> compareRange = points[i]; // 比较区间

            // 判断是否有交集
            if (compareRange[1] < baseRange[0] || baseRange[1] < compareRange[0]) // 无交集
            {
                continue;
            }
            if (removeArr.empty())
            {
                removeArr.push_back(baseRange); // 是不要要保存基准区间的副本
            }

            baseRange = {max(baseRange[0], compareRange[0]), min(baseRange[1], compareRange[1])};
            removeArr.push_back(compareRange);
        }

        // 遍历removeArr，将其中的元素从points集合中删除
        for (vector<int> &item : removeArr)
        {
            // points.erase(item);
        }
    }
}

/**
 * 有一些球形气球贴在一堵用 XY 平面表示的墙面上。墙面上的气球记录在整数数组 points ，
 * 其中points[i] = [xstart, xend] 表示水平直径在 xstart 和 xend之间的气球。你不知道气球的确切 y 坐标。

一支弓箭可以沿着 x 轴从不同点 完全垂直 地射出。在坐标 x 处射出一支箭，若有一个气球的直径的开始和结束坐标为 xstart，xend，
且满足  xstart ≤ x ≤ xend，则该气球会被 引爆 。可以射出的弓箭的数量 没有限制 。 弓箭一旦被射出之后，可以无限地前进。

给你一个数组 points ，返回引爆所有气球所必须射出的 最小 弓箭数 。

示例 1：
输入：points = [[10,16],[2,8],[1,6],[7,12]]
输出：2
解释：气球可以用2支箭来爆破:
-在x = 6处射出箭，击破气球[2,8]和[1,6]。
-在x = 11处发射箭，击破气球[10,16]和[7,12]。

示例 2：
输入：points = [[1,2],[3,4],[5,6],[7,8]]
输出：4
解释：每个气球需要射出一支箭，总共需要4支箭。

示例 3：
输入：points = [[1,2],[2,3],[3,4],[4,5]]
输出：2
解释：气球可以用2支箭来爆破:
- 在x = 2处发射箭，击破气球[1,2]和[2,3]。
- 在x = 4处射出箭，击破气球[3,4]和[4,5]。
 */
int main(int argc, char const *argv[])
{
    vector<vector<int>> points;
    // points.push_back({10, 16});
    // points.push_back({2, 8});
    // points.push_back({1, 6});
    // points.push_back({7, 12});

    points.push_back({5, 6});
    points.push_back({3, 4});
    points.push_back({1, 2});
    points.push_back({7, 8});
    auto res = findMinArrowShots(points);
    cout << "res:" << res << endl;
    return 0;
}
