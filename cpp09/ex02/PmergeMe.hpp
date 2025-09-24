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
#include <sys/time.h>

#define ERR_ARG "Error \n./RPN [expression]"
#define ERR_DOUBLE "Error \nno duplicates"
#define ERR_INT "Error \nOnly numbers"

void fill_vector_deque(char** sequence, std::vector<int>& vector, std::deque<int>& deque);
long long jacobsthal_next(bool reset);
template<typename container>

void movePreviousBlockAfterIt(container &lst, typename container::iterator it, int n)
{
        if (lst.empty() || n <= 0) return;
	typename container::iterator it2 = it;
	int size = n;
        while(n > 0)
        {
                std::advance(it2, -size); 
                std::iter_swap(it, it2);
                n--;
                it--;
                it2 = it;
                
        }
}
template<typename container>
void copy_in_list(container& main, container& vector)
{
	int i = 0;
	for (typename container::iterator it = main.begin(); it != main.end(); it++, i++)
	{
		vector[i] = *it;
	}
}

template <typename container>
void printvector(const container& lst, const std::string& label) {
    std::cout << label << ": [ ";
    for (typename container::const_iterator it = lst.begin(); it != lst.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "]" << std::endl;
}

template<typename container>
void insert_in_main(container& main, container& pend, long long n, int size)
{
	typename container::iterator it = main.begin();
	it = it + size - 1;
	int i = ((n - 1) * size) - 1 ;
	int after = i;
	static long long end;
	bool sup = 0;
	if (n == 3)
		end = 0;
	if (i + 1 >= (long long)pend.size())
	{
		sup = 1;
		i = pend.size() - 1;
	}
	while(i > end || (end == 0 && i == 0) ) 
	{
		if(pend[i] < *it || it + 1 == main.end())
		{
			if (it + 1 == main.end() && !(pend[i] < *it))
				it++;
			else if (it > main.begin() + (size - 1))
				it = it - size + 1;
			else
				it = main.begin();
			for(int k = 0; k < size; k++)
			{
				it = main.insert(it, pend[i - k]);
			}
			i -= size;
			it = main.begin() + size - 1;
			
		}
		else
			it = it + size;
		
	}
	if (sup)
	{
		pend.clear();
	}	
	end = after;
}

template<typename container>
void copy_in_main_pend(container&vector, container&main,container&pend, int size)
{
        	int reste;
	typename container::iterator it = vector.begin();
	int end = (vector.size() / size) * size;
	
	for(int i = 0; i < end ;i++, it++)
	{	
		reste = std::ceil(i / size);
		if(i < size || reste % 2 == 1)
			main.push_back(*it);
		else
			pend.push_back(*it);
	}
}
int	check_expression(int ar, char **l);
void fill_vector_deque(char** sequence, std::vector<int>& vector, std::deque<int>& deque);
template<typename container>
int sort_vector_stage1(container& vector)
{
        int i,a;
	unsigned long size = 1;
	while (size < vector.size())
	{
		a = -1;
		i = 1;
		for (typename container::iterator it = vector.begin(); it != vector.end(); it++, i++)
		{
			if(i % size == 0)
			{
				if (a ==-1)
					a = *it;
				else
				{
					if (a > *it)
						movePreviousBlockAfterIt(vector, it, size);	
					a = -1;
				}		
			}
		}
		size *= 2;
	}
	return size;
}
template<typename container>
int sort_vector_stage2(container& vector, int size)
{
	int k = 0;
	size = size / 4;
	container main;
	container pend;

	
	while(size >= 1)
	{
		copy_in_main_pend(vector, main, pend, size);
		while(!pend.empty())
		{
			insert_in_main(main, pend, jacobsthal_next(0), size);
			k++;
		}
		copy_in_list(main, vector);
		jacobsthal_next(1);
		main.clear();
		pend.clear();
		size /= 2;
	}
	return 1;        
}
std::vector<std::string> split(const char* str, char delim);




#endif