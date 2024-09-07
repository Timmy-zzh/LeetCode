#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#include <map>

using namespace std;

vector<vector<string>> res;

bool isAnagram(string &s, string &t)
{
    int letters[26];
    for (int i = 0; i < 26; i++)
    {
        letters[i] = 0;
    }
    for (int i = 0; i < s.size(); i++)
    {
        letters[s[i] - 'a'] = letters[s[i] - 'a'] + 1; // 元素值++
    }
    for (int i = 0; i < t.size(); i++)
    {
        letters[t[i] - 'a'] = letters[t[i] - 'a'] - 1;
    }
    for (int i = 0; i < 26; i++)
    {
        if (letters[i] != 0)
        {
            return false;
        }
    }
    return true;
}

void groupAnagramsBack(int i, vector<string> &strs, vector<string> itemStrs, vector<bool> &used)
{
    if (i == strs.size())
    {
        for (int i = 0; i < itemStrs.size(); i++)
        {
            cout << itemStrs[i] << " , ";
        }
        cout << endl;

        res.push_back(itemStrs);
        return;
    }

    // 判断该单词是否和 itemStrs集合中的单词是否是字母异位词？
    if (isAnagram(strs[i], itemStrs[0]))
    {
        used[i] = true;
        itemStrs.push_back(strs[i]);
    }

    groupAnagramsBack(i + 1, strs, itemStrs, used);
}

/**
 * 1、审题：
 * - 输入一个字符串数组，要求将所有字母异位词的所有单词组合在一起返回。
 * - 字母异位词，指两个单词包含的字母类型和数量相同
 * 2、解题：广度优先遍历
 * - 题目要求解的就是如何从字符串数组中找出所有相同的字母异位词
 * - 暴力遍历解法，遍历字符串数组中每个单词，并以该单词为基准，找到所有与该基准单词为字母异位词的单词，并保存在集合中
 * 3、问题，超出时间限制
 * - 在遍历的过程中，与已有的itemStr集合中的单词判断是否是字母异位词，减少多次遍历判断
 */
vector<vector<string>> groupAnagrams1(vector<string> &strs)
{
    vector<bool> used(strs.size());
    fill(used.begin(), used.end(), false);

    for (int i = 0; i < strs.size(); i++)
    {
        cout << "for:" << i << endl;
        for (int i = 0; i < used.size(); i++)
        {
            cout << used[i] << ",";
        }
        cout << endl;

        if (!used[i])
        {
            vector<string> itemStrs;
            itemStrs.push_back(strs[i]);
            used[i] = true;

            groupAnagramsBack(i + 1, strs, itemStrs, used);
        }
    }
    return res;
}

/**
 * 这种处理方式还是超出时间限制，时间复杂度O（n2）
 */
vector<vector<string>> groupAnagrams2(vector<string> &strs)
{
    vector<vector<string>> res2;
    for (int i = 0; i < strs.size(); i++)
    {
        cout << "for:" << i << endl;
        string itemStr = strs[i];

        if (res2.empty()) // 集合为空，将当前元素添加到集合中，添加之前，需要先添加到子集合中
        {
            vector<string> itemStrs;
            itemStrs.push_back(itemStr);
            res2.push_back(itemStrs);
            continue;
        }

        // 判断当前字符串，和子集合中的第一个单词是否匹配为字母异位词，如果命中，则添加到这个集合中，如果都没有匹配，则新建子集合添加
        bool isMatch = false;
        for (int i = 0; i < res2.size(); i++)
        {
            if (isAnagram(itemStr, res2[i][0]))
            {
                res2[i].push_back(itemStr);
                isMatch = true;
                break;
            }
        }
        if (!isMatch)
        {
            vector<string> itemStrs;
            itemStrs.push_back(itemStr);
            res2.push_back(itemStrs);
        }
    }
    return res2;
}

/**
 * 1、排序解法
 * - 遍历字符串中所有单词，对每个单词进行排序处理，如果是字母异位词的字符串，则单词排序后生成的结果相同，
 * -- 可使用map保存起来，map的key值是排序后的字符串，value值是相同字母异位词的vector数组
 * - 再对map进行遍历，找出所有的数组，添加到最后的res数组集合中
 */
vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    vector<vector<string>> res3;
    map<string, vector<string>> mapV;

    for (int i = 0; i < strs.size(); i++)
    {
        string key = strs[i];
        sort(key.begin(), key.end());    // 对字符串进行排序
        mapV[key].emplace_back(strs[i]); // 添加到集合中取
    }

    for (auto it = mapV.begin(); it != mapV.end(); it++)
    {
        res3.emplace_back(it->second);
    }
    return res3;
}

/**
 * 给你一个字符串数组，请你将 字母异位词 组合在一起。可以按任意顺序返回结果列表。
字母异位词 是由重新排列源单词的所有字母得到的一个新单词。

示例 1:
输入: strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
输出: [["bat"],["nat","tan"],["ate","eat","tea"]]

示例 2:
输入: strs = [""]
输出: [[""]]

示例 3:
输入: strs = ["a"]
输出: [["a"]]
 */
int main(int argc, char const *argv[])
{
    vector<string> strs{"eat", "tea", "tan", "ate", "nat", "bat"};
    groupAnagrams(strs);
    return 0;
}
