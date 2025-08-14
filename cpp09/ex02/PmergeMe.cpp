#include "PmergeMe.hpp"
void fill_list_deque(char** sequence, std::list<int>& list, std::deque<int>& deque)
{
	int value;
	for (int i = 1; sequence[i] != NULL; i++)
	{
		value = atoi(sequence[i]);
		list.push_back(value);
		deque.push_back(value);
	}
}
void movePreviousBlockAfterIt(std::list<int> &lst, std::list<int>::iterator it, int n) {
    if (lst.empty() || n <= 0) return;
    std::list<int>::iterator it2 = it;
    int size = n;
        while(n > 0)
        {
        //     for (std::list<int>::iterator i = lst.begin(); i != lst.end(); ++i)
        //             std::cout << *i << " ";
        //         std::cout << std::endl;
                std::advance(it2, -size); 
                std::iter_swap(it, it2);
                n--;
                it--;
                it2 = it;
                
        }
}

/**
 * permet de faire un pre trie des plus grand nombre des paires
 * 
 *
 * @param i pour savoir sur quel nombre on est
 * @param a pour garder en memoire le nombre de la paire d'avant
 * @param size pour simuler des paires
 */
int sort_list_stage1(std::list<int>& list)
{
	int i,a;
	unsigned long size = 1;
	while (size < list.size())
	{
		a = -1;
		i = 1;
		for (std::list<int>::iterator it = list.begin(); it != list.end(); it++, i++)
		{
			if(i % size == 0)
			{
				if (a ==-1)
					a = *it;
				else
				{
					if (a > *it)
						movePreviousBlockAfterIt(list, it, size);	
					a = -1;
				}		
			}
		}
		size *= 2;
	}
	return size;
}
/**
 * copie seulement les pairs pair et 1
 * 1 2 3 4 | 5 6 7 8 | 9 10 11 12 |13 14 15 16 | 17 18 19 20
 *    yes      yes        no           yes          no
 */
void copy_in_main_pend(std::list<int>&list, std::list<int>&main,std::list<int>&pend, int size)
{
	int reste;
	std::list<int>::iterator it = list.begin();

	for(int i; i < size ;i++, it++)
	{
		reste = std::ceil(i / size);
		if(i < size || reste % 2 == 0)
			main.push_back(*it);
		else
			pend.push_back(*it);
	}
}

/**
 * debut de l'algo tant qu'on est pas revenue a un seul nombre 
 * creation de pend et main
 * insert dans main
 *
 * 
 */
int sort_list_stage2(std::list<int>& list, int size)
{
	size = size / 4;
	std::list<int> main;
	std::list<int> pend;
	
	while(size != 1)
	{
		copy_in_main_pend(list, main, pend, size);
		while(!pend.empty())
		{
			//insert dans main
		}

		size /= 2;
	}
}



int	ft_double(int argc, char **liste, int reference)
{
	int	j;
	int	signe;
	int	num;

	if (liste[argc - 1][0] == '-')
		reference = -reference;
	while (argc - 2)
	{
		signe = 1;
		j = 0;
		num = 0;
		if (liste[argc - 2][0] == '-' || liste[argc - 2][0] == '+')
			j++;
		if (liste[argc - 2][0] == '-')
			signe = -signe;
		while (liste[argc - 2][j])
		{
			num = num * 10 + liste[argc - 2][j] - 48;
			j++;
		}
		if (num * signe == reference)
			return (0);
		argc--;
	}
	return (1);
}

/**
 * This function check if the list is numbers,
	is not bigger or smaller the int_max and the int_min and
 * if there is no duplicate
 *
 * @param ar for browse the list
 * @param l
 * @return 1 if the list is good 0 if one rules is not respect
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
				return (0);
			j++;
		}
		if (ft_double(ar + 1, l, num) == 0)
			return (0);
	}
	return (1);
}