#include <iostream>
#include <string>
// #include <string.h> // 这是C字符串头文件
#include <stack>
#include <vector>

using namespace std;
string simplifyPath(string path);

void stringSplit(const string &str, const char split, vector<string> &res);
string simplifyPath(string path);

int main(int argc, char const *argv[])
{

    vector<string> vector;
    stringSplit("/a/./b/../../c/", '/', vector);
    // stringSplit("This is a test", ' ', vector);

    // 遍历
    for (size_t i = 0; i < vector.size(); i++)
    {
        cout << vector.at(i) << endl;
    }

    auto res = simplifyPath("/a/./b/../../c/");

    // auto res = simplifyPath("/home//foo/");
    cout << "res:" << res << endl;

    return 0;
}

/**
 * 1、审题
 * - 输入一个表示路劲的字符串，路径规则有. .. / // 等，需要将当前路径进行简化后输出
 * 2、解题
 * - 先分割，根据反斜线切割/, 再获取分割后数组中的元素，
 * - 遍历过程中，将数组元素的字符插入到栈中，插入过程中，根据路径规则，对栈元素进行处理
 * - 最后将栈中的元素全部出栈，翻转
 * 3、自己实现字符串分割函数，
 * - 使用string 字符串的find和substr函数实现
 * --
 */
string simplifyPath(string path)
{
    // path.splite("/");
    stack<string> stackV = stack<string>();
    vector<string> vector;
    stringSplit(path, '/', vector);
    for (auto str : vector)
    {
        if (str == "")
        {
            continue;
        }
        // 判断当前输入的路径，匹配规则 . ..
        if (str == ".")
        {
            continue;
        }
        else if (str == "..")
        {
            stackV.pop();
        }
        else
        {
            stackV.push(str);
        }
    }

    string res;
    while (!stackV.empty())
    {
        string item = stackV.top();
        stackV.pop();
        res = "/"+item + res;
    }

    return res;
}

/**
 * 1、字符串分割，主要使用find方法在str原始字符串中查到分割串split的位置，
 * - 如果存在该位置，则使用substr方法截取这部分子串，并保存到vector集合中
 * - 接着原始字符串进行更新，还是使用substr方法截取后面位置的字符串，并继续查找分割串split的位置，
 * - 使用while循环不断获取
 */
void stringSplit(const string &str, const char split, vector<string> &res)
{
    cout << "stringSplit -- str:" << str
         << " , split:" << split << endl;
    if (str == "")
    {
        return;
    }

    string strs = str + split; // 原始数组添加分割子串，方面截取最后一部分数据
    int pos = strs.find(split);
    cout << "stringSplit -- strs:" << strs
         << " ,pos:" << pos << endl;

    while (pos != strs.npos)
    {
        // 找到了，获取子串部分-》保存-》再更新strs的值-》再查找分割串
        string temp = strs.substr(0, pos);
        cout << "while strs:" << strs
             << " ,temp:" << temp
             << " ,pos:" << pos
             << endl;
        res.push_back(temp);

        strs = strs.substr(pos + 1, strs.size());
        pos = strs.find(split);
    }
}