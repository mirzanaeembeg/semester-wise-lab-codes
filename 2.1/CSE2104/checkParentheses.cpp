#include <bits/stdc++.h>
using namespace std;

void checkParentheses(string exp) {
    stack<char> s;
    
    for (int i = 0; i < exp.size(); i++) {
        char c = exp[i];
        if (c == '(' || c == '[' || c == '{') {
            s.push(c);
        } else if (c == ')' || c == ']' || c == '}') {
            if (s.empty()) {
                cout << "Parentheses are not balanced." << endl;
                return;
            }
            
            char top = s.top();
            s.pop();
            
            if ((c == ')' && top != '(') ||
                (c == ']' && top != '[') ||
                (c == '}' && top != '{')) {
                cout << "Parentheses are not balanced." << endl;
                return;
            }
        }
    }
    
    if (s.empty()) {
        cout << "Parentheses are balanced." << endl;
    } else {
        cout << "Parentheses are not balanced." << endl;
    }
}

int main() {
    string expression;
    cout << "Enter an expression: ";
    cin >> expression;
    checkParentheses(expression);
    return 0;
}
