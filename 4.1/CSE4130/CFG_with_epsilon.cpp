#include<bits/stdc++.h>
using namespace std;

// =============================================================================
// PART 1: CFG Implementation A -> aXd, X -> bbX | bcX | epsilon
// =============================================================================

class CFG_Parser1 {
private:
    string input;
    int pos;
    int length;
    
    void skipWhitespace() {
        while (pos < length && isspace(input[pos])) {
            pos++;
        }
    }
    
    bool parseX() {
        cout << "Parsing X at position " << pos << endl;
        
        // X -> bbX (Production 1)
        if (pos + 1 < length && input[pos] == 'b' && input[pos + 1] == 'b') {
            cout << "  Found 'bb', applying X -> bbX" << endl;
            pos += 2; // consume 'bb'
            return parseX(); // recursive call for X
        }
        
        // X -> bcX (Production 2)
        else if (pos + 1 < length && input[pos] == 'b' && input[pos + 1] == 'c') {
            cout << "  Found 'bc', applying X -> bcX" << endl;
            pos += 2; // consume 'bc'
            return parseX(); // recursive call for X
        }
        
        // X -> epsilon (Epsilon production)
        else {
            cout << "  Applying X -> epsilon" << endl;
            // Don't consume any input for epsilon
            return true;
        }
    }
    
    bool parseA() {
        cout << "Parsing A (Start Symbol)" << endl;
        
        // A -> aXd
        if (pos < length && input[pos] == 'a') {
            cout << "Found 'a', expecting X then 'd'" << endl;
            pos++; // consume 'a'
            
            if (parseX()) {
                if (pos < length && input[pos] == 'd') {
                    cout << "Found 'd', production A -> aXd complete" << endl;
                    pos++; // consume 'd'
                    return true;
                } else {
                    cout << "Error: Expected 'd' after X" << endl;
                    return false;
                }
            }
            return false;
        } else {
            cout << "Error: Expected 'a' at start" << endl;
            return false;
        }
    }
    
public:
    bool parse(const string& str) {
        input = str;
        pos = 0;
        length = str.length();
        
        cout << "\n=== Parsing: \"" << input << "\" ===" << endl;
        
        bool result = parseA();
        
        // Check if we consumed all input
        if (result && pos == length) {
            cout << "SUCCESS: String accepted!" << endl;
            return true;
        } else if (result) {
            cout << "FAILED: Extra characters remain: " << input.substr(pos) << endl;
            return false;
        } else {
            cout << "FAILED: String rejected!" << endl;
            return false;
        }
    }
};

// =============================================================================
// PART 2: Stack-based PDA Implementation for the same grammar
// =============================================================================

class PDA_Parser {
private:
    stack<char> pdaStack;
    string input;
    int pos;
    
    void printStack() {
        cout << "Stack: ";
        stack<char> temp = pdaStack;
        vector<char> elements;
        while (!temp.empty()) {
            elements.push_back(temp.top());
            temp.pop();
        }
        reverse(elements.begin(), elements.end());
        for (char c : elements) {
            cout << c << " ";
        }
        cout << endl;
    }
    
public:
    bool parse(const string& str) {
        input = str;
        pos = 0;
        
        // Clear and initialize stack
        while (!pdaStack.empty()) pdaStack.pop();
        pdaStack.push('$'); // Bottom of stack marker
        pdaStack.push('A'); // Start symbol
        
        cout << "\n=== PDA Parsing: \"" << input << "\" ===" << endl;
        cout << "Initial state:" << endl;
        printStack();
        
        while (!pdaStack.empty() && pdaStack.top() != '$') {
            char top = pdaStack.top();
            pdaStack.pop();
            
            cout << "\nProcessing: " << top << " (input position: " << pos << ")" << endl;
            
            if (top == 'A') {
                // A -> aXd
                cout << "Applying A -> aXd" << endl;
                pdaStack.push('d');
                pdaStack.push('X');
                pdaStack.push('a');
            }
            else if (top == 'X') {
                // Look ahead to decide which production to use
                if (pos + 1 < input.length() && input[pos] == 'b' && input[pos + 1] == 'b') {
                    // X -> bbX
                    cout << "Applying X -> bbX" << endl;
                    pdaStack.push('X');
                    pdaStack.push('b');
                    pdaStack.push('b');
                }
                else if (pos + 1 < input.length() && input[pos] == 'b' && input[pos + 1] == 'c') {
                    // X -> bcX
                    cout << "Applying X -> bcX" << endl;
                    pdaStack.push('X');
                    pdaStack.push('c');
                    pdaStack.push('b');
                }
                else {
                    // X -> epsilon
                    cout << "Applying X -> epsilon (nothing pushed)" << endl;
                    // Don't push anything for epsilon
                }
            }
            else {
                // Terminal symbol - must match input
                if (pos < input.length() && input[pos] == top) {
                    cout << "Matched terminal: " << top << endl;
                    pos++;
                } else {
                    cout << "Error: Expected '" << top << "' but found '";
                    if (pos < input.length()) {
                        cout << input[pos];
                    } else {
                        cout << "EOF";
                    }
                    cout << "'" << endl;
                    return false;
                }
            }
            
            printStack();
        }
        
        // Check if we consumed all input
        if (pos == input.length()) {
            cout << "SUCCESS: String accepted by PDA!" << endl;
            return true;
        } else {
            cout << "FAILED: Extra input remains: " << input.substr(pos) << endl;
            return false;
        }
    }
};

// =============================================================================
// PART 3: Arithmetic Expression Parser (from previous assignment)
// =============================================================================

class ArithmeticParser {
private:
    string input;
    int pos;
    int length;
    
    void skipWhitespace() {
        while (pos < length && isspace(input[pos])) {
            pos++;
        }
    }
    
    bool parseID() {
        skipWhitespace();
        if (pos < length && (input[pos] >= 'a' && input[pos] <= 'e')) {
            pos++;
            return true;
        }
        return false;
    }
    
    bool parseNUM() {
        skipWhitespace();
        if (pos < length && isdigit(input[pos])) {
            pos++;
            return true;
        }
        return false;
    }
    
    bool parseFactor() {
        skipWhitespace();
        
        // ( Exp )
        if (pos < length && input[pos] == '(') {
            pos++;
            if (parseExp()) {
                skipWhitespace();
                if (pos < length && input[pos] == ')') {
                    pos++;
                    return true;
                }
            }
            return false;
        }
        
        // Try ID or NUM
        int savePos = pos;
        if (parseID()) return true;
        pos = savePos;
        if (parseNUM()) return true;
        
        return false;
    }
    
    bool parseTerm() {
        if (!parseFactor()) return false;
        
        skipWhitespace();
        if (pos < length && (input[pos] == '*' || input[pos] == '/')) {
            pos++;
            if (parseFactor()) return true;
            return false;
        }
        return true;
    }
    
    bool parseExp() {
        if (!parseTerm()) return false;
        
        skipWhitespace();
        if (pos < length && (input[pos] == '+' || input[pos] == '-')) {
            pos++;
            if (parseTerm()) return true;
            return false;
        }
        return true;
    }
    
public:
    bool parse(const string& str) {
        input = str;
        pos = 0;
        length = str.length();
        
        bool result = parseExp();
        skipWhitespace();
        return result && pos == length;
    }
};

// =============================================================================
// MAIN FUNCTION - Testing Both Implementations
// =============================================================================

int main() {
    cout << "CFG PARSER IMPLEMENTATIONS WITH EPSILON HANDLING" << endl;
    cout << "=======================================================" << endl;
    
    // Test CFG 1: A -> aXd, X -> bbX | bcX | epsilon
    cout << "\nGRAMMAR 1: A -> aXd, X -> bbX | bcX | epsilon" << endl;
    cout << "Test cases for recursive descent parser:" << endl;
    
    CFG_Parser1 parser1;
    vector<string> testCases1 = {"ad", "abbd", "abcd", "abbbbcd", "abcbbcbbd", "abc", "abd", "aabbdd"};
    
    for (const string& test : testCases1) {
        parser1.parse(test);
        cout << endl;
    }
    
    cout << "\n" << string(50, '=') << endl;
    cout << "SAME GRAMMAR using PDA (Stack-based approach):" << endl;
    
    PDA_Parser pdaParser;
    for (const string& test : testCases1) {
        pdaParser.parse(test);
        cout << endl;
    }
    
    // Test Arithmetic Expression Parser
    cout << "\n" << string(50, '=') << endl;
    cout << "ARITHMETIC EXPRESSION PARSER:" << endl;
    cout << "<Exp> -> <Term> + <Term> | <Term> - <Term> | <Term>" << endl;
    cout << "<Term> -> <Factor> * <Factor> | <Factor> / <Factor> | <Factor>" << endl;
    cout << "<Factor> -> ( <Exp> ) | ID | NUM" << endl;
    
    ArithmeticParser arithParser;
    vector<string> arithTests = {"3 * (a - 2)", "a +", "9 - d", "3 4", "a", "(b + c) * d"};
    
    for (const string& test : arithTests) {
        cout << "\nTesting: \"" << test << "\" -> ";
        if (arithParser.parse(test)) {
            cout << "Accepted";
        } else {
            cout << "Rejected";
        }
    }
    
    cout << "\n\nInteractive Mode - Test your own strings!" << endl;
    cout << "Choose parser (1=CFG1, 2=PDA, 3=Arithmetic, q=quit): ";
    
    string choice, testString;
    while (cin >> choice && choice != "q") {
        cout << "Enter test string: ";
        cin.ignore();
        getline(cin, testString);
        
        if (choice == "1") {
            parser1.parse(testString);
        } else if (choice == "2") {
            pdaParser.parse(testString);
        } else if (choice == "3") {
            cout << (arithParser.parse(testString) ? "Accepted" : "Rejected") << endl;
        }
        
        cout << "\nChoose parser (1=CFG1, 2=PDA, 3=Arithmetic, q=quit): ";
    }
    
    return 0;
}