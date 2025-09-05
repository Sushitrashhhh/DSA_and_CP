#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isBalanced(char opening, char closing) {
    return (opening == '(' && closing == ')') ||
           (opening == '{' && closing == '}') ||
           (opening == '[' && closing == ']');
}

bool areParenthesesBalanced(const string& expr) {
    stack<char> s;
    for (char ch : expr) {
        if (ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            if (s.empty() || !isBalanced(s.top(), ch)) {
                return false;
            }
            s.pop();
        }
    }
    return s.empty();
}