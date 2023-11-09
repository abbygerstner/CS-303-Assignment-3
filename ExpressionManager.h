#ifndef EXPRESSIONMANAGER_H
#define EXPRESSIONMANAGER_H

#include <string>

class ExpressionManager {
public:
    ExpressionManager();
    ~ExpressionManager();

    bool checkBalancedParentheses(const std::string& expression);
    std::string infixToPostfix(const std::string& infix);
};

#endif