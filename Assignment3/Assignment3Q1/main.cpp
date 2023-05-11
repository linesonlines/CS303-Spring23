#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
#include <ctype.h>

using namespace std;

// Returns character count
int count_char(string s, char c) {
  int count = 0;
  for (int i = 0; i < s.size(); i++)
    if (s[i] == c) count++;

  return count;
}

// Returns the precedence 
int precedence(char op) {
    if (op == '/' || op == '*' || op == '%'){
        return 2;
    } else if (op == '+' || op == '-') {
        return 1;
    } else {
        return 0;
    }
}

// Returns true if character is an operator
bool is_operator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%');
}

// Checks for balanced number of open/closed parentheses
bool is_balanced(string exp) {
    int count_open_p = count_char(exp, '(');
    int count_close_p = count_char(exp, ')');
    return count_open_p == count_close_p;
}

// Converts infix expression to postfix
string infix_to_postfix(string exp) {

    // Initialize the stack
    stack<char> my_stack;

    // Initialize postfix expression
    string postfix_exp = "";

    // Iterate through the infix expression
    for (int i = 0; i < exp.length(); i++) {
        char ch = exp[i];

        // If the character is an alphanumeric character, append it to the postfix expression
        if (isalnum(ch)) {
            postfix_exp += ch;
        } 
        // If the character is an operator, pop all operators 
        // from the stack with higher or equal precedence 
        // and add them to the postfix expression
        else if (is_operator(ch)) {
            while (!my_stack.empty() && my_stack.top() != '(' && precedence(ch) <= precedence(my_stack.top())) {
                postfix_exp += my_stack.top();
                my_stack.pop();
            }
            // Push the current operator onto the stack
            my_stack.push(ch);
        }
        // If the character is a (, push it onto the stack
        else if (ch == '(') {
            my_stack.push(ch);
        } 
        // If the character is a ), pop operators from the stack 
        // and add them to postfix_exp until a matching ( is found
        else if (ch == ')') {
            while (!my_stack.empty() && my_stack.top() != '(') {
                postfix_exp += my_stack.top();
                my_stack.pop();
            }
            if (!my_stack.empty() && my_stack.top() == '(') {
                my_stack.pop();
            }
        }
    }

    // Pop any remaining operators from the stack 
    // and add them to postfix_exp
    while (!my_stack.empty()) {
        postfix_exp += my_stack.top();
        my_stack.pop();
    }

    // Returns final postfix expression
    return postfix_exp;
}

int main() {
    cout << "Assignment 3, Question 1" << endl;
    cout << "Expression Manager - Infix to Postfix" << endl;
    string infix_exp = "(1 + 3) * {6 - 4} + 5";
    cout << "Infix expression: " << infix_exp << endl;
    replace( infix_exp.begin(), infix_exp.end(), '{', '(');
    replace( infix_exp.begin(), infix_exp.end(), '[', '(');
    replace( infix_exp.begin(), infix_exp.end(), '}', ')');
    replace( infix_exp.begin(), infix_exp.end(), ']', ')');
    if (is_balanced(infix_exp)){
        string postfix_exp = infix_to_postfix(infix_exp);
        cout << "Postfix expression: " << postfix_exp << endl;
    } else {
        cout << "Your expression is not balanced, so the conversion cannot occur." << endl;
    }
    return 0;
}