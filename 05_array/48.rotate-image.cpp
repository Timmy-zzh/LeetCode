#include <iostream>
#include <vector>

using namespace std;

/**
 * 1、审题： 输入一个n*n的二维矩阵，需要将矩阵沿着顺时针旋转90度
 * 2、解题：
 * - 每次沿着矩阵的最外层四条边进行旋转，然后四条边逐次往内收缩，直到最后没有元素可以旋转
 * - 每次旋转一条边上的元素，四条边的对应位置的元素进行交换，
 */
void rotate(vector<vector<int>> &matrix)
{
    int up = 0;
    int down = matrix.size() - 1;
    int left = 0;
    int right = matrix[0].size() - 1;

    int temp = 0;

    while (true)
    {
        for (int i = 0; i < right - left; i++) // 一条边上的元素数据
        {
            // 对每个元素，进行四次交换

            temp = matrix[up][left + i];                      // temp -> 左上角元素
            matrix[up][left + i] = matrix[down - i][left];    // 左下角元素 -》 左上角
            matrix[down - i][left] = matrix[down][right - i]; // 右下角元素 -》 左下角
            matrix[down][right - i] = matrix[up + i][right];  // 右上角元素 -》 右下角
            matrix[up + i][right] = temp;                     // 左上角元素 -》 右上角
        }
        
        up++;
        down--;
        left++;
        right--;

        if (left >= right || up >= down)
            break;
    }
}

/**
 * 给定一个 n × n 的二维矩阵 matrix 表示一个图像。请你将图像顺时针旋转 90 度。
你必须在 原地 旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要 使用另一个矩阵来旋转图像。

示例 1：
输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
输出：[[7,4,1],[8,5,2],[9,6,3]]

示例 2：
输入：matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
输出：[[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]
 */
int main(int argc, char const *argv[])
{

    return 0;
}
