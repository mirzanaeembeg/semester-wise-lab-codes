#include<bits/stdc++.h>
using namespace std;

int precedence(char ch)
{
    if(ch == '^')
    {
        return 5;
    }
    else if(ch == '*' || ch == '/')
    {
        return 4;
    }
    else if(ch == '+' || ch == '-')
    {
        return 3;
    }
    else
    {
        return -1;
    }
}

int expEvaluation(string postfix)
{
    stack<int> op;

    for(int i = 0; i < postfix.size(); i++)
    {
        char symbol = postfix[i];

        if(symbol >= '0' && symbol <= '9')
        {
            op.push(symbol - '0');
        }
        else if(symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/')
        {
            int op2 = op.top();
            op.pop();
            int op1 = op.top();
            op.pop();

            int value;
            switch(symbol)
            {
                case '+':
                    value = op1 + op2;
                    break;
                case '-':
                    value = op1 - op2;
                    break;
                case '*':
                    value = op1 * op2;
                    break;
                case '/':
                    value = op1 / op2;
                    break;
            }

            op.push(value);
        }
    }

    return op.top();
}

string inToPost(string input)
{
    string postfix = "";
    stack<char> s;

    for(int i = 0; i < input.size(); i++)
    {
        char symbol = input[i];
        if(symbol >= '0' && symbol <= '9')
        {
            postfix = postfix + symbol;
        }
        else if(symbol == '(')
        {
            s.push(symbol);
        }
        else if(symbol == ')')
        {
            while(s.top() != '(')
            {
                postfix = postfix + s.top();
                s.pop();
            }
            if(!s.empty())
            {
                s.pop();
            }
        }
        else if(symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/')
        {
            while(!s.empty() && precedence(symbol) <= precedence(s.top()))
            {
                postfix = postfix + s.top();
                s.pop();
            }
            s.push(symbol);
        }
    }
    while(!s.empty())
    {
        postfix = postfix + s.top();
        s.pop();
    }
    return postfix;
}

int main()
{
    string input, postfix = "";

    cout << "Enter infix expression: ";
    cin >> input;

    postfix = inToPost(input);

    cout << "Postfix expression: " << postfix << endl;

    int value = expEvaluation(postfix);
    cout << "Value: "<< value << endl;

    return 0;
}
