/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */

// @lc code=start
#include <string>
#include <stack>
using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> stc;
        for (char c : s)
        {
            if (c == '(' || c == '{' || c == '[')
            {
                stc.push(c);
            }
            else
            {
                // If stack is empty but we have a closing bracket, it's invalid
                if (stc.empty())
                    return false;

                // Check if current closing bracket matches the top of the stack
                if (c == ')' && stc.top() == '(')
                {
                    stc.pop();
                }
                else if (c == '}' && stc.top() == '{')
                {
                    stc.pop();
                }
                else if (c == ']' && stc.top() == '[')
                {
                    stc.pop();
                }
                else
                {
                    // Mismatch found (e.g., top is '(' but current is ']')
                    return false;
                }
            }
        }
        // If stack is empty, all opened brackets were successfully closed
        return stc.empty();
    }
};
// @lc code=end
