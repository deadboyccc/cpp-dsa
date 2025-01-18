#include <stack>
#include <string>
#include <iostream>
int isOperand(char x)
{
    if (x == '+' || x == '-' || x == '*' || x == '/')
        return 0;
    return 1;
}
int pre(char x)
{
    if (x == '+' || x == '-')
        return 1;
    else if (x = '*' || x == '/')
        return 2;
    return 0;
}
std::string convert(std::string infix)
{
    std::stack<char> st;
    std::string postfix;
    for (char c : infix)
    {
        if (isOperand(c))
            postfix += c;
        else
        {
            while (!st.empty() && pre(c) <= pre(st.top()))
            {
                postfix += st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    while (!st.empty())
    {
        postfix += st.top();
        st.pop();
    }
    return postfix;
}
int evaluate(std::string postfix)
{
    std::stack<int> stk;
    for (char c : postfix)
    {
        if (isOperand(c))
        {
            stk.push(c - '0');
        }
        else
        {
            int a = stk.top();
            stk.pop();
            int b = stk.top();
            stk.pop();
            int r;
            // b*a
            switch (c)
            {
            case '+':
                r = b + a;
                stk.push(r);
                break;
            case '-':
                r = b - a;
                stk.push(r);
                break;
            case '*':
                r = b * a;
                stk.push(r);
                break;
            case '/':
                r = b / a;
                stk.push(r);
                break;
            default:
                break;
            }
        }
    }
    return stk.top();
}
int main(int argc, char const *argv[])
{
    // std::string test = "a+b*c";
    // std::string post;
    // post = convert(test);
    // std::cout << post;
    std::string input = "234*+82/-";
    int answer = evaluate(input);
    std::cout << answer << std::endl;

    return 0;
}
