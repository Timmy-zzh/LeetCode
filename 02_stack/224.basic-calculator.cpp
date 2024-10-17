#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <cctype>

using namespace std;

/**
 * 去除字符串中的空格
 * erase() 删除集合中的元素，
 * - 可以删除集合中指定位置的元素， -- 传入的是迭代器，例子要删除集合第二个元素，需要传入 arr.begin() + 2
 * - 也可以删除集合中某个范围的元素 -- 传入的是int类型表示元素第几个位置，arr.erase(2,5);
 * - erase调用后，会返回下一个迭代器位置
 *
 * - remove是删除的意思，但是在底层并不会将该元素删除，而是通过交换数据
 */
std::string removeSpace(const std::string &input)
{
    std::string result = input;
    result.erase(std::remove(result.begin(), result.end(), ' '), result.end());
    return result;
}

/**
 * 字符串在分割的时候，还要注意区分连续的数字和加减符号的分割
 * 还要注意加减
 */
// int index = 0;
// int calculateBack(int len, string &s, stack<string> &stackVal)
// {
//     if (index == len)
//     {
//         return stoi(stackVal.top());
//     }

//     char ch = s[index];
//     index++;

//     if (ch == '(')
//     {
//         stack<string> newStack;
//         int res = calculateBack(len, s, newStack);

//         if (stackVal.empty())
//         {
//             stackVal.push(to_string(res));
//         }
//         else
//         {
//             // 将括号内的数值，与当前栈stack中的数据进行运算处理
//             string calStyle = stackVal.top();
//             stackVal.pop();
//             // 取出数字
//             int numCh = stoi(stackVal.top());
//             stackVal.pop();

//             // char
//             if (calStyle == "+")
//             {
//                 int calRes = numCh + res;
//                 stackVal.push(to_string(calRes));
//             }
//             else
//             {
//                 int calRes = numCh - res;
//                 stackVal.push(to_string(calRes));
//             }
//         }
//         return calculateBack(len, s, stackVal);
//     }
//     else if (ch == ')') // 右括号
//     {
//         // 出栈了
//         return stoi(stackVal.top());
//     }
//     else
//     {
//         // 数字，只能处理单个数字了，多个连续的数字，更复杂
//         // 取出栈中的数字，进行计算处理
//         int currNum{ch};
//         if (stackVal.empty())
//         {
//             stackVal.push(to_string(currNum));
//         }
//         else
//         {
//             // 将括号内的数值，与当前栈stack中的数据进行运算处理
//             string calStyle = stackVal.top();
//             stackVal.pop();
//             // 取出数字
//             int numCh = stoi(stackVal.top());
//             stackVal.pop();

//             // char
//             if (calStyle == "+")
//             {
//                 int calRes = numCh + currNum;
//                 stackVal.push(to_string(calRes));
//             }
//             else
//             {
//                 int calRes = numCh - currNum;
//                 stackVal.push(to_string(calRes));
//             }
//         }
//         return calculateBack(len, s, stackVal);
//     }
// }

/**
 * 1、审题：
 * - 输入一个由字符串标识的表达式，要求根据数学规则，计算表达式的结果
 * - 字符串由+，-，（，）,加减左右括号组成，有乘除运算那就更复杂了
 * 2、解题：
 * - 要使用到递归算法，遇到左括号时，进入递归，遇到右括号退出递归，并返回括号内的计算结果值
 * - 运算中的结果使用栈stack保存下来
 *
 * 0918
 * - 遍历字符串，遇到了数字，从栈中取出两个元素，进行加减运算，运算结果再入栈，
 * - 遇到左括号，相当于重新开始一段计算逻辑，使用一个新的栈来保存计算的结果值，遇到右括号或者遍历结束，则返回栈中结果
 * - 栈内元素始终保持一个，或者两个（1个数字，一个加减符号）
 *
 * 0920 直接用栈保存就好了，不用管括号，遇到括号，直接过滤掉，只处理数组和加减符号。
 * - 因为没有乘除运算，所以不用考虑括号导致的优先级问题
 * - 遍历字符串，遇到加减符号，则将前一个阶段的数字放到栈中，然后将符号也放到栈中
 * - 遍历栈中的元素，进行加减运算
 */
// int calculate1(string s)
// {
//     int len = s.size();
//     if (len == 0)
//     {
//         return 0;
//     }

//     // 去除空格
//     s = removeSpace(s);
//     cout << "removeSpace s:" << s << endl;
//     index = 0;

//     stack<string> stackVal;
//     // 经过计算后，栈中最后只保留一个元素，就是计算器的结果值
//     return calculateBack(len, s, stackVal);
// }

/**
 * 问题1： 负号运算符问题，和括号在一起形成--的正情况
 * - 还是要用递归算法，遇到左括号，进入递归，遇到右括号，退出递归
 *
 */
int calculate2(string s)
{
    int len = s.size();
    if (len == 0)
    {
        return 0;
    }

    // 将空格清除,也可以考虑把左右括号去除
    string newStr = removeSpace(s);
    cout << "removeStr:" << newStr << endl;
    len = newStr.length();

    stack<string> stackStrs;
    int start = 0;
    for (int i = 0; i < len; i++)
    {
        char ch = newStr[i];

        if (ch == '(')
        {
            start = i + 1;
            continue;
        }

        if (i == len - 1 || ch == ')')
        {
            if (ch == ')')
            {
                string numStr = newStr.substr(start, i - start);
                if (numStr.size() > 0)
                {
                    cout << "1111 last newStr:" << numStr << endl;
                    stackStrs.push(numStr);
                }
                start = i + 1;
            }
            else
            {
                string numStr = newStr.substr(start, i - start + 1);
                cout << "last newStr:" << numStr << endl;
                stackStrs.push(numStr);
                break;
            }
        }
        // 遇到加减符号
        if (ch == '+' || ch == '-')
        {
            // 将前面的数字获取到，添加到栈中，substr的是，从start开始，去i个字符
            string numStr = newStr.substr(start, i - start);
            cout << "start:" << start << ",i:" << i << ",numStr:" << numStr << ",ch:" << ch << endl;
            if (!numStr.empty())
            {
                stackStrs.push(numStr);
            }

            string itemStr(1, ch);
            stackStrs.push(itemStr);
            start = i + 1;
            cout << "numStr:" << numStr << " ,itemStr:" << itemStr << endl;
        }
    }

    if (stackStrs.size() == 1)
    {
        return stoi(stackStrs.top());
    }

    // 要先将栈内数据翻转
    stack<string> stackTmp;
    while (!stackStrs.empty())
    {
        stackTmp.push(stackStrs.top());
        stackStrs.pop();
    }

    int size = stackTmp.size();
    int res = stoi(stackTmp.top());
    stackTmp.pop();

    // 栈不能获取到第i个位置元素数据，只能用while递归
    while (!stackTmp.empty())
    {
        // 取出栈顶元素，先取出运算符，再取出数字
        string operateStr = stackTmp.top();
        stackTmp.pop();

        string numStr = stackTmp.top();
        stackTmp.pop();

        if (operateStr == "+")
        {
            res += stoi(numStr);
        }
        else
        {
            res -= stoi(numStr);
        }
    }

    return res;
}

std::string removeFilter(const std::string &input, const char &filter)
{
    std::string result = input;
    result.erase(std::remove(result.begin(), result.end(), filter), result.end());
    return result;
}
/**
 * 解题思路：
 * - 将所有空格和左右括号去除
 * - 再遍历字符串，处理两次重复出现的运算符，负负得正
 * - 处理第一个字符是运算符的情况
 * - 最后接着遍历，使用栈保存遇到的数字和运算符，最后计算结果
 * -- 对于数字，需要判断区间，对数字进行截取
 * 2、这种思路不行哦，当输入字符串为 - (3 + (4 + 5)) 时，会出现问题
 * - 最后的结果是-12，但是这种思路计算结果是 6
 * - 还是要使用栈和递归算法来实现
 */
int calculate3(string s)
{
    int len = s.size();
    if (len == 0)
    {
        return 0;
    }

    // 将空格清除,也可以考虑把左右括号去除
    s = removeFilter(s, ' ');
    cout << "removeSpace:" << s << endl;
    // 去除左括号
    s = removeFilter(s, '(');
    cout << "removeSpace  ( :" << s << endl;
    // 去除右括号
    s = removeFilter(s, ')');
    cout << "removeSpace  ) :" << s << endl;

    // 处理运算符重复情况
    len = s.size();
    string newStr = "";
    int sign = 1; // 标记开头第一个字符是否是-运算符
    for (int i = 0; i < len; i++)
    {
        char ch = s[i];
        if (i == 0 && (ch == '+' || ch == '-'))
        {
            sign = (ch == '-') ? -1 : 1;
            continue;
        }

        if (ch == '+' || ch == '-') // 如果前一个字符也是运算符，需要处理，只能保存一个
        {
            char preCh = s[i - 1];
            if (preCh == '+' || preCh == '-')
            {
                // 如果相同，则之前保存的最后一个字符串，删除，然后加入+运算符号，否则加入-运算符
                newStr.erase(newStr.size() - 1);
                if (ch == preCh)
                {
                    newStr += "+";
                }
                else
                {
                    newStr += "-";
                }
                continue;
            }
        }

        // 后面的字符正常情况下，直接加入到newStr字符串中
        newStr += ch;
    }
    cout << "removeSpace  +-  newStr:" << newStr << endl;

    stack<string> stackStrs;
    int start = 0;
    for (int i = 0; i < len; i++)
    {
        char ch = newStr[i];
        if (i == len - 1)
        {
            string numStr = newStr.substr(start, i - start + 1);
            cout << "push last newStr:" << numStr << endl;
            stackStrs.push(numStr);
            break;
        }
        // 遇到加减符号
        if (ch == '+' || ch == '-')
        {
            // 将前面的数字获取到，添加到栈中，substr的是，从start开始，去i个字符
            string numStr = newStr.substr(start, i - start);
            cout << "start:" << start << ",i:" << i << ",numStr:" << numStr << ",ch:" << ch << endl;
            if (!numStr.empty())
            {
                stackStrs.push(numStr);
            }

            string itemStr(1, ch);
            stackStrs.push(itemStr);
            start = i + 1;
            cout << "push numStr:" << numStr << " ,itemStr:" << itemStr << endl;
        }
    }

    if (stackStrs.size() == 1)
    {
        return stoi(stackStrs.top()) * sign;
    }

    // 要先将栈内数据翻转
    stack<string> stackTmp;
    while (!stackStrs.empty())
    {
        stackTmp.push(stackStrs.top());
        stackStrs.pop();
    }

    int size = stackTmp.size();
    int res = stoi(stackTmp.top()) * sign;
    stackTmp.pop();

    // 栈不能获取到第i个位置元素数据，只能用while递归
    while (!stackTmp.empty())
    {
        // 取出栈顶元素，先取出运算符，再取出数字
        string operateStr = stackTmp.top();
        stackTmp.pop();

        string numStr = stackTmp.top();
        stackTmp.pop();

        if (operateStr == "+")
        {
            res += stoi(numStr);
        }
        else
        {
            res -= stoi(numStr);
        }
    }
    return res;
}

/**
 * 1、审题：输入一个字符串，字符串由数字，加减符号，左右括号组成，要求计算表达式的结果
 * 2、解题：
 * - 主要处理括号与加减符号的问题
 * - 遍历整个字符串，使用一个栈保存当前数字运算使用到的加减符号，栈中先默认保存加符号1
 * - 后面继续遍历，遇到加减符号，需要将前面的运算符号sign与当前符号进行相乘，得出当前数组使用到的加减符号
 * - 遇到左括号，将当前的sign入栈，随后括号内的运算符，都使用栈顶的运算符sign，遇到右括号，出栈
 * - 遇到数字，就一直办理，直到遇到非数字
 * - 遇到空格，直接跳过
 */
int calculate(string s)
{
    int len = s.size();
    if (len == 0)
    {
        return 0;
    }
    int i = 0;
    stack<int> stackSign;
    stackSign.push(1);
    int sign = 1;
    int res = 0;

    while (i < len)
    {
        char ch = s[i];
        if (ch == ' ')
        {
            i++;
            continue;
        }
        else if (ch == '+')
        {
            sign = stackSign.top();
            i++;
        }
        else if (ch == '-')
        {
            sign = -stackSign.top();
            i++;
        }
        else if (ch == '(')
        {
            stackSign.push(sign);
            i++;
        }
        else if (ch == ')')
        {
            stackSign.pop();
            i++;
        }
        else
        {
            // 取出数字
            int num = 0;
            while (i < len && isdigit(s[i]))
            { // 是否是数字
                num = num * 10 + (s[i] - '0');
                i++;
            }
            res += sign * num;
        }
    }

    return res;
}

/**
 * 给你一个字符串表达式 s ，请你实现一个基本计算器来计算并返回它的值。
注意:不允许使用任何将字符串作为数学表达式计算的内置函数，比如 eval() 。

示例 1：
输入：s = "1 + 1"
输出：2

示例 2：
输入：s = " 2-1 + 2 "
输出：3

示例 3：
输入：s = "(1+(4+5+2)-3)+(6+8)"
输出：23

提示：
1 <= s.length <= 3 * 105
s 由数字、'+'、'-'、'('、')'、和 ' ' 组成
s 表示一个有效的表达式
'+' 不能用作一元运算(例如， "+1" 和 "+(2 + 3)" 无效)
'-' 可以用作一元运算(即 "-1" 和 "-(2 + 3)" 是有效的)
输入中不存在两个连续的操作符
每个数字和运行的计算将适合于一个有符号的 32位 整数
 */
int main(int argc, char const *argv[])
{
    // int res = calculate(" 1 + 1 ");
    // int res = calculate(" 2-1 + 2 ");
    int res = calculate("(1+(4+5+2)-3)+(6+8)");
    // int res = calculate("1-(     -2)");
    // int res = calculate("- (3 + (4 + 5))");

    cout << "res:" << res << endl;
    return 0;
}
