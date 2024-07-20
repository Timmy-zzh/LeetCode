#include <iostream>
#include <vector>

using namespace std;

/**
 * 加油站：
 *
 * 在一条环路上有 n 个加油站，其中第 i 个加油站有汽油 gas[i] 升。
你有一辆油箱容量无限的的汽车，从第 i 个加油站开往第 i+1 个加油站需要消耗汽油 cost[i] 升。你从其中的一个加油站出发，开始时油箱为空。
给定两个整数数组 gas 和 cost ，如果你可以按顺序绕环路行驶一周，则返回出发时加油站的编号，否则返回 -1 。如果存在解，则 保证 它是 唯一 的。

示例 1:
输入: gas = [1,2,3,4,5], cost = [3,4,5,1,2]
输出: 3
解释:
从 3 号加油站(索引为 3 处)出发，可获得 4 升汽油。此时油箱有 = 0 + 4 = 4 升汽油
开往 4 号加油站，此时油箱有 4 - 1 + 5 = 8 升汽油
开往 0 号加油站，此时油箱有 8 - 2 + 1 = 7 升汽油
开往 1 号加油站，此时油箱有 7 - 3 + 2 = 6 升汽油
开往 2 号加油站，此时油箱有 6 - 4 + 3 = 5 升汽油
开往 3 号加油站，你需要消耗 5 升汽油，正好足够你返回到 3 号加油站。
因此，3 可为起始索引。

示例 2:
输入: gas = [2,3,4], cost = [3,4,3]
输出: -1
解释:
你不能从 0 号或 1 号加油站出发，因为没有足够的汽油可以让你行驶到下一个加油站。
我们从 2 号加油站出发，可以获得 4 升汽油。 此时油箱有 = 0 + 4 = 4 升汽油
开往 0 号加油站，此时油箱有 4 - 3 + 2 = 3 升汽油
开往 1 号加油站，此时油箱有 3 - 3 + 3 = 3 升汽油
你无法返回 2 号加油站，因为返程需要消耗 4 升汽油，但是你的油箱只有 3 升汽油。
因此，无论怎样，你都不可能绕环路行驶一周。
 */

int currGas = 0; // 记录当前持有的汽油量

bool canCircleIndex2(int index, int size, int start, vector<int> &gas, vector<int> &cost)
{
    index = index % size;
    if (index == start)
    {
        return true;
    }
    currGas += gas[index];     // 补充汽油
    if (currGas < cost[index]) // 下一站都到不了，那就算了
    {
        return false;
    }
    currGas -= cost[index]; // 到达下一站，消耗汽油

    return canCircleIndex2(index + 1, size, start, gas, cost);
}

/**
 * 不用递归，改为while迭代
 * 递归和迭代的方式不行，都会超时
 * - 上面方法的时间复杂度，总共需要n*n计算，太高了，
 */
bool canCircleIndex(int index, int size, int start, vector<int> &gas, vector<int> &cost)
{
    index = index % size;
    while (index != start)
    {
        currGas += gas[index];     // 补充汽油
        if (currGas < cost[index]) // 下一站都到不了，那就算了
        {
            return false;
        }
        currGas -= cost[index]; // 到达下一站，消耗汽油

        index++;
        index = index % size;
    }
    return true;
}

/**
 * 1、审题：
 * - 输入两个数组分别标识沿途的加油站存在的石油，另一个数组表示沿途加油站行驶所需要消耗的汽油
 * - 求从哪个加油站开始可以绕一圈回到原点
 * 2、解题：
 * - 分别从沿途的加油站出发，使用for循环，判断每次出发最后返回的结果
 * - 拆解： 题目要求是绕一圈回到原点，可以拆解为从当前加油站出发能否到达下一站的问题
 * -- 再进一步，就是判断当前的汽油量和达到下一站所需要消耗的汽油量大小，
 */
int canCompleteCircuit1(vector<int> &gas, vector<int> &cost)
{
    int size = gas.size();

    for (size_t i = 0; i < size; i++)
    {
        currGas = gas[i];
        if (currGas < cost[i]) // 下一站都到不了，那就算了
        {
            continue;
        }
        currGas -= cost[i]; // 到达下一站，消耗汽油

        bool res = canCircleIndex(i + 1, size, i, gas, cost);
        if (res)
        {
            return i;
        }
    }
    return -1;
}

/**
 * 要实现时间复杂度是n的算法，需要改变思路：
 * - 我们从第0个加油站开始出发，在每个加油站可以获取到汽油，接着判断获得的汽油是否满足行驶到下一个加油站消耗的汽油
 * - 如果满足继续行驶，不满足
 * - 情况1：从第i个加油站开始出发，下一个加油站i+1，都到不了，则往后移动，重新从i+1个位置加油站开始出发
 * - 情况2：从第i个加油站开始出发，中途不断加油消耗，行驶到下一个加油站，最终环绕一圈后，回到原始加油站
 * - 情况3：从第i个加油站开始出发，中途行驶到第j个加油站没油了，这个时候是从第i+1个加油站开始重新出发，就变成情况1了，
 * -- 还是从第j+1个加油站开始出发，答案是从j+1个加油站出发，因为[i,j]位置的加油站位置，都无法走完全程
 * - 这种方式也超过时间限制了，事件复杂度为n的平方
 */
int canCompleteCircuit3(vector<int> &gas, vector<int> &cost)
{
    int size = gas.size();

    int i = 0;
    while (i < size)
    {
        int j = i;
        int currGas = gas[j]; // 当前已有的汽油
        if (currGas >= cost[j])
        {
            // 从j位置加油站开始出发
            currGas -= cost[j];
            j++;
            j = j % size;
            while (j != i)
            {
                std::cout << "while j:" << j << " ,i:" << i << " " << std::endl;
                currGas += gas[j];
                if (currGas >= cost[j])
                {
                    currGas -= cost[j];
                    j++;
                    j = j % size;
                }
                else
                {
                    if (j + 1 > i)
                    {
                        i = j + 1;
                    }
                    else
                    {
                        i++;
                    }
                    std::cout << "break j:" << j << " ,i:" << i << " " << std::endl;
                    break;
                }
            }
            if (i == j)
            {
                return i;
            }
            std::cout << "return j:" << j << " ,i:" << i << " " << std::endl;
        }
        else
        {
            i++;
        }
    }

    return -1;
}

/**
 * 有卡壳，再重新写一遍
 * - 沿着加油站，顺序往后移动，先判断能不能到达下一个加油站，不能则从下一个加油站重新开始出发
 * - 如果从下一个加油站出发，加入的油比消耗的油要大，则继续往后移动，先加油，判断能否到达下一个加油站，能的话当前的油量减去消耗的
 * - 如果不能，直接中断了，又的重新从下一个加油站开始出发，
 * - 如果循环了一圈，又跑到前面加油站位置去了，那指定是不能绕一圈的，直接返回-1
 */
int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
{
    int count = gas.size();
    int currGas = 0;
    int i = 0;
    while (i < count)
    {
        if (gas[i] >= cost[i])
        {
            currGas = gas[i];
            // while循环，让加油站不断往后移动，移动到最后一位再返回到第一位置，直到遇到开始出发的加油站位置（也就是i）
            int j = i;
            while (currGas >= cost[j])
            {
                currGas -= cost[j];
                j++;
                j = j % count;
                currGas += gas[j];

                if (i == j)
                {
                    return i;
                }
            }
            if (j < i)
            {
                return -1;
            }
            else
            {
                i = j;
            }
        }
        else
        {
            i++;
        }
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    vector<int> gas = {1, 2, 3, 4, 5};
    vector<int> cost = {3, 4, 5, 1, 2};

    // vector<int> gas = {2, 3, 4};
    // vector<int> cost = {3, 4, 3};

    // vector<int> gas = {5};
    // vector<int> cost = {4};
    auto res = canCompleteCircuit(gas, cost);
    cout << "res:" << res << endl;
    return 0;
}
