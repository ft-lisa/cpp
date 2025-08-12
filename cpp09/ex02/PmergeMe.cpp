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


int sort_merge_insert_list(std::list<int>& list)
{
	std::list<int> a;
	std::list<int> b;
	std::list<int> reste;

	

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