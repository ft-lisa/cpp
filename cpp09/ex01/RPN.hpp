#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <string>
#include <cstring>
#include <climits>
#include <cstdlib> 
#include <iomanip>
#include <list>
#include <cmath>
#include <stack>

#define ERR_ARG "./RPN [expression]"
#define ERR_CHAR "authorized character : 0-9, +, -, /, *"
#define ERR_SPACE "there must be a space between each character"
#define ERR_NUM "0 >= num <= 9"
#define ERR_POLISH "error in polish reverse notation"
#define ERR_DIVZ "division by 0"


int check_expression(char* expr);
std::stack<int> fill_stack(char* str);
int calculated(char* str);

#endif
