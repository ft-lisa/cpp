#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <string>
#include <cstring>
#include <climits>
#include <cstdlib> 
#include <iomanip>
#include <vector>
#include <list>
#include <cmath>
#include <stack>

int check_expression(char* expr);
std::stack<int> fill_stack(char* str);

#endif
