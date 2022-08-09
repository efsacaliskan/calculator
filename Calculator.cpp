//============================================================================
// Name        : main.cpp

#include "Calculator.h"

#include <string>
#include <iostream>
#include <sstream>

Calculator::Calculator(string infixExpression) {
    this->infixExpression = infixExpression;
    this->postfixExpression = "";
    this->stack = new Stack();

    istringstream iss(infixExpression);
    string token = "";
    iss >> token;
   
    while (token.compare(";") != 0) {
        StackItem* item = new StackItem(token);
        if (!item->isOperator) {
            postfixExpression += item->toString() + " ";
        }     
        else {
            if (stack->isEmpty()) {
                stack->push(item);
            }
            else {
                if (item->op == OPERATOR_LEFTPAR) {
                    stack->push(item);
                }
                else if (item->op == OPERATOR_RIGHTPAR) {
                    while (!(stack->top()->op == 0)) {
           
                            postfixExpression +=  stack->top()->toString() + " ";
                            StackItem* popped = stack->pop();
                            delete popped;                 
                    }
                    StackItem* popped = stack->pop();
                    delete popped;
                }
                else {
                    if (item->op == OPERATOR_PLUS || item->op == OPERATOR_MINUS) {
                        while (!stack->isEmpty() && stack->top()->op != OPERATOR_LEFTPAR) {
                            postfixExpression += stack->top()->toString() + " ";
                            StackItem* popped = stack->pop();
                            delete popped;
                        }
                    }
                    else {
                        while (!stack->isEmpty() && (stack->top()->op == OPERATOR_DIVISION || stack->top()->op == OPERATOR_MULTIPLICATION)) {
                            postfixExpression += stack->top()->toString() + " ";
                            StackItem* popped = stack->pop();
                            delete popped;
                        }
                    }
                    stack->push(item);
                }     
            }
        }
        iss >> token;
     }

    while (!stack->isEmpty()) {
        postfixExpression += stack->top()->toString() + " ";
        StackItem* popped = stack->pop();
        delete popped;
    }   
    postfixExpression += ";";      
}

 Calculator::~Calculator() {
	 delete this->stack;
 }
 string Calculator::getPostfix() {
	 return postfixExpression;
 }
 int Calculator::calculate() {

     istringstream iss(postfixExpression);
     string s = "";
     iss >> s;

     while (s != "") {
         
         if (s == ";") { 
             break; 
         } 

         StackItem* calculated = new StackItem(s);

         if (calculated->isOperator) {
             int item = stack->pop()->n;
             int seconditem = stack->pop()->n;

             if (s.compare("+") == 0) { 
                 stack->push(new StackItem(false, (seconditem + item))); 
             }
             else if (s.compare("-") == 0) { 
                 stack->push(new StackItem(false, (seconditem - item))); 
             }
             else if (s.compare("*") == 0) {
                 stack->push(new StackItem(false, (seconditem * item))); 
             }
             else if (s.compare("/") == 0) { 
                 stack->push(new StackItem(false, (seconditem / item))); 
             }
         }
         else {
             stack->push(calculated);
         }
         iss >> s;
     }
     return stack->pop()->n;
 }