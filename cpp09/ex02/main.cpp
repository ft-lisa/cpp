#include "PmergeMe.hpp"

template<typename Container>
void afficher(const Container& c, const std::string& nom) {
    std::cout << nom << " contient : ";
    typename Container::const_iterator it;
    for (it = c.begin(); it != c.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}

int main(int argc, char** argv)
{
        std::list<int> list;
        std::deque<int> deque;

        if (argc == 1)
                return std::cerr << ERR_ARG << std::endl, 1;
        if(check_expression(argc, argv) == 0)
                return 1;
        fill_list_deque(argv, list, deque);
        afficher(list, "list");
        afficher(deque, "deque");
        sort_merge_insert(list);
        return 0;
}