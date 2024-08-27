#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * 1、审题： 输入一个m*n的矩阵，如果发现一个元素为0，则将该元素所在的行和列上的所有元素都设置为0
 * 2、解题：
 * - 缓存遍历法
 * - 遍历矩阵元素，发现元素为0，将该元素的行和列的位置添加到数组中，
 * - 最后在遍历保存了行和列的数组，将对应行和列的元素设置为0
 */
void setZeroes(vector<vector<int>> &matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();

    vector<int> row;
    vector<int> col;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == 0)
            {
                if (row.empty() || find(row.begin(), row.end(), i) == row.end()) // row集合中没有当前i行
                {
                    row.push_back(i);
                }
                if (col.empty() || find(col.begin(), col.end(), j) == col.end()) // row集合中没有当前i行
                {
                    col.push_back(j);
                }
            }
        }
    }

    for (int i = 0; i < row.size(); i++)
    {
        // 遍历行，将该行上的元素都设置为0
        for (int j = 0; j < n; j++)
        {
            matrix[row[i]][j] = 0;
        }
    }

    for (int i = 0; i < col.size(); i++)
    {
        for (int j = 0; j < m; j++)
        {
            matrix[j][col[i]] = 0;
        }
    }
}

/**
 * 给定一个 m x n 的矩阵，如果一个元素为 0 ，则将其所在行和列的所有元素都设为 0 。请使用 原地 算法。

示例 1：
输入：matrix = [[1,1,1],[1,0,1],[1,1,1]]
输出：[[1,0,1],[0,0,0],[1,0,1]]

示例 2：
输入：matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
输出：[[0,0,0,0],[0,4,5,0],[0,3,1,0]]
 */
int main(int argc, char const *argv[])
{
    return 0;
}
