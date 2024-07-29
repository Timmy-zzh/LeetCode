#include <iostream>
#include <string.h>

using namespace std;
/**
 * 给你一个字符串 s ，请你反转字符串中 单词 的顺序。
单词 是由非空格字符组成的字符串。s 中使用至少一个空格将字符串中的 单词 分隔开。
返回 单词 顺序颠倒且 单词 之间用单个空格连接的结果字符串。
注意：输入字符串 s中可能会存在前导空格、尾随空格或者单词间的多个空格。返回的结果字符串中，单词间应当仅用单个空格分隔，且不包含任何额外的空格。

示例 1：
输入：s = "the sky is blue"
输出："blue is sky the"

示例 2：
输入：s = "  hello world  "
输出："world hello"
解释：反转后的字符串中不能存在前导空格和尾随空格。

示例 3：
输入：s = "a good   example"
输出："example good a"
解释：如果两个单词间有多余的空格，反转后的字符串需要将单词间的空格减少到仅有一个。
 */

/**
 * 1、审题：
 * - 输入一个字符串，字符串由单次和空格组成，空格可能存在多个，现在需要对字符串中的单词进行翻转，最后一个单词需要翻转到前面位置去
 * - 且单词之间的只有一个空格连接
 * 2、解题：
 * - list集合解法： 将字符串根据空格字符进行切分，切分后是空格字符则过滤，不是空格的单词则从后往前遍历存放在字符串中，并使用空格连接
 * - 字符串原地翻转法：
 * -- 先将头尾和中间多于的空格清除，中间的多个空格符只保留一个
 * -- 将所有字符串翻转，载接着翻转单个字符
 */

void reverseStr(string &str, int start, int end)
{
    cout << "reverseStr str:" << str << ",start:" << start << ",end:" << end << endl;
    int count = end - start + 1;
    for (int i = 0; i < count / 2; i++)
    {
        int temp = str[start + i];
        str[start + i] = str[end - i];
        str[end - i] = temp;
    }
    cout << "reverseStr222 str:" << str << ",start:" << start << ",end:" << end << endl;
}

string reverseWords(string s)
{
    /**
     * 新建一个字符串 news
     * 遍历原始字符串s： 遇到字符则添加到新字符串中
     * - 遇到空格，则判断当前位置的前面是空格还是字符，是字符则插入空格，是空格也过滤
     * - 这样新字符串的末尾可能会是空格，判断后去除就可以
     */
    string newS = "";
    int len = s.length();
    for (int i = 0; i < len; i++)
    {
        if (s[i] != ' ')
        { // 不是空格，则插入
            newS.push_back(s[i]);
        }else if (i > 0 && s[i - 1] != ' ')
        {
            newS.push_back(s[i]);
        }
    }
    // 获取字符串最后一个字符
    if (!newS.empty() && newS.back() == ' ')
    {
        newS.pop_back(); // 字符串最后一个字符是空格，则出栈
    }

    cout << "newS:" << newS << endl;

    // 新字符串整体翻转
    int newLen = newS.length();
    reverseStr(newS, 0, newLen - 1);
    // for (int i = 0; i < newLen / 2; i++)
    // {
    //     int temp = newS[i];
    //     newS[i] = newS[newLen - 1 - i];
    //     newS[newLen - 1 - i] = temp;
    // }
    cout << "for1 newS:" << newS << endl;

    // 寻找到单个单词翻转，遇到空格，或最后一位
    int left = 0;
    for (int i = 0; i < newLen; i++)
    {
        if (newS[i] == ' ')
        {
            reverseStr(newS, left, i - 1);
            left = i + 1;
        }
        if (i == newLen - 1)
        {
            reverseStr(newS, left, i);
        }
    }

    return newS;
}

int main(int argc, char const *argv[])
{
    // string res = reverseWords("the sky is blue");
    // string res = reverseWords("a good   example");
    string res = reverseWords("  hello world  ");
    cout << "res:" << res << endl;
    return 0;
}
