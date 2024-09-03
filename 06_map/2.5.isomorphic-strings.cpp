#include <iostream>
#include <vector>
#include <string.h>
#include <map>

using namespace std;

/**
 * 1、审题：
 * - 输入两个字符串s和t，判断s和t是否同构，
 * - 同构的意思是，s中的字符可以由t中的字符映射替换，t中的每个字符只能使用一次，且映射的顺序不能改变。
 * - 每个字符可以映射一个其他字符，也可以映射自己
 * 2、解题：
 * - hashmap解法，遍历s中的字符和t中的字符，首先字符s和t长度需要一样
 * - s中字符与t中的字符在遍历的时候，要一一对应映射起来，保存在map中，遍历过程中判断新遍历到的字符在map中是否存在
 * - 如果存在，则需要和之前的字符一致，否则返回false
 * 3、还需要一个字符t到字符s的映射关系集合，他们相互之间的关系要一一对应
 * 4、总结：
 * - 同构字符串，判断单词映射关系，每个单词只能映射一个单词，且顺序保持不变
 * - 使用map保存他们的映射关系，需要使用两个map保存来回的映射关系
 */
bool isIsomorphic(string s, string t)
{
    map<char, char> stMap;
    map<char, char> tsMap;

    if (s.size() != t.size())
        return false;

    // 遍历
    for (int i = 0; i < s.size(); i++)
    {
        if (stMap.empty()) // map为空
        {
            stMap.insert({s[i], t[i]});
            tsMap.insert({t[i], s[i]});
        }
        else if (stMap.find(s[i]) == stMap.end()) // 不包含s[i]元素,则添加到map中，建立映射关系
        {
            // 字符s到字符t没有映射关系，反过来字符t[i]不应该存在有映射关系
            if (tsMap.find(t[i]) != tsMap.end())
                return false;

            stMap.insert({s[i], t[i]});
            tsMap.insert({t[i], s[i]});
        }
        else
        {
            // 如果已经包含了s[i]元素，判断对应的映射stMap[s[i]] 是否等于遍历到的t[i]元素
            if (stMap[s[i]] != t[i])
                return false;
        }
    }

    return true;
}

/**
 * 给定两个字符串 s 和 t ，判断它们是否是同构的。
如果 s 中的字符可以按某种映射关系替换得到 t ，那么这两个字符串是同构的。
每个出现的字符都应当映射到另一个字符，同时不改变字符的顺序。不同字符不能映射到同一个字符上，相同字符只能映射到同一个字符上，字符可以映射到自己本身。

示例 1:
输入：s = "egg", t = "add"
输出：true

示例 2：
输入：s = "foo", t = "bar"
输出：false

示例 3：
输入：s = "paper", t = "title"
输出：true
 */
int main(int argc, char const *argv[])
{
    bool res = isIsomorphic("badc", "baba");
    cout << "res:" << res << endl;
    return 0;
}
