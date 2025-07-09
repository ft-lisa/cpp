#ifndef PMERGEME_HPP
# define PMERGEME_HPP

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

#define ERR_ARG "./RPN [expression]"
#define ERR_CHAR "authorized character : 0-9, +, -, /, *"
#define ERR_SPACE "there must be a space between each character"
#define ERR_NUM "0 >= num <= 9"
#define ERR_POLISH "error in polish reverse notation"

int	check_expression(int ar, char **l);
void fill_list_deque(char** sequence, std::list<int>& list, std::deque<int>& deque);

#endif