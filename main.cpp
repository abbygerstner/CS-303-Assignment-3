#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
#include <cctype> // Include the ctype library for character checking

class ExpressionManager {
public:
    ExpressionManager() {}
    ~ExpressionManager() {}

    // Function to check balanced parentheses in an expression
    bool checkBalancedParentheses(const std::string& expression);

    // Function to convert infix expression to postfix
    std::string infixToPostfix(const std::string& infix);

    // Function to check if two characters are matching parentheses
    bool areMatching(char open, char close);
};

// Function to check balanced parentheses in an expression
bool ExpressionManager::checkBalancedParentheses(const std::string& expression) {
    std::stack<char> s;

    for (char c : expression) {
        if (c == '(' || c == '{' || c == '[') {
            s.push(c);
        } else if (c == ')' || c == '}' || c == ']') {
            if (s.empty() || !areMatching(s.top(), c)) {
                return false; // Unbalanced parentheses
            }
            s.pop();
        }
    }

    return s.empty();
}

// Function to convert infix expression to postfix
std::string ExpressionManager::infixToPostfix(const std::string& infix) {
    std::stack<char> operators;
    std::string postfix = "";
    std::unordered_map<char, int> precedence = {{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}, {'%', 2}};

    for (char c : infix) {
        if (isalnum(c)) {
            postfix += c; // Add operands to the postfix expression
        } else if (c == ' ' || c == '\t') {
            continue; // Ignore spaces and tabs
        } else if (c == '(') {
            operators.push(c);
        } else if (c == ')') {
            while (!operators.empty() && operators.top() != '(') {
                postfix += operators.top();
                operators.pop();
            }
            if (!operators.empty() && operators.top() == '(') {
                operators.pop();
            }
        } else {
            // Operator encountered
            while (!operators.empty() && operators.top() != '(' &&
                   precedence[operators.top()] >= precedence[c]) {
                postfix += operators.top();
                operators.pop();
            }
            operators.push(c);
        }
    }

    while (!operators.empty()) {
        postfix += operators.top();
        operators.pop();
    }

    return postfix;
}

// Function to check if two characters are matching parentheses
bool ExpressionManager::areMatching(char open, char close) {
    return ((open == '(' && close == ')') || (open == '{' && close == '}') || (open == '[' && close == ']'));
}

int main() {
    ExpressionManager manager;
    std::string infix;
    std::cout << "Enter an infix expression: ";
    std::getline(std::cin, infix);

    // Input validation to check for extra characters
    for (char c : infix) {
        if (!(std::isdigit(c) || c == '+' || c == '-' || c == '*' || c == '/' || c == '%' ||
              c == '(' || c == ')' || c == '{' || c == '}' || c == '[' || c == ']')) {
            std::cout << "Invalid response. Input should consist of only numbers and operators." << std::endl;
            return 1; // Return an error code to indicate failure
        }
    }

    if (manager.checkBalancedParentheses(infix)) {
        std::string postfix = manager.infixToPostfix(infix);
        std::cout << "Postfix expression: " << postfix << std::endl;
        return 0; // Return success (0) here
    } else {
        std::cout << "Invalid expression. Unbalanced parentheses." << std::endl;
        return 1; // Return an error code (non-zero) to indicate failure
    }
}
