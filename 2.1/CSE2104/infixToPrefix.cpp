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

int expEvaluation(string prefix)
{
    stack<int> op;

    for(int i = prefix.size() - 1; i >= 0; i--)
    {
        char symbol = prefix[i];

        if(symbol >= '0' && symbol <= '9')
        {
            op.push(symbol - '0');
        }
        else if(symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/')
        {
            int op1 = op.top();
            op.pop();
            int op2 = op.top();
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

string inToPre(string input)
{
    string prefix = "";
    stack<char> s;
    stack<string> value;

    for(int i = 0; i < input.size(); i++)
    {
        char symbol = input[i];
        if(symbol >= '0' && symbol <= '9')
        {
            string operand(1, symbol);
            value.push(operand);
        }
        else if(symbol == ')')
        {
            s.push(symbol);
        }
        else if(symbol == '(')
        {
            while(s.top() != ')')
            {
                string op1 = value.top();
                value.pop();
                string op2 = value.top();
                value.pop();

                string temp = s.top() + op2 + op1;
                value.push(temp);

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
                string op1 = value.top();
                value.pop();
                string op2 = value.top();
                value.pop();

                string temp = s.top() + op2 + op1;
                value.push(temp);

                s.pop();
            }
            s.push(symbol);
        }
    }
    while(!s.empty())
    {
        string op1 = value.top();
        value.pop();
        string op2 = value.top();
        value.pop();

        string temp = s.top() + op2 + op1;
        value.push(temp);

        s.pop();
    }

    prefix = value.top();
    return prefix;
}

int main()
{
    string input, prefix = "";

    cout << "Enter infix expression: ";
    cin >> input;

    prefix = inToPre(input);

    cout << "Prefix expression: " << prefix << endl;

    int value = expEvaluation(prefix);
    cout << "Value: " << value << endl;

    return 0;
}
