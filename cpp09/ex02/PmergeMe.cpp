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

void moveBlockBeforeIterator(std::list<int> &lst,
                              std::list<int>::iterator it,
                              int n) {
    if (lst.empty() || n <= 0) return;

    // Trouver le début du bloc n éléments avant `it`
    std::list<int>::iterator start = it;
    std::advance(start, -n); // ⚠ il faut s'assurer que n <= distance(begin, it)

    // Déplacer le bloc [start, it) juste après `it`
    std::list<int>::iterator after_it = it;
    ++after_it; // position d'insertion après it
    lst.splice(after_it, lst, start, it);
}


int sort_merge_insert_list(std::list<int>& list)
{
	int size = 1;
	int i = 1;
	int a = -1;
	int b = -1;

	while (size < list.size())
	{
		i = 1;
		for (std::list<int>::iterator it; it != list.end(); it++)
		{
			if(i % size == 0)
			{
				if (a ==-1)
					a = *it;
				else
				{
					b = *it;
					if (a > b)
					{
						
					}
				}
					
			}
			i++;
		}
		size *= 2;
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