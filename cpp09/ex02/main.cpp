#include "PmergeMe.hpp"

template<typename Container>
void afficher(const Container& c, const std::string& nom) {
    std::cout << nom << " contient : ";
    typename Container::const_iterator it;
    for (it = c.begin(); it != c.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}

bool is_sorted(const std::vector<int>& v) {
    for (size_t i = 1; i < v.size(); i++) {
        if (v[i] < v[i-1])
            return false;
    }
    return true;
}

int main(int argc, char** argv)
{
        std::vector<int> vector;
        std::deque<int> deque;

        if (argc == 1)
                return std::cerr << ERR_ARG << std::endl, 1;
        if (argc == 2)
                argv = split(argv[1], ' ');
        if(check_expression(argc, argv) == 0)
                return 1;
        fill_vector_deque(argv, vector, deque);
        afficher(vector, "vector");
        //afficher(deque, "deque");
        int size = sort_vector_stage1(vector);
        sort_vector_stage2(vector, size);
        afficher(vector, "vector");
        
        if (is_sorted(vector)) std::cout << "Trié\n";
        else std::cout << "Pas trié\n";

        return 0;
}