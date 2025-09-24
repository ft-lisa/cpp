#include "PmergeMe.hpp"

					/* TOOLS */
void fill_vector_deque(char** sequence, std::vector<int>& vector, std::deque<int>& deque)
{
	int value;
	for (int i = 1; sequence[i] != NULL; i++)
	{
		value = atoi(sequence[i]);
		vector.push_back(value);
		deque.push_back(value);
	}
}

long long jacobsthal_next(bool reset)
{
	static int n = 2;
	static long long a = 1, b = 1;
	long long res = 0;

	if (reset)
	{
		n = 2;
		a = 1;
		b = 1;
		return -1;
	}
	res = b + 2 * a;
	a = b;
	b = res;
	n++;
	return res;
}

// template<typename container>
// void movePreviousBlockAfterIt(container &lst, typename container::iterator it, int n) 
// {
// 	if (lst.empty() || n <= 0) return;
// 	typename container::iterator it2 = it;
// 	int size = n;
//         while(n > 0)
//         {
//                 std::advance(it2, -size); 
//                 std::iter_swap(it, it2);
//                 n--;
//                 it--;
//                 it2 = it;
                
//         }
// }

/**
 * copy to associated container
 * 1 2 3 4 | 5 6 7 8 | 9 10 11 12 |13 14 15 16 | 17 18 19 20 | 21 22
 *   main     main        pend          main          pend      no
 */
// template<typename container>
// void copy_in_main_pend(container&vector, container&main,container&pend, int size)
// {
// 	int reste;
// 	typename container::iterator it = vector.begin();
// 	int end = (vector.size() / size) * size;
	
// 	for(int i = 0; i < end ;i++, it++)
// 	{	
// 		reste = std::ceil(i / size);
// 		if(i < size || reste % 2 == 1)
// 			main.push_back(*it);
// 		else
// 			pend.push_back(*it);
// 	}
// }
// template<typename container>
// void copy_in_list(container& main, container& vector)
// {
// 	int i = 0;
// 	for (typename container::iterator it = main.begin(); it != main.end(); it++, i++)
// 	{
// 		vector[i] = *it;
// 	}
// }


				/* ALGO */
/**
 * allows you to pre-sort the largest number of pairs
 * 
 *
 * @param i to know what number we are on
 * @param a to keep in memory the number of the previous pair
 * @param size to simulate pairs
 */
// template<typename container>
// int sort_vector_stage1(container& vector)
// {
// 	int i,a;
// 	unsigned long size = 1;
// 	while (size < vector.size())
// 	{
// 		a = -1;
// 		i = 1;
// 		for (typename container::iterator it = vector.begin(); it != vector.end(); it++, i++)
// 		{
// 			if(i % size == 0)
// 			{
// 				if (a ==-1)
// 					a = *it;
// 				else
// 				{
// 					if (a > *it)
// 						movePreviousBlockAfterIt(vector, it, size);	
// 					a = -1;
// 				}		
// 			}
// 		}
// 		size *= 2;
// 	}
// 	return size;
// }



// template<typename container>
// void insert_in_main(container& main, container& pend, long long n, int size)
// {
// 	typename container::iterator it = main.begin();
// 	it = it + size - 1;
// 	int i = ((n - 1) * size) - 1 ;
// 	int after = i;
// 	static long long end;
// 	bool sup = 0;
// 	if (n == 3)
// 		end = 0;
// 	if (i + 1 >= (long long)pend.size())
// 	{
// 		sup = 1;
// 		i = pend.size() - 1;
// 	}
// 	while(i > end || (end == 0 && i == 0) ) 
// 	{
// 		if(pend[i] < *it || it + 1 == main.end())
// 		{
// 			if (it + 1 == main.end() && !(pend[i] < *it))
// 				it++;
// 			else
// 				it = it - size + 1;
// 			for(int k = 0; k < size; k++)
// 			{
// 				it = main.insert(it, pend[i - k]);
// 			}
// 			i -= size;
// 			it = main.begin() + size - 1;
			
// 		}
// 		else
// 			it = it + size;
		
// 	}
// 	if (sup)
// 	{
// 		pend.clear();
// 	}	
// 	end = after;
// }





/**
* Start the algorithm until we get back to a single number
* Create pend and main
* Insert into main
* 
*/
// template<typename container>
// int sort_vector_stage2(container& vector, int size)
// {
// 	int k = 0;
// 	size = size / 4;
// 	container main;
// 	container pend;

	
// 	while(size >= 1)
// 	{
// 		copy_in_main_pend(vector, main, pend, size);
// 		while(!pend.empty())
// 		{
// 			insert_in_main(main, pend, jacobsthal_next(0), size);
// 			k++;
// 		}
// 		copy_in_list(main, vector);
// 		jacobsthal_next(1);
// 		main.clear();
// 		pend.clear();
// 		size /= 2;
// 	}
// 	return 1;
// }


				/* PARCING */

int	ft_double(int argc, char **list, int reference)
{
	int	j;
	int	signe;
	int	num;

	if (list[argc - 1][0] == '-')
		reference = -reference;
	while (argc - 2)
	{
		signe = 1;
		j = 0;
		num = 0;
		if (list[argc - 2][0] == '-' || list[argc - 2][0] == '+')
			j++;
		if (list[argc - 2][0] == '-')
			signe = -signe;
		while (list[argc - 2][j])
		{
			num = num * 10 + list[argc - 2][j] - 48;
			j++;
		}
		if (num * signe == reference)
			return std::cerr << ERR_DOUBLE <<std::endl, (0);
		argc--;
	}
	return (1);
}

/**
 * This function check if the vector is numbers,
	is not bigger or smaller the int_max and the int_min and
 * if there is no duplicate
 *
 * @param ar for browse the vector
 * @param l
 * @return 1 if the vector is good 0 if one rules is not respect
 */
int	check_expression(int ar, char **l)
{
	int		j;
	long	num;

	while (ar != 1)
	{
		ar--;
		j = 0;
		num = 0;
		if ((l[ar][0] == '-' && l[ar][1] != '\0') || (l[ar][0] == '+'
				&& l[ar][1] != '\0'))
			j++;
		while (l[ar][j] != '\0')
		{
			num = num * 10 + l[ar][j] - 48;
			if (l[ar][j] < 48 || l[ar][j] > 57 || (num > 2147483647
					&& l[ar][0] != '-') || num > 2147483648)
				return std::cout << ERR_INT << std::endl,(0);
			j++;
		}
		if (ft_double(ar + 1, l, num) == 0)
			return (0);
	}
	return (1);
}