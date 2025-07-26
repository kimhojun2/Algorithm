#include<iostream>
#include<stack>
#include<string>
using namespace std;

void printStk(stack<char> &stk)
{
    while (!stk.empty())
    {
        cout << stk.top();
        stk.pop();
    }
}
int main()
{
    stack<char>stk;
    string str;
    getline(cin, str);
    bool tag = false;
    for (char ch : str)
    {
        if (ch == '<')
        {
            printStk(stk);
            tag = true;
            cout << ch;
        }
        else if (ch == '>')
        {
            tag = false;
            cout << ch;
        }
        else if (tag)
        {
            cout << ch;
        }
        else
        {
            if (ch == ' ')
            {
                printStk(stk);
                cout << ch;
            }
            else
            {
                stk.push(ch);
            }

        }
    }
    printStk(stk);
    cout<<'\n';
    return 0;
}