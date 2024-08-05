#include <iostream>
#include <string.h>

using namespace std;

/**
 * 判断s是否是t的子序列
 * - 双指针解法：
 * - 一个指针指向s，另一个指向t
 * - 不断遍历t，如果t指向的元等于s指向的元素，则s指针往右移动，知道s或t的指针到达末尾
 */
bool isSubsequence(string s, string t)
{
    int lenT = t.length();
    int lenS = s.length();
    if (lenS == 0)
    {
        return true;
    }

    int iS = 0;
    for (int iT = 0; iT < lenT; iT++)
    {
        if (t[iT] == s[iS])
        {
            iS++;
            cout << "iT:" << iT << "，iS:" << iS << ",lenS:" << lenS << endl;
            if (iS == lenS)
            {
                return true;
            }
        }
    }
    return false;
}

int main(int argc, char const *argv[])
{
    auto res = isSubsequence("abc", "ahbgdc");
    cout << res << endl;
    return 0;
}
