#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

/**
 * 1、审题：输入一个二维m*n矩阵，以螺旋路线查询所有元素，并返回一个数组
 * 2、解题：
 * - 螺旋式遍历矩阵元素，从外层到内层，遍历的时候如何转角呢？
 * - 模拟，按照螺旋遍历的方式，从四个方向：右，下，左，上，遍历，并且在遍历的过程中，不断更新边界
 * -- 例如从左往右遍历，遍历完一行后，上边界++，并且判断上边界和下边界是否相交，如果相交则退出
 * - 其他方向的遍历也是同样的操作逻辑
 * 3、总结： 边界问题判断， if(left++ >right)  执行逻辑是先判断，再++，需要注意
 * - 基本知识点要牢固
 */
vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    vector<int> res;
    if (matrix.empty())
    {
        return res;
    }

    // 定义边界
    int up = 0;
    int down = matrix.size() - 1;
    int left = 0;
    int right = matrix[0].size() - 1;

    // while循环遍历，直到上下，有做边界相交
    while (true)
    {
        // 向右遍历
        for (int i = left; i <= right; i++)
        {
            res.push_back(matrix[up][i]);
        }
        // 上边界更新
        up++;
        // 判断上下边界是否相交
        if (up > down)
        {
            break;
        }

        // 向下遍历
        for (int i = up; i <= down; i++)
            res.push_back(matrix[i][right]);
        if (--right < left) // 先--，再判断
            break;

        // 向左遍历
        for (int i = right; i >= left; i--)
            res.push_back(matrix[down][i]);
        if (--down < up)
            break;

        // 向上遍历
        for (int i = down; i >= up; i--)
            res.push_back(matrix[i][left]);
        if (++left > right)
            break;
    }

    return res;
}

/**
 * 给你一个 m 行 n 列的矩阵 matrix ，请按照 顺时针螺旋顺序 ，返回矩阵中的所有元素。

示例 1：
输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
输出：[1,2,3,6,9,8,7,4,5]

示例 2：
输入：matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
输出：[1,2,3,4,8,12,11,10,9,5,6,7]
 */
int main(int argc, char const *argv[])
{
    // vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    // vector<vector<int>> matrix = {{7, 9, 6}};
    vector<vector<int>> matrix = {{7}, {9}, {6}};
    std::vector<int> res = spiralOrder(matrix);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    return 0;
}
