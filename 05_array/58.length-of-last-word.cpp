#include <iostream>
#include <string.h>

using namespace std;

/**
 * 给你一个字符串 s，由若干单词组成，单词前后用一些空格字符隔开。返回字符串中 最后一个 单词的长度。
单词 是指仅由字母组成、不包含任何空格字符的最大
子字符串

示例 1：
输入：s = "Hello World"
输出：5
解释：最后一个单词是“World”，长度为 5。

示例 2：
输入：s = "   fly me   to   the moon  "
输出：4
解释：最后一个单词是“moon”，长度为 4。

示例 3：
输入：s = "luffy is still joyboy"
输出：6
解释：最后一个单词是长度为 6 的“joyboy”。
 */

/**
 * 1、审题：
 * - 输入一个字符串，字符串由单词和空格组成，求最后一个单词的长度
 * 2、解题：
 * - 标记遍历法：
 * - 从右往左遍历，使用一个标记标量记录是否遇到了单词，
 * - 如果遇到了单词，则开始计算，并将标记设置为true
 * - 当遇到了空格，需要判断标记是否有true，如果是true，则说明遍历完了第一个单词，直接返回其长度
 */
int lengthOfLastWord(string s)
{
    bool flag = false;
    int len = s.length();
    int count=0;

    for (int i = len - 1; i >= 0; i--)
    {
        if (s[i] == ' ' && flag)
        {
            return count;
        }
        if (s[i] != ' ')
        {
            count++;
            flag = true;
        }
    }
    return count;
}

int main(int argc, char const *argv[])
{
    // int res = lengthOfLastWord("Hello World");
    int res = lengthOfLastWord("Hello");
    cout << "res:" << res << endl;
    return 0;
}