#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <string>
#include <cstring>
#include <climits>
#include <cstdlib> 
#include <iomanip>
#include <vector>
#include <deque>
#include <cmath>
#include <stack>

#define ERR_ARG "./RPN [expression]"
#define ERR_CHAR "authorized character : 0-9, +, -, /, *"
#define ERR_SPACE "there must be a space between each character"
#define ERR_NUM "0 >= num <= 9"
#define ERR_POLISH "error in polish reverse notation"

int	check_expression(int ar, char **l);
void fill_vector_deque(char** sequence, std::vector<int>& vector, std::deque<int>& deque);
int sort_vector_stage1(std::vector<int>& vector);
int sort_vector_stage2(std::vector<int>& vector, int size);
char **split(const char *str, char sep);




#endif