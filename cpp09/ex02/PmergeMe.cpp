#include "PmergeMe.hpp"
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
void movePreviousBlockAfterIt(std::vector<int> &lst, std::vector<int>::iterator it, int n) {
    if (lst.empty() || n <= 0) return;
    std::vector<int>::iterator it2 = it;
    int size = n;
        while(n > 0)
        {
        //     for (std::vector<int>::iterator i = lst.begin(); i != lst.end(); ++i)
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
int sort_vector_stage1(std::vector<int>& vector)
{
	int i,a;
	unsigned long size = 1;
	while (size < vector.size())
	{
		a = -1;
		i = 1;
		for (std::vector<int>::iterator it = vector.begin(); it != vector.end(); it++, i++)
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
/**
 * est ce que probleme si reste 
 * copie seulement les pairs pair et 1
 * 1 2 3 4 | 5 6 7 8 | 9 10 11 12 |13 14 15 16 | 17 18 19 20 | 21 22
 *    yes      yes        no           yes          no
 */
void copy_in_main_pend(std::vector<int>&vector, std::vector<int>&main,std::vector<int>&pend, int size)
{
	int reste;
	std::vector<int>::iterator it = vector.begin();
	int end = (vector.size() / size) * size;
	
	//std::cout << end << std::endl;
	for(int i = 0; i < end ;i++, it++)
	{
		
		reste = std::ceil(i / size);
		if(i < size || reste % 2 == 1)
			main.push_back(*it);
		else
			pend.push_back(*it);
	}
}

long long jacobsthal_next(bool reset) {
    static int n = 2;
    static long long a = 1, b = 1;
    long long res = 0;

    if (reset) {
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

template <typename T>
void printvector(const std::vector<T>& lst, const std::string& label) {
    std::cout << label << ": [ ";
    for (typename std::vector<T>::const_iterator it = lst.begin(); it != lst.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "]" << std::endl;
}

void insert_in_main(std::vector<int>& main, std::vector<int>& pend, long long n, int size)
{
	std::vector<int>::iterator it = main.begin();
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
		// end = 0;
	}
	std::cout << "start : " << i << " end : " << end << " size : " << size << " jacob " << n << std::endl;
	 printvector(main, "main in");
	 printvector(pend, "pend in");
	while(i > end) // faire quand le nombre est plus grand que le dernier de main
	{
		
		std::cout << "pend[i] = " << pend[i] << std::endl;
		std::cout << "main[i] = " << *it << std::endl;
		if(pend[i] < *it || it + 1 == main.end())
		{
			if (it + 1 == main.end())
				it++;
			it = it - size + 1;
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
	//pend.erase(pend.begin() + end, pend.begin() + i + 1);
	//printvector(pend, "pend");
	printvector(main, "main :");
	if (sup)
	{
		pend.clear();
	}	
	end = after;
}


void copy_in_list(std::vector<int>& main, std::vector<int>& vector)
{
	int i = 0;
	for (std::vector<int>::iterator it = main.begin(); it != main.end(); it++, i++)
	{
		vector[i] = *it;
	}
}


/**
 * debut de l'algo tant qu'on est pas revenue a un seul nombre 
 * creation de pend et main
 * insert dans main
 *
 * 
 */
int sort_vector_stage2(std::vector<int>& vector, int size)
{
	int k = 0;
	size = size / 4;
	std::vector<int> main;
	std::vector<int> pend;

	
	while(size >= 1) //size != 0
	{
		copy_in_main_pend(vector, main, pend, size);
		// printvector(main, "avant main");
		// printvector(pend, "avant pend");
		while(size >= 1 && !pend.empty()) //!pend.empty()
		{
			insert_in_main(main, pend, jacobsthal_next(0), size);
			k++;
		}
		copy_in_list(main, vector);
		printvector(vector, "list: ");
		jacobsthal_next(1);
		main.clear();
		pend.clear();
		size /= 2;
	}
	return 1;
}



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
			return (0);
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
				return (0);
			j++;
		}
		if (ft_double(ar + 1, l, num) == 0)
			return (0);
	}
	return (1);
}