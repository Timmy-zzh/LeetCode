#include <vector>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <map>

using namespace std;

/**
 * 1、审题：
 * - 输入一个字符串s和一个字符串数组words，从字符串s中找到所有目标子串，子串要求由字符串数组words中的所有单词组成，不管单词顺序
 * 2、解题：
 * - 暴力解法，遍历字符串s，每次截取words数组长度个单词的子串，判断截取的子串是否与words数组中的单词匹配
 * - 遍历开始位置，需要从0到words数组中每个单词长度的位置，
 * - 遍历的子串，和words中数组中的字符串，是否匹配判断，可通过map集合来保存，以words数组中的单词和对应个数为标准，
 * -- 然后遍历截取的子串中每个单词，每遍历一个单词，map对应单词的个数减1，知道最后看map集合中的key值是否为空。为空表示匹配条件
 * 3、超过时间限制
 * - 需要做优化
 */
vector<int> findSubstring(string s, vector<string> &words)
{
    int m = words.size();
    int n = words[0].size();
    int sLen = s.length();
    vector<int> res;

    map<string, int> mapArr;
    for (int i = 0; i < m; i++)
    {
        string word = words[i];
        if (mapArr.find(word) != mapArr.end()) // 包含，值在原有基础上加1
        {
            mapArr[word] = mapArr[word] + 1;
        }
        else
        {
            mapArr[word] = 1;
        }
    }

    // 打印map集合
    for (auto it = mapArr.begin(); it != mapArr.end(); it++)
    {
        cout << "key:" << it->first << ",value:" << it->second << endl;
    }

    // 先从字符串第0个字符开始截取，每次截取 words所有单词的长度，
    // int start = 0; // 开始位置，不一定是从0开始的，应该是动态的从[0,n]
    for (int j = 0; j < n; j++)
    {
        int start = j;
        while (start + (m * n) <= sLen) // start表示开始位置，以i为起点，遍历m*n个字符作为滑动窗口去截取字符串
        {
            cout << "----start:" << start << endl;
            // 深拷贝一个map集合，用于操作
            map<string, int> mapTemp(mapArr);
            for (int j = 0; j < m; j++)
            {
                // 截取字符串
                string subStr = s.substr(start + j * n, n);
                cout << "subStr:" << subStr << endl;
                if (mapTemp.find(subStr) == mapTemp.end()) // 判断截取的子串，在mapTemp集合中是否存在，不存在，则start更新遍历位置，从新遍历
                {
                    start = start + j * n;
                    cout << "not exist start:" << start << endl;
                    break;
                }

                // 存在，处理mapTemp集合的单词对应个数，如果个数为0，则删除这个key
                // mapTemp[subStr] = mapTemp[subStr] - 1;
                if (mapTemp.find(subStr) != mapTemp.end()) // 存在
                {
                    mapTemp[subStr] = mapTemp[subStr] - 1;
                }
                else
                {
                    mapTemp[subStr] = 1;
                }
            }

            // 判断mapTemp集合中key值对应的个数是否都为0，都为0，则找到满足条件的子串
            bool isMatch = true;
            for (auto it = mapTemp.begin(); it != mapTemp.end(); it++)
            {
                if (it->second != 0)
                {
                    isMatch = false;
                    break;
                }
            }
            if (isMatch)
            {
                res.push_back(start);
            }

            start = start + n;
        }
    }

    return res;
}

/**
 * 解题：
 * - 使用map保存滑动窗口中的单词，是否已经全部使用过了
 * - 只要遍历滑动窗口范围内的所有单词，也就是map中标记的单词是否已经全部使用过了，
 * - 如何使用滑动窗口呢？
 * -- 一个进一个出，
 * -- 使用map集合保存滑动窗口中单词出现的次数，需要和wordk数组中单词出现的次数一致，才算是满足条件
 * -- 可以先将words数组中的单词，使用mapArr集合保存，key为单词，value为单词出现的次数
 * -- 再遍历字符串，每次截取一个单词出来，第一次，截取厨words.size 个单词，保存到mapS集合中，完了与mapArr集合进行比较
 * -- 后面再遍历字符串时，每次截取的单词，和出去的单词，都需要操作mapS中单词的数据，每次截取完后，与mapArr基准集合进行比较
 * -- 遍历过程中，暴力解法，每次截取单词，都需要与基础集合mapArr进行比较，查看是否满足条件
 * -- 如果遇到截取的单词在mapArr中不存在，则直接跳过，从新开始遍历，滑动窗口移动到新的位置，maps集合清空后再填充
 */
/**
 vector<int> findSubstring2(string s, vector<string> &words)
{
    cout << "s:" << s << endl;
    vector<int> res;
    int arrSize = words.size();           // 数组长度
    int itemLen = words[0].size();        // 数组中一个单词的长度
    int strLen = s.length();              // 字符串长度
    vector<bool> mapExist;                   // 标记数组，默认所有单词都没有遍历过,key为单词在数组s中的索引位置，vulue标记这个单词是否已经使用过了
    vector<bool> visited(arrSize, false); // 标记数组，默认所有单词都没有遍历过

    // 过滤字符串s长度过小的情况
    if (strLen < arrSize * itemLen)
    {
        return res;
    }

    for (int i = 0; i < strLen;)
    {
        // 截取单个字符串
        string subStr = s.substr(i, itemLen);

        // 判断该子串在words数组中是否存在？
        if (words.end() != find(words.begin(), words.end(), subStr)) // 找到了
        {
            mapExist[i] = true;
        }
        else
        {
            mapExist[i] = false;
        }

        // 修改mapUserd的值，标记这个起始位置的单词是否已经使用过了

        // 完了，从当前位置i开始，往前遍历，判断所有的子串，在words数组中是否都使用到了，还是需要一个visited数组来标记
        // 裁剪，判断i位置的长度，是否超过works数组的长度，未超过，继续遍历

        i = i + itemLen;
    }

     // 遍历map集合，一次遍历的个数是words数组的长度，组成一个滑动窗口，后面再移动的时候，
     // 由窗口负责增加一个单词，和减少一个单词的使用标记
    // fill(mapUsed.begin(), mapUsed.end(), false);
    fill(visited.begin(), visited.end(), false);

    int i = 0;
    while (i < strLen)
    {
        // 找到 words数组长度个单词，组成一个滑动窗口，滑动窗口中的所有单词都需要已经使用过的，
        // 也就是每个单词在words数组中都有一个空位置等着他存放

        for (int j = 0; j < arrSize; j++)
        {
            int index = i + j * itemLen;
            if (!mapExist[index]) // 不存在
            {
                i = index + itemLen;
                fill(visited.begin(), visited.end(), false);
                break;
            }

            // 获取子串，并判断在visited数组中是否还有空位等着存放，
            string subStr = s.substr(index, itemLen);
            bool isUsed = false;
            int index = -1;
            for (int i = 0; i < arrSize; i++)
            {
                if (subStr == words[i])
                {
                    if (!visited[i])
                    {
                        isUsed = false; // 找到未使用过的单词，标记并退出for循环
                        index = i;
                        break;
                    }
                    else
                    {
                        index = i;
                        isUsed = true; // 找到已经使用过的单词，标记使用过了，继续判断后面是否有一个未使用的
                    }
                }
            }

            if (!isUsed) // 存在未使用过得单词，将标记数组进行处理
            {
                visited[index] = true;
            }
            else // 存在已经使用过的单词，先清空，再标记
            {
                // 当前截取的子串subStr在words数组中已经使用过了，
                fill(visited.begin(), visited.end(), false); //  不能全部清空，按照滑动滑动窗口的数据，进行判断
                visited[index] = true;
            }
        }

        // 如果遇到map集合的值为false，说明遇到不存在words数组中的单词，直接跳过，vistied数组清空

        // 修改mapUserd的值，标记这个起始位置的单词是否已经使用过了

        // 完了，从当前位置i开始，往前遍历，判断所有的子串，在words数组中是否都使用到了，还是需要一个visited数组来标记
        // 裁剪，判断i位置的长度，是否超过works数组的长度，未超过，继续遍历

        i = i + itemLen;
    }

    return res;
}
 */

/**
 * 1、审题： 给定一个字符串s和一个字符串数组words，字符串s的子串，由words中的所有字符组成，
 * - 返回满足条件的子串的起始索引位置
 * 2、解题：
 * - 滑动窗口解法，不断遍历字符串s，每次遍历的长度是workd中元素的长度，判断该单词在words数组中是否存在
 * - 1、如果存在，则标记该单词已经使用过了，继续遍历下一个单词是否存在
 * -- 当words中所有单词都使用过了，则表示找到了满足条件的子串，记录起始索引位置
 * - 2、如果遇到遍历的子串在words数组中不存在，则直接跳过，标记数组清除
 * - 3、如果遇到words中的单词与当前遍历的子串匹配，且已经使用过了，则从新开始遍历，以这个单词为起始
 *
 * 3、当前遍历的子串与words数组中的元素进行匹配，分三种情况：
 * - 1、子串在数组中不存在，直接跳过，标记清空
 * - 2、子串在数组中存在，且未使用过，则标记使用过，继续遍历
 * - 3、子串在数组中存在，且已经使用过，则从新开始遍历，以这个单词为起始，标记数组先清空再记录
 *
 */
vector<int> findSubstring1(string s, vector<string> &words)
{
    cout << "s:" << s << endl;
    vector<int> res;
    int arrSize = words.size();   // 数组长度
    int strLen = words[0].size(); // 数组中一个单词的长度
    int count = s.length();       //   字符粗长度
    // 过滤字符串s长度过小的情况
    if (count < arrSize * strLen)
    {
        return res;
    }

    vector<bool> visited(arrSize, false); // 标记数组，默认所有单词都没有遍历过
    int i = 0;
    // 遍历字符串s，以每次遍历strLen长度为准
    while (i < count)
    {
        // 截取以当前位置i开始的strLent长度的子串，进行判断
        string subStr = s.substr(i, strLen);
        cout << "i:" << i << ",subStr:" << subStr << endl;

        // 判断该子串在words数组中是否存在？
        if (words.end() == find(words.begin(), words.end(), subStr)) // 遍历最后都没找到，不存在
        {
            cout << "no exit:" << subStr << endl;
            // 不存在，直接跳过，标记数组清空
            fill(visited.begin(), visited.end(), false);
            i = i + strLen;
            continue;
        }
        cout << "--- exit:" << subStr << endl;

        // 存在，继续判断在words数组中的位置，和是否已经使用过
        bool isUsed = false;
        int index = -1;
        for (int i = 0; i < arrSize; i++)
        {
            if (subStr == words[i])
            {
                if (!visited[i])
                {
                    isUsed = false; // 找到未使用过的单词，标记并退出for循环
                    index = i;
                    break;
                }
                else
                {
                    index = i;
                    isUsed = true; // 找到已经使用过的单词，标记使用过了，继续判断后面是否有一个未使用的
                }
            }
        }

        cout << "index:" << index << ",isUsed-------:" << isUsed << endl;
        if (!isUsed) // 存在未使用过得单词，将标记数组进行处理
        {
            visited[index] = true;
            // 是否存在所有的单词都已经使用过了的情况
            if (all_of(visited.begin(), visited.end(), [](bool v)
                       { return v; }))
            {
                cout << "all isUsed==============:" << endl;
                // 所有单词都已经使用过了，添加起始索引到结果中
                res.push_back(i - (arrSize - 1) * strLen);
                fill(visited.begin(), visited.end(), false); // 重置标记数组
            }
        }
        else // 存在已经使用过的单词，先清空，再标记
        {
            // 当前截取的子串subStr在words数组中已经使用过了，

            fill(visited.begin(), visited.end(), false); //  不能全部清空，按照滑动滑动窗口的数据，进行判断
            visited[index] = true;
        }

        i = i + strLen;
    }

    return res;
}

int main(int argc, char const *argv[])
{
    // vector<string> words = {"foo", "bar"};
    // vector<int> res = findSubstring("barfoothefoobarman", words);

    // vector<string> words = {"bar", "foo", "the"};
    // vector<int> res = findSubstring("barfoofoobarthefoobarman", words);

    vector<string> words = {"fooo", "barr", "wing", "ding", "wing"};
    vector<int> res = findSubstring("lingmindraboofooowingdingbarrwingmonkeypoundcake", words);
    for (auto r : res)
    {
        cout << "r:" << r << endl;
    }
    return 0;
}
