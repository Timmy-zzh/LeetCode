#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <sstream>

using namespace std;

void stringSplit1(const string &str, const char split, vector<string> &res);
string simplifyPath(string path);

/**
 * 1、审题：
 * - 输入一个表示路径的字符串，需要根据规则，对这个字符串进行精简处理，并返回
 * 2、解题：使用栈保存已遍历到的路径
 * - 遍历字符串，遇到反斜杠情况时，就需要判断已经遍历的部分是什么内容，如果是../ 则栈中内容出栈。
 * -- 如果是./ ，说明标识的是当前路径，直接过滤，如果只有一个斜杠/ 说明遇到多个斜杠重复出现了，也是过滤
 * -- 其他情况就入栈
 * - 最后取出栈内内容，注意路径头尾的特殊处理
 * 3、不断遍历，获取字符串中的字符，遇到反斜杠则将之前获得的区域字符串，保存下来放到stack栈中。注意细节处理
 */
string simplifyPath(string path)
{
    stack<string> myStack;
    int size = path.size();
    stringstream sst("");

    for (int i = 0; i < size; i++)
    {
        if (path[i] == '/' || i == size - 1)
        {
            cout << "for / sst:" << sst.str() << endl;
            sst << path[i];

            string itemStr = sst.str();
            if (itemStr == ".." || itemStr == "../") // ../情况，出栈
            {
                if (!myStack.empty())
                {
                    myStack.pop();
                }
                sst.str("");
                continue;
            }
            if (itemStr == "." || itemStr == "./") // ./情况，过滤
            {
                sst.str("");
                continue;
            }

            // 合并字符串，插入到栈中
            if (sst.str() != "/")
            {
                myStack.push(sst.str());
            }
            sst.str(""); // 字符串清空
            continue;
        }

        sst << path[i];
    }

    // 最后一个字符的特殊处理
    if (!sst.str().empty())
    {
        myStack.push(sst.str());
    }

    string res;
    // 取出栈中的数据，保存到res中，
    while (!myStack.empty())
    {
        res = myStack.top() + res;
        myStack.pop();
    }

    // 处理字符串str的头尾部分
    if (res.empty() || res[0] != '/')
    {
        res = "/" + res;
    }
    if (res.size() > 1 && res[res.size() - 1] == '/') // 去掉尾部
    {
        res = res.substr(0, res.size() - 1);
    }

    return res;
}

int main(int argc, char const *argv[])
{

    vector<string> vector;
    // stringSplit("/a/./b/../../c/", '/', vector);
    // stringSplit("This is a test", ' ', vector);

    // 遍历
    // for (size_t i = 0; i < vector.size(); i++)
    // {
    //     cout << vector.at(i) << endl;
    // }

    // auto res = simplifyPath("/a/./b/../../c/");
    // auto res = simplifyPath("/home//foo/");
    // /a//b////c/d//././/..
    auto res = simplifyPath("/a//b////c/d//././/..");
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
string simplifyPath1(string path)
{
    // path.splite("/");
    stack<string> stackV = stack<string>();
    vector<string> vector;
    stringSplit1(path, '/', vector);
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
        res = "/" + item + res;
    }

    return res;
}

/**
 * 1、字符串分割，主要使用find方法在str原始字符串中查到分割串split的位置，
 * - 如果存在该位置，则使用substr方法截取这部分子串，并保存到vector集合中
 * - 接着原始字符串进行更新，还是使用substr方法截取后面位置的字符串，并继续查找分割串split的位置，
 * - 使用while循环不断获取
 */
void stringSplit1(const string &str, const char split, vector<string> &res)
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