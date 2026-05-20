#include<bits/stdc++.h>
using namespace std;

string input;
int pos;
int length;

// Forward declarations
bool parseExp();
bool parseTerm();
bool parseFactor();

// Skip whitespace
void skipWhitespace() {
    while (pos < length && isspace(input[pos])) {
        pos++;
    }
}

// Parse ID: a|b|c|d|e
bool parseID() {
    skipWhitespace();
    if (pos < length && (input[pos] == 'a' || input[pos] == 'b' || 
                         input[pos] == 'c' || input[pos] == 'd' || 
                         input[pos] == 'e')) {
        pos++;
        return true;
    }
    return false;
}

// Parse NUM: 0|1|2|...|9
bool parseNUM() {
    skipWhitespace();
    if (pos < length && isdigit(input[pos])) {
        pos++;
        return true;
    }
    return false;
}

// Parse Factor: ( Exp ) | ID | NUM
bool parseFactor() {
    skipWhitespace();
    
    // Try ( Exp )
    if (pos < length && input[pos] == '(') {
        pos++; // consume '('
        if (parseExp()) {
            skipWhitespace();
            if (pos < length && input[pos] == ')') {
                pos++; // consume ')'
                return true;
            }
        }
        return false;
    }
    
    // Try ID
    int savePos = pos;
    if (parseID()) {
        return true;
    }
    pos = savePos;
    
    // Try NUM
    if (parseNUM()) {
        return true;
    }
    
    return false;
}

// Parse Term: Factor * Factor | Factor / Factor | Factor
bool parseTerm() {
    if (!parseFactor()) {
        return false;
    }
    
    skipWhitespace();
    
    // Check for * or /
    if (pos < length && (input[pos] == '*' || input[pos] == '/')) {
        pos++; // consume operator
        if (parseFactor()) {
            return true;
        }
        return false;
    }
    
    // Just Factor (no operator)
    return true;
}

// Parse Exp: Term + Term | Term - Term | Term
bool parseExp() {
    if (!parseTerm()) {
        return false;
    }
    
    skipWhitespace();
    
    // Check for + or -
    if (pos < length && (input[pos] == '+' || input[pos] == '-')) {
        pos++; // consume operator
        if (parseTerm()) {
            return true;
        }
        return false;
    }
    
    // Just Term (no operator)
    return true;
}

// Main parsing function
bool parse(const string& str) {
    input = str;
    pos = 0;
    length = str.length();
    
    bool result = parseExp();
    skipWhitespace();
    
    // Check if we consumed all input
    return result && pos == length;
}

int main() {
    string testInput;
    
    cout << "Enter 'quit' to exit" << endl << endl;
    
    while (true) {
        cout << "Enter expression: ";
        getline(cin, testInput);
        
        if (testInput == "quit") {
            break;
        }
        
        if (testInput.empty()) {
            continue;
        }
        
        if (parse(testInput)) {
            cout << "Result: Accepted" << endl;
        } else {
            cout << "Result: Rejected" << endl;
        }
        cout << endl;
    }
    
    return 0;
}