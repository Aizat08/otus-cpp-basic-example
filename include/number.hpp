#pragma once

#include <string>

#include "astnode.hpp"

class Number : public ASTNode {
  public:
    Number(int val) : ASTNode(std::to_string(val)) {}

};

class Variable : public ASTNode {
  public:
    Variable(std::string var) : ASTNode(var) {}
};

class Mul : public ASTNode {
  public:
    Mul(ASTNode* lhs_, ASTNode* rhs_) : ASTNode("*", lhs_, rhs_) {}
};

class Div : public ASTNode {
  public:
    Div(ASTNode* lhs_, ASTNode* rhs_) : ASTNode("/", lhs_, rhs_) {}
};

class Add : public ASTNode {
  public:
    Add(ASTNode* lhs_, ASTNode* rhs_) : ASTNode("+", lhs_, rhs_) {}
};

class Sub : public ASTNode {
  public:
    Sub(ASTNode* lhs_, ASTNode* rhs_) : ASTNode("-", lhs_, rhs_) {}
};

